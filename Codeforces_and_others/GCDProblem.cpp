#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

const ll N = 100 + 1;
vector<bool> isPrime(N, true);
set<ll> allPrimes;
void calculateSieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (isPrime[i])
            allPrimes.insert(i);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    c = 1;
    n--;
    set<ll> divisors;
    for (i = 2; i <= *allPrimes.rbegin(); i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    for (auto x : allPrimes)
    {
        if (divisors.find(x) == divisors.end())
        {
            a = x;
            b = n - x;
            break;
        }
    }
    cout << a << gap << b << gap << c << endl;
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