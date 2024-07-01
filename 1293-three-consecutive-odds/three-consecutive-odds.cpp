#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
static int fastIO = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
// Paste the Class here-
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2)
            {
                return true;
            }
        }
        return false;
    }
};