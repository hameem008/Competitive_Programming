#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n), evens, odds;
    for (auto &x : v)
        cin >> x;
    for (auto x : v)
    {
        if (x % 2 == 0)
            evens.push_back(x);
        else
            odds.push_back(x);
    }
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    flag = true;
    ll alice = 0, bob = 0;
    while (n--)
    {
        if (flag)
        {
            if (evens.size() != 0 && odds.size() != 0)
            {
                if (evens.back() > odds.back())
                {
                    alice += evens.back();
                    evens.pop_back();
                }
                else if (evens.back() < odds.back())
                {
                    odds.pop_back();
                }
            }
            else if (evens.size() == 0)
            {
                odds.pop_back();
            }
            else if (odds.size() == 0)
            {
                alice += evens.back();
                evens.pop_back();
            }
            flag = false;
        }
        else
        {
            if (evens.size() != 0 && odds.size() != 0)
            {
                if (evens.size() != 0 && odds.size() != 0)
                {
                    if (evens.back() > odds.back())
                    {
                        evens.pop_back();
                    }
                    else if (evens.back() < odds.back())
                    {
                        bob += odds.back();
                        odds.pop_back();
                    }
                }
                else if (evens.size() == 0)
                {
                    bob += odds.back();
                    odds.pop_back();
                }
                else if (odds.size() == 0)
                {
                    evens.pop_back();
                }
            }
            else if (evens.size() == 0)
            {
                bob += odds.back();
                odds.pop_back();
            }
            else if (odds.size() == 0)
            {
                evens.pop_back();
            }
            flag = true;
        }
    }
    if (alice == bob)
        cout << "Tie" << endl;
    else if (alice > bob)
        cout << "Alice" << endl;
    else if (alice < bob)
        cout << "Bob" << endl;
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