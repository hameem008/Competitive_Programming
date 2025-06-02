#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    reverse(v.begin(), v.end());
    ll cnt = 0;
    flag = true;
    ll min_ele = *min_element(v.begin(), v.end());
    while (v.size())
    {
        if (v.back() == min_ele)
        {
            break;
        }
        else
        {
            v.pop_back();
            cnt++;
        }
    }
    reverse(v.begin(), v.end());
    for (i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            flag = false;
    }
    flag ? cout << cnt << endl : cout << -1 << endl;
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