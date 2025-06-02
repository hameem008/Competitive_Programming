#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m >> d;
    vector<ll> v(m + 2);
    v[0] = 1;
    v[m + 1] = n + 1;
    for (i = 1; i <= m; i++)
    {
        cin >> v[i];
    }
    ll total = m;
    for (i = 0; i <= m; i++)
    {
        total += (v[i + 1] - v[i] - 1) / d;
    }
    if (v[1] != 1)
        total++;
    map<ll, ll> freq;
    for (i = 1; i <= m; i++)
    {
        if (v[i] == 1)
        {
            freq[total]++;
            continue;
        }
        a = (v[i] - v[i - 1] - 1) / d + (v[i + 1] - v[i] - 1) / d + 1;
        b = (v[i + 1] - v[i - 1] - 1) / d;
        if (b <= a)
        {
            freq[total - (a - b)]++;
        }
    }
    cout << freq.begin()->first << gap << freq.begin()->second << endl;
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