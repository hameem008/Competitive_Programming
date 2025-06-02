#include <bits/stdc++.h>
using namespace std;
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
    vector<pair<ll, ll>> vp;
    set<ll> s;
    for (i = 2; i <= n; i++)
        s.insert(i);
    while (s.size())
    {
        vector<ll> st;
        a = 1;
        b = *s.begin();
        s.erase(s.begin());
        st.push_back(b);
        while (1)
        {
            if (a == b)
                break;
            cout << "?" << gap << a << gap << b << endl;
            cin >> c;
            if (c == a)
            {
                vp.push_back({a, b});
                a = b;
                if (st.size() > 1)
                {
                    st.pop_back();
                    b = st.back();
                }
            }
            else
            {
                if (s.find(c) == s.end())
                {
                    a = c;
                }
                else
                {
                    s.erase(c);
                    st.push_back(c);
                    b = c;
                }
            }
        }
    }
    cout << "!" << gap;
    for (auto x : vp)
        cout << x.first << gap << x.second << gap;
    cout << endl;
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