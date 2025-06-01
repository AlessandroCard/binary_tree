
typedef struct AVL
{
  int value, height;
  struct AVL *left, *right;
}avl;

void printree(avl *root, int level);

int bigger(int a, int b);

int height(avl *root);

avl * rotleft(avl *root);

avl * rotright(avl *root);

int balancefactor(avl *root);

avl * balance(avl *root);

avl * insert(avl *root, int value);

avl * removal(avl *root, int value);
