#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<bool> primes(1e6 + 1, true);

void Sieve()
{
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= 1e6; i++)
    {
        if (primes[i] == true)
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    Sieve();
    set<ll> s;
    for (i = 0; i <= 1e6; i++)
    {
        if (primes[i])
            s.insert(i * i);
    }
    ll size = s.size();
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    for (i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
        if (size != s.size())
        {
            cout << "NO" << endl;
            s.erase(v[i]);
        }
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

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}