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
    cin >> n >> m;
    string s;
    cin >> s;
    set<ll> st;
    for (i = 0; i < m; i++)
    {
        cin >> a;
        st.insert(a - 1);
    }
    string t;
    cin >> t;
    multiset<char> ms;
    for (auto x : t)
        ms.insert(x);
    for (auto x : st)
    {
        s[x] = *ms.begin();
        ms.erase(ms.begin());
    }
    cout << s << endl;
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