#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<string> v;

void gen(string &s, ll open, ll close)
{
    if (open == 0 && close == 0)
    {
        v.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        gen(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0 && open < close)
    {
        s.push_back(')');
        gen(s, open, close - 1);
        s.pop_back();
    }
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    string str;
    gen(str, n, n);
    for (auto x : v)
        cout << x << endl;
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