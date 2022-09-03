#include <iostream>

using namespace std;
double calculatePull(int t)
{
    const double g = 9.80665;
    return (0.5 * g * t * t);
}
int main()
{
    int t;
    cout << "Enter time: ";
    cin >> t;
    cout << "Hight is: " << calculatePull(t);
    return 0;
}