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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        unordered_map<TreeNode*, TreeNode*>childToParent;
        for(int i = 0;i<descriptions.size();i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isLeft = descriptions[i][2];

            if(nodes.find(parent)==nodes.end()){
                nodes[parent] = new TreeNode(parent);
            }

            
            if(nodes.find(child)==nodes.end()){
                nodes[child] = new TreeNode(child);
            }

            if(isLeft){
                nodes[parent]->left = nodes[child];
            }
            else{
                nodes[parent]->right = nodes[child];
            }

            childToParent[nodes[child]] = nodes[parent];
        }
    TreeNode* root;
    for(auto curr: nodes){
        if(childToParent.find(curr.second)==childToParent.end()){
            root = curr.second;
            break;
        }
    }
    return root;}
};