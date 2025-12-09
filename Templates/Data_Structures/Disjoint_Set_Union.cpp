class dsu
{
private:
    int N = 0;
    vector<int> parrents;
    vector<int> ranks;

public:
    dsu(int n)
    {
        build(n);
    }
    void build(int n)
    {
        clear();
        N = n;
        parrents.assign(n + 1, 0);
        ranks.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parrents[i] = i;
            ranks[i] = 0;
        }
    }
    int Find(int v)
    {
        if (v == parrents[v])
            return v;
        return parrents[v] = Find(parrents[v]);
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            if (ranks[a] < ranks[b])
                swap(a, b);
            parrents[b] = a;
            if (ranks[a] == ranks[b])
                ranks[a]++;
        }
    }
    void clear()
    {
        parrents.clear();
        ranks.clear();
        N = 0;
    }
    ~dsu()
    {
        clear();
    }
};