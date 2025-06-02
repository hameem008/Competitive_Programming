#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

const ll N = 31625;
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
    for (int i = 0; i < allPrimes.size(); i++)
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
    return primeFactors;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v = getPrimeFactorsOf(n);
    multiset<ll> ms(v.begin(), v.end());
    ll ans = 0;
    while (ms.size())
    {
        set<ll> s(ms.begin(), ms.end());
        ll mul = 1;
        for (auto x : s)
        {
            mul *= x;
            ms.erase(ms.find(x));
        }
        ans += mul;
        s.clear();
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calculateSieve();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}