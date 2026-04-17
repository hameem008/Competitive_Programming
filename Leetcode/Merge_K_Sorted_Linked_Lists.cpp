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

class Solution
{
public:
    void merge_2_list(ListNode *res, ListNode *l)
    {
        ListNode *it_res = res;
        ListNode *it_l = l;
        while (1)
        {
            if (it_l == nullptr)
                break;
            if (it_res->val > it_l->val)
            {
                ListNode *temp = it_l;
                it_l = it_l->next;
                temp->next = it_res->next;
                it_res->next = temp;
                swap(it_res->val, temp->val);
            }
            it_res = it_res->next;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = new ListNode(-1e4 - 1);
        result->next = new ListNode(1e4 + 1);
        for (int i = 0; i < lists.size(); i++)
        {
            merge_2_list(result, lists[i]);
        }
        ListNode *it = result;
        while (1)
        {
            if (it->next->val == 1e4 + 1)
            {
                it->next = nullptr;
                break;
            }
            it = it->next;
        }
        return result->next;
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