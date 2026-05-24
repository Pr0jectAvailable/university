#include "fun.h"

bool is_empty_s_s(Node* top) {
    return top == nullptr;
}

void push(Node*& top, DataType value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

bool pop(Node*& top, DataType& value) {
    if (is_empty_s_s(top)) {
        return false;
    }
    Node* temp = top;
    value = temp->data;
    top = top->next;
    delete temp;
    return true;
}

void clear(Node*& top) {
    while (!is_empty_s_s(top)) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void print_stack(Node* top) {
    if (is_empty_s_s(top)) {
        cout << "стек пуст.\n";
        return;
    }
    cout << "стек: ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool save_to_file(Node* top, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    int count = 0;
    Node* temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    file << count << endl;

    temp = top;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
    return true;
}

bool load_from_file(Node*& top, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    int count;
    file >> count;
    if (count < 0 || count > 1000) {
        file.close();
        return false;
    }

    DataType* buffer = new DataType[count];
    for (int i = 0; i < count; ++i) {
        file >> buffer[i];
        if (file.fail()) {
            delete[] buffer;
            file.close();
            return false;
        }
    }
    file.close();

    clear(top);

    for (int i = count - 1; i >= 0; --i) {
        push(top, buffer[i]);
    }
    delete[] buffer;
    return true;
}

void split_by_parity(Node* source, Node*& even_stack, Node*& odd_stack) {
    clear(even_stack);
    clear(odd_stack);

    Node* current = source;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            push(even_stack, current->data);
        }
        else {
            push(odd_stack, current->data);
        }
        current = current->next;
    }
}

int count_duplicates(Node* top) {
    if (is_empty_s_s(top)) {
        return 0;
    }
    int size = 0;
    Node* temp = top;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    DataType* values = new DataType[size];
    temp = top;
    for (int i = 0; i < size; i++) {
        values[i] = temp->data;
        temp = temp->next;
    }

    bool* processed = new bool[size];
    for (int i = 0; i < size; i++) {
        processed[i] = false;
    }

    int duplicate_count = 0;

    for (int i = 0; i < size; i++) {
        if (!processed[i]) {
            int freq = 1;
            for (int j = i + 1; j < size; j++) {
                if (values[j] == values[i]) {
                    freq++;
                    processed[j] = true;
                }
            }
            if (freq > 1) {
                duplicate_count++;
            }
            processed[i] = true;
        }
    }

    delete[] values;
    delete[] processed;
    return duplicate_count;
}