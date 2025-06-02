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
    cin >> n;
    string str;
    cin >> str;
    m = sqrt(n);
    if (m * m == n)
    {
        string ans;
        for (i = 0; i < m; i++)
        {
            ans.push_back('1');
        }
        for (i = 0; i < m - 2; i++)
        {
            ans.push_back('1');
            for (j = 0; j < m - 2; j++)
            {
                ans.push_back('0');
            }
            ans.push_back('1');
        }
        for (i = 0; i < m; i++)
        {
            ans.push_back('1');
        }
        if (ans == str)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        cout << "No" << endl;
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