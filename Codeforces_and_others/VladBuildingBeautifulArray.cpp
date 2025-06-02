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
    bool flag1 = true, flag2 = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> odd, even;
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
            even.push_back(v[i]);
        else
            odd.push_back(v[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
odd_parity:
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            if (odd.size() == 0 || v[i] < odd.front())
                flag1 = false;
        }
    }
even_parity:
    if (odd.size() != 0)
        flag2 = false;
    flag1 | flag2 ? cout << "YES" << endl : cout << "NO" << endl;
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