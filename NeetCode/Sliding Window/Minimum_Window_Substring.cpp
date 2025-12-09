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
    int start, end;
    bool pf(int mid, string &s, string &t)
    {
        map<char, int> mapt, maps;
        for (auto x : t)
            mapt[x]++;
        int alfange = 0, enden = mid - 1;
        for (int i = alfange; i <= enden; i++)
            maps[s[i]]++;
        while (1)
        {
            bool flag = true;
            for (auto x : mapt)
            {
                if (maps[x.first] < x.second)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                start = alfange, end = enden;
                return true;
            }
            maps[s[alfange]]--;
            alfange++, enden++;
            if (enden == s.size())
                break;
            maps[s[enden]]++;
        }
        return false;
    }
    string minWindow(string s, string t)
    {
        string str = "";
        int hi = s.size(), lo = 1, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pf(mid, s, t))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(lo, s, t))
        {
            str.clear();
            for (int i = start; i <= end; i++)
                str.push_back(s[i]);
        }
        else if (pf(hi, s, t))
        {
            str.clear();
            for (int i = start; i <= end; i++)
                str.push_back(s[i]);
        }
        return str;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string s, t;
    cin >> s >> t;
    Solution sl;
    cout << sl.minWindow(s, t);
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