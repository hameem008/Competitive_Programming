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
    if (n % 4 == 0)
    {
        cout << "YES" << endl;
        vector<ll> v1, v2;
        for (i = 1; i <= n; i += 4)
        {
            v1.push_back(i);
            v1.push_back(i + 3);

            v2.push_back(i + 1);
            v2.push_back(i + 2);
        }
        cout << v1.size() << endl;
        for (auto x : v1)
            cout << x << gap;
        cout << endl;
        cout << v2.size() << endl;
        for (auto x : v2)
            cout << x << gap;
        cout << endl;
    }
    else if ((n - 3) % 4 == 0)
    {
        cout << "YES" << endl;
        vector<ll> v1, v2;
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
        for (i = 4; i <= n; i += 4)
        {
            v1.push_back(i);
            v1.push_back(i + 3);

            v2.push_back(i + 1);
            v2.push_back(i + 2);
        }
        cout << v1.size() << endl;
        for (auto x : v1)
            cout << x << gap;
        cout << endl;
        cout << v2.size() << endl;
        for (auto x : v2)
            cout << x << gap;
        cout << endl;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}