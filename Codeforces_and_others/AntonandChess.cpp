#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
    ll king_x, king_y;
    cin >> king_x >> king_y;
    vector<pair<ll, ll>> rooks, bishops;
    for (i = 0; i < n; i++)
    {
        char ch;
        cin >> ch >> p >> q;
        if (ch == 'B')
            bishops.push_back({p, q});
        else if (ch == 'R')
            rooks.push_back({p, q});
        else if (ch == 'Q')
        {
            bishops.push_back({p, q});
            rooks.push_back({p, q});
        }
    }
    set<ll> upper_right, lower_right, upper_left, lower_left, right, left, up, down;
    for (auto x : rooks)
    {
        if (abs(x.first - king_x) == abs(x.second - king_y))
        {
            if (x.first - king_x > 0 && x.second - king_y > 0)
                lower_right.insert(x.first);
            else if (x.first - king_x < 0 && x.second - king_y > 0)
                upper_right.insert(x.first);
            else if (x.first - king_x > 0 && x.second - king_y < 0)
                lower_left.insert(x.first);
            else if (x.first - king_x < 0 && x.second - king_y < 0)
                upper_left.insert(x.first);
        }
    }
    for (auto x : bishops)
    {
        if (x.first == king_x || x.second == king_y)
        {
            if (x.first == king_x && x.second > king_y)
                right.insert(x.second);
            else if (x.first == king_x && x.second < king_y)
                left.insert(x.second);
            else if (x.first > king_x && x.second == king_y)
                down.insert(x.first);
            else if (x.first < king_x && x.second == king_y)
                up.insert(x.first);
        }
    }
    flag = false;
    for (auto x : bishops)
    {
        if (abs(x.first - king_x) == abs(x.second - king_y))
        {
            if (x.first - king_x > 0 && x.second - king_y > 0)
            {
                if (lower_right.lower_bound(king_x) == lower_right.lower_bound(x.first))
                    flag = true;
            }
            else if (x.first - king_x < 0 && x.second - king_y > 0)
            {
                if (upper_right.lower_bound(king_x) == upper_right.lower_bound(x.first + 1))
                    flag = true;
            }
            else if (x.first - king_x > 0 && x.second - king_y < 0)
            {
                if (lower_left.lower_bound(king_x) == lower_left.lower_bound(x.first))
                    flag = true;
            }
            else if (x.first - king_x < 0 && x.second - king_y < 0)
            {
                if (upper_left.lower_bound(king_x) == upper_left.lower_bound(x.first + 1))
                    flag = true;
            }
        }
    }

    for (auto x : rooks)
    {
        if (x.first == king_x || x.second == king_y)
        {
            if (x.first == king_x && x.second > king_y)
            {
                if (right.lower_bound(king_y) == right.lower_bound(x.second))
                    flag = true;
            }
            else if (x.first == king_x && x.second < king_y)
            {
                if (left.lower_bound(king_y) == left.lower_bound(x.second + 1))
                    flag = true;
            }
            else if (x.first > king_x && x.second == king_y)
            {
                if (down.lower_bound(king_x) == down.lower_bound(x.first))
                    flag = true;
            }
            else if (x.first < king_x && x.second == king_y)
            {
                if (up.lower_bound(king_x) == up.lower_bound(x.first + 1))
                    flag = true;
            }
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}