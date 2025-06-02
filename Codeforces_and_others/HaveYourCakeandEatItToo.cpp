#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<pair<ll, ll>> func(vector<ll> va, vector<ll> vb, vector<ll> vc, ll n, ll tot)
{
    vector<pair<ll, ll>> ret = {{1, 0}, {1, 0}, {1, 0}};
    ll i, j;
    ll sum = 0;
    ll diya = ceil(tot / 3.0);
    for (i = 1; i <= n; i++)
    {
        sum += va[i];
        if (sum >= diya)
        {
            ret[0] = {1, i};
            break;
        }
    }
    sum = 0;
    for (j = i + 1; j <= n; j++)
    {
        sum += vb[j];
        if (sum >= diya)
        {
            ret[1] = {i + 1, j};
            ret[2] = {j + 1, n};
            break;
        }
    }
    return ret;
}

bool fun(vector<ll> &cuma, vector<ll> &cumb, vector<ll> &cumc, vector<pair<ll, ll>> ret, ll tot)
{
    ll diya = ceil(tot / 3.0);
    if (cuma[ret[0].second] - cuma[ret[0].first - 1] >= diya && cumb[ret[1].second] - cumb[ret[1].first - 1] >= diya && cumc[ret[2].second] - cumc[ret[2].first - 1] >= diya)
        return true;
    return false;
}

void print_it(vector<pair<ll, ll>> ans)
{
    for (auto x : ans)
        cout << x.first << gap << x.second << gap;
    cout << endl;
    return;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> va(n + 1, 0), vb(n + 1, 0), vc(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> va[i];
    for (i = 1; i <= n; i++)
        cin >> vb[i];
    for (i = 1; i <= n; i++)
        cin >> vc[i];
    vector<ll> cuma = va, cumb = vb, cumc = vc;
    for (i = 1; i <= n; i++)
    {
        cuma[i] += cuma[i - 1];
        cumb[i] += cumb[i - 1];
        cumc[i] += cumc[i - 1];
    }
    ll tot = cuma[n];
    vector<pair<ll, ll>> ans;
    ans = func(va, vb, vc, n, tot);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    ans = func(va, vc, vb, n, tot);
    swap(ans[1], ans[2]);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    ans = func(vb, va, vc, n, tot);
    swap(ans[0], ans[1]);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    ans = func(vb, vc, va, n, tot);
    swap(ans[0], ans[2]);
    swap(ans[1], ans[2]);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    ans = func(vc, va, vb, n, tot);
    swap(ans[0], ans[1]);
    swap(ans[1], ans[2]);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    ans = func(vc, vb, va, n, tot);
    swap(ans[0], ans[2]);
    if (fun(cuma, cumb, cumc, ans, tot))
    {
        print_it(ans);
        return;
    }
    cout << -1 << endl;
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