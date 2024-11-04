class Solution {
public:
    bool rotateString(string s, string goal) {
  
       int idx=goal.find(s[0]);
 

    string temp=goal+goal;
      if(temp.find(s)==string::npos) // not exits in concat. string
      return false;
  return true &&s.size()==goal.size(); // check size also
    }
};