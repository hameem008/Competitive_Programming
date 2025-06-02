#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> v;
vector<vector<ll>> allSubsets;

void gen(vector<ll> &subset, int i, vector<ll> &v)
{
    if (i == v.size())
    {
        allSubsets.push_back(subset);
        return;
    }
    gen(subset, i + 1, v);
    
    subset.push_back(v[i]);
    gen(subset, i + 1, v);
    subset.pop_back();
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    vector<ll> empty;
    gen(empty, 0, v);
    sort(allSubsets.begin(), allSubsets.end());
    for (i = 0; i < allSubsets.size(); i++)
    {
        for (j = 0; j < allSubsets[i].size(); j++)
        {
            cout << allSubsets[i][j] << gap;
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
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}