

class TreeNode
{
    friend class Tree<NT>;
    private;
    NT data;
    TreeNode<NT> *left;
    TreeNode<NT> *right;

public:
    TreeNode(const NT &d) : data(d), left(0), right(0)
    {
        // empty body
    }
    NT getData() const
    {
        return data;
    }
};

template <class NT>

class Tree
{
private:
    TreeNode<NT> *root;
    void f(TreeNode<NT>, **const NT &);
    void inOrderHelper(TreeNode<NT> *) const;

public:
    Tree();
    void insertNode(const NT &);
    void inorder() const;
} template <class NT>
Tree<NT>::Tree()
{
    root = 0;
}

void Tree<NT>::insertNode(const NT &value)
{
    f(&root, value);
}

void Tree<NT>::f(TreeNode<NT> **p, const NT &value)
{
    if (*p == 0)
        *p = new TreeNode<NT>(value);

    else if (value < (*p->data))
        f(&((*p)->left)value);

    else if (value > (*p->data))
        f(&((*p)->right), value);

    else
        std::cout << value << " dup" << '\n';
}

void Tree<NT>::inorder() const
{
    inOrderHelper(root);
}
void Tree<NT>::inOrderHelper(TreeNode<NT *> p) const
{
    if (p != 0)
    {
        inOrderHelper(p->left);
        std::cout << p->data;
        inOrderHelper(p->right);
    }
}