// bst (inorder)
#include <iostream>
#include <iomanip>
#include <conio.h>

using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;

#include "Tree.h"

int main()
{
    Tree<int> T;
    int x;
    std::cout << "Enter 7 integer values:\n";

    for (int i = 0; i < 7; i++)
    {
        std::cin >> x;
        T.insertNode(x);
    }
    std::cout << "\nInorder traversal\n";
    T.inOrderTraversal();

    Tree<double> DT;
    double d;

    std::cout << fixed << setprecision(1);
    std::cout << "\n\n\nEnter 7 double values:\n";

    for (int j = 0; j < 7; j++)
    {
        std::cin >> d;
        DT.insertNode(d);
    }
    std::cout << "\nIndorder traversal\n";
    DT.inOrderTraversal();

    return 0;
}