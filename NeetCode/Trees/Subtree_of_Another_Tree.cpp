#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

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
    bool flag = false;
    vector<int> v_subRoot, v_root;
    void isSame()
    {
        if (v_root.size() == v_subRoot.size())
        {
            for (int i = 0; i < v_root.size(); i++)
            {
                if (v_root[i] != v_subRoot[i])
                    return;
            }
            flag = true;
        }
        else
            return;
    }
    void dfs_2(TreeNode *node, vector<int> &v_node)
    {
        if (node == nullptr)
        {
            v_node.push_back(-INT32_MAX);
            return;
        }
        v_node.push_back(node->val);
        dfs_2(node->left, v_node);
        dfs_2(node->right, v_node);
    }
    void dfs(TreeNode *root)
    {
        v_root.clear();
        dfs_2(root, v_root);
        isSame();
        if (root == nullptr)
            return;

        dfs(root->left);
        dfs(root->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        else if (root == nullptr || subRoot == nullptr)
            return false;
        else
        {
            dfs_2(subRoot, v_subRoot);
            dfs(root);
            return flag;
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}