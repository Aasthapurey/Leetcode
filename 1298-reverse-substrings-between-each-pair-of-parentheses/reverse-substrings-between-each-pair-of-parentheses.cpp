class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                reverse(s.begin()+st.top(),s.begin()+i);
                st.pop();
            }
        }
        string t="";
        for(auto &i:s){
            if(i!='(' && i!=')')t+=i;
        }
        return t;
    }
};