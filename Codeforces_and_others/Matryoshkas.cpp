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
    set<ll> s;
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    ll ans = 1;
    ll curr_num = *ms.begin();
    ms.erase(ms.begin());
    while (ms.size() != 0)
    {
        auto it = ms.find(curr_num + 1);
        if (it != ms.end())
        {
            curr_num++;
            ms.erase(it);
        }
        else
        {
            curr_num = *ms.begin();
            ms.erase(ms.begin());
            ans++;
        }
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