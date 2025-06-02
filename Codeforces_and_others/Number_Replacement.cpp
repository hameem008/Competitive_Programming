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
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string str;
    cin >> str;
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    multimap<ll, char> mm;
    for (i = 0; i < n; i++)
    {
        mm.insert({v[i], str[i]});
    }
    auto it2 = mm.begin();
    it2++;
    for (auto it1 = mm.begin(); it1 != mm.end(); it1++)
    {
        if (it1->first == it2->first)
        {
            if (it1->second != it2->second)
            {
                cout << "NO" << endl;
                return;
            }
        }
        it2++;
        if (it2 == mm.end())
        {
            break;
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

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}