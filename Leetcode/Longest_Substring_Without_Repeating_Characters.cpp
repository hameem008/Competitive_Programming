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
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> ch_ind;
        for (auto x : s)
            ch_ind[x] = -1;
        int alfange = 0, enden = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (ch_ind[s[i]] != -1)
            {
                ans = max(ans, enden - alfange);
                alfange = ch_ind[s[i]] + 1;
                for (auto &x : ch_ind)
                    if (x.second < alfange)
                        x.second = -1;
                i--;
            }
            else
            {
                ch_ind[s[i]] = i;
                enden++;
                if (i == s.size() - 1)
                    ans = max(ans, enden - alfange);
            }
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    // cin >> str;
    str = " ";
    Solution sl;
    cout << sl.lengthOfLongestSubstring(str) << endl;
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