#include <iostream>
#include <vector>
#include <algorithm> // find 함수를 쓸려면 포함 해야 함!!
using namespace std;

int main()
{
    vector<int> array_num = {10, 20, 30, 40, 50};

    auto it = find(array_num.begin(), array_num.end(), 100); // 30이라는 값 있는지??

    if (it != array_num.end())
    {
        cout << "found! : " << *it << endl;
    }
    else
    {
        cout << "no.." << endl;
    }

    return 0;
}