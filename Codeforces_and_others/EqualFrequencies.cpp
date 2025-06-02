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
    cin >> n;
    string str, check;
    cin >> str;
    check = str;
    vector<ll> v(26, 0);
    for (auto x : str)
        v[x - 'a']++;
    vector<pair<ll, char>> vp;
    map<char, vector<ll>> mp;
    for (i = 0; i < 26; i++)
    {
        mp[i + 'a'];
        vp.push_back({v[i], 'a' + i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    ll min_ans = infinite;
    ll ind;
    for (ll letters = 1; letters <= 26; letters++)
    {
        if (n % letters == 0)
        {
            ll freq = n / letters;
            ll cur_ans = 0;
            for (i = 1; i <= 26; i++)
            {
                if (vp[i - 1].first > freq)
                    cur_ans += vp[i - 1].first - freq;
                if (i > letters)
                    cur_ans += vp[i - 1].first;
            }
            if (cur_ans < min_ans)
            {
                min_ans = cur_ans;
                ind = letters - 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        mp[str[i]].push_back(i);
    }
    ll freq = n / (ind + 1);
    vector<ll> extraind;
    for (i = 0; i < 26; i++)
    {
        if (i <= ind && vp[i].first > freq)
        {
            while (vp[i].first > freq)
            {
                extraind.push_back(mp[vp[i].second].back());
                mp[vp[i].second].pop_back();
                vp[i].first--;
            }
        }
        else if (i > ind)
        {
            if (vp[i].first != 0)
            {
                while (vp[i].first > 0)
                {
                    extraind.push_back(mp[vp[i].second].back());
                    mp[vp[i].second].pop_back();
                    vp[i].first--;
                }
            }
        }
    }
    for (i = 0; i <= ind; i++)
    {
        while (mp[vp[i].second].size() < freq && extraind.size() != 0)
        {
            mp[vp[i].second].push_back(extraind.back());
            extraind.pop_back();
        }
    }
    for (auto x : mp)
    {
        for (auto y : x.second)
        {
            str[y] = x.first;
        }
    }
    ll ans = 0;
    for (i = 0; i < n; i++)
        if (check[i] != str[i])
            ans++;
    cout << ans << endl;
    cout << str << endl;
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