/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool search(TreeNode* root, TreeNode* node, vector<TreeNode*>&a){
        if(root==nullptr){
            return false;
        }
        if(node==root){
            a.push_back(node);
            return true;
        }
        a.push_back(root);
        if(search(root->left,node,a)){
            return true;
        }
        if(search(root->right,node, a)){
            return true;
        }
        a.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>first_an;
        vector<TreeNode*>second_an;

        search(root, p, first_an);
        search(root, q, second_an);
        TreeNode* res = root;
        for(int i = 0;i<first_an.size()&&i<second_an.size();i++){
            if(first_an[i]!=second_an[i]){
                return res;
            }
            res = first_an[i];
        }
        return res;
    }
};