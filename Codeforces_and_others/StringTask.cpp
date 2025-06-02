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
    string str;
    cin >> str;
    set<char> s;
    s.insert('a');
    s.insert('e');
    s.insert('i');
    s.insert('o');
    s.insert('u');
    s.insert('y');
    for (auto &x : str)
    {
        if (x >= 'A' && x <= 'Z')
        {
            x -= ('A' - 'a');
        }
    }
    string ans;
    for (auto x : str)
    {
        if (s.find(x) == s.end())
        {
            ans.push_back('.');
            ans.push_back(x);
        }
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}