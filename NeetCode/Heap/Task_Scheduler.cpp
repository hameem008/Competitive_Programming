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
    int leastInterval(vector<char> &tasks, int n)
    {
        int time = 0;
        queue<int> q;
        priority_queue<int> pq;
        vector<int> freq(26, 0);
        for (auto x : tasks)
            freq[x - 'A']++;
        for (auto x : freq)
            if (x != 0)
                pq.push(x);
        while (1)
        {
            if (pq.size() == 0 && q.size() == 0)
                break;
            if (q.size() == n + 1 || pq.size() == 0)
            {
                int sz = q.size();
                while (q.size())
                {
                    if (q.front() > 0)
                        pq.push(q.front());
                    q.pop();
                }
                if (pq.size())
                    time += n + 1 - sz;
            }
            else
            {
                time++;
                q.push(pq.top() - 1);
                pq.pop();
            }
        }
        return time;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    // tasks = ["X","X","Y","Y"], n = 2
    // tasks = ["A","A","A","B","C"], n = 3
    vector<char> v = {'X', 'X', 'Y', 'Y'};
    n = 2;
    Solution sl;
    cout << sl.leastInterval(v, n) << endl;
    v = {'A', 'A', 'A', 'B', 'C'};
    n = 3;
    cout << sl.leastInterval(v, n) << endl;
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