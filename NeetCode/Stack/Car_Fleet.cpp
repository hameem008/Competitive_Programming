#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        deque<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({position[i], speed[i]});
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        cout << endl;
        int fleet = 0;
        int i = 0;
        while (vp.size())
        {
            n = vp.size();
            if (i + 1 < n)
            {
                if (vp[i].second >= vp[i + 1].second)
                {
                    fleet++;
                    vp.pop_front();
                }
                else
                {
                    long double time_t = abs(vp[i].first - vp[i + 1].first) * 1.0 / abs(vp[i].second - vp[i + 1].second);
                    long double meeting_spot = vp[i].first + time_t * vp[i].second;
                    if (meeting_spot > target)
                    {
                        fleet++;
                        vp.pop_front();
                    }
                    else
                    {
                        pair<int, int> pr = vp[i];
                        vp.pop_front();
                        vp.pop_front();
                        vp.push_front(pr);
                    }
                }
            }
            else
            {
                fleet++;
                vp.pop_front();
            }
        }
        return fleet;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    int target;
    cin >> n >> target;
    vector<int> position(n);
    for (auto &x : position)
        cin >> x;
    vector<int> speed(n);
    for (auto &x : speed)
        cin >> x;
    Solution sl;
    cout << sl.carFleet(target, position, speed) << endl;
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