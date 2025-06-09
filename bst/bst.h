#ifndef BST_H
#define BST_H


typedef struct BST
{
  int value;
  struct BST *left, *right;
} bst;

bst * insert(bst *root, int value);

bst * busca(bst *root, int value);

bst * removal(bst *root, int value);

#endif
