#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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
        else if (n < pf)
            break;
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
    bool flag;
    // solve starts
    cin >> a >> b >> k;
    if (a == 1 && b == 1)
    {
        flag = false;
    }
    else if (a == 1 || b == 1)
    {
        if (b == 1)
        {
            swap(a, b);
        }
        ll op = getPrimeFactorsOf(b).size();
        if (op >= k)
            flag = true;
        else
            flag = false;
    }
    else if (k == 1)
    {
        if (max(a, b) % min(a, b) == 0 && a != b)
            flag = true;
        else
            flag = false;
    }
    else
    {
        ll op = getPrimeFactorsOf(a).size() + getPrimeFactorsOf(b).size();
        if (op >= k)
            flag = true;
        else
            flag = false;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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