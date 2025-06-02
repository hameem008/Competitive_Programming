#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, num;
    // solve starts
    cin >> q;
    set<ll> s;
    map<ll, ll> mp;
    for (i = 0; i < q; i++)
    {
        string str;
        cin >> str >> num;
        if (str[0] == '+')
        {
            s.insert(num);
            for (j = 1; j <= *(--s.end()) / num; j++)
                if (s.find(j * num) == s.end())
                    break;
            mp.insert({num, j * num});
        }
        else if (str[0] == '?')
        {
            if (mp.find(num) == mp.end())
            {
                cout << num << endl;
            }
            else
            {
                for (j = mp[num] / num; j <= *(--s.end()) / num; j++)
                    if (s.find(j * num) == s.end())
                        break;
                mp[num] = j * num;
                cout << mp[num] << endl;
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

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}