#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll num_length(ll n)
{
    ll len = 0;
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> a >> b >> c;
    c = powl(10, c - 1);
    i = 0;
    while (1)
    {
        if (num_length(c * powl(2, i)) == a)
        {
            a = c * powl(2, i);
            break;
        }
        i++;
    }
    i = 0;
    while (1)
    {
        if (num_length(c * powl(3, i)) == b)
        {
            b = c * powl(3, i);
            break;
        }
        i++;
    }
    cout << a << gap << b << endl;
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