#ifndef STRUCT_H
#define STRUCT_H

// структура для представления узла бинарного дерева
typedef struct node_t
{
    int _data;
    node_t *left;
    node_t *right;

    node_t(int data) : _data(data), left(nullptr), right(nullptr) {}
}node_t;

#endif // STRUCT_H