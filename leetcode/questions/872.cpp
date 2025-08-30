/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>


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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leafValues1, leafValues2;
        find_leaves(root1, leafValues1);
        find_leaves(root2, leafValues2);
        return leafValues1 == leafValues2;
    }

    void find_leaves(TreeNode* root, std::vector<int>& leafValues) {
        if (!root) {
            return;
        } else if (!root->left && !root->right){
            leafValues.push_back(root->val);
            return;
        }
        find_leaves(root->left, leafValues);
        find_leaves(root->right, leafValues);
        return;
    }
};
