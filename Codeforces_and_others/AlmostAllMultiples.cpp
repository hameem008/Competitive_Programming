#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        v[i] = i;
    }
    vector<ll> divisor;
    for (i = 1; i < sqrt(n + 1); i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
            divisor.push_back(n / i);
        }
    }
    sort(divisor.begin(), divisor.end());
    for (i = 0; i < divisor.size(); i++)
    {
        if (divisor[i] == k)
            break;
    }
    i++;
    swap(v[1], v[k]);
    swap(v[k], v[n]);
    for (; i < divisor.size() - 1; i++)
    {
        if (divisor[i] % k == 0)
        {
            swap(v[divisor[i]], v[k]);
            k = divisor[i];
        }
    }
    if (n % k == 0)
    {
        for (i = 1; i <= n; i++)
        {
            cout << v[i] << gap;
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
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