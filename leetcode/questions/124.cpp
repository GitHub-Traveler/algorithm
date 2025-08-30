#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    struct result {
        int max = INT_MIN;
        int maxToRoot = INT_MIN;
    };

    int maxPathSum(TreeNode *root) { return helper(root).max; }

    result helper(TreeNode *root) {
        result left, right;
        if (root->left != nullptr)
            left = helper(root->left);
        if (root->right != nullptr)
            right = helper(root->right);
        result current;
        unsigned int ll0 = 1, rl0 = 1;
        if (left.maxToRoot < 0)
            ll0 = 0;
        if (right.maxToRoot < 0)
            rl0 = 0;
        int max_through_root = ll0 * left.maxToRoot + rl0 * right.maxToRoot + root->val;
        current.max = max(max(max_through_root, left.max), right.max);
        if (left.maxToRoot > 0 || right.maxToRoot > 0)
            current.maxToRoot =
                (left.maxToRoot > right.maxToRoot) ? root->val + left.maxToRoot : root->val + right.maxToRoot;
        else
            current.maxToRoot = root->val;
        return current;
    }
};