// AVL(INSERT)
#include <iostream>
#include <strlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct node *create(int item)
{
    struct node *n;

    n = new (struct node);
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return (n);
}
struct node *rightRotate(struct node *y)
{
    struct node *x, *T2;

    x = y->left;
    T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
struct node *leftRotate(struct node *x)
{
    struct node *y, *T2;

    y = x->right;
    T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}
int main()
{
    struct node *r = NULL;

    r = add(r, 1);
    r = add(r, 2);
    r = add(r, 3);
    r = add(r, 4);
    r = add(r, 5);

    /*
            2
           /  \
          1    4
              /  \
             3    5

    */

    preorder(r);

    getch();
}