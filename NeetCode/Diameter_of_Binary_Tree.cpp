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
    int ans = 0;
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth = 0;
        int left_depth = 0, right_depth = 0;
        if (root->left != nullptr)
        {
            left_depth = 1 + maxDepth(root->left);
            depth = max(depth, 1 + left_depth);
        }
        if (root->right != nullptr)
        {
            right_depth = 1 + maxDepth(root->right);
            depth = max(depth, 1 + right_depth);
        }
        ans = max(ans, left_depth + right_depth);
        return depth;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return ans;
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