/*Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().*/

class Solution {
public:
  string solve(vector<string>v){
    stack<string>st;
    for(int i=0;i<v.size();i++){
      if(v[i] == "-"){
        int x = 0;
        if(st.empty() == false){
          x = stoi(st.top());
          st.pop();
        }
        int y = stoi(v[i+1]);
        st.push(to_string(x-y));
        i++;
      }else if(v[i] =="+"){
        int x = 0;
        if(st.empty() == false){
          x = stoi(st.top());
          st.pop();
        }
        int y = stoi(v[i+1]);
        st.push(to_string(x+y));
        i++;
      }else{
        st.push(v[i]);
      }
    }
    return st.top();
  }
  int calculate(string s) {
    vector<string>nums;
    string temp;
//--------------------------------------------------//
/*
  removed unnecessary spaces and converted each element to 
  string and stored in a vector.
*/
    for(int i=0;i<s.size();i++){
      if(s[i] == ' '){
        continue;
      }
      if(isdigit(s[i])){
        temp += s[i];
      }else{
        if(temp.empty() == false){
          nums.push_back(temp);
        }
        string t;
        t += s[i];
        nums.push_back(t);
        temp.clear();
      }
    }
    if(temp.empty() == false){
      nums.push_back(temp);
    }
//--------------------------------------------------//
    stack<string>st;
    for(int i=0;i<nums.size();i++){
      vector<string>t;
      if(nums[i] == ")"){
        while(st.empty() == false && st.top() != "("){
          t.push_back(st.top());
          st.pop();
        }
        st.pop();
        reverse(t.begin(),t.end());
        string ans = solve(t);
        st.push(ans);
      }else{
        st.push(nums[i]);
      }
    }
    vector<string>v1;
    while(st.empty() == false){
      v1.push_back(st.top());
      st.pop();
    }
    reverse(v1.begin(),v1.end());
    return stoi(solve(v1));
  }
};