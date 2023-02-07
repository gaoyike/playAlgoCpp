#include "bits/stdc++.h" 
using namespace std;   
/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
 */

// @lc code=start
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
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = depth(root);
        vector<TreeNode*> v;
        find(root, 1, d, v);
        TreeNode* res = root;
        for(auto vv : v)
            res = lca(res, vv);
        return res;
    }

    void find(TreeNode* root, int level, int depth, vector<TreeNode*>& v) {
        if(!root)
            return;
        if(level == depth)
            v.push_back(root);
        find(root->left, level + 1, depth,v);
        find(root->right, level + 1, depth, v);
    }

    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max(depth(root->right), depth(root->left))+1;
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root == p || root == q)
            return root;
        TreeNode* left = lca(root->left,p, q);
        TreeNode* right = lca(root->right ,p, q);
        if(left && right)
            return root;
        else if(left)
            return left;
        else
            return right;
    }
};
// @lc code=end

