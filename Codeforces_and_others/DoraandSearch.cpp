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
    vector<ll> v(n);
    set<ll> s;
    for (auto &x : v)
    {
        cin >> x;
        s.insert(x);
    }
    a = n, b = -1;
    i = 0, j = n - 1;
    while (1)
    {
        if (i == j)
            break;
        ll maxele = *s.rbegin();
        ll minele = *s.begin();
        if (v[i] == maxele || v[i] == minele)
        {
            if (v[i] == maxele)
            {
                s.erase(maxele);
            }
            else if (v[i] == minele)
            {
                s.erase(minele);
            }
            i++;
        }
        else if (v[j] == maxele || v[j] == minele)
        {
            if (v[j] == maxele)
            {
                s.erase(maxele);
            }
            else if (v[j] == minele)
            {
                s.erase(minele);
            }
            j--;
        }
        else
        {
            a = i, b = j;
            break;
        }
    }
    if (a == n || b == -1)
        cout << -1 << endl;
    else
        cout << a + 1 << gap << b + 1 << endl;
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