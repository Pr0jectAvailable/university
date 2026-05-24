#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == NULL) return false;
    if (value == root->data) return true;
    if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* removeNode(Node* root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data) {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = removeNode(root->right, value);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = removeNode(root->right, minRight->data);
    }
    return root;
}

void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "пусто" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "уровень " << level << ": ";
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
        ++level;
    }
}

void accumulateSums(Node* node, int level, int sums[], int& maxLevel) {
    if (node == NULL) return;
    sums[level] += node->data;
    if (level > maxLevel) maxLevel = level;
    accumulateSums(node->left, level + 1, sums, maxLevel);
    accumulateSums(node->right, level + 1, sums, maxLevel);
}

void printSumPerLevel(Node* root) {
    if (root == NULL) {
        cout << "пусто" << endl;
        return;
    }
    int sums[11] = { 0 };
    int maxLevel = 0;
    accumulateSums(root, 0, sums, maxLevel);
    cout << "суммы значений по уровням:" << endl;
    for (int i = 0; i <= maxLevel; ++i) {
        cout << "уровень " << i << ": " << sums[i] << endl;
    }
}

int sumLeaves(Node* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) {
        return node->data;
    }
    return sumLeaves(node->left) + sumLeaves(node->right);
}

void clearTree(Node* root) {
    if (root == NULL) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 65);
    root = insert(root, 75);
    root = insert(root, 90);
    printLevelOrder(root);

    int choice, value;
    do {
        cout << "\nменю\n";
        cout << "1 добавить элемент\n";
        cout << "2 удалить элемент\n";
        cout << "3 поиск элемента\n";
        cout << "4 вывести дерево (по уровням)\n";
        cout << "5 вывести суммы по уровням\n";
        cout << "6 вывести сумму листьев\n";
        cout << "0 выход\n";
        cout << "выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "введите значение: ";
            cin >> value;
            root = insert(root, value);
            cout << "элемент добавлен\n";
            break;
        case 2:
            cout << "введите значение: ";
            cin >> value;
            if (search(root, value)) {
                root = removeNode(root, value);
                cout << "элемент удалён\n";
            }
            else {
                cout << "элемент не найден\n";
            }
            break;
        case 3:
            cout << "введите значение: ";
            cin >> value;
            if (search(root, value)) {
                cout << "элемент найден\n";
            }
            else {
                cout << "элемент не найден\n";
            }
            break;
        case 4:
            cout << "дерево:\n";
            printLevelOrder(root);
            break;
        case 5:
            printSumPerLevel(root);
            break;
        case 6:
            cout << "сумма всех листьев: " << sumLeaves(root) << endl;
            break;
        case 0:
            cout << "выход из программы\n";
            break;
        default:
            cout << "неверный выбор\n";
            break;
        }
    } while (choice != 0);

    clearTree(root);
    return 0;
}