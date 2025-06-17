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
    int depth(TreeNode* root){  // Hypothesis that the tree would do just this i.e find the depth
        
        if(root == NULL){
            return  0;
        }

        int lh = depth(root->left); 
        int rh = depth(root->right);
        return 1 + max(lh,rh);
    }

    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};