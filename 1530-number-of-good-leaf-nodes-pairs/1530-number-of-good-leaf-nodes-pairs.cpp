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
    TreeNode* parent;
    int ans = 0;
    vector<int> help(TreeNode* root,int& d){
        vector<int>ret;
        if(root==nullptr){
            return ret;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return {1};
        }
        auto l = help(root->left, d);
        auto r = help(root->right, d);
        for(auto a: l){
            for(auto b: r){
                if(a&&b&&a+b<=d){
                    ans++;
                }
            }      
        }
          for(auto a: l){
            if(a&&a+1<=d){
                ret.push_back(a+1);
            }
        }
        for(auto b: r){
            if(b&&b+1<=d){
                ret.push_back(b+1);
            }
        }
        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        parent = root;
        help(root, distance);
        return ans;
    }
};