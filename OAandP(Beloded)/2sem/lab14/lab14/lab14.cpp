#include <iostream>
#include <cstdarg>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

void addEdge(Node** adjList, int u, int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = new Node;
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void dfs(Node** adjList, bool* visited, int v, int& compSize) {
    visited[v] = true;
    compSize++;
    Node* curr = adjList[v];
    while (curr != nullptr) {
        if (!visited[curr->vertex]) {
            dfs(adjList, visited, curr->vertex, compSize);
        }
        curr = curr->next;
    }
}

void graphOperation(int n, Node** adjList, int opCode, ...) {
    if (n <= 0 || adjList == nullptr) {
        cout << "ошибка\n";
        return;
    }

    bool* visited = new bool[n]();

    va_list args;
    va_start(args, opCode);

    int* maxSizePtr = nullptr;
    int* compSizes = nullptr;

    switch (opCode) {
    case 1:
        break;
    case 2:
        maxSizePtr = va_arg(args, int*);
        break;
    case 3:
        compSizes = va_arg(args, int*);
        maxSizePtr = va_arg(args, int*);
        break;
    default:
        cout << "ошибка\n";
        va_end(args);
        delete[] visited;
        return;
    }

    int maxSize = 0;
    int compCount = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int curSize = 0;
            dfs(adjList, visited, i, curSize);
            if (compSizes != nullptr) {
                compSizes[compCount] = curSize;
            }
            if (curSize > maxSize) {
                maxSize = curSize;
            }
            compCount++;
        }
    }

    switch (opCode) {
    case 1:
        cout << "компонент связности с максимальным количеством вершин: " << maxSize - 1 << endl;
        break;
    case 2:
        if (maxSizePtr != nullptr) {
            *maxSizePtr = maxSize;
        }
        break;
    case 3:
        if (maxSizePtr != nullptr) {
            *maxSizePtr = maxSize;
        }
        if (compSizes != nullptr) {
            cout << "размеры компонент связности: ";
            for (int i = 0; i < compCount; ++i) {
                cout << compSizes[i] << " ";
            }
            cout << endl;
        }
        break;
    }

    va_end(args);
    delete[] visited;
}

void countVerticesWithinDistance(Node** adjList, int n, int maxDist) {
    if (maxDist < 0) {
        cout << "расстояние не может быть отрицательным\n";
        return;
    }

    cout << "\nдля каждой вершины количество других вершин достижимых за расстояние <= " << maxDist << ":\n";
    for (int start = 0; start < n; ++start) {
        vector<int> dist(n, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            Node* neighbor = adjList[cur];
            while (neighbor != nullptr) {
                int v = neighbor->vertex;
                if (dist[v] == -1) {
                    dist[v] = dist[cur] + 1;
                    q.push(v);
                }
                neighbor = neighbor->next;
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i != start && dist[i] != -1 && dist[i] <= maxDist) {
                count++;
            }
        }
        cout << "вершина " << start << ": " << count << " вершин\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;
    cout << "введите количество вершин и рёбер: ";
    cin >> n >> m;

    Node** adjList = new Node * [n];
    for (int i = 0; i < n; ++i) {
        adjList[i] = nullptr;
    }

    cout << "введите рёбра (начало и конец):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    cout << "\nсписок смежности:\n";
    for (int i = 0; i < n; ++i) {
        cout << "вершина " << i << ": ";
        Node* cur = adjList[i];
        while (cur) {
            cout << cur->vertex << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    cout << endl;


    graphOperation(n, adjList, 1);

    int userDist;
    cout << endl;
    cin >> userDist;
    countVerticesWithinDistance(adjList, n, userDist);

    return 0;
}

// 15 Определить для каждой вершины количество других вершин, до которых можно добраться по кратчайшему пути, не превышающему заданное пользователем значение.