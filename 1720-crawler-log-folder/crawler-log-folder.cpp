class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                level-=(level>0);
            }
            if(logs[i]!="./"&&logs[i]!="../"){
                level+=1;
            }

        }
        return level;
    }
};