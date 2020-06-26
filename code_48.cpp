#include <iostream>
#include <stack>
using namespace std;

bool isParenthesis(char c)
{
    return c == '(' || c == ')';
}

int precendence(char c)
{
    if (c == '^')
    {
        return 5;
    }
    else if (c == '/')
    {
        return 4;
    }
    else if (c == '*')
    {
        return 3;
    }
    else if (c == '+')
    {
        return 2;
    }
    else if (c == '-')
    {
        return 1;
    }
    return -1;
}

int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    stack<char> s;
    int n = str.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            ans+=str[i];
        }
        else if (isParenthesis(str[i]))
        {
            if (str[i] == '(')
            {
                cout << "PUSH " << str[i] << "\n";
                s.push('(');
            }
            else
            {
                while (!s.empty() && s.top() != '(')
                {
                    ans += s.top();
                    cout << "POP " << s.top() << "\n";
                    s.pop();
                }
                if (!s.empty() && s.top() == '(')
                {
                    cout << "POP " << s.top() << "\n";
                    s.pop();
                }
            }
        }
        else
        {
            while (!s.empty() && precendence(str[i]) <= precendence(s.top()))
            {
                ans += s.top();
                cout << "POP " << s.top() << "\n";
                s.pop();
            }
            cout << "PUSH " << str[i] << "\n";
            s.push(str[i]);
        }
    }
    while (!s.empty())
    {
        cout << "POP " << s.top() << "\n";
        ans += s.top();
        s.pop();
    }
    cout << ans << "\n";
}