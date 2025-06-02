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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<bool> done(n + 1, false);
    sort(v.begin(), v.end());
    vector<ll> elements;
    for (i = 0; i < n; i++)
    {
        if (v[i] <= n && !done[v[i]])
        {
            done[v[i]] = true;
        }
        else
        {
            elements.push_back(v[i]);
        }
    }
    k = 0;
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (!done[i])
        {
            if (i <= (elements[k] - 1) / 2)
            {
                done[i] = true;
                ans++;
                k++;
            }
            else
            {
                i--;
                k++;
            }
        }
        if (k == elements.size())
            break;
    }
    flag = true;
    for (i = 1; i <= n; i++)
        flag &= done[i];
    flag ? cout << ans << endl : cout << -1 << endl;
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