#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <iterator>

int main()
{
    std::cout << "------------array------------" << '\n';
    std::array<int, 3> arr;

    arr = {10, 6, 12};
    std::cout << arr.front() << '\n';
    std::cout << arr.back() << '\n';
    std::cout << arr.at(1) << '\n';

    std::array<int, 3>::iterator i;
    for (i = arr.begin(); i != arr.end(); ++i)
        std::cout << *i << '\t';

    std::cout << '\n'
              << "-------------vector------------" << '\n';
    std::vector<int> v;

    v.push_back(10);
    v.push_back(6);
    v.push_back(12);

    std::cout << v.size() << '\n';
    std::cout << v.capacity() << '\n';
    std::cout << v.front() << '\n';
    std::cout << v.back() << '\n';
    std::cout << v.at(1) << '\n';

    std::vector<int>::iterator iv;
    for (iv = v.begin(); iv != v.end(); ++iv)
        std::cout << *iv << '\t';

    std::cout << '\n'
              << "------------stack------------" << '\n';
    std::stack<int> s;

    s.push(10);
    s.push(6);
    s.push(12);

    std::cout << s.size() << '\n';
    std::cout << s.top() << '\n';

    while (!s.empty())
    {
        std::cout << s.top() << '\t';
        s.pop();
    }

    std::cout << '\n'
              << "------------List------------" << '\n';
    std::list<int> l;

    l.push_back(10);
    l.push_back(6);
    l.push_back(12);

    std::cout << l.front() << '\n';
    std::cout << l.back() << '\n';

    l.sort();

    std::list<int>::iterator il;

    for (il = l.begin(); il != l.end(); ++il)
        std::cout << *il << '\t';

    std::cout << '\n'
              << "------------forward-list------------" << '\n';

    std::forward_list<int> fl;

    fl.assign({10, 6, 12});

    fl.push_front(1);

    for (int &a : fl)
        std::cout << a << "    ";
    std::cout << '\n';

    std::cout;
    std::forward_list<int>::iterator p;
    p = fl.insert_after(fl.begin(), {2, 3});

    for (int &t : fl)
        std::cout << t << "    ";
}