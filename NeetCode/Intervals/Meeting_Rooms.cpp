#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool is_non_overlap(Interval a, Interval b)
    {
        if (a.start >= b.end || a.end <= b.start)
            return true;
        return false;
    }
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
            return true;
        auto cmp = [](Interval a, Interval b)
        {
            if (a.start < b.start)
                return true;
            else if (a.start > b.start)
                return false;
            else
            {
                if (a.end < b.end)
                    return true;
                else if (a.end > b.end)
                    return false;
                else
                    return true;
            }
        };
        sort(intervals.begin(), intervals.end(), cmp);
        bool flag = true;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (!is_non_overlap(intervals[i], intervals[i + 1]))
                flag = false;
        }
        return flag;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    auto cmp = [](int a, int b)
    {
        if (a > b)
            return false;
        else if (a < b)
            return true;
        else
            return true;
    };
    vector<int> v = {1, 5, 3, 1, 2, 1};
    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
        cout << x << gap;
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