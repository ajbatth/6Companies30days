//                                       https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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
private:
    void fxn(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        fxn(root->left,v);
        v.push_back(root->val);
        fxn(root->right,v);
        
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        fxn(root1,v);
        fxn(root2,v);
        sort(v.begin(),v.end());
        return v;
    }
};
