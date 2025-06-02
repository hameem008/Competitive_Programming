#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> digits(ll n)
{
    vector<ll> v;
    while (n)
    {

        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> dg = digits(k);
    set<ll> s(dg.begin(), dg.end());
    s.erase(1), s.erase(0);
    if (dg.size() > n || s.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    map<ll, ll> dist;
    map<ll, ll> isVisited;
    queue<ll> q;
    q.push(k);
    dist[k] = 0;
    ll num = k;
    isVisited[num] = true;
    while (q.size())
    {
        num = q.front();
        q.pop();
        vector<ll> v = digits(num);
        if (v.size() == n)
            break;
        for (auto x : v)
        {
            if (x > 1 && !isVisited[num * x])
            {
                dist[num * x] = dist[num] + 1;
                q.push(num * x);
                isVisited[num * x] = true;
            }
        }
    }
    cout << dist[num] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}