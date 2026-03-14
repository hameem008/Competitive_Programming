#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *it = head;
        while (it != nullptr)
        {
            Node *new_node = new Node(it->val);
            mp[it] = new_node;
            it = it->next;
        }
        it = head;
        while (it != nullptr)
        {
            if (it->next != nullptr)
                mp[it]->next = mp[it->next];
            else
                mp[it]->next = nullptr;

            if (it->random != nullptr)
                mp[it]->random = mp[it->random];
            else
                mp[it]->random = nullptr;
            it = it->next;
        }
        return mp[head];
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