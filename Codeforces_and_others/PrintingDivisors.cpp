#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

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
    return distinctPrimeFactors;
}

vector<ll> ans;
void dfs(ll vertex, map<ll, set<ll>> &graph, map<ll, bool> &isVisited)
{
    if (isVisited[vertex])
        return;
    ans.push_back(vertex);
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
        dfs(x, graph, isVisited);
}

bool chec(ll n)
{
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (getPrimeFactorsOf(max(ans[i], ans[i + 1]) / min(ans[i], ans[i + 1])).size() != 1 || ans.size() != n)
        {
            cout << ans[i] << endl;
            return false;
        }
    }
    return true;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ans.clear();
    cin >> n;
    set<ll> s;
    for (i = 1; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }
    vector<ll> primes = getPrimeFactorsOf(n);
    map<ll, set<ll>> graph;
    map<ll, bool> isVisited;
    for (auto x : s)
    {
        for (auto y : primes)
        {
            if (s.find(x * y) != s.end())
            {
                if (graph[x].size() < 5)
                    graph[x].insert(x * y);
                if (graph[x * y].size() < 5)
                    graph[x * y].insert(x);
            }
        }
        isVisited[x] = false;
    }
    ll rt = 1;
    for (auto x : graph)
    {
        if (x.second.size() == 1)
        {
            rt = x.first;
            break;
        }
    }
    dfs(rt, graph, isVisited);
    if (!chec(s.size()))
    {
        cout << n << endl;
        for (auto x : s)
            cout << x << gap;
        cout << endl;
        for (auto x : ans)
            cout << x << gap;
        cout << endl;
        for (auto x : graph)
        {
            cout << x.first << "=>";
            for (auto y : x.second)
                cout << y << gap;
            cout << endl;
        }
    }
    // cout << "Case " << I << ": " << endl;
    // for (auto x : ans)
    //     cout << x << gap;
    // cout << endl;
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