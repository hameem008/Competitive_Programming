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
    string str;
    cin >> str;
    n = str.size();
    vector<ll> freq(10, 0);
    for (auto x : str)
    {
        freq[x - '0']++;
    }
    ll ans = n - *max_element(freq.begin(), freq.end());
    set<string> s;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            string st;
            st.push_back(i + '0');
            st.push_back(j + '0');
            s.insert(st);
        }
    }
    for (auto x : s)
    {
        ll ind = 0;
        ll dum_ans = 0;
        for (auto y : str)
        {
            if (y != x[ind])
                dum_ans++;
            else
                ind ? ind = 0 : ind = 1;
        }
        if (ind == 1)
            dum_ans++;
        ans = min(ans, dum_ans);
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