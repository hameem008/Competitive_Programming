// base template
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}

// policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order()
// order_of_key()
// for indexed_multiset upper_bound works like lower_bound and vice versa

// debug
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

// sieve algorithm
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
    // if max_element <= 1e9 then use this snippet where N = 31625
    // for (int i = 0; i < allPrimes.size(); i++)
    // {
    //     ll pf = allPrimes[i];
    //     if (n % pf == 0)
    //     {
    //         distinctPrimeFactors.push_back(pf);
    //         while (n % pf == 0)
    //         {
    //             primeFactors.push_back(pf);
    //             n /= pf;
    //         }
    //     }
    //     else if (n < pf)
    //         break;
    // }
    // if (n != 1)
    // {
    //     distinctPrimeFactors.push_back(n);
    //     primeFactors.push_back(n);
    // }
    // return distinctPrimeFactors;
}

// binary search
ll hi, lo, mid;
while (hi - lo > 1) // FFFFTTT find first true
{
    mid = (hi + lo) / 2;
    if (pf(mid))
        hi = mid;
    else
        lo = mid + 1;
}
if (pf(lo))
    cout << lo << endl;
else
    cout << hi << endl;
while (hi - lo > 1) // TTTTFFF find last true
{
    mid = (hi + lo) / 2;
    if (pf(mid))
        lo = mid;
    else
        hi = mid - 1;
}
if (pf(hi))
    cout << hi << endl;
else
    cout << lo << endl;

// ternary search
lld lo, hi;
while (hi - lo > 1e-7) // finding minimum
{
    lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
    lld ans1 = fun(mid1), ans2 = fun(mid2);
    if (ans1 < ans2)
        hi = mid2;
    else if (ans1 > ans2)
        lo = mid1;
    else
    {
        hi = mid2;
        lo = mid1;
    }
}
while (hi - lo > 1e-7) // finding maximum
{
    lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
    lld ans1 = fun(mid1), ans2 = fun(mid2);
    if (ans1 < ans2)
        lo = mid1;
    else if (ans1 > ans2)
        hi = mid2;
    else
    {
        hi = mid2;
        lo = mid1;
    }
}

// modular arithmetic
ll binExp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll rec = binExp(a, b / 2, mod);
    if (b % 2 != 0)
        return ((a % mod) * (rec % mod) % mod) * (rec % mod) % mod;
    else
        return (rec % mod) * (rec % mod) % mod;
}

ll modMulInv(ll n, ll mod)
{
    return binExp(n, mod - 2, mod) % mod;
}

ll abybmod(ll a, ll b, ll mod)
{
    ll ans = a;
    ans %= mod;
    ans *= modMulInv(b, mod);
    ans %= mod;
    return ans;
}

ll nPr(ll n, ll r, ll mod)
{
    ll nfact = 1, n_rfact = 1;
    for (int i = 1; i <= n; i++)
    {
        nfact *= i;
        nfact %= mod;
    }
    for (int i = 1; i <= n - r; i++)
    {
        n_rfact *= i;
        n_rfact %= mod;
    }
    ll ans = abybmod(nfact, n_rfact, mod);
    return ans;
}

ll nCr(ll n, ll r, ll mod)
{
    ll nfact = 1, rfact = 1, n_rfact = 1;
    for (int i = 1; i <= n; i++)
    {
        nfact *= i;
        nfact %= mod;
    }
    for (int i = 1; i <= r; i++)
    {
        rfact *= i;
        rfact %= mod;
    }
    for (int i = 1; i <= n - r; i++)
    {
        n_rfact *= i;
        n_rfact %= mod;
    }
    ll ans = abybmod(nfact, rfact, mod);
    ans = abybmod(ans, n_rfact, mod);
    return ans;
}

// segment tree
template <class T>
class segment_tree
{
private:
    ll N = 0;
    T *t;
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return a + b;
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    segment_tree()
    {
    }
    segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        if (N)
            delete[] t;
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
    {
        if (N)
            clear();
    }
};

