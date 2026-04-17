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
    bool check(vector<int> &v1, vector<int> v2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;
        vector<int> v1(26, 0), v2(26, 0);
        for (auto x : s1)
            v1[x - 'a']++;
        int len = s1.size();
        for (int i = 0; i < len; i++)
            v2[s2[i] - 'a']++;
        int alfange = 0, enden = len - 1;
        while (1)
        {
            if (check(v1, v2))
                return true;
            if (enden + 1 == s2.size())
                break;
            v2[s2[alfange] - 'a']--;
            alfange++, enden++;
            v2[s2[enden] - 'a']++;
        }
        return false;
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