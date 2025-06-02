#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> a(n), b(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> dum;
    for (i = 0; i < n; i++)
        dum.push_back({a[i], b[i]});
    vector<pair<ll, ll>> ans;
    for (i = 0; i < n - 1; i++)
    {
        ll min = i;
        for (j = i; j < n; j++)
        {
            if (dum[min] > dum[j])
                min = j;
        }
        if (min != i)
        {
            ans.push_back({i, min});
            swap(dum[i], dum[min]);
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        if (dum[i].first > dum[i + 1].first || dum[i].second > dum[i + 1].second)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.first + 1 << gap << x.second + 1 << endl;
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