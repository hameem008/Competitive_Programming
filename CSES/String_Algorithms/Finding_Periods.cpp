#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

// s = ptrn + $ + str
vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0, i;
    for (i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

vector<int> next_index;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str, st;
    cin >> str;
    n = str.size();
    for (int i = 0; i < n; i++)
        next_index.push_back(i);
    vector<int> v = z_function(str);
    vector<int> ans;
    for (i = 1; i < n; i++)
    {
        for (int idx = i; idx < n;)
        {
            if (v[idx] < i)
            {
                if (v[idx] + idx == n)
                    ans.push_back(i);
                break;
            }
            idx += i;
            if (idx >= n)
                ans.push_back(i);
        }
    }
    ans.push_back(n);
    for (auto x : ans)
        cout << x << gap;
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