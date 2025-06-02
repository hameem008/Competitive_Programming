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
    cin >> n >> m >> k;
    vector<ll> v(k);
    for (auto &x : v)
        cin >> x;
    set<ll> buffer;
    ll free = n * m - 2;
    ll req_num = k;
    flag = true;
    for (i = 0; i < k; i++)
    {
        buffer.insert(v[i]);
        free--;
        if (!free)
        {
            flag = false;
            break;
        }
        auto it = buffer.find(req_num);
        while (it != buffer.end())
        {
            req_num--;
            free++;
            it = buffer.find(req_num);
        }
    }
    flag ? cout << "YA" << endl : cout << "TIDAK" << endl;
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