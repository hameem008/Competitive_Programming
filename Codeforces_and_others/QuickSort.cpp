#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        v[a] = i;
    }
    ll last_ind = n;
    ll cur_num = 2;
    ll op = 0;
    while (cur_num <= n)
    {
        if (v[cur_num] < v[cur_num - 1])
        {
            op++;
            last_ind += k;
            if (cur_num + k - 1 <= n)
                v[cur_num + k - 1] = last_ind;
            cur_num += k;
        }
        else
            cur_num++;
    }
    cout << op << endl;
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