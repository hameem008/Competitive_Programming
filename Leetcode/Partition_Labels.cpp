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
    vector<int> partitionLabels(string s)
    {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        int unq = 0, zero = 0, length = 0;
        for (auto x : s)
            freq[x - 'a']++;
        vector<int> ret;
        for (auto x : s)
        {
            freq[x - 'a']--;
            if (freq[x - 'a'] == 0)
                zero++;
            if (!visited[x - 'a'])
            {
                visited[x - 'a'] = true;
                unq++;
            }
            length++;
            if (unq == zero)
            {
                ret.push_back(length);
                unq = zero = length = 0;
            }
        }
        if (length)
            ret.push_back(length);
        return ret;
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