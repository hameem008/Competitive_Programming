#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;
    string ans;
    for (i = 0; i < n; i++)
    {
        if (ch > str[i])
            break;
    }
    for (j = 0; j < i; j++)
    {
        ans.push_back(str[j]);
    }
    ans.push_back(ch);
    for (j = i; j < n; j++)
    {
        ans.push_back(str[j]);
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}