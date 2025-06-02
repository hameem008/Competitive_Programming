#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<pair<ll, ll>> odd, even;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            even.push_back({a, i});
        else
            odd.push_back({a, i});
    }
    vector<ll> ind;
    if (even.size() >= 2 && odd.size() >= 1)
    {
        cout << "YES" << endl;
        cout << even[0].second << gap << even[1].second << gap << odd[0].second << endl;
    }
    else if (odd.size() >= 3)
    {
        cout << "YES" << endl;
        cout << odd[0].second << gap << odd[1].second << gap << odd[2].second << endl;
    }
    else
        cout << "NO" << endl;
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