// segment tree lazy propagation
template <class T>
class lazy_segment_tree
{
private:
    ll N = 0;
    T *t;
    T *lazy;
    ll root = 1;
    ll tla = 0, tra = 0;
    void push(ll v, ll tl, ll tm, ll tr)
    {
        t[v * 2] += (tm - tl + 1) * lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += (tr - tm) * lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return a + b;
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T add_val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += (r - l + 1) * add_val;
            lazy[v] += add_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), add_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

public:
    lazy_segment_tree()
    {
    }
    lazy_segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        lazy = new T[4 * N];
        for (int i = 0; i < 4 * N; i++)
            lazy[i] = 0;
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll l, ll r, T add_val)
    {
        update(root, tla, tra, l, r, add_val);
    }
    void clear()
    {
        if (N)
        {
            delete[] t;
            delete[] lazy;
        }
        N = 0, tra = 0, tla = 0;
    }
    ~lazy_segment_tree()
    {
        if (N)
            clear();
    }
};

// all subset generation
vector<vector<ll>> subsetgen(vector<ll> &nums)
{
    ll n = nums.size();
    ll subsetCount = 1 << n;
    vector<vector<ll>> subsets;
    for (ll mask = 0; mask < subsetCount; ++mask)
    {
        vector<ll> subset;
        for (ll i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

// dfs
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

// bfs
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
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
            }
        }
    }
}

// shortest path using bfs
vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    Parents.clear();
    Distance.clear();
    Parents.assign(isVisited.size(), 0);
    Distance.assign(isVisited.size(), 0);
    Source = source;
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
                Parents[x] = vertex;
                Distance[x] = Distance[vertex] + 1;
            }
        }
    }
}

