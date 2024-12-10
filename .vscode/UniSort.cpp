#include <iostream>
#include <conio.h>
#include <stdio.h>

typedef struct
{
    int StID;
    char Name[20];
    float Avg;
} Student;
int lenstr(char str[])
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
void a2A(char str[])
{
    int i = 0;
    while (i < lenstr(str))
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
        while (str[i - 1] == ' ')
            i++;
    }
}
void cpystr(char str1[], char str2[])
{
    for (int i = 0; i < lenstr(str1); i++)
        str2[i] = str1[i];
    str2[lenstr(str1)] = '\0';
}
int cmpstr(char str1[], char str2[])
{
    int flag, i;
    flag = 0;
    if (lenstr(str1) != lenstr(str2))
        flag = 1;
    i = 0;
    while (i < lenstr(str1) && !flag)
    {
        if (str1[i] != str2[i])
            flag = 1;
        i++;
    }
    return (flag);
}

int cmpstr2(char str1[], char str2[])
{
    char tmp1[256], tmp2[256];
    cpystr(str1, tmp1);
    cpystr(str2, tmp2);
    a2A(tmp1);
    a2A(tmp2);
    int flag = 0, i = 0;
    while ((tmp1[i] || tmp2[i]) && !flag)
    {
        if (tmp1[i] > tmp2[i])
            flag = 1;
        else if (tmp1[i] < tmp2[i])
            flag = -1;
        i++;
    }
    return (flag);
}

char Menu()
{
    char ch;
    std::cout << "Student's  DataBase \n";
    std::cout << "------------------- \n";
    std::cout << "\t 1) Enter New Student\n";
    std::cout << "\t 2) View list sorted by ID.\n";
    std::cout << "\t 3) View list sorted by Name.\n";
    std::cout << "\t 4) View list sorted by Average.\n";
    std::cout << "\t 5) Find by ID.\n";
    std::cout << "\t 6) Find by Name.\n";
    std::cout << "\t 7) Exit\n ";
    std::cout << " Select: ";
    std::cin >> ch;
    return (ch);
}
int stdinput(Student arr[], int size)
{
    int n;
    std::cout << "\nEnter New Student's Information:";
    std::cout << "\n--------------------------------";
    std::cout << "\n How many student? ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << "\n";
        std::cout << "Name: ";
        std::cin >> arr[size].Name;
        std::cout << "ID: ";
        std::cin >> arr[size].StID;
        std::cout << "Avrage: ";
        std::cin >> arr[size].Avg;
        size++;
        std::cout << '\n';
    }
    std::cout << '\n'
              << n << " New entry.";
    return (size);
}
void AZid(Student arr[], int size)
{
    Student temp;
    int j;
    std::cout << "\nStudent's Information (Sorted bt ID)";
    std::cout << "\n------------------------------------";
    std::cout << "\nNo. \t Name \t\t ID \t\t Avrage \n\n";
    for (int i = 0; i < size; i++)
    {
        j = i;
        temp = arr[i];
        while (j > 0 && temp.StID < arr[j - 1].StID)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << " )\t";
        std::cout << arr[i].Name << " \t\t";
        std::cout << arr[i].StID << " \t\t";
        std::cout << arr[i].Avg << " \n";
    }
}
void AZname(Student arr[], int size)
{
    Student temp;
    int j;
    std::cout << "Student's Information (Sorted bt Name)";
    std::cout << "\n------------------------------------";
    std::cout << "\nNo. \t Name \t\t ID \t\t Average \n\n";
    for (int i = 0; i < size; i++)
    {
        j = i;
        temp = arr[i];
        while (j > 0 && cmpstr2(arr[j - 1].Name, temp.Name) > 0)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "\t";
        std::cout << arr[i].Name << "\t\t";
        std::cout << arr[i].StID << "\t\t";
        std::cout << arr[i].Avg << " \n";
    }
}
void AZavg(Student arr[], int size)
{
    Student temp;
    int j;
    std::cout << "Student's Information (Sorted bt Average)";
    std::cout << "\n---------------------------------------";
    std::cout << "\nNo. \t Name \t\t ID \t\t Average \n\n";
    for (int i = 0; i < size; i++)
    {
        j = i;
        temp = arr[i];
        while (j > 0 && temp.Avg < arr[j - 1].Avg)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "\t";
        std::cout << arr[i].Name << "\t\t";
        std::cout << arr[i].StID << "\t\t";
        std::cout << arr[i].Avg << "\t\t";
    }
}
void Findid(Student arr[], int size)
{
    int n, i;
    std::cout << "\nFind Student by Std ID";
    std::cout << "\n----------------------";
    std::cout << "\nEnter Student ID: ";
    std::cin >> n;
    for (i = 0; i < size; i++)
        if (arr[i].StID == n)
            break;
    if (i < size)
    {
        std::cout << i + 1 << "\t";
        std::cout << arr[i].Name << "\t\t";
        std::cout << arr[i].StID << "\t\t";
        std::cout << arr[i].Avg << "\t\t";
    }
    else
        std::cout << "\nNNot found.";
}
void Findname(Student arr[], int size)
{
    int i;
    char name[20];
    std::cout << "\nFind Student by Name";
    std::cout << "\n--------------------";
    std::cout << "\nEnter Student Name: ";
    std::cin >> name;
    for (i = 0; i < size; i++)
        if (!cmpstr(arr[i].Name, name))
            break;
    if (i < size)
    {
        std::cout << i + 1 << "\t";
        std::cout << arr[i].Name << "\t\t";
        std::cout << arr[i].StID << "\t\t";
        std::cout << arr[i].Avg << "\n";
    }
    else
        std::cout << "Not found.";
}
int main()
{
    Student Data[100];
    int size = 0;
    char key;
    while ((key = Menu()) != '7')
    {
        switch (key)
        {
        case '1':
            size = stdinput(Data, size);
            break;
        case '2':
            AZid(Data, size);
            break;
        case '3':
            AZname(Data, size);
            break;
        case '4':
            AZavg(Data, size);
            break;
        case '5':
            Findid(Data, size);
            break;
        case '6':
            Findname(Data, size);
            break;
        }
    }
    return 0;
}