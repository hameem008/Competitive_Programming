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
    cin >> k;
    ll ans = 1;
    vector<ll> v(10, 1);
    i = 0;
    while (ans < k)
    {
        ans /= v[i];
        v[i]++;
        ans *= v[i];
        i++;
        if (i == 10)
            i = 0;
    }
    string str = "codeforces";
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < v[i]; j++)
        {
            cout << str[i];
        }
    }
    cout << endl;
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