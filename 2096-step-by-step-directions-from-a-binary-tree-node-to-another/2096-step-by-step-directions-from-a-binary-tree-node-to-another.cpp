class Solution {
public:
    bool find(TreeNode* root, int val, vector<char> &path){
        if(root == nullptr) {
            return false;
        }
        if(root->val == val) {
            return true;
        }
        path.push_back('L');
        if(find(root->left, val, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(find(root->right, val, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> startPath, destPath;
        find(root, startValue, startPath);
        find(root, destValue, destPath);

        int i = 0;
        while(i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }

        string result(startPath.size() - i, 'U');
        for(int j = i; j < destPath.size(); j++) {
            result.push_back(destPath[j]);
        }

        return result;
    }
};