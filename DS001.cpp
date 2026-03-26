#include <iostream>
using namespace std;
// g++ DS001.cpp -o main
int main()
{
    int height, weight;
    double bmi;

    cin >> height >> weight;
    bmi = weight / height * 0.01 * height * 0.01;
    if (bmi >= 25)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}