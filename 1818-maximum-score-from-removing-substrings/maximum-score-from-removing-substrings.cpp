class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ab=0,ba=0,aba=0,o=0,t=0;
        stack<char>st,st1,st2;
        if(x>y){
            for(auto &i:s){
                
                if(!st.empty() &&st.top()=='a' && i=='b'){
                    st.pop();
                    ab++;
                }else{
                st.push(i);
                }
            }
            o=1;
        }else{
            for(auto &i:s){
                
                if(!st.empty() && st.top()=='b' && i=='a'){
                    st.pop();
                    ba++;
                }else{
                st.push(i);
                }
            }
            o=0;
        }
        if(o==1){
            while(!st.empty()){
                if( !st1.empty() && st1.top()=='a' && st.top()=='b'){
                    st1.pop();
                    ba++;

                }
                else{
                    st1.push(st.top());
                }
                st.pop();
            }
        }else{
            while(!st.empty()){
                if(!st1.empty() && st1.top()=='b' && st.top()=='a'){
                    st1.pop();
                    ab++;

                }
                else{
                    st1.push(st.top());
                }
                st.pop();
            }
        }
        cout<<ab<<"\t"<<ba;
        return ab*x+ba*y;
    }
};