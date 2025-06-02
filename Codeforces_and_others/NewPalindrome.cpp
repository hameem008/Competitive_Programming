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
    string str;
    cin >> str;
    map<char, ll> mp;
    for (auto x : str)
        mp[x]++;
    if (mp.size() == 1)
    {
        cout << "NO" << endl;
    }
    else if (mp.size() == 2)
    {
        if (str.size() % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            for (auto x : mp)
            {
                if (x.second == 1)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            cout << "YES" << endl;
        }
    }
    else
    {
        cout << "YES" << endl;
    }
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