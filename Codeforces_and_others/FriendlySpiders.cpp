#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

const ll N = 1e6 + 1;
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

vector<ll> shortest_path(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited, ll destination)
{
    vector<ll> parent(isVisited.size(), -1);
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                q.push(x);
                isVisited[x] = true;
                parent[x] = vertex;
            }
        }
    }
    vector<ll> path;
    if (parent[destination] != -1)
    {
        ll node = destination;
        while (node != source)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
    }
    // path.size() = 0 --> No path exist
    // distance = path.size() - 1
    return path;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    cin >> a >> b;
    vector<ll> vind(N, -1);
    for (i = 1; i <= n; i++)
    {
        if (vind[v[i]] == -1)
            vind[v[i]] = i;
    }
    if (a == b)
    {
        cout << 1 << endl;
        cout << a << endl;
        return;
    }
    else if (v[a] == 1 || v[b] == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (v[a] == v[b])
    {
        cout << 2 << endl;
        cout << a << gap << b << endl;
        return;
    }
    vector<ll> dum;
    vector<vector<ll>> graph(N, dum);
    vector<bool> isVisited(N, false);
    for (i = 0; i < N; i++)
    {
        if (vind[i] != -1)
        {
            dum = getPrimeFactorsOf(i);
            for (auto x : dum)
            {
                if (i != x)
                {
                    graph[x].push_back(i);
                    graph[i].push_back(x);
                }
            }
        }
    }
    vector<ll> path = shortest_path(v[a], graph, isVisited, v[b]);
    if (path.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<ll> ans;
        ans.push_back(a);
        for (i = 1; i < path.size() - 1; i++)
        {
            if (!isPrime[path[i]])
                ans.push_back(vind[path[i]]);
        }
        ans.push_back(b);
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << gap;
        cout << endl;
    }
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