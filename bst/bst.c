#include "bst.h"
#include <stdlib.h>

bst * insert(bst *root, int value)
{
  if(root == NULL)
  {
    bst *new = (bst *) malloc(sizeof(bst));

    new->value = value;
    new->left = NULL;
    new->right = NULL;

    return new;
  }

  if(value < root->value)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);

  return root;
}

bst * busca(bst *root, int value)
{
  bst *aux1 = root, *aux2;

  while(aux1 != NULL && aux1->value != value)
  {
    aux2 = aux1;
    if(value < aux1->value)
      aux1 = aux1->left;
    else
      aux1 = aux1->right;
  }

  if(aux1 == NULL)
    return aux1;
  else
    return aux2;
}

bst * removal(bst *root, int value)
{
  if(root == NULL)
    return NULL;

  if(root->value == value)
  {
    if(root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if (root->left != NULL && root->right != NULL) {
      bst * aux1 = root->left;

      while(aux1->right != NULL)
        aux1 = aux1->right;

      root->value = aux1->value;
      aux1->value = value;

      root->left = removal(root->left, value);

      return root;
    }
    else
    {
      bst *aux;
      if (root->left == NULL) 
        aux = root->right;
      else
        aux = root->left;

      free(root);
      return aux;
    }
  }
  else
  {
    if(value < root->value)
      root->left = removal(root->left, value);
    else
      root->right = removal(root->right, value);

    return root;
  }
}

