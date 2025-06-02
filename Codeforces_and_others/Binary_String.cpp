#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> indexOfOne;
vector<ll> prefixZero;
deque<ll> d;

ll current_ans;

bool predicate(ll n)
{
    ll lowinone = 0;
    ll highinone = indexOfOne.size() - n - 1;
    ll loop = n + 1;
    set<ll> s;
    while (loop--)
    {
        s.insert(prefixZero[indexOfOne[highinone]] - prefixZero[indexOfOne[lowinone]]);
        lowinone++;
        highinone++;
    }
    ll zerocnt = *s.begin();
    current_ans = zerocnt > n ? zerocnt : n;
    if (zerocnt <= n)
        return true;
    return false;
}

void solve(int I)
{
    ll i, j, k, m, n, p;
    // solve stars
    indexOfOne.clear();
    prefixZero.clear();
    d.clear();

    string bit;
    cin >> bit;
    for (i = 0; i < bit.size(); i++)
        d.push_back(bit[i] - '0');
    while (!d.back())
    {
        d.pop_back();
        if (d.size() == 0)
            break;
    }
    if (d.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    while (!d.front())
    {
        d.pop_front();
        if (d.size() == 0)
            break;
    }
    for (i = 0; i < d.size(); i++)
    {
        if (d[i] == 1)
            indexOfOne.push_back(i);
    }
    if (d.size() == indexOfOne.size())
    {
        cout << 0 << endl;
        return;
    }
    ll num = 0;
    for (i = 0; i < d.size(); i++)
    {
        if (d[i] == 0)
            num++;
        prefixZero.push_back(num);
    }
    ll high = indexOfOne.size() - 1;
    ll low = 1;
    while (high - low > 1)
    {
        ll mid = (high + low) / 2;
        if (predicate(mid))
            high = mid;
        else
            low = mid + 1;
    }
    if (predicate(low))
        cout << current_ans << endl;
    else if (predicate(high))
        cout << current_ans << endl;
    indexOfOne.clear();
    prefixZero.clear();
    d.clear();
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