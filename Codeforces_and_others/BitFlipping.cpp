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
    cin >> n >> k;
    ll inik = k;
    string str;
    cin >> str;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        if (str[i] == '1')
            v[i] = 1;
        else
            v[i] = 0;
    }
    vector<ll> hash(n, 0);
    ll used = 0;
    i = 0;
    while (k)
    {
        ll current = v[i];
        if (used % 2 != 0)
        {
            current ^= 1;
        }

        if (i == n - 1)
        {
            hash[i] = k;
            k = 0;
            break;
        }

        if (current == 1 && k % 2 == 0)
        {
            i++;
        }
        else if (current == 1 && k % 2 != 0)
        {
            hash[i]++;
            k--;
            i++;
            used++;
        }
        else if (current == 0 && k % 2 == 0)
        {
            hash[i]++;
            k--;
            i++;
            used++;
        }
        else if (current == 0 && k % 2 != 0)
        {
            i++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if ((inik - hash[i]) % 2 != 0)
        {
            v[i] ^= 1;
        }
    }
    for (auto x : v)
        cout << x;
    cout << endl;
    for (auto x : hash)
        cout << x << gap;
    cout << endl;
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