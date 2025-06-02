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
    isPrime[1] = true;
    for (int i = 0; i < N; i++)
    {
        if (isPrime[i])
            allPrimes.push_back(i);
    }
}

vector<ll> preprime(1e6 + 1, 0);

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    m = sqrt(n);
    cout << preprime[n] - preprime[m] + 1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calculateSieve();
    for (int i = 1; i <= 1e6; i++)
    {
        if (isPrime[i])
            preprime[i] = 1;
    }
    for (int i = 1; i <= 1e6; i++)
    {
        preprime[i] = preprime[i] + preprime[i - 1];
    }
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}