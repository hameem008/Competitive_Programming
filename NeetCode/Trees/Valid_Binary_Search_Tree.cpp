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
    bool flag = true;
    void dfs(TreeNode *root, int min_val, int max_val)
    {
        if (root->left != nullptr)
        {
            if (root->left->val < root->val && root->left->val > min_val)
                dfs(root->left, min_val, root->val);
            else
                flag = false;
        }
        if (root->right != nullptr)
        {
            if (root->right->val > root->val && root->right->val < max_val)
                dfs(root->right, root->val, max_val);
            else
                flag = false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        if (root != nullptr)
        {
            dfs(root, -101, 101);
        }
        return flag;
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