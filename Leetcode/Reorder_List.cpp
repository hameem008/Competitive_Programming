#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vector_to_list(vector<int> &v)
{
    ListNode *it = new ListNode();
    ListNode *ans = it;
    for (auto x : v)
    {
        ListNode *new_node = new ListNode(x, nullptr);
        it->next = new_node;
        it = it->next;
    }
    ans = ans->next;
    return ans;
}

void print_list(ListNode *head)
{
    ListNode *it = head;
    while (it != nullptr)
    {
        cout << it->val << gap;
        it = it->next;
    }
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *it = head;
        vector<ListNode *> v_node;
        while (it != nullptr)
        {
            v_node.push_back(it);
            it = it->next;
        }
        int limit = v_node.size();
        int i = 0, j = limit - 1;
        vector<ListNode *> v_node_new;
        for (int k = 0; k < limit; k++)
        {
            if (k % 2 == 0)
            {
                v_node_new.push_back(v_node[i]);
                i++;
            }
            else
            {
                v_node_new.push_back(v_node[j]);
                j--;
            }
        }
        for (int k = 0; k < limit; k++)
        {
            if (k == limit - 1)
            {
                v_node_new[k]->next = nullptr;
            }
            else
            {
                v_node_new[k]->next = v_node_new[k + 1];
            }
        }
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *list = vector_to_list(v);
    print_list(list);
    cout << endl;
    Solution sl;
    sl.reorderList(list);
    print_list(list);
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