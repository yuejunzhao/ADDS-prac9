#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char oper)
{
    switch (oper)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}
string prefix(string prefixString)
{
    std::stack<int> operandStack;
    std::stack<string> sts;

    int size = prefixString.size();
    int digitIndex = 0;
    int operIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (isOperator(prefixString[i]))
        {
            // cout << prefixString[i] << "operIndex++" << endl;
            operIndex++;
        }
        else if (prefixString[i] == ' ')
        {
            continue;
        }
        else
        {
            // cout << prefixString[i] << "digitIndex++" << endl;
            digitIndex++;
        }
    }
    operIndex++;
    if (digitIndex != operIndex)
    {
        // cout << endl;
        // cout << digitIndex << endl;
        // cout << operIndex << endl;
        cout << "Error" << endl;
        exit(1);
    }

    // cout << "exit" << endl;
    // exit(1);
    for (int i = size - 1; i >= 0; i--)
    {
        if (isdigit(prefixString[i]))
        {
            operandStack.push(prefixString[i] - '0');
            sts.push(string(1, prefixString[i]));
        }
        else if (prefixString[i] == ' ')
        {
            continue;
        }
        else
        {
            // cout << "Here1" << endl;
            int o1 = operandStack.top();
            operandStack.pop();
            string s1 = sts.top();
            sts.pop();
            int o2 = operandStack.top();
            operandStack.pop();
            string s2 = sts.top();
            sts.pop();
            if (prefixString[i] == '+' || prefixString[i] == '-')
            {
                string s3 = "( " + s1 + " " + prefixString[i] + " " + s2 + " )";
                sts.push(s3);
            }
            else
            {
                string s3 = s1 + " " + prefixString[i] + " " + s2;
                sts.push(s3);
            }
            // cout << "Here2" << endl;
            if (prefixString[i] == '+')
            {
                operandStack.push(o1 + o2);
            }
            else if (prefixString[i] == '-')
            {
                operandStack.push(o1 - o2);
            }
            else if (prefixString[i] == '*')
            {
                operandStack.push(o1 * o2);
            }
            else if (prefixString[i] == '/')
            {
                operandStack.push(o1 / o2);
            }
            else
            {
                cout << "Error";
                exit(1);
            }
        }
    }
    string res = sts.top() + " = " + to_string(operandStack.top());
    return res;
}

int main()
{
    // string prefixExp = "* - 5 6 7";
    // cout << "The result of evaluation of expression " << prefixExp << " is " << prefix(prefixExp) << endl;
    // cout << prefix(prefixExp) << endl;
    string pf;
    getline(cin, pf);
    string result = prefix(pf);
    cout << result << endl;
    return 0;
}