#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<TreeNode *, int> max_link;
    map<TreeNode *, int> max_ans;
    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;
        dfs(node->left);
        dfs(node->right);
        int max_link_left = max_link[node->left];
        int max_lint_right = max_link[node->right];
        max_ans[node] = max({node->val,
                             node->val + max_link_left,
                             node->val + max_lint_right,
                             max_link_left + node->val + max_lint_right});
        max_link[node] = max({node->val,
                              node->val + max_link_left,
                              node->val + max_lint_right});
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        int ret = INT32_MIN;
        for (auto x : max_ans)
        {
            ret = max(ret, x.second);
        }
        return ret;
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