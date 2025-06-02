#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

struct Node
{
    ll value;
    Node() : value(0) {}
};

class segment_tree_2D
{
private:
    ll rows, cols;
    vector<vector<Node>> tree;
    ll combine(ll a, ll b)
    {
        return a + b;
    }
    void buildY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, const vector<vector<ll>> &arr)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = arr[lx][ly];
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            buildY(vx, lx, rx, vy * 2, ly, my, arr);
            buildY(vx, lx, rx, vy * 2 + 1, my + 1, ry, arr);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void buildX(ll vx, ll lx, ll rx, const vector<vector<ll>> &arr)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            buildX(vx * 2, lx, mx, arr);
            buildX(vx * 2 + 1, mx + 1, rx, arr);
        }
        buildY(vx, lx, rx, 1, 0, cols - 1, arr);
    }
    ll queryY(ll vx, ll vy, ll tly, ll try_, ll ly, ll ry)
    {
        if (ly > ry)
            return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy].value;
        ll tmy = (tly + try_) / 2;
        return combine(queryY(vx, vy * 2, tly, tmy, ly, min(ry, tmy)), queryY(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }
    ll queryX(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry)
    {
        if (lx > rx)
            return 0;
        if (lx == tlx && trx == rx)
            return queryY(vx, 1, 0, cols - 1, ly, ry);
        ll tmx = (tlx + trx) / 2;
        return combine(queryX(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry), queryX(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }
    void updateY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, ll x, ll y, ll new_val)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = tree[vx][vy].value ^ new_val;
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            if (y <= my)
                updateY(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                updateY(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void updateX(ll vx, ll lx, ll rx, ll x, ll y, ll new_val)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            if (x <= mx)
                updateX(vx * 2, lx, mx, x, y, new_val);
            else
                updateX(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        updateY(vx, lx, rx, 1, 0, cols - 1, x, y, new_val);
    }

public:
    segment_tree_2D(const vector<vector<ll>> &arr)
    {
        rows = arr.size();
        cols = arr[0].size();
        tree.resize(4 * rows);
        for (ll i = 0; i < 4 * rows; ++i)
            tree[i].resize(4 * cols);
        buildX(1, 0, rows - 1, arr);
    }
    ll query(ll lx, ll rx, ll ly, ll ry)
    {
        return queryX(1, 0, rows - 1, lx, rx, ly, ry);
    }
    void update(ll x, ll y, ll new_val)
    {
        updateX(1, 0, rows - 1, x, y, new_val);
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<vector<ll>> v;
    for (i = 0; i < n; i++)
    {
        vector<ll> dum;
        for (j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                a = 1;
            }
            else if (ch == '.')
            {
                a = 0;
            }
            dum.push_back(a);
        }
        v.push_back(dum);
    }
    segment_tree_2D sg(v);
    for (i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            ll y_, x_;
            cin >> x_ >> y_;
            y_--, x_--;
            sg.update(x_, y_, 1);
        }
        else if (c == 2)
        {
            ll y_1, x_1, y_2, x_2;
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            y_1--, x_1--, y_2--, x_2--;
            cout << sg.query(x_1, x_2, y_1, y_2) << endl;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}