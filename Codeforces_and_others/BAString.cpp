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
    cin >> n >> k >> p;
    string str;
    cin >> str;
    ll cnt = 0;
    vector<ll> v;
    string str_main;
    for (auto x : str)
    {
        if (x == '*')
        {
            cnt++;
            if (str_main.size() == 0 || str_main.back() != '*')
                str_main.push_back('*');
        }
        else
        {
            if (cnt)
            {
                v.push_back(cnt);
                cnt = 0;
            }
            str_main.push_back(x);
        }
    }
    ll mul = 1;
    for (i = v.size() - 1; i >= 0; i--)
    {
        mul *= v[i];
        if (mul > p)
            break;
    }
    
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