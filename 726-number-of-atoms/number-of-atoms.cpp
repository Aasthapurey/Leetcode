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

class Solution
{
public:
    string countOfAtoms(string s)
    {
        int n = s.length();
        string temp = "";
        temp += s[0];
        vector<string> container;
        for (int i = 1; i < n; i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                temp += s[i];
            }
            else
            {
                container.push_back(temp);
                temp.clear();
                temp += s[i];
            }
        }
        container.push_back(temp);
        for (int i = 0; i < container.size(); i++)
        {
            if (container[i][0] == '(' || container[i][0] == ')')
            {
                container.erase(container.begin() + i);
                i--;
            }
        }
        vector<pair<string, int>> elementswithfreq;
        for (string &cont : container)
        {
            string freq = "";
            while (!cont.empty() && cont.back() >= '0' && cont.back() <= '9')
            {
                freq += cont.back();
                cont.pop_back();
            }
            reverse(all(freq));
            int f = freq.empty() ? 1 : stoi(freq);
            elementswithfreq.push_back({cont, f});
        }

        stack<pair<string, int>> stk1;
        stack<pair<string, int>> stk2;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                stk1.push({elementswithfreq[ind].first, elementswithfreq[ind].second});
                ind++;
            }
            else if (s[i] == '(')
            {
                stk1.push({"(", -1});
            }
            else if (s[i] == ')')
            {
                string number = "";
                int x = i + 1;
                while (x < n && s[x] >= '0' && s[x] <= '9')
                {
                    number += s[x];
                    x++;
                }
                int multiply = number.empty() ? 1 : stoi(number);
                while (stk1.top().first != "(")
                {
                    int newfreq = stk1.top().second * multiply;
                    stk2.push({stk1.top().first, newfreq});
                    stk1.pop();
                }
                if (stk1.top().first == "(")
                {
                    stk1.pop();
                    while (!stk2.empty())
                    {
                        stk1.push(stk2.top());
                        stk2.pop();
                    }
                }
                i = x - 1;
            }
        }

        vector<pair<string, int>> finalcontainer;
        unordered_map<string, int> freqMap;
        while (!stk1.empty())
        {
            freqMap[stk1.top().first] += stk1.top().second;
            stk1.pop();
        }
        for (const auto &entry : freqMap)
        {
            finalcontainer.push_back(entry);
        }
        sort(all(finalcontainer));

        string Res = "";
        for (const auto &p : finalcontainer)
        {
            Res += p.first;
            if (p.second != 1)
            {
                Res += to_string(p.second);
            }
        }
        return Res;
    }
};