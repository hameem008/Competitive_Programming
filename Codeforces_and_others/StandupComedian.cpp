#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    ll type_1, type_2, type_3, type_4;
    cin >> type_1 >> type_2 >> type_3 >> type_4;
    // cout << type_1 << gap << type_2 << gap << type_3 << gap << type_4 << gap;
    ll ans = 0;
    ll mood = type_1;
    ans += type_1;
    if (type_1 != 0)
    {
        if (type_2 > type_3)
        {
            ans += 2 * type_3;
            type_2 -= type_3;
            type_3 = 0;
            if (mood > (type_2 + type_4))
            {
                ans += (type_2 + type_4);
            }
            else if (mood < (type_2 + type_4))
            {
                ans += mood + 1;
            }
            else
            {
                ans += mood;
            }
        }
        else
        {
            ans += 2 * type_2;
            type_3 -= type_2;
            type_2 = 0;
            if (mood > (type_3 + type_4))
            {
                ans += (type_3 + type_4);
            }
            else if (mood < (type_3 + type_4))
            {
                ans += mood + 1;
            }
            else
            {
                ans += mood;
            }
        }
    }
    else
    {
        if (type_2 || type_3 || type_4)
            ans++;
    }
    // cout << "ans: " << gap << ans << endl;
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