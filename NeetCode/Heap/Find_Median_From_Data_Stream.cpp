#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (max_q.size() == 0 && min_q.size() == 0)
            max_q.push(num);
        else if (max_q.size() == 0)
            min_q.push(num);
        else if (min_q.size() == 0)
            max_q.push(num);
        else
        {
            if (num <= max_q.top())
                max_q.push(num);
            else if (num >= min_q.top())
                min_q.push(num);
            else
                max_q.push(num);
        }
        while (1)
        {
            int max_size = max_q.size();
            int min_size = min_q.size();
            if (max_size - min_size > 1)
            {
                min_q.push(max_q.top());
                max_q.pop();
            }
            else if (min_size - max_size > 1)
            {
                max_q.push(min_q.top());
                min_q.pop();
            }
            else
                break;
        }
    }

    double findMedian()
    {
        if (max_q.size() > min_q.size())
            return max_q.top() * 1.0;
        else if (max_q.size() < min_q.size())
            return min_q.top() * 1.0;
        else
            return (max_q.top() + min_q.top()) * 1.0 / 2;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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