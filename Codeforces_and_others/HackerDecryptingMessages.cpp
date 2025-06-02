#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 arg1, Args... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

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
    if (n <= 1e7)
    {
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
    }
    else
    {
        for (int i = 0; allPrimes[i] * allPrimes[i] <= 1e9; i++)
        {
            ll pf = allPrimes[i];
            if (n % pf == 0)
            {
                distinctPrimeFactors.push_back(pf);
                while (n % pf == 0)
                {
                    primeFactors.push_back(pf);
                    n /= pf;
                }
            }
        }
        if (n != 1)
        {
            distinctPrimeFactors.push_back(n);
            primeFactors.push_back(n);
        }
    }
    return primeFactors;
}

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts

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