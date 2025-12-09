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
    vector<int> cnt(string &str)
    {
        vector<int> ret(26, 0);
        for (int i = 0; i < str.size(); i++)
        {
            ret[str[i] - 'a']++;
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            mp[cnt(strs[i])].push_back(strs[i]);
        }
        for (auto x : mp)
        {
            ans.push_back(x.second);
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}