#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

bool pf(vector<ll> &mt, vector<ll> &main)
{
    for (int i = 0; i < mt.size(); i++)
    {
        if (mt[i] > main[i])
            return false;
        else if (mt[i] < main[i])
            return true;
    }
    return true;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> v;
    for (i = 0; i < n; i++)
    {
        vector<ll> dum(m);
        for (auto &x : dum)
            cin >> x;
        v.push_back(dum);
    }
    vector<vector<ll>> bin(v.begin(), v.end());
    sort(bin.begin(), bin.end());
    vector<ll> ansv;
    for (i = 0; i < n; i++)
    {
        ll ans = 0;
        for (j = 1; j <= m; j++)
        {
            vector<ll> dum(v[i].begin(), v[i].begin() + j);
            ll hi = n - 1, lo = 0, mid;
            while (hi - lo > 1)
            {
                mid = (hi + lo) / 2;
                if (pf(dum, bin[mid]))
                    hi = mid;
                else
                    lo = mid + 1;
            }
            a = 0;
            for (k = 0; k < m; k++)
            {
                if (bin[lo][v[i][k] - 1] == k + 1)
                    a++;
                else
                    break;
            }
            b = 0;
            for (k = 0; k < m; k++)
            {
                if (bin[hi][v[i][k] - 1] == k + 1)
                    b++;
                else
                    break;
            }
            if (ans < max(a, b))
                ans = max(a, b);
        }
        ansv.push_back(ans);
    }
    for (auto x : ansv)
        cout << x << gap;
    cout << endl;
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