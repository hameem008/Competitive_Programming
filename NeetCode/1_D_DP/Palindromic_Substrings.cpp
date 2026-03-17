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
    // mancher's algorithm
    int countSubstrings(string s)
    {
        int ret = 0;
        string str;
        char percentage = '%', hash_ = '#', star = '*';
        str.push_back(percentage);
        str.push_back(hash_);
        for (auto x : s)
        {
            str.push_back(x);
            str.push_back(hash_);
        }
        str.push_back(star);
        int l = 0, r = 1, n = str.size() - 2;
        vector<int> p(str.size(), 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = min(r - i, p[l + r - i]);
            while (str[i - p[i]] == str[i + p[i]])
                p[i]++;
            if (i + p[i] > r)
                l = i - p[i], r = i + p[i];
            int len = p[i] - 1;
            if (len == 0)
                continue;
            if (str[i] == '#')
                ret += len / 2;
            else
                ret += (len - 1) / 2 + 1;
        }
        return ret;
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