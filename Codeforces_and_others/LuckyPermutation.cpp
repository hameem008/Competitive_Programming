#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> numberToRing;
ll cnt;
ll ringNo;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    cnt++;
    numberToRing[vertex] = ringNo;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            dfs(x, graph, isVIsited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ringNo = 0;
    cin >> n;
    vector<ll> positionToNumber(n + 1);
    for (i = 1; i <= n; i++)
        cin >> positionToNumber[i];
    vector<ll> numberToPosition(n + 1);
    for (i = 1; i <= n; i++)
        numberToPosition[positionToNumber[i]] = i;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (numberToPosition[i] != i)
        {
            graph[i].push_back(numberToPosition[i]);
        }
    }
    numberToRing.clear();
    numberToRing.assign(n + 1, 0);
    map<ll, ll> opNoInRing;
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cnt = 0;
            ringNo++;
            dfs(i, graph, isVisited);
            opNoInRing[ringNo] = cnt - 1;
        }
    }
    ll totalOp = 0;
    for (auto x : opNoInRing)
    {
        totalOp += x.second;
    }
    ll ans = infinite;
    for (i = 1; i <= n - 1; i++)
    {
        ll num1 = i, num2 = i + 1;
        if (numberToRing[num1] == numberToRing[num2])
            ans = min(totalOp - 1, ans);
        else
            ans = min(totalOp + 1, ans);
    }
    cout << ans << endl;
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