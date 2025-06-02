#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    int v[n][n - 1];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<ll> ans;
    j = 0;
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        ms.insert(v[i][j]);
    }
    ll curr_num;
    if (ms.count(*ms.begin()) > ms.count(*(--ms.end())))
    {
        ans.push_back(*ms.begin());
        curr_num = *(--ms.end());
    }
    else
    {
        ans.push_back(*(--ms.end()));
        curr_num = *(ms.begin());
    }
    j++;
    ans.push_back(curr_num);
    for (i = 0; i < n; i++)
    {
        if (j == n - 1)
            break;
        if (v[i][j] != curr_num)
        {
            ans.push_back(v[i][j]);
            curr_num = v[i][j];
            j++;
            if (j == n - 1)
                break;
            i = -1;
        }
    }
    for (auto x : ans)
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