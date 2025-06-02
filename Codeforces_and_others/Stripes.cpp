#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define line '\n'
#define gap ' '
typedef long long ll;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    vector<string> v(8);
    for (i = 0; i < 8; i++)
    {
        cin >> v[i];
    }
    for (i = 0; i < 8; i++)
    {
        ll count = 0;
        for (j = 0; j < 8; j++)
        {
            if (v[i][j] == 'R')
                count++;
        }
        if (count == 8)
        {
            cout << 'R' << line;
            return;
        }
    }
    cout << 'B' << line;
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