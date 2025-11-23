template <class T>
class fenwick_tree
{
private:
    int N;
    vector<T> bit;
    T sum(int r)
    {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

public:
    fenwick_tree() {}
    fenwick_tree(vector<T> &a) { build(a); }
    void build(vector<T> &a)
    {
        N = a.size();
        bit.assign(N, 0);
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    T sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    void add(int pos, int add_val)
    {
        for (; pos < N; pos = pos | (pos + 1))
            bit[pos] += add_val;
    }
};