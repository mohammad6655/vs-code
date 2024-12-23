// count leaf
#include <iostream>
#include <conio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int item)
{
    struct node *n;
    n = new (struct node);

    n->data = item;
    n->left = NULL;
    n->right = NULL;

    return (n);
}
unsigned int countLeaf(struct node *p)
{
    if (p == NULL)
        return 0;
    if (p->left == NULL && p->right == NULL)
        return 1;
    else
        return countLeaf(p->left) + countLeaf(p->right);
}

int main(){
    struct node*r;

    r                       =create(1);

    r->left                 =create(2);
    r->right                =create(3);

    r->left->left           =create(4);
    r->left->right          =create(5);

    r->left->right->left    =create(6);

    std::cout<<countLeaf(r);

    getch();
}