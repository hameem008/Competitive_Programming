#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '

template <class T>
class segment_tree
{
private:
    int N = 0;
    T *t;
    int root = 1;
    int tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return min(a, b);
    }
    void build(vector<T> &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return INT32_MAX;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(int v, int tl, int tr, int pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    segment_tree()
    {
    }
    segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        build(a, 1, tla, tra);
    }
    T query(int l, int r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(int pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        if (N)
            delete[] t;
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
    {
        if (N)
            clear();
    }
};

class Solution
{
public:
    segment_tree<int> sg;
    bool pf1(int low, int mid, int num)
    {
        return sg.query(low, mid) >= num;
    }
    int find_front_index(int num, int low, int high)
    {
        int ans;
        int hi = high, lo = low, mid;
        while (hi - lo > 1) // TTTTFFF find last true
        {
            mid = (hi + lo) / 2;
            if (pf1(low, mid, num))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (pf1(low, hi, num))
            ans = hi;
        else
            ans = lo;
        return ans;
    }
    bool pf2(int mid, int high, int num)
    {
        return sg.query(mid, high) >= num;
    }
    int find_back_index(int num, int low, int high)
    {
        int ans;
        int hi = high, lo = low, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf2(mid, high, num))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf2(lo, high, num))
            ans = lo;
        else
            ans = hi;
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        sg.build(heights);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (i == 0 || i + 1 == heights.size())
            {
                if (i == 0)
                {
                    int front_ind = find_front_index(heights[i], i, heights.size() - 1);
                    ans = max(ans, (front_ind - i + 1) * heights[i]);
                }
                else
                {
                    int back_ind = find_back_index(heights[i], 0, i);
                    ans = max(ans, (i - back_ind + 1) * heights[i]);
                }
            }
            else
            {
                int front_ind = find_front_index(heights[i], i, heights.size() - 1);
                int back_ind = find_back_index(heights[i], 0, i);
                ans = max(ans, (front_ind - back_ind + 1) * heights[i]);
            }
        }
        return ans;
    }
};

void solve(int I, int T)
{
    int i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Solution sl;
    cout << sl.largestRectangleArea(v) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}