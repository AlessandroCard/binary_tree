#include "bst.h"
#include <stdio.h>

void printree(bst *root)
{
  if(root != NULL)
  {
    printree(root->left);
    printf("%d ", root->value);
    printree(root->right);
  }
}

int main()
{
  bst *root = NULL;
  
  root = insert(root, 5);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 3);

  printree(root);

  return 0;
}
