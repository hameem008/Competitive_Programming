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
    bool pf(int mid, string &str, int k)
    {
        if (mid > str.size())
            return false;
        bool ret = false;
        int alfange = 0, enden = mid - 1;
        vector<int> freq(26, 0);
        multiset<int> ms;
        for (int i = 0; i <= enden; i++)
            freq[str[i] - 'A']++;
        for (auto x : freq)
            ms.insert(x);
        while (1)
        {
            auto it = ms.end();
            it--;
            if (mid - *it <= k)
            {
                ret = true;
                break;
            }
            if (enden + 1 == str.size())
                break;
            ms.erase(ms.find(freq[str[alfange] - 'A']));
            freq[str[alfange] - 'A']--;
            ms.insert(freq[str[alfange] - 'A']);
            alfange++, enden++;
            ms.erase(ms.find(freq[str[enden] - 'A']));
            freq[str[enden] - 'A']++;
            ms.insert(freq[str[enden] - 'A']);
        }
        return ret;
    }
    int characterReplacement(string s, int k)
    {
        int ans = 1;
        int hi = s.size(), lo = 1, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(mid, s, k))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (pf(hi, s, k))
            ans = hi;
        else
            ans = lo;
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