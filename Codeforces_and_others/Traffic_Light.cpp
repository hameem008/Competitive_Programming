#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;
    set<ll> red, green, yellow;
    for (i = 0; i < n; i++)
    {
        if (str[i] == 'r')
            red.insert(i + 1);
        else if (str[i] == 'g')
            green.insert(i + 1);
        else
            yellow.insert(i + 1);
    }
    set<ll> ans;
    if (ch == 'r')
    {
        auto it = red.begin();
        for (; it != red.end(); it++)
        {
            auto IT = green.upper_bound(*it);
            if (IT != green.end())
                ans.insert(*IT - *it);

            else
                ans.insert(n - *it + *green.begin());
        }
        auto ITA = ans.end();
        ITA--;
        cout << *ITA << endl;
    }
    else if (ch == 'y')
    {
        auto it = yellow.begin();
        for (; it != yellow.end(); it++)
        {
            auto IT = green.upper_bound(*it);
            if (IT != green.end())
                ans.insert(*IT - *it);

            else
                ans.insert(n - *it + *green.begin());
        }
        auto ITA = ans.end();
        ITA--;
        cout << *ITA << endl;
    }
    else
        cout << 0 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}