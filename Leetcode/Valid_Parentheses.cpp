#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    bool isValid(string s)
    {
        bool ret;
        map<char, int> mp;
        mp['('] = mp[')'] = mp['{'] = mp['}'] = mp['['] = mp[']'] = 0;
        for (auto x : s)
            mp[x]++;
        if (true && mp['('] == mp[')'] && mp['{'] == mp['}'] && mp['['] == mp[']'])
            ret = true;
        else
            ret = false;
        vector<char> v;
        for (auto x : s)
        {
            if (x == '(' || x == '{' || x == '[')
                v.push_back(x);
            else if (x == ')')
            {
                if (v.empty() || v.back() != '(')
                {
                    ret = false;
                    break;
                }
                else
                    v.pop_back();
            }
            else if (x == '}')
            {
                if (v.empty() || v.back() != '{')
                {
                    ret = false;
                    break;
                }
                else
                    v.pop_back();
            }
            else if (x == ']')
            {
                if (v.empty() || v.back() != '[')
                {
                    ret = false;
                    break;
                }
                else
                    v.pop_back();
            }
        }
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    Solution sl;
    cout << sl.isValid(str) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}