#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class LRUCache
{
public:
    int capacity = 0;
    list<int> ls_order;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> key_iterator;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        auto key_it = key_iterator.find(key);
        ls_order.erase(key_it->second);
        ls_order.push_back(key);
        key_it->second = --ls_order.end();
        return it->second;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            ls_order.push_back(key);
            key_iterator.insert({key, --ls_order.end()});
            cache.insert({key, value});
            if (cache.size() > capacity)
            {
                cache.erase(cache.find(*ls_order.begin()));
                key_iterator.erase(key_iterator.find(*ls_order.begin()));
                ls_order.erase(ls_order.begin());
            }
        }
        else
        {
            auto key_it = key_iterator.find(key);
            ls_order.erase(key_it->second);
            ls_order.push_back(key);
            key_it->second = --ls_order.end();
            it->second = value;
        }
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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