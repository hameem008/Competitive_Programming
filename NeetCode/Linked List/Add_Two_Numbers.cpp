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
        int num_1 = 0, num_2 = 0;
        ListNode *it = l1;
        int cnt = 0;
        while (it != nullptr)
        {
            num_1 += it->val * pow(10, cnt);
            it = it->next;
            cnt++;
        }
        cnt = 0;
        it = l2;
        while (it != nullptr)
        {
            num_2 += it->val * pow(10, cnt);
            it = it->next;
            cnt++;
        }
        int answer = num_1 + num_2;
        ListNode *root = new ListNode();
        it = root;
        while (1)
        {
            it->val = answer % 10;
            answer /= 10;
            if (answer == 0)
                break;
            it->next = new ListNode();
            it = it->next;
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