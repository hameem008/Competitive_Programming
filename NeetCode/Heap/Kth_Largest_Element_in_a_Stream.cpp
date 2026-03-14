#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class KthLargest
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto x : nums)
            pq.push(x);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > k)
            pq.pop();
        return pq.top();
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