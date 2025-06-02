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
    set<ll> ans;
    ll curr_cnt = 0;
    char curr_char = str[0];
    for (i = 0; i < n; i++)
    {
        if (str[i] == curr_char)
        {
            curr_cnt++;
        }
        else
        {
            ans.insert(curr_cnt + 1);
            curr_char = str[i];
            curr_cnt = 1;
        }
    }
    ans.insert(curr_cnt + 1);
    cout << *(--ans.end()) << endl;
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