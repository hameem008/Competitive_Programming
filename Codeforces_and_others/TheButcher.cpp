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
    ll area = 0;
    map<ll, multiset<ll>> WidthToHeight, HeightToWidth;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        area += a * b;
        HeightToWidth[a].insert(b);
        WidthToHeight[b].insert(a);
    }
    set<pair<ll, ll>> ans;
    ll canBeHeight = 0, canBeWidth = 0;
    if (area % HeightToWidth.rbegin()->first == 0)
    {
        canBeHeight = HeightToWidth.rbegin()->first;
        ll h = canBeHeight, w = area / canBeHeight;
        map<ll, multiset<ll>> tempWidthToHeight(WidthToHeight.begin(), WidthToHeight.end()), tempHeightToWidth(HeightToWidth.begin(), HeightToWidth.end());
        while (1)
        {
            if (tempHeightToWidth.find(h) != tempHeightToWidth.end())
            {
                auto it = tempHeightToWidth.find(h);
                for (auto x : it->second)
                {
                    w -= x;
                    tempWidthToHeight[x].erase(it->first);
                }

                tempHeightToWidth.erase(it);
            }
            else if (tempWidthToHeight.find(w) != tempWidthToHeight.end())
            {
                auto it = tempWidthToHeight.find(w);
                for (auto x : it->second)
                {
                    h -= x;
                    tempHeightToWidth[x].erase(it->first);
                }
                tempWidthToHeight.erase(it);
            }
            else
                break;
        }
        if (h == 0 || w == 0)
            ans.insert({canBeHeight, area / canBeHeight});
    }
    if (area % WidthToHeight.rbegin()->first == 0)
    {
        canBeWidth = WidthToHeight.rbegin()->first;
        ll h = area / canBeWidth, w = canBeWidth;
        map<ll, multiset<ll>> tempWidthToHeight(WidthToHeight.begin(), WidthToHeight.end()), tempHeightToWidth(HeightToWidth.begin(), HeightToWidth.end());
        while (1)
        {
            if (tempWidthToHeight.find(w) != tempWidthToHeight.end())
            {
                auto it = tempWidthToHeight.find(w);
                for (auto x : it->second)
                {
                    h -= x;
                    tempHeightToWidth[x].erase(it->first);
                }
                tempWidthToHeight.erase(it);
            }
            else if (tempHeightToWidth.find(h) != tempHeightToWidth.end())
            {
                auto it = tempHeightToWidth.find(h);
                for (auto x : it->second)
                {
                    w -= x;
                    tempWidthToHeight[x].erase(it->first);
                }
                tempHeightToWidth.erase(it);
            }
            else
                break;
        }
        if (h == 0 || w == 0)
            ans.insert({area / canBeWidth, canBeWidth});
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.first << gap << x.second << endl;
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