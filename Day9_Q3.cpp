class Solution {
public:
    void inorder(TreeNode *root , vector<int> &inorderVal){
        if(root == NULL)
            return ;
        
        inorder(root->left , inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right , inorderVal);
        
    }
    
    vector<int> mergeArrays(vector<int> &a , vector<int> &b){
        vector<int> ans(a.size() + b.size());
        
        int i = 0 , j = 0 , k = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }
        
        while(i < a.size()){
            ans[k++] = a[i];
            i++;
        }
        
        while(j < b.size()){
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1 , in2;
        inorder(root1 , in1);
        inorder(root2 , in2);
        
        //merge 2 sorted arrays
        vector<int> ans = mergeArrays(in1 , in2);
        return ans;
    }
};