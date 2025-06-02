#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<vector<ll>> nest_vec;
    for (i = 0; i < n; i++)
    {
        if (v[i] == v[i + 1])
        {
            vector<ll> dum;
            dum.push_back(i + 1);
            dum.push_back(i + 2);
            nest_vec.push_back(dum);
            i++;
        }
        else
        {
            vector<ll> dum;
            dum.push_back(i + 1);
            dum.push_back(i + 1);
            nest_vec.push_back(dum);
            dum.clear();
            dum.push_back(i + 2);
            dum.push_back(i + 2);
            nest_vec.push_back(dum);
            i++;
        }
    }
    cout << nest_vec.size() << endl;
    for (i = 0; i < nest_vec.size(); i++)
    {
        for (j = 0; j < nest_vec[i].size(); j++)
        {
            cout << nest_vec[i][j] << gap;
        }
        cout << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}