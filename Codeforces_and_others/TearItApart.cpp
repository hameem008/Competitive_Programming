#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    vector<ll> v(26, 0);
    set<ll> ans;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        ll max_len = 0;
        ll cur_len = 0;
        for (auto x : str)
        {
            if (x != ch)
                cur_len++;
            else
            {
                max_len = max(cur_len, max_len);
                cur_len = 0;
            }
        }
        max_len = max(max_len, cur_len);
        if (max_len == 0 || max_len == 1)
            ans.insert(max_len);
        else
            ans.insert(floor(log2(max_len)) + 1);
    }
    cout << *ans.begin() << endl;
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