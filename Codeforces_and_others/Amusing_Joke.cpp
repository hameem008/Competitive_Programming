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
    flag = true;
    string str1, str2, strrr;
    cin >> str1;
    cin >> str2;
    cin >> strrr;
    vector<int> v(26, 0);
    for (auto x : strrr)
        v[x - 'A']++;
    for (auto x : str1)
        v[x - 'A']--;
    for (auto x : v)
        if (x < 0)
            flag = false;
    for (auto x : str1)
        v[x - 'A']++;
    for (auto x : str2)
        v[x - 'A']--;
    for (auto x : v)
        if (x < 0)
            flag = false;
    for (auto x : str2)
        v[x - 'A']++;
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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