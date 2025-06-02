#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
#define re register
typedef long long ll;

vector<bool> sieve(31625, true);
vector<ll> primes;
set<ll> primeFact;
ll primeFactCounter;

void calcSieve()
{
    sieve[0] = sieve[1] = false;
    for (re int i = 2; i <= 31623; i++)
    {
        if (sieve[i])
        {
            for (re int j = 2 * i; j <= 31623; j += i)
                sieve[j] = false;
        }
    }
    for (re int i = 0; i <= 31623; i++)
        if (sieve[i])
            primes.push_back(i);
}

void getPrimeFact(ll n)
{
    for (re int i = 0; i < primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {
            primeFact.insert(primes[i]);
            primeFactCounter++;
            while (n % primes[i] == 0)
                n /= primes[i];
        }
    }
    if (n != 1)
    {
        primeFact.insert(n);
        primeFactCounter++;
    }
}

void solve(int I)
{
    re ll i, j, k, a, b, m, n, p;
    // solve stars
    primeFactCounter = 0;
    primeFact.clear();
    cin >> n;
    re vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (a != 1)
        {
            v.push_back(a);
            getPrimeFact(a);
        }
    }
    if (v.size() > 1 && primeFactCounter > primeFact.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calcSieve();
    re ll t = 1;
    cin >> t;
    for (re int I = 1; I <= t; I++)
        solve(I);
    return 0;
}