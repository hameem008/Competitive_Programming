#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class TimeMap
{
public:
    map<string, multiset<pair<int, string>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp[key].begin() == mp[key].end())
            return "";
        auto it = mp[key].lower_bound({timestamp, ""});
        if (it == mp[key].end())
            it--;
        if (it != mp[key].begin() && it->first > timestamp)
            it--;
        string ret;
        if (it->first <= timestamp)
            ret = it->second;
        else
            ret = "";
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    TimeMap timeMap;
    timeMap.set("key1", "value1", 10);
    cout << timeMap.get("key1", 1) << endl;
    cout << timeMap.get("key1", 10) << endl;
    cout << timeMap.get("key1", 11) << endl;
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