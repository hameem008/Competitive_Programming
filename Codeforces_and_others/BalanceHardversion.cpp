#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, af, num;
    // solve starts
    cin >> q;
    set<ll> s;
    s.insert(0);
    set<ll> removed;
    map<ll, ll> mp;
    map<ll, set<ll>> rm;
    for (i = 0; i < q; i++)
    {
        string str;
        cin >> str >> num;
        if (str[0] == '+')
        {
            s.insert(num);
            removed.erase(num);
            for (auto &x : rm)
            {
                x.second.erase(num);
            }
            for (j = 1; j <= *(--s.end()) / num; j++)
                if (s.find(j * num) == s.end())
                    break;
            if (mp.find(num) != mp.end())
                mp[num] = j * num;
            else
                mp.insert({num, j * num});
        }
        else if (str[0] == '?')
        {
            set<ll> faka;
            if (rm.find(num) == rm.end())
                rm.insert({num, faka});
            if (mp.find(num) == mp.end())
            {
                cout << num << endl;
            }
            else if (rm[num].size() != 0)
                cout << *rm[num].begin() << endl;
            else
            {
                for (j = mp[num] / num; j <= *(--s.end()) / num; j++)
                    if (s.find(j * num) == s.end())
                        break;
                mp[num] = j * num;
                cout << mp[num] << endl;
            }
        }
        else
        {
            removed.insert(num);
            s.erase(num);
            mp.erase(num);
            for (auto &x : rm)
            {
                if (x.first < num)
                {
                    if (num % x.first == 0 && num < mp[x.first])
                        x.second.insert(num);
                }
                else
                    break;
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