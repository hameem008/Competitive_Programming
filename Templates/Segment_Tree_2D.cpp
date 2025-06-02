struct Node
{
    ll value;
    Node() : value(0) {}
    // for min--> value(INT32_MAX);
    // for max--> value(INT32_MIN);
    // for gcd--> value(0);
    // for xor--> value(0);
};

class segment_tree_2D
{
private:
    ll rows, cols;
    vector<vector<Node>> tree;
    ll combine(ll a, ll b)
    {
        return a + b;
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
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
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy].value;
        ll tmy = (tly + try_) / 2;
        return combine(queryY(vx, vy * 2, tly, tmy, ly, min(ry, tmy)), queryY(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }
    ll queryX(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry)
    {
        if (lx > rx)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
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
                tree[vx][vy].value = new_val;
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