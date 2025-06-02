#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

multimap<ll, ll> lm_num, num_lm;

void solve(int I)
{
    ll i, j, q, k, a, b, m, n, p;
    // solve stars
    cin >> q;
    char ch;
    for (i = 0; i < q; i++)
    {
        cin >> ch >> p;
        if (ch == '+')
        {
            auto it1 = lm_num.find(p);
            if (it1 == lm_num.end())
            {
                num_lm.insert({p, 2 * p});
                lm_num.insert({2 * p, p});
            }
            else
            {
                a = it1->first;
                b = it1->second;
                lm_num.erase(it1);
                lm_num.insert({a + b, b});
            }
        }
    }
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