#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p, q;
    // solve stars
    cin >> n >> q;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll sum = 0, odd_cnt = 0, even_cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            even_cnt++;
        }
        else
        {
            odd_cnt++;
        }
        sum += v[i];
    }
    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (a == 0)
        {
            sum += b * even_cnt;
            if (b % 2 != 0)
            {
                odd_cnt = odd_cnt + even_cnt;
                even_cnt = 0;
            }
        }
        else
        {
            sum += b * odd_cnt;
            if (b % 2 != 0)
            {
                even_cnt = even_cnt + odd_cnt;
                odd_cnt = 0;
            }
        }
        cout << sum << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}