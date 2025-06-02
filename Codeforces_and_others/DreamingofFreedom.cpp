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
    cin >> n >> m;
    if (m == 1 || n == 1)
        cout << "YES" << endl;
    else if (n <= m)
        cout << "NO" << endl;
    else
    {
        vector<ll> div;
        ll lim = sqrt(n) + 1;
        for (i = 2; i <= lim; i++)
        {
            if (n % i == 0)
                div.push_back(i);
        }
        sort(div.begin(), div.end());
        if (div.size() == 0)
            cout << "YES" << endl;
        else if (div.front() <= m)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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