#include <iostream>
#include <cstring>

int main()
{
    char s1[] = "ABCDEFG";
    char s2[] = "XYZ";
    std::cout << "Before strcpy(s1,s2):\n";
    std::cout << "\ts1= [" << s1 << "], length = " << strlen(s1) << '\n';
    std::cout << "\ts1= [" << s2 << "], length = " << strlen(s2) << '\n';
    strcpy(s1, s2);
    std::cout << "After strcpy(s1,s2):\n";
    std::cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << '\n';
    std::cout << "\ts1 = [" << s2 << "], length = " << strlen(s2) << '\n';
    return 0;
}