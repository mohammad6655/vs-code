#include <iostream>

struct Book
{
    int ISBN;
    char bookName[30];
    int price;
};
void readbook(Book book[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Please enter a ISBN , price && bookName: ";
        std::cin >> book[i].ISBN >> book[i].price;
        std::cin.getline(book[i].bookName, 30);
    }
}
void sortWithPrice(Book book[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (book[i].price > book[j].price)
            {
                Book t = book[i];
                book[i] = book[j];
                book[j] = t;
            }
    }
}
int stringCompare(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 > *s2)
        return (1);
    else if (*s1 < *s2)
        return -1;
    else
        return 0;
}
void sortWithBookName(Book book[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (stringCompare(book[i].bookName, book[j].bookName) > 0)
            {
                Book t = book[i];
                book[i] = book[j];
                book[j] = t;
            }
    }
}
void deleteBook(Book book[], int *n, int ISBN1)
{
    int i;
    for (i = 0; i < *n; i++)
        if (ISBN1 == book[i].ISBN)
            break;
    if (i == *n - 1)
    {
        *n--;
        return;
    }
    int flagDelete = 0;
    for (int j = i; j < *n - 1; j++)
    {
        flagDelete = 1;
        book[j] = book[j + 1];
    }
    if (flagDelete != 0)
    {
        (*n)--;
    }
}
void printBook(Book book[], int n)
{
    std::cout << "ISBN" << "\t" << "price\tbookName\n";
    std::cout << "=======\t=======\t=======\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << book[i].ISBN << "\t" << book[i].price << "\t" << book[i].bookName << "\n";
    }
}
int main()
{
    Book book[5];
    int n = 5, isbn;
    readbook(book, n);
    sortWithPrice(book, n);
    std::cout << "\n      Sort By Price \n";
    printBook(book, n);
    sortWithBookName(book, n);
    std::cout << "\n      Sort By Name \n";
    printBook(book, n);
    std::cout << "\nEnter ISBN for deleted: ";
    std::cin >> isbn;
    deleteBook(book, &n, isbn);
    printBook(book, n);
    return 0;
}