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
    string str;
    cin >> str;
    ll curr_length = 0, sorted_length = 0;
    set<ll> unsorted;
    for (auto x : str)
    {
        if (x == '+')
        {
            curr_length++;
            if (curr_length == 1)
            {
                sorted_length = 1;
            }
        }
        else if (x == '-')
        {
            curr_length--;
            auto it = unsorted.end();
            if (unsorted.size() != 0)
            {
                it--;
                if (*it > curr_length)
                {
                    unsorted.erase(it);
                }
            }
            if (curr_length < sorted_length)
            {
                sorted_length = curr_length;
            }
        }
        else if (x == '0')
        {
            if (curr_length == sorted_length)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                unsorted.insert(curr_length);
            }
        }
        else if (x == '1')
        {
            if (unsorted.size() != 0)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                sorted_length = curr_length;
            }
        }
    }
    cout << "YES" << endl;
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