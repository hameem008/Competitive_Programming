#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    set<ll> indexOfOne, indexOfZero;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        if (p == 1)
            indexOfOne.insert(i);
        else
            indexOfZero.insert(i);
    }
    if (indexOfOne.size() == 0 || indexOfZero.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (indexOfOne.size() == 1)
    {
        if (*indexOfOne.begin() == n - 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }
    if (indexOfZero.size() == 1)
    {
        if (*indexOfZero.begin() == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }
    ll answer = 0;
    ll size = indexOfOne.size() + 1;
    while (size--)
    {
        auto it1 = indexOfOne.begin();
        auto it3 = indexOfZero.end();
        it3--;
        if (n - *it1 == indexOfOne.size())
        {
            break;
        }
        else
        {
            indexOfOne.erase(*it1);
            indexOfOne.insert(*it3);
            indexOfZero.erase(*it3);
            answer++;
        }
        if (n - *indexOfOne.begin() == indexOfOne.size())
        {
            break;
        }
    }
    cout << answer << endl;
    // solve ends
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}