#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    deque<char> d(str.begin(), str.end());
    flag = false;
    for (auto x : d)
    {
        if (x == '0')
        {
            flag = true;
        }
    }
    if (!flag)
    {
        n = d.size();
        cout << n * n << endl;
    }
    else
    {
        while (d.back() == '1' && d.front() == '1')
        {
            d.push_front(d.back());
            d.pop_back();
        }
        ll n = 0;
        ll start = 0, end = 0;
        for (i = 0; i < d.size(); i++)
        {
            if (d[i] == '1')
            {
                end++;
            }
            else
            {
                if (n < end - start)
                    n = end - start;
                start = i + 1;
                end = i + 1;
            }
        }
        if (n < end - start)
        {
            n = end - start;
        }
        if (n == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            n++;
            if (n % 2 == 0)
            {
                cout << n / 2 * n / 2 << endl;
            }
            else
            {
                cout << (n / 2) * (n / 2 + 1) << endl;
            }
        }
    }
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