#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

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
    // if max_element <= 1e7 then use this snippet where N = 1e7 + 1
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
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
Alice:
    bool alice = true;
    set<ll> seta, setb;
    for (auto x : a)
    {
        for (auto y : getPrimeFactorsOf(x))
            seta.insert(y);
    }
    for (auto x : b)
    {
        for (auto y : getPrimeFactorsOf(x))
            setb.insert(y);
    }
    for (auto x : setb)
    {
        if (seta.find(x) == seta.end())
        {
            alice = false;
            break;
        }
    }
Bob:
    bool bob = true;
    if (!alice)
    {
        bob = false;
    }
    else
    {
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] * b[i + 1] != a[i + 1] * b[i])
            {
                bob = false;
                break;
            }
        }
        ll gcd = a[0];
        for (auto x : a)
        {
            gcd = __gcd(x, gcd);
        }
        set<ll> setgcd;
        for (auto x : getPrimeFactorsOf(gcd))
        {
            setgcd.insert(x);
        }
        for (auto x : setb)
        {
            if (setgcd.find(x) == setgcd.end())
            {
                bob = false;
                break;
            }
        }
        bool flag = true;
        for (i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                flag = false;
        }
        if (flag)
            bob = true;
    }
    cout << "Case " << I << ": ";
    if (alice)
        cout << "Yes ";
    else
        cout << "No ";
    if (bob)
        cout << "Yes ";
    else
        cout << "No ";
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    calculateSieve();
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}