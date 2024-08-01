#include <vector>
#include <string>

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto detail : details){
            int age = stoi(detail.substr(11,2));
               if(age > 60){
                count++;
               }
            }
        return count;
    }
};