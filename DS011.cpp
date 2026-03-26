#include <iostream>
using namespace std;

int *maxNum(int input[], int size);

int main()
{
    int num, sum = 0;
    cout << "input num : ";
    cin >> num; // 3

    int *input = new int[num]; // 0 1 2

    for (int i = 0; i < num; i++)
    {
        cin >> input[i];
        sum += input[i];
    }
    cout << sum << endl;

    // int *max = maxNum(input, num);
    // cout << sum << " " << *max;

    int *max = maxNum(input, num);
    cout << sum << " // " << *max << " // " << max;
    return 0;
}

int *maxNum(int input[], int size)
{
    int *max;
    // if (size > 0)
    // {
    //     max = &input[0];
    // }
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            max = &input[0];
        }

        if (*max < input[i])
        {
            max = &input[i];
        }
    }
    return max;
}