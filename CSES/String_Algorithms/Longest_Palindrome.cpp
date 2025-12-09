#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

string proc(string s)
{
    string str;
    str.push_back('%');
    for (auto x : s)
    {
        str.push_back('#');
        str.push_back(x);
    }
    str.push_back('#');
    str.push_back('$');
    return str;
}

vector<int> mancher(string s)
{
    string str;
    str.push_back('%');
    for (auto x : s)
    {
        str.push_back('#');
        str.push_back(x);
    }
    str.push_back('#');
    str.push_back('$');
    vector<int> p(str.size());
    int l = 0, r = 1, n = str.size() - 2;
    for (int i = 1; i <= n; i++)
    {
        p[i] = min(r - i, p[l + (r - i)]);
        while (str[i - p[i]] == str[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return p;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    vector<int> v = mancher(str);
    str = proc(str);
    int l, r, max_len = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] > max_len)
        {
            max_len = v[i];
            l = i - max_len + 2;
            r = i + max_len - 2;
        }
    }
    for (i = l; i <= r; i++)
    {
        if (str[i] != '#')
            cout << str[i];
    }
    cout << endl;
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