#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    set<ll> s(v.begin(), v.end());
    i = 1;
    ll cnt = 0;
    for (auto x : s)
    {
        if (x == i)
        {
            cnt++;
            i++;
        }
        else
            break;
    }

    if (cnt == 0)
    {
        cout << "Alice" << endl;
        return;
    }

    if (cnt == s.size())
    {
        if (cnt % 2 == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    else
    {
        if (cnt % 2 == 0)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
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