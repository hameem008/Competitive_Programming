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
    TreeNode *num_to_node[1001];
    vector<int> parrent;
    pair<int, int> range[1001];
    int in_index[1001];
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        parrent.assign(1001, 0);
        for (int i = 0; i < inorder.size(); i++)
        {
            in_index[inorder[i]] = i;
        }
        TreeNode *current_node = nullptr;
        int root;
        for (int i = 0; i < preorder.size(); i++)
        {
            int x = preorder[i];
            TreeNode *new_node = new TreeNode(x);
            num_to_node[x] = new_node;

            if (current_node == nullptr)
            {
                current_node = new_node;
                parrent[x] = -1;
                root = x;
            }

            if (parrent[x] == -1)
            {
                range[x].first = 0;
                range[x].second = inorder.size() - 1;
            }
            else
            {
                if (in_index[x] >= range[current_node->val].first && in_index[x] <= range[current_node->val].second)
                {
                    parrent[x] = current_node->val;
                    if (in_index[x] < in_index[current_node->val])
                    {
                        current_node->left = new_node;
                        range[x].first = range[current_node->val].first;
                        range[x].second = in_index[current_node->val] - 1;
                    }
                    else if (in_index[x] > in_index[current_node->val])
                    {
                        current_node->right = new_node;
                        range[x].first = in_index[current_node->val] + 1;
                        range[x].second = range[current_node->val].second;
                    }
                    current_node = new_node;
                }
                else
                {
                    i--;
                    current_node = num_to_node[parrent[current_node->val]];
                }
            }
        }
        return num_to_node[root];
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    Solution sl;
    vector<int> pre = {5, 3, 1, 2, 4, 6, 7};
    vector<int> in = {1, 2, 3, 4, 5, 6, 7};
    sl.buildTree(pre, in);
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