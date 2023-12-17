/* Basic Calculator II

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 */

 class Solution {
public:
    string toPostfix(string& s) {
        auto precedence = [](char c){return c == '*' || c == '/';};
        stack<char> op;
        string post = "";
        for(auto c : s) 
            if(c == ' ') continue;
            else if(isdigit(c)) post += c;
            else {
                post += '|';                              // markers to separate numbers
                while(size(op) && precedence(c) <= precedence(op.top())) 
                    post += op.top(), op.pop();
                op.push(c);
            }
        
        post += '|';
        while(size(op)) 
            post += op.top(), op.pop();        
        return post;
    }
    int calculate(string& s) {
        s = toPostfix(s);
        stack<int> num;
        for(int i = 0; i < size(s); i++) 
            if(isdigit(s[i])) {
                int cur = 0;
                while(i < size(s) && isdigit(s[i]))
                    cur = cur * 10 + (s[i++] - '0');
                num.push(cur);
            }
            else {
                int num1 = num.top(); num.pop();
                int num2 = num.top(); num.pop();
                if(s[i] == '*')      num.push(num2 * num1);
                else if(s[i] == '/') num.push(num2 / num1);
                else if(s[i] == '+') num.push(num2 + num1);
                else if(s[i] == '-') num.push(num2 - num1);
            }
        
        return num.top();
    }
};