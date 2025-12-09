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
    vector<int> ret;
    while (1)
    {
        if (s[n - 1] == '$')
            break;
        else
            ret.push_back(z[n - 1]);
        n--;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> prefix_function(string s)
{
    int n = s.length(), i, j;
    vector<int> pi(n);
    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    vector<int> v_p = prefix_function(str);
    vector<int> v_z = z_function(str + '$' + str);
    v_z[0] = 0;
    for (auto x : v_z)
        cout << x << gap;
    cout << endl;
    for (auto x : v_p)
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