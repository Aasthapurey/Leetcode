class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push(make_pair(a,'a'));
        if(b>0) pq.push(make_pair(b,'b'));
        if(c>0) pq.push(make_pair(c,'c'));
        // return "hello";
        string result = "";
        while(!pq.empty()){
            auto [char1,count1] = pq.top();
            pq.pop();
            if(result.size()>=2 && result.back() == count1 && result[result.size()-2] == count1){
                if(pq.empty()) break;
                auto [char2,count2] = pq.top();
                pq.pop();
                result += count2;
                char2--;
                if(char2>0) pq.push(make_pair(char2,count2));
                pq.push(make_pair(char1,count1));
            }
            else{
                result += count1;
                char1--;
                if(char1>0) pq.push(make_pair(char1,count1));
            }
        }
        return result;
    }
};