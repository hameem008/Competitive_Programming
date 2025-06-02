#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), aind(n + 1), bind(n + 1);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        aind[a[i]] = i;
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
        bind[b[i]] = i;
    ll ans = 0;
    set<ll> sind;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            ll len = abs(aind[i] - bind[i]) - 1;
            if (aind[i] != bind[i])
                ans += len * (len - 1) / 2 + len;
            len = n - max(aind[i], bind[i]);
            ans += len * (len - 1) / 2 + len;
            len = min(aind[i], bind[i]) - 1;
            ans += len * (len - 1) / 2 + len;
            sind.insert(aind[i]);
            sind.insert(bind[i]);
        }
        else
        {
            ll len1, len2;
            ll start = *sind.begin();
            ll end = *sind.rbegin();
            ll high = max(aind[i], bind[i]);
            ll low = min(aind[i], bind[i]);
            if (low < start && end < high)
            {
                len1 = start - low;
                len2 = high - end;
                ans += len1 * len2;
            }
            else if (end < low)
            {
                len1 = start;
                len2 = low - end;
                ans += len1 * len2;
            }
            else if (start > high)
            {
                len1 = start - high;
                len2 = n - end + 1;
                ans += len1 * len2;
            }
            sind.insert(aind[i]);
            sind.insert(bind[i]);
        }
    }
    ans++;
    cout << ans << endl;
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