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
    int depth = 0;
    int returnDepth = 0;
    TreeNode * rootNode;
    int maxDepth(TreeNode* root) {
        rootNode = root;
        preorderTraversal(root);
        return returnDepth;
    }

    void preorderTraversal(TreeNode* treeNode) {
        if(treeNode == NULL) return;
        depth ++;
        returnDepth = max(depth, returnDepth);
        preorderTraversal(treeNode->left);
        preorderTraversal(treeNode->right);
        depth --;
    }
};