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
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> s;
        while (head != nullptr)
        {
            int sz = s.size();
            s.insert(head);
            if (s.size() == sz)
                return true;
            head = head->next;
        }
        return false;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v = {1, 2, 3};
    ListNode *list = vector_to_list(v);
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