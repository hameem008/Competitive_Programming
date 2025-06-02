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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (s1[s1.size() - 1] == s2[s2.size() - 1])
    {
        if (s1[s1.size() - 1] == 'S')
        {
            if (s1.size() > s2.size())
                cout << "<" << line;
            else if (s1.size() < s2.size())
                cout << ">" << line;
            else
                cout << "=" << line;
        }
        else if (s1[s1.size() - 1] == 'L')
        {
            if (s1.size() < s2.size())
                cout << "<" << line;
            else if (s1.size() > s2.size())
                cout << ">" << line;
            else
                cout << "=" << line;
        }
        else
            cout << "=" << line;
    }
    else
    {
        if (s1.back() < s2.back())
            cout << ">" << line;
        else
            cout << "<" << line;
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