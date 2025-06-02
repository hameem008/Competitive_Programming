#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    if (n % 2 == 0)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        a = n / 2;
        set<ll> s;
        for (i = 1; i <= 2 * n; i++)
        {
            s.insert(i);
        }
        vector<pair<ll, ll>> ans;
        m = 2 * n + 1;
        s.erase(n);
        s.erase(n + 1);
        ans.push_back({n, n + 1});
        i = 2 * n;
        while (a)
        {
            ans.push_back({i, m + a - i});
            s.erase(i);
            s.erase(m + a - i);
            a--;
            i -= 2;
        }
        a = n / 2;
        vector<ll> av(s.begin(), s.end());
        for (i = 0, j = av.size() - 1; a--; i++, j--)
        {
            ans.push_back({av[i], av[j]});
        }
        for (auto x : ans)
            cout << x.first << gap << x.second << endl;
    }
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