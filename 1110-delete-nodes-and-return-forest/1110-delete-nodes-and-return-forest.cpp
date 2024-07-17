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
        void traverse(TreeNode* root, vector<TreeNode*>& res, unordered_set<int>& s, TreeNode* parent, bool isLeft) {
        if (root == nullptr) {
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (s.find(root->val) != s.end()) {
            if (root->left != nullptr && s.find(root->left->val) == s.end()) {
                res.push_back(root->left);
            }
            if (root->right != nullptr && s.find(root->right->val) == s.end()) {
                res.push_back(root->right);
            }
            if (parent != nullptr) {
                if (isLeft) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        } else {
            traverse(left, res, s, root, true);
            traverse(right, res, s, root, false);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;

        if (root == nullptr) {
            return res;
        }

        if (s.find(root->val) == s.end()) {
            res.push_back(root);
        }

        traverse(root, res, s, nullptr, true);
        return res;
    }
};