vector<ll> shortest_path(ll destination)
{
    ll source = Source;
    vector<ll> path;
    ll node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = Parents[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

// grid dfs
void grid_dfs(ll i, ll j, ll row, ll column)
{
    if (i < 1 || i > row || j < 1 || j > column || isVisited[i][j] == true)
        return;
    isVisited[i][j] = true;
    // adjacent cell
    grid_dfs(i + 1, j, row, column);
    grid_dfs(i - 1, j, row, column);
    grid_dfs(i, j + 1, row, column);
    grid_dfs(i, j - 1, row, column);
    // diagonal cell
    grid_dfs(i + 1, j + 1, row, column);
    grid_dfs(i - 1, j + 1, row, column);
    grid_dfs(i - 1, j - 1, row, column);
    grid_dfs(i + 1, j - 1, row, column);
}

// dsu
class dsu
{
private:
    ll N = 0;
    ll *parrents;
    ll *ranks;

public:
    dsu(ll n)
    {
        build(n);
    }
    void build(ll n)
    {
        if (N)
            clear();
        N = n;
        parrents = new ll[n + 1];
        ranks = new ll[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            parrents[i] = i;
            ranks[i] = 0;
        }
    }
    ll Find(ll v)
    {
        if (v == parrents[v])
            return v;
        return parrents[v] = Find(parrents[v]);
    }
    void Union(ll a, ll b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            if (ranks[a] < ranks[b])
                swap(a, b);
            parrents[b] = a;
            if (ranks[a] == ranks[b])
                ranks[a]++;
        }
    }
    void clear()
    {
        if (N)
        {
            delete[] parrents;
            delete[] ranks;
        }
        N = 0;
    }
    ~dsu()
    {
        if (N)
            clear();
    }
};

// 2D presum
ll presum[1008][1008];
void grid_presum(ll row, ll column)
{
	for (ll i = 2; i <= row; i++)
	{
		presum[i][1] = presum[i][1] + presum[i - 1][1];
	}
	for (ll i = 2; i <= column; i++)
	{
		presum[1][i] = presum[1][i] + presum[1][i - 1];
	}
	for (ll i = 2; i <= row; i++)
	{
		for (ll j = 2; j <= column; j++)
		{
			presum[i][j] = presum[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
		}
	}
}
ll query(pair<ll, ll> p1, pair<ll, ll> p2)
{
	return presum[p2.first][p2.second] + presum[p1.first - 1][p1.second - 1] - presum[p2.first][p1.second - 1] - presum[p1.first - 1][p2.second];
}

// single source shortest path
vector<int> parrents_dijkstra;
vector<int> distance_dijkstra;
void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    parrents_dijkstra.clear();
    distance_dijkstra.clear();
    parrents_dijkstra.assign(n, -1);
    distance_dijkstra.assign(n, 99999999);
    distance_dijkstra[source] = 0;
    parrents_dijkstra[source] = source;
    vector<bool> isDone(n, false);
    int cost;
    set<pair<int, int>> pq;
    pq.insert({distance_dijkstra[source], source});
    while (pq.size())
    {
        pair<int, int> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p.first;
        if (isDone[p.second])
            continue;
        isDone[p.second] = true;
        for (auto x : graph[p.second])
        {
            if (cost + x.second < distance_dijkstra[x.first])
            {
                distance_dijkstra[x.first] = cost + x.second;
                parrents_dijkstra[x.first] = p.second;
                pq.insert({distance_dijkstra[x.first], x.first});
            }
        }
    }
}
vector<int> shortest_path_dijkstra(int source, int destination)
{
    vector<int> path;
    int node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_dijkstra[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

bool isCyclePresent = false;
vector<int> parrents_bellman_ford;
vector<int> distance_bellman_ford;
void bellman_ford(vector<pair<pair<int, int>, int>> &edge_list, int source, int n)
{
    parrents_bellman_ford.clear();
    distance_bellman_ford.clear();
    parrents_bellman_ford.assign(n + 1, -1);
    distance_bellman_ford.assign(n + 1, 99999999);
    parrents_bellman_ford[source] = source;
    distance_bellman_ford[source] = 0;
    int limit = n - 1;
    while (limit--)
    {
        for (auto x : edge_list)
        {
            if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
            {
                distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                parrents_bellman_ford[x.first.second] = x.first.first;
            }
        }
    }
    vector<int> check = distance_bellman_ford;
    for (auto x : edge_list)
    {
        if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
        {
            distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
            parrents_bellman_ford[x.first.second] = x.first.first;
        }
    }
    if (check != distance_bellman_ford)
        isCyclePresent = true;
}
vector<int> shortest_path_bellman_ford(int source, int destination)
{
    vector<int> path;
    int node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_bellman_ford[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

// all pair shortest path
vector<vector<int>> shortest_distance;
vector<vector<int>> graph;
void floydwarshall(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                shortest_distance[u][v] = min(shortest_distance[u][v], shortest_distance[u][i] + shortest_distance[i][v]);
            }
        }
    }
}

// max flow
int edmondsKarp(vector<vector<int>> &graph, int source, int sink, vector<vector<int>> &edge_capacity)
{
    int n = graph.size();
    int max_flow = 0;
    while (1)
    {
        vector<bool> isVisited(n, false);
        vector<int> parrents(n, 0);
        queue<int> q;
        isVisited[source] = true;
        parrents[source] = source;
        q.push(source);
        while (q.size())
        {
            int vertex = q.front();
            q.pop();
            for (auto x : graph[vertex])
            {
                if (edge_capacity[vertex][x] > 0 && !isVisited[x])
                {
                    q.push(x);
                    isVisited[x] = true;
                    parrents[x] = vertex;
                }
            }
        }
        if (parrents[sink] == 0)
            break;
        vector<int> path;
        int node = sink;
        while (node != source)
        {
            path.push_back(node);
            node = parrents[node];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        int bottle_neck = INT32_MAX;
        for (int i = 0; i < path.size() - 1; i++)
        {
            bottle_neck = min(bottle_neck, edge_capacity[path[i]][path[i + 1]]);
        }
        for (int i = 0; i < path.size() - 1; i++)
        {
            edge_capacity[path[i]][path[i + 1]] -= bottle_neck;
            edge_capacity[path[i + 1]][path[i]] += bottle_neck;
        }
        max_flow += bottle_neck;
    }
    return max_flow;
}

// Matrix mapping to adjacency list
vector<vector<ll>> grid_to_arr;
vector<pair<ll, ll>> arr_to_grid;
vector<vector<ll>> grid_mapped_arr(ll n, ll m)
{
    grid_to_arr.assign(n + 1, vector<ll>(m + 1, 0));
    arr_to_grid.assign((n + 1) * (m + 1), {0, 0});
    ll k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            grid_to_arr[i][j] = k;
            arr_to_grid[k] = {i, j};
            k++;
        }
    }
    vector<vector<ll>> graph(k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // adjacent
            if (i > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j]);
            }
            if (j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j - 1]);
            }
            if (i < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j]);
            }
            if (j < m)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j + 1]);
            }

            // diagonal
            if (i > 1 && j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j - 1]);
            }
            if (i < n && j > 1)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j - 1]);
            }
            if (i < n && j < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i + 1][j + 1]);
            }
            if (i > 1 && j < n)
            {
                graph[grid_to_arr[i][j]].push_back(grid_to_arr[i - 1][j + 1]);
            }
        }
    }
    return graph;
}

