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
    void rec(vector<pair<int,int>>& res, TreeNode* root,int level){
        if(root==nullptr){
            return;
        }
        res.push_back(make_pair(level,root->val));
        rec(res,root->left, level+1);
        rec(res,root->right, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<pair<int, int>>res;
        map<int, int>m;
        vector<int>ans;
        rec(res, root,0);
        for(auto it: res){
            m[it.first] = it.second;
        }
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};