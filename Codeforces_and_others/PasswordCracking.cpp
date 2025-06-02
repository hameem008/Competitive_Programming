#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    ll res;
    bool left = true, right = true;
    deque<ll> dq;
    for (i = 1; i <= n; i++)
    {
        dq.push_back(1);
    }
    cout << "? ";
    for (auto x : dq)
    {
        cout << x;
    }
    cout << endl;
    cin >> res;
    if (res == 1)
    {
        cout << "! ";
        for (auto x : dq)
        {
            cout << x;
        }
        cout << endl;
        return;
    }
    for (auto &x : dq)
    {
        x = 0;
    }
    cout << "? ";
    for (auto x : dq)
    {
        cout << x;
    }
    cout << endl;
    cin >> res;
    if (res == 1)
    {
        cout << "! ";
        for (auto x : dq)
        {
            cout << x;
        }
        cout << endl;
        return;
    }
    dq.clear();
    dq.push_back(0);
    dq.push_back(1);
    cout << "? ";
    for (auto x : dq)
    {
        cout << x;
    }
    cout << endl;
    cin >> res;
    if (res == 0)
    {
        dq.clear();
        dq.push_back(1);
        dq.push_back(0);
    }
    while (dq.size() != n)
    {

        if (left && right)
        {
            dq.push_back(0);
            cout << "? ";
            for (auto x : dq)
            {
                cout << x;
            }
            cout << endl;
            cin >> res;
            if (res == 1)
                continue;
            dq.pop_back();
            dq.push_back(1);
            cout << "? ";
            for (auto x : dq)
            {
                cout << x;
            }
            cout << endl;
            cin >> res;
            if (res == 1)
                continue;
            dq.pop_back();
            right = false;
        }
        else if (left)
        {
            dq.push_front(0);
            cout << "? ";
            for (auto x : dq)
            {
                cout << x;
            }
            cout << endl;
            cin >> res;
            if (res == 1)
                continue;
            else
            {
                dq.pop_front();
                dq.push_front(1);
            }
        }
    }
    cout << "! ";
    for (auto x : dq)
    {
        cout << x;
    }
    cout << endl;
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