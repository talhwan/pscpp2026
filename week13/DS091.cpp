#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> stackL;
    stack<int> stackR;

    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "q")
        {
            break;
        }
        else
        {
            for (char c : input)
            {
                if (c == '<')
                {
                    if (!stackL.empty())
                    {
                        stackR.push(stackL.top());
                        stackL.pop();
                    }
                }
                else if (c == '>')
                {
                    if (!stackR.empty())
                    {
                        stackL.push(stackR.top());
                        stackR.pop();
                    }
                }
                else
                {
                    stackL.push(c);
                }
            }

            while (!stackL.empty())
            {
                stackR.push(stackL.top());
                stackL.pop();
            }

            cout << "=> ";
            while (!stackR.empty())
            {
                cout << (char)stackR.top();
                stackR.pop();
            }
            cout << endl;
        }
    }

    return 0;
}