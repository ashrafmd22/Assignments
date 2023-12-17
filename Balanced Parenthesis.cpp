#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{')
            s.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string expression = "{[()]}";
    if (isBalanced(expression))
        cout << "Balanced parentheses." << endl;
    else
        cout << "Unbalanced parentheses." << endl;

    return 0;
}
