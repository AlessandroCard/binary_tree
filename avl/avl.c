#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

void printree(avl *root, int level)
{
    if(root)
    {
        printree(root->right, level + 1);
        printf("\n\n");

        for(int i = 0; i < level; i++)
            printf("\t");

        printf("%d", root->value);
        printree(root->left, level + 1);
    }
}

int bigger(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(avl *root)
{
    return root ? root->height : -1;
}

avl * rotleft(avl *root)
{
    avl *aux = root->right, *aux2 = aux->left;

    aux->left = root;
    root->right = aux2;

    root->height = bigger(height(root->left), height(root->right)) + 1;
    aux->height = bigger(height(aux->left), height(aux->right)) + 1;

    return aux;
}

avl * rotright(avl *root)
{
    avl *aux1 = root->left, *aux2 = aux1->right;

    aux1->right = root;
    root->left = aux2;

    root->height = bigger(height(root->left), height(root->right)) + 1;
    aux1->height = bigger(height(aux1->left), height(aux1->right)) + 1;

    return aux1;
}

int balancefactor(avl *root)
{
    int heightleft = root->left ? root->left->height : -1;
    int heightright = root->right ? root->right->height : -1;
    return heightleft - heightright;
}

avl * balance(avl *root)
{
    int bf = balancefactor(root);

    if(bf < -1 && balancefactor(root->right) <= 0)
        root = rotleft(root);
    else if(bf > 1 && balancefactor(root->left) >= 0)
        root = rotright(root);
    else if(bf < -1 && balancefactor(root->right) > 0 )
    {
        root->right = rotright(root->right);
        root = rotleft(root);
    }
    else if(bf > 1 && balancefactor(root->left) < 0)
    {
        root->left = rotright(root->left);
        root = rotleft(root);
    }

    return root;
}

avl * insert(avl *root, int value)
{
    if(root == NULL)
    {
        avl *aux = (avl *) malloc(sizeof(avl));
        aux->height = 0;
        aux->value = value;
        aux->left = NULL;
        aux->right = NULL;

        return aux;
    }

    if(value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    
    root->height = bigger(height(root->left), height(root->right)) + 1;

    root = balance(root);
    
    return root;
}

avl * removal(avl *root, int value)
{
    if(root == NULL)
        return NULL;
    
    if(root->value != value)
    {
        if(value < root->value)
            root->left = removal(root->left, value);
        else
            root->right = removal(root->right, value);

        root->height = bigger(height(root->left), height(root->right)) + 1;

        root = balance(root);

        return root;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left != NULL && root->right != NULL)
        {
            avl *aux = root->left;

            while (aux->right != NULL)
                aux = aux->right;

            root->value = aux->value;
            aux->value = value;

            root->left = removal(root->left, value);

            return root;
        }
        else
        {
            avl *aux;

            if(root->left == NULL)
                aux = root->right;
            else
                aux = root->left;
            
            free(root);
            return aux;
        }
    }
}
