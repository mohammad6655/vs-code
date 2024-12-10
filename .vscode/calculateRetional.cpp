#include <iostream>

struct rational
{
    int a, b;
};

struct rational add(struct rational p1, struct rational p2)
{
    struct rational p3;
    p3.a = p1.a * p2.b + p2.a * p1.b;
    p3.b = p2.b * p1.b;
    return p3;
}
struct rational sub(struct rational p1, struct rational p2)
{
    struct rational p3;
    p3.a = p1.a * p2.b - p2.a * p1.b;
    p3.b = p2.b * p1.b;
    return p3;
}
struct rational mul(struct rational p1, struct rational p2)
{
    struct rational p3;
    p3.a = p1.a * p2.a;
    p3.b = p1.b * p1.b;
    return p3;
}
struct rational div(struct rational p1, struct rational p2)
{
    struct rational p3;
    p3.a = p1.a * p2.b;
    p3.b = p1.b * p2.a;
    return p3;
}
int main()
{
    struct rational a = {0}, b = {0}, c = {0};
    std::cout << "Enter a/b for Fraction a:";
    std::cin >> a.a >> a.b;
    std::cout << "Enter a/b for Fraction b:";
    std::cin >> b.a >> b.b;
    c = add(a, b);
    std::cout << "\n"
              << a.a << "/" << a.b << "+" << b.a << "/" << b.b << " = " << c.a << "/" << c.b;
    c = sub(a, b);
    std::cout << "\n"
              << a.a << "/" << a.b << " - " << b.a << "/" << b.b << " = " << c.a << "/" << c.b;
    c = mul(a, b);
    std::cout << "\n"
              << a.a << "/" << a.b << " * " << b.a << "/" << b.b << " = " << c.a << "/" << c.b;
    c = div(a, b);
    std::cout << "\n"
              << a.a << "/" << a.b << " / " << b.a << "/" << b.b << " = " << c.a << "/" << c.b;
    return 0;
}