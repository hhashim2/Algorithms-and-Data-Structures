/**
    Algorithms and Data Structures
    Homework 8
    Red Black Tree Implementation
    Huzaifa Hashim
**/

#include <iostream>
#include <queue>
#include <cstdlib>

enum Color { RED, BLACK };
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *&);
    void rotateRight(Node *&);

public:
    RedBlackTree();
    void insert(int);
    void delete(Node *&);
    Node * predecessor(const Node *&);
    Node * successor(const Node &&);
    Node * getMinimum();
    Node * getMaximum();
    Node * search(int);
};