// z function
vector<ll> z_function(string s)
{
    int n = s.size();
    vector<ll> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min((ll)r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// Bridges of a graph
void bridgedfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &start, vector<ll> &low, vector<ll> &parrents, ll &timer, vector<pair<ll, ll>> &ret)
{
    isVisited[vertex] = true;
    start[vertex] = timer++;
    low[vertex] = start[vertex];
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            parrents[x] = vertex;
            bridgedfs(x, graph, isVisited, start, low, parrents, timer, ret);
        }
        if (parrents[vertex] != x)
            low[vertex] = min(low[vertex], low[x]);
    }
    if (low[vertex] > start[parrents[vertex]] && vertex > 1)
    {
        ret.push_back({min(vertex, parrents[vertex]), max(vertex, parrents[vertex])});
    }
}
vector<pair<ll, ll>> bridges(vector<vector<ll>> &graph)
{
    ll n = graph.size() - 1, timer = 1;
    vector<ll> start(n + 1, 0), low(n + 1);
    vector<ll> parrents(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    vector<pair<ll, ll>> ret;
    bridgedfs(1, graph, isVisited, start, low, parrents, timer, ret);
    return ret;
}

// segment tree 2D
struct Node
{
    ll value;
    Node() : value(0) {}
    // for min--> value(INT32_MAX);
    // for max--> value(INT32_MIN);
    // for gcd--> value(0);
    // for xor--> value(0);
};

class segment_tree_2D
{
private:
    ll rows, cols;
    vector<vector<Node>> tree;
    ll combine(ll a, ll b)
    {
        return a + b;
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
    }
    void buildY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, const vector<vector<ll>> &arr)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = arr[lx][ly];
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            buildY(vx, lx, rx, vy * 2, ly, my, arr);
            buildY(vx, lx, rx, vy * 2 + 1, my + 1, ry, arr);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void buildX(ll vx, ll lx, ll rx, const vector<vector<ll>> &arr)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            buildX(vx * 2, lx, mx, arr);
            buildX(vx * 2 + 1, mx + 1, rx, arr);
        }
        buildY(vx, lx, rx, 1, 0, cols - 1, arr);
    }
    ll queryY(ll vx, ll vy, ll tly, ll try_, ll ly, ll ry)
    {
        if (ly > ry)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy].value;
        ll tmy = (tly + try_) / 2;
        return combine(queryY(vx, vy * 2, tly, tmy, ly, min(ry, tmy)), queryY(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }
    ll queryX(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry)
    {
        if (lx > rx)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (lx == tlx && trx == rx)
            return queryY(vx, 1, 0, cols - 1, ly, ry);
        ll tmx = (tlx + trx) / 2;
        return combine(queryX(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry), queryX(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }
    void updateY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, ll x, ll y, ll new_val)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = new_val;
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            if (y <= my)
                updateY(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                updateY(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void updateX(ll vx, ll lx, ll rx, ll x, ll y, ll new_val)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            if (x <= mx)
                updateX(vx * 2, lx, mx, x, y, new_val);
            else
                updateX(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        updateY(vx, lx, rx, 1, 0, cols - 1, x, y, new_val);
    }

public:
    segment_tree_2D(const vector<vector<ll>> &arr)
    {
        rows = arr.size();
        cols = arr[0].size();
        tree.resize(4 * rows);
        for (ll i = 0; i < 4 * rows; ++i)
            tree[i].resize(4 * cols);
        buildX(1, 0, rows - 1, arr);
    }
    ll query(ll lx, ll rx, ll ly, ll ry)
    {
        return queryX(1, 0, rows - 1, lx, rx, ly, ry);
    }
    void update(ll x, ll y, ll new_val)
    {
        updateX(1, 0, rows - 1, x, y, new_val);
    }
};

// least common ancestor
pair<ll, ll> func(ll n)
{
    ll k;
    k = log2(n);
    pair<ll, ll> ret = {k, powl(2, k)};
    return ret;
}
vector<vector<ll>> bin_lift;
vector<ll> next_child;
void bin_lift_func(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> parv, ll level)
{
    isVisited[vertex] = true;
    if (level > 0)
    {
        for (auto x : parv)
            bin_lift[vertex].push_back(next_child[x]);
        pair<ll, ll> pr = func(level);
        if (pr.second == level)
            bin_lift[vertex].push_back(1);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            next_child[vertex] = x;
            bin_lift_func(x, graph, isVisited, bin_lift[vertex], level + 1);
        }
    }
}
ll get_kth_parrent(ll node, ll kth_parrent)
{
    while (1)
    {
        pair<ll, ll> pr = func(kth_parrent);
        ll pow_2 = pr.first;
        ll powl_ = pr.second;
        if (powl_ == kth_parrent && pow_2 < bin_lift[node].size())
            return bin_lift[node][pow_2];
        else if (pow_2 < bin_lift[node].size())
        {
            node = bin_lift[node][pow_2];
            kth_parrent -= powl_;
        }
        else
            return -1;
    }
}
vector<ll> start_time, end_time, level_of;
ll time_ = 0;
void calc_time(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll level)
{
    isVisited[vertex] = true;
    level_of[vertex] = level;
    time_++;
    start_time[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            calc_time(x, graph, isVisited, level + 1);
        }
    }
    time_++;
    end_time[vertex] = time_;
}
ll least_common_ancestor(ll u, ll v)
{
    if (start_time[u] <= start_time[v] && end_time[u] >= end_time[v])
        return u;
    else if (start_time[v] <= start_time[u] && end_time[v] >= end_time[u])
        return v;
    ll lca;
    lca = u;
    while (1)
    {
        ll dum;
        for (int i = 0; i < bin_lift[lca].size(); i++)
        {
            ll k = bin_lift[lca][i];
            if (start_time[k] < start_time[v] && end_time[k] > end_time[v])
            {
                if (i == 0)
                {
                    return k;
                }
                else
                {
                    break;
                }
            }
            else
                dum = k;
        }
        lca = dum;
    }
    return lca;
}
void init(ll n)
{
    vector<ll> v;
    bin_lift.assign(n + 1, v);
    next_child.assign(n + 1, 0);
    start_time.assign(n + 1, 0);
    end_time.assign(n + 1, 0);
    level_of.assign(n + 1, 0);
}
void pre_processing(ll number_of_nodes, vector<vector<ll>> &graph, ll root)
{
    init(number_of_nodes);
    vector<bool> isVIsited(number_of_nodes + 1, false);
    vector<ll> v;
    bin_lift_func(root, graph, isVIsited, v, 0);
    isVIsited.assign(number_of_nodes + 1, false);
    calc_time(root, graph, isVIsited, 0);
}

// Matrix exponentiation
// square matrix nXn
vector<vector<ll>> matrix_multiplication(vector<vector<ll>> &a, vector<vector<ll>> &b, ll n)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}
vector<vector<ll>> binExp(vector<vector<ll>> &a, ll b, ll n)
{
    if (b == 1)
        return a;
    vector<vector<ll>> ans = binExp(a, b / 2, n);
    if (b % 2 != 0)
    {
        vector<vector<ll>> v = matrix_multiplication(ans, ans, n);
        return matrix_multiplication(v, a, n);
    }
    else
    {
        return matrix_multiplication(ans, ans, n);
    }
}

