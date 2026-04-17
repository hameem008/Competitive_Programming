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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *it1 = list1, *it2 = list2;
        ListNode *it = new ListNode();
        it->next = nullptr;
        ListNode *ans = it;
        while (1)
        {
            if (it1 == nullptr && it2 == nullptr)
                break;
            else if (it1 == nullptr)
            {
                ListNode *new_node = new ListNode();
                new_node->val = it2->val;
                new_node->next = nullptr;
                it->next = new_node;
                it = it->next;
                it2 = it2->next;
            }
            else if (it2 == nullptr)
            {
                ListNode *new_node = new ListNode();
                new_node->val = it1->val;
                new_node->next = nullptr;
                it->next = new_node;
                it = it->next;
                it1 = it1->next;
            }
            else if (it1->val > it2->val)
            {
                ListNode *new_node = new ListNode();
                new_node->val = it2->val;
                new_node->next = nullptr;
                it->next = new_node;
                it = it->next;
                it2 = it2->next;
            }
            else if (it1->val < it2->val)
            {
                ListNode *new_node = new ListNode();
                new_node->val = it1->val;
                new_node->next = nullptr;
                it->next = new_node;
                it = it->next;
                it1 = it1->next;
            }
            else
            {
                ListNode *new_node1 = new ListNode();
                new_node1->val = it2->val;
                new_node1->next = nullptr;
                it->next = new_node1;
                it = it->next;
                it2 = it2->next;

                ListNode *new_node2 = new ListNode();
                new_node2->val = it1->val;
                new_node2->next = nullptr;
                it->next = new_node2;
                it = it->next;
                it1 = it1->next;
            }
        }
        ans = ans->next;
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {1, 3, 5};
    ListNode *list1 = vector_to_list(v1);
    ListNode *list2 = vector_to_list(v2);
    Solution sl;
    ListNode *list = sl.mergeTwoLists(list1, list2);
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