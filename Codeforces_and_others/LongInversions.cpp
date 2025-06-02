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
    // solve starts
    cin >> n;
    string str;
    cin >> str;
    vector<ll> check(n);
    for (i = 0; i < n; i++)
    {
        if (str[i] == '1')
            check[i] = 0;
        else
            check[i] = 1;
    }
    ll ans = 1;
    for (i = 1; i <= n; i++)
    {
        ll add = 0;
        vector<ll> addv(n, 0), arr(n, 0);
        for (j = 0; j < n; j++)
        {
            add += addv[j];
            addv[j] = 0;
            arr[j] += add;
            if (j + i <= n)
            {
                if (arr[j] % 2 != check[j])
                {
                    addv[j] = 1;
                    arr[j]++;
                    if (i + j < n)
                    {
                        addv[i + j] = -1;
                    }
                }
            }
            add += addv[j];
            addv[j] = 0;
        }
        bool flag = true;
        for (j = 0; j < n; j++)
        {
            if (arr[j] % 2 != check[j])
                flag = false;
        }
        if (flag)
            ans = i;
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