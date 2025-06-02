#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, h, m, n, p, q;
    // solve starts
    cin >> n >> h;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll temph, green, blue, cnt;
    set<ll> ans;
case_1: // 3-2-2
    temph = h, green = 2, blue = 1, cnt = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (temph > v[i])
        {
            temph += v[i] / 2;
            cnt++;
        }
        else if (green == 2 && blue == 1)
        {
            temph *= 3;
            i--;
            blue--;
        }
        else if (green == 2 && blue == 0)
        {
            temph *= 2;
            i--;
            green--;
        }
        else if (green == 1 && blue == 0)
        {
            temph *= 2;
            i--;
            green--;
        }
    }
    ans.insert(cnt);
case_2: // 2-3-2
    temph = h, green = 2, blue = 1, cnt = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (temph > v[i])
        {
            temph += v[i] / 2;
            cnt++;
        }
        else if (green == 2 && blue == 1)
        {
            temph *= 2;
            i--;
            green--;
        }
        else if (green == 1 && blue == 1)
        {
            temph *= 3;
            i--;
            blue--;
        }
        else if (green == 1 && blue == 0)
        {
            temph *= 2;
            i--;
            green--;
        }
    }
    ans.insert(cnt);
case_3: // 2-2-3
    temph = h, green = 2, blue = 1, cnt = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (temph > v[i])
        {
            temph += v[i] / 2;
            cnt++;
        }
        else if (green == 2 && blue == 1)
        {
            temph *= 2;
            i--;
            green--;
        }
        else if (green == 1 && blue == 1)
        {
            temph *= 2;
            i--;
            green--;
        }
        else if (green == 0 && blue == 1)
        {
            temph *= 3;
            i--;
            blue--;
        }
    }
    ans.insert(cnt);
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