// strongly connectd components
ll time_ = 0;
vector<ll> start_t, end_t;
void scc_dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    time_++;
    start_t[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs(x, graph, isVisited);
        }
    }
    time_++;
    end_t[vertex] = time_;
}
vector<ll> nodes;
void scc_dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs_2(x, graph, isVisited);
        }
    }
}
vector<vector<ll>> all_scc;
vector<ll> map_scc_index;
void strongly_connnected_components(ll n, vector<pair<ll, ll>> &edge_list)
{
    ll i;
    start_t.assign(n + 1, 0);
    end_t.assign(n + 1, 0);
    map_scc_index.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1), graph_t(n + 1);
    for (auto x : edge_list)
    {
        graph[x.first].push_back(x.second);
        graph_t[x.second].push_back(x.first);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            scc_dfs(i, graph, isVisited);
        }
    }
    isVisited.assign(n + 1, false);
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        vp.push_back({end_t[i], i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    all_scc.push_back(vector<ll>(0));
    i = 1;
    for (auto x : vp)
    {
        if (!isVisited[x.second])
        {
            nodes.clear();
            scc_dfs_2(x.second, graph_t, isVisited);
            all_scc.push_back(nodes);
            for (auto y : nodes)
            {
                map_scc_index[y] = i;
            }
            i++;
        }
    }
}

// Heavy Light decomposion
// add segment tree and least common ancestor
vector<ll> subtree_size;
vector<ll> parrent;
vector<ll> max_subtree_size;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll mx_subtree_sz = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            subtree_size[vertex] += subtree_size[x];
            parrent[x] = vertex;
            if (mx_subtree_sz < subtree_size[x])
            {
                max_subtree_size[vertex] = x;
                mx_subtree_sz = subtree_size[x];
            }
        }
    }
}
vector<vector<ll>> sgv;
vector<pair<ll, ll>> info;
void dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll &ind)
{
    isVisited[vertex] = true;
    ll max_sbtreenode = max_subtree_size[vertex];
    if (max_sbtreenode)
    {
        info[max_sbtreenode].first = ind;
        info[max_sbtreenode].second = sgv[ind].size();
        sgv[ind].push_back(max_sbtreenode);
        dfs_2(max_sbtreenode, graph, isVisited, ind);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            info[x].first = ind;
            info[x].second = sgv[ind].size();
            sgv[ind].push_back(x);
            dfs_2(x, graph, isVisited, ind);
        }
    }
    if (graph[vertex].size() == 1 && graph[vertex].front() == parrent[vertex])
    {
        ind++;
    }
}
vector<segment_tree<ll>> vec_of_sg;
void HLD_preprocessing(vector<vector<ll>> &graph, vector<ll> &valv, ll n, ll root)
{
    sgv.assign(n + 1, vector<ll>(0));
    subtree_size.assign(n + 1, 1);
    max_subtree_size.assign(n + 1, 0);
    parrent.assign(n + 1, 0);
    info.assign(n + 1, make_pair(0, 0));
    vector<bool> isVisited(n + 1, false);
    dfs(root, graph, isVisited);
    isVisited.assign(n + 1, false);
    ll ind = 0;
    sgv[ind].push_back(root);
    dfs_2(root, graph, isVisited, ind);
    for (auto x : sgv)
    {
        if (x.size() == 0)
            continue;
        vector<ll> vec = x;
        for (ll i = 0; i < vec.size(); i++)
        {
            vec[i] = valv[vec[i]];
        }
        segment_tree<ll> sg(vec);
        vec_of_sg.push_back(sg);
    }
}
ll HLD_query(ll a, ll b)
{
    ll lca = least_common_ancestor(a, b);
    ll qr = 0;
    bool flag_a = true, flag_b = true;
    while (flag_a || flag_b)
    {
        if (flag_a)
        {
            ll sg_a = info[a].first, sg_lca = info[lca].first;
            if (sg_a == sg_lca)
            {
                qr = max(qr, vec_of_sg[sg_a].query(info[lca].second, info[a].second));
                flag_a = false;
            }
            else
            {
                qr = max(qr, vec_of_sg[sg_a].query(0, info[a].second));
                a = parrent[sgv[sg_a][0]];
            }
        }
        if (flag_b)
        {
            ll sg_b = info[b].first, sg_lca = info[lca].first;
            if (sg_b == sg_lca)
            {
                qr = max(qr, vec_of_sg[sg_b].query(info[lca].second, info[b].second));
                flag_b = false;
            }
            else
            {
                qr = max(qr, vec_of_sg[sg_b].query(0, info[b].second));
                b = parrent[sgv[sg_b][0]];
            }
        }
    }
    return qr;
}