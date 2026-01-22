#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<pair<ll, ll>> get_valid_points(pair<ll, ll> &rang, vector<ll> &door_len, ll len, ll max_wide)
{
    ll sum = 0;
    deque<pair<ll, ll>> vp;
    vp.push_back({rang.first, rang.first + max_wide - len});
    for (auto x : door_len)
    {
        sum += x;
        vp.push_back({rang.first + sum, rang.first + sum + max_wide - len});
    }
    vector<pair<ll, ll>> ret;
    while (1)
    {
        if (vp.size() < 2)
        {
            ret.push_back(vp[0]);
            vp.pop_front();
            break;
        }
        pair<ll, ll> pr1 = vp[0], pr2 = vp[1];
        vp.pop_front();
        if (pr1.second >= pr2.first && pr1.second <= pr2.second)
        {
            pair<ll, ll> pr = {pr1.first, pr2.second};
            vp.pop_front();
            vp.push_front(pr);
        }
        else
        {
            ret.push_back(pr1);
        }
    }
    cout << endl;
    return ret;
}

bool cond(ll pnt, pair<ll, ll> rng)
{
    if (pnt >= rng.first && pnt <= rng.second)
        return true;
    else
        return false;
}

bool pf(ll mid, vector<pair<ll, ll>> &v_range, vector<vector<ll>> &v_doors_length, set<pair<ll, ll>> &vs)
{
    vector<pair<ll, ll>> valid_range;
    valid_range.push_back({0, 1e9});
    for (auto it = vs.rbegin(); it != vs.rend(); it++)
    {
        vector<pair<ll, ll>> vp = get_valid_points(v_range[it->second], v_doors_length[it->second], mid, it->first);
        int i = 0, j = 0;
        vector<pair<ll, ll>> dum_valid_range;
        while (1)
        {
            if (i == valid_range.size() || j == vp.size())
                break;
            if (vp[j].second < valid_range[i].first)
            {
                j++;
            }
            else if (valid_range[i].second < vp[j].first)
            {
                i++;
            }
            else if (cond(valid_range[i].first, vp[j]) && cond(vp[j].second, valid_range[i]))
            {
                dum_valid_range.push_back({valid_range[i].first, vp[j].second});
                j++;
            }
            else if (cond(vp[j].first, valid_range[i]) && cond(valid_range[i].second, vp[j]))
            {
                dum_valid_range.push_back({vp[j].first, valid_range[i].second});
                i++;
            }
            else if (cond(vp[j].first, valid_range[i]) && cond(vp[j].second, valid_range[i]))
            {
                dum_valid_range.push_back(vp[j]);
                j++;
            }
            else if (cond(valid_range[i].first, vp[j]) && cond(valid_range[i].second, vp[j]))
            {
                dum_valid_range.push_back(valid_range[i]);
                i++;
            }
        }
        valid_range = dum_valid_range;
    }
    if (valid_range.size())
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<pair<ll, ll>> v_range;
    vector<vector<ll>> v_doors_length;
    set<pair<ll, ll>> max_wide;
    for (i = 0; i < n; i++)
    {
        cin >> m >> p >> q;
        v_range.push_back({p, q});
        vector<ll> v_door_length;
        ll sum = 0;
        for (j = 0; j < m; j++)
        {
            cin >> a;
            v_door_length.push_back(a);
            sum += a;
        }
        v_doors_length.push_back(v_door_length);
        max_wide.insert({q - p - sum, i});
    }
    ll max_space_length = (*max_wide.begin()).first;
    ll hi = max_space_length, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, v_range, v_doors_length, max_wide))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf(hi, v_range, v_doors_length, max_wide))
        cout << hi << endl;
    else if (pf(lo, v_range, v_doors_length, max_wide))
        cout << lo << endl;
    else
        cout << 0 << endl;
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