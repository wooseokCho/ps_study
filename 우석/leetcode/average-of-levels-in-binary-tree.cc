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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> count;
        average(root, 0, result, count);
        for (int i = 0; i < result.size(); i++) {
            result[i] /= count[i];
        }   
        return result;
    }
    
    void average(TreeNode* node, int level, vector<double> &sum, vector<int> &count) {
        if (node == nullptr) return;
        if (level < sum.size()) { 
            sum[level] += node->val;
            count[level] += 1;
        } else {
            sum.push_back(node->val);
            count.push_back(1);
        }
        average(node->left, level + 1, sum, count);
        average(node->right, level + 1, sum, count);
    }
};