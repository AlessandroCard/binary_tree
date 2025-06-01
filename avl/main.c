#include "avl.h"
#include <stdio.h>

int main()
{
    avl *root = NULL;

    for(int i = 0; i < 20; i++)
    {
        root = insert(root, i);
    }
    printree(root, 1);
    printf("\n\n\n\n\n\n\n\n");

    for(int i = 7; i < 14; i++)
        root = removal(root, i);
    printree(root, 1);

    return 0;
}
