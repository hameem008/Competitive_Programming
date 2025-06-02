#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<string> vstr(3);
    for (i = 0; i < 3; i++)
    {
        cin >> vstr[i];
    }
    for (i = 0; i < 3; i++)
    {
        set<char> s(vstr[i].begin(), vstr[i].end());
        if (s.find('?') != s.end())
        {
            if (s.find('A') == s.end())
            {
                cout << 'A' << endl;
            }
            else if (s.find('B') == s.end())
            {
                cout << 'B' << endl;
            }
            else if (s.find('C') == s.end())
            {
                cout << 'C' << endl;
            }
        }
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