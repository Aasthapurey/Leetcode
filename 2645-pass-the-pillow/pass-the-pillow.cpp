class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        bool front = true;
        while (time--) {
            if (front) {
                i++;
            } else {
                i--;
            }
            if (i == n) {
                front = false;
            }
            if (i == 1) {
                front = true;
            }
        }
        return i;
    }
};

/*
class Solution {
public:
    int passThePillow(int n, int time) {
        n--; 
        int rounds = time / n; 
        int rem = time % n;

        if (rounds % 2 == 0) {
            return rem + 1;
        } else {
            return (n - rem + 1); 
        }
    }
};
*/
