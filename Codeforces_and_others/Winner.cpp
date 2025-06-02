#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    map<string, ll> mp;
    vector<pair<string, ll>> v;
    for (i = 0; i < n; i++)
    {
        string str;
        cin >> str >> a;
        v.push_back({str, a});
        auto it = mp.find(str);
        if (it != mp.end())
        {
            it->second += a;
        }
        else
        {
            mp.insert({str, a});
        }
    }
    ll max_pt = 0;
    for (auto x : mp)
    {
        if (x.second > max_pt)
            max_pt = x.second;
    }
    set<string> pos_winner;
    for (auto x : mp)
    {
        if (x.second == max_pt)
            pos_winner.insert(x.first);
    }
    mp.clear();
    string winner;
    for (auto x : v)
    {
        auto it = mp.find(x.first);
        if (it != mp.end())
        {
            it->second += x.second;
            if (it->second >= max_pt && pos_winner.find(it->first) != pos_winner.end())
            {
                winner = it->first;
                break;
            }
        }
        else
        {
            mp.insert({x.first, x.second});
            if (x.second >= max_pt && pos_winner.find(x.first) != pos_winner.end())
            {
                winner = x.first;
                break;
            }
        }
    }
    cout << winner << endl;
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