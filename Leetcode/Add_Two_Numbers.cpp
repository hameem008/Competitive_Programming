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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode(-1);
        auto l1_it = l1;
        auto l2_it = l2;
        auto curr_it = root;
        int carry = 0;
        while (1)
        {
            if (l1_it == nullptr && l2_it == nullptr)
            {
                if (carry)
                {
                    ListNode *node = new ListNode(carry);
                    curr_it->next = node;
                }
                break;
            }
            int sum = carry;
            if (l1_it != nullptr)
            {
                sum += l1_it->val;
                l1_it = l1_it->next;
            }
            if (l2_it != nullptr)
            {
                sum += l2_it->val;
                l2_it = l2_it->next;
            }
            carry = sum / 10;
            sum %= 10;
            if (curr_it->val == -1)
                curr_it->val = sum;
            else
            {
                ListNode *node = new ListNode(sum);
                curr_it->next = node;
                curr_it = curr_it->next;
            }
        }
        return root;
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