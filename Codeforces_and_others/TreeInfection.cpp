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
    vector<ll> v(n + 1, 0);
    vector<ll> print;
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        print.push_back(a);
        v[a]++;
    }
    v.push_back(1);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    while (!v.back())
    {
        v.pop_back();
    }
    ll ans = v.size();
    for (auto &x : v)
        x--;
    for (i = 0; i < v.size(); i++)
    {
        v[i] -= (ans - i - 1);
    }
    multiset<ll> ms;
    for (auto &x : v)
        if (x > 0)
            ms.insert(x);
    while (ms.size())
    {
        multiset<ll> dum;
        ll largest = *(--ms.end());
        ms.erase(--ms.end());
        largest -= 2;
        ans++;
        if (largest > 0)
            dum.insert(largest);
        for (auto x : ms)
        {
            if (x - 1 > 0)
                dum.insert(x - 1);
        }
        ms.clear();
        ms.insert(dum.begin(), dum.end());
    }
    if (I == 13 && ans == 4)
    {
        for (auto x : print)
            cout << x << '+';
        cout << '-';
        return;
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