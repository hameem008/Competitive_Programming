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
    bool isAnagram(string s, string t)
    {
        map<char, int> mp;
        for (auto x : s)
        {
            mp[x]++;
        }
        for (auto x : t)
        {
            mp[x]--;
        }
        for (auto x : mp)
        {
            if (x.second != 0)
                return false;
        }
        return true;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string s, t;
    cin >> s;
    cin >> t;
    Solution sl;
    cout << sl.isAnagram(s, t);
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