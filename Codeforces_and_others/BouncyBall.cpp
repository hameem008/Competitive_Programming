#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll di, dj, si, sj, ans = 0;
    string op;
    cin >> n >> m >> si >> sj >> di >> dj >> op;
    pair<ll, ll> destination = {di, dj}, source = {si, sj}, previous = source, present = source, next = {-1, -1};
    vector<pair<ll, ll>> vp;
    vp.push_back(present);
    i = 2 * m * n;
    while (i--)
    {
        if (op == "UL")
        {
            next.first = present.first - 1;
            next.second = present.second - 1;
        }
        else if (op == "UR")
        {
            next.first = present.first - 1;
            next.second = present.second + 1;
        }
        else if (op == "DL")
        {
            next.first = present.first + 1;
            next.second = present.second - 1;
        }
        else if (op == "DR")
        {
            next.first = present.first + 1;
            next.second = present.second + 1;
        }

        vp.push_back(next);

        previous = present;
        present = next;

        if (present.first < 1 || present.first > n)
        {
            if (present.first < 1)
                op[0] = 'D';
            if (present.first > n)
                op[0] = 'U';
        }
        if (present.second < 1 || present.second > m)
        {
            if (present.second < 1)
                op[1] = 'R';
            if (present.second > m)
                op[1] = 'L';
        }

        if (present.first < 1 || present.first > n || present.second < 1 || present.second > m)
        {
            present = previous;
        }
    }
    flag = false;
    for (i = 0; i < vp.size() - 1; i++)
    {
        if (destination == vp[i])
        {
            flag = true;
            break;
        }
        if (vp[i].first < 1 || vp[i].first > n || vp[i].second < 1 || vp[i].second > m)
            ans++;
    }
    flag ? cout << ans << endl : cout << -1 << endl;
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