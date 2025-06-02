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
    set<ll> greater, less, noteq;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            greater.insert(b);
        }
        else if (a == 2)
        {
            less.insert(b);
        }
        else if (a == 3)
        {
            noteq.insert(b);
        }
    }
    if (greater.size() == 0)
    {
        greater.insert(0);
    }
    if (less.size() == 0)
    {
        less.insert(1e9);
    }
    if (*less.begin() < *greater.rbegin())
    {
        cout << 0 << endl;
    }
    else
    {
        while (noteq.size())
        {
            if (*greater.rbegin() > *noteq.begin())
            {
                noteq.erase(noteq.begin());
            }
            else
                break;
        }
        while (noteq.size())
        {
            if (*less.begin() < *noteq.rbegin())
            {
                noteq.erase(--noteq.end());
            }
            else
                break;
        }
        cout << *less.begin() - *greater.rbegin() - noteq.size() + 1 << endl;
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