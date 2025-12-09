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
    string encode(vector<string> &strs)
    {
        string ans;
        for (int i = 0; i < strs.size(); i++)
        {
            for (auto x : strs[i])
                ans.push_back(x);
            if (i == strs.size() - 1)
            {
                ans.push_back('.');
                break;
            }
            ans.push_back('|');
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')
            {
                ans.push_back(str);
                str.clear();
            }
            else if (s[i] == '.')
                ans.push_back(str);
            else
                str.push_back(s[i]);
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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