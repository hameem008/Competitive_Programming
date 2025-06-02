#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

const ll N = 1e7 + 1;
vector<bool> isPrime(N, true);
vector<ll> allPrimes;
vector<ll> lowestPrimeFactorOf(N, 0);
vector<ll> highestPrimeFactorOf(N, 0);
void calculateSieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            highestPrimeFactorOf[i] = lowestPrimeFactorOf[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highestPrimeFactorOf[j] = i;
                if (lowestPrimeFactorOf[j] == 0)
                    lowestPrimeFactorOf[j] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (isPrime[i])
            allPrimes.push_back(i);
    }
}
vector<ll> getPrimeFactorsOf(ll n)
{
    vector<ll> distinctPrimeFactors;
    vector<ll> primeFactors;
    while (n > 1)
    {
        ll pf = lowestPrimeFactorOf[n];
        distinctPrimeFactors.push_back(pf);
        while (n % pf == 0)
        {
            primeFactors.push_back(pf);
            n /= pf;
        }
    }
    return distinctPrimeFactors;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<pair<ll, ll>> ans(n, {-1, -1});
    for (k = 0; k < n; k++)
    {
        ll x = v[k];
        vector<ll> dum = getPrimeFactorsOf(x);
        if (dum.size() == 1)
        {
            ans[k] = {-1, -1};
        }
        else
        {
            ll mul = 1;
            for (i = 1; i < dum.size(); i++)
            {
                mul *= dum[i];
            }
            ans[k] = {dum[0], mul};
        }
    }
    for (auto x : ans)
        cout << x.first << gap;
    cout << endl;
    for (auto x : ans)
        cout << x.second << gap;
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calculateSieve();
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}