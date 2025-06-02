#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, t, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str1, str2;
    cin >> str1 >> str2;
    cin >> t >> q;
    vector<string> vstr;
    vstr.push_back(str1);
    vstr.push_back(str2);
    n = str1.size();
    map<char, set<ll>> mpstr1, mpstr2;
    set<ll> unmatched_pos;
    map<ll, ll> blocked_pos;
    for (i = 0; i < n; i++)
    {
        mpstr1[str1[i]].insert(i);
        mpstr2[str2[i]].insert(i);
        if (str1[i] != str2[i])
            unmatched_pos.insert(i);
    }
    vector<map<char, set<ll>>> vmpstr;
    vmpstr.push_back(mpstr1);
    vmpstr.push_back(mpstr2);
    for (ll curr_time = 1; curr_time <= q; curr_time++)
    {
        if (blocked_pos.size())
        {
            auto it = blocked_pos.begin();
            if (curr_time > it->first)
            {
                unmatched_pos.insert(it->second);
                blocked_pos.erase(it);
            }
        }
        ll op;
        cin >> op;
        if (op == 1)
        {
            cin >> a;
            a--;
            if (unmatched_pos.find(a) != unmatched_pos.end())
            {
                blocked_pos.insert({curr_time + t - 1, a});
                unmatched_pos.erase(a);
            }
        }
        else if (op == 2)
        {
            ll strno1, strno2, pos1, pos2;
            cin >> strno1 >> pos1 >> strno2 >> pos2;
            pos1--, pos2--, strno1--, strno2--;
            vmpstr[strno1][vstr[strno1][pos1]].erase(pos1);
            vmpstr[strno2][vstr[strno2][pos2]].erase(pos2);
            vmpstr[strno1][vstr[strno2][pos2]].insert(pos2);
            vmpstr[strno2][vstr[strno1][pos1]].insert(pos1);
            swap(vstr[strno1][pos1], vstr[strno2][pos2]);
            if (vstr[0][pos1] == vstr[1][pos1])
                unmatched_pos.erase(pos1);
            else
                unmatched_pos.insert(pos1);

            if (vstr[0][pos2] == vstr[1][pos2])
                unmatched_pos.erase(pos2);
            else
                unmatched_pos.insert(pos2);
        }
        else if (op == 3)
        {
            unmatched_pos.size() ? cout << "NO" << endl : cout << "YES" << endl;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}