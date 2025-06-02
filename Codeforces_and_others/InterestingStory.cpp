#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> v(5);
    for (i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        vector<ll> cnt(5, 0);
        for (auto x : str)
        {
            cnt[x - 'a']++;
        }
        for (j = 0; j < 5; j++)
        {
            v[j].push_back(2 * cnt[j] - str.length());
        }
    }
    for (auto &x : v)
    {
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
    }
    ll ans = 0;
    for (i = 0; i < 5; i++)
    {
        ll curr_ans = 0, score = 0;
        for (auto x : v[i])
        {
            if (curr_ans + x > 0)
            {
                curr_ans += x;
                score++;
            }
            else
                break;
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
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