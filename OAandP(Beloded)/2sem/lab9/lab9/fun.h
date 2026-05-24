#pragma once

#include <iostream>
#include <fstream>

using namespace std;

typedef int DataType;

struct Node {
    DataType data;
    Node* next;
};

bool is_empty_s_s(Node* top);
void push(Node*& top, DataType value);
bool pop(Node*& top, DataType& value);
void clear(Node*& top);
void print_stack(Node* top);
bool save_to_file(Node* top, const char* filename);
bool load_from_file(Node*& top, const char* filename);

void split_by_parity(Node* source, Node*& even_stack, Node*& odd_stack);
int count_duplicates(Node* top);