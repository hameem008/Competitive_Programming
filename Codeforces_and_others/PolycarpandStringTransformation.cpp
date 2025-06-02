#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool isIt(pair<string, string> &sln, string &main_str)
{
    string dum;
    set<char> dont;
    for (auto x : sln.second)
    {
        for (auto y : sln.first)
        {
            if (dont.find(y) == dont.end())
            {
                dum.push_back(y);
            }
        }
        dont.insert(x);
    }
    if (dum == main_str)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    map<char, ll> char_cnt, dum_char_cnt;
    set<char> letters;
    for (auto x : str)
    {
        char_cnt[x]++;
        letters.insert(x);
    }
    vector<pair<string, string>> vstr;
    string dumstr;
    for (auto x : str)
    {
        dumstr.push_back(x);
        dum_char_cnt[x]++;
        flag = true;
        if (char_cnt.size() == dum_char_cnt.size())
        {
            vector<pair<ll, char>> v;
            for (auto x : letters)
            {
                if (char_cnt[x] % dum_char_cnt[x] == 0)
                {
                    v.push_back({char_cnt[x] / dum_char_cnt[x], x});
                }
                else
                {
                    flag = false;
                }
            }
            sort(v.begin(), v.end());
            string rmv;
            for (i = 0; i < v.size(); i++)
            {
                if (v[i].first != i + 1)
                    flag = false;
                rmv.push_back(v[i].second);
            }
            if (flag)
            {
                vstr.push_back({dumstr, rmv});
            }
        }
    }
    for (auto x : vstr)
    {
        if (isIt(x, str))
        {
            cout << x.first << gap << x.second << endl;
            return;
        }
    }
    cout << -1 << endl;
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