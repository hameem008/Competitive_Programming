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
    vector<int> v;
    void bfs(TreeNode *root)
    {
        vector<TreeNode *> que, temp;
        que.push_back(root);
        while (que.size())
        {
            vector<int> v_val;
            for (int i = 0; i < que.size(); i++)
            {
                if (que[i] != nullptr)
                {
                    v_val.push_back(que[i]->val);
                    temp.push_back(que[i]->left);
                    temp.push_back(que[i]->right);
                }
            }
            que = temp;
            temp.clear();
            if (v_val.size())
                v.push_back(v_val.back());
        }
    }
    vector<int> rightSideView(TreeNode *root)
    {
        bfs(root);
        return v;
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