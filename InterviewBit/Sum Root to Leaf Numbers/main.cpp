/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, long long int lastVal, long long int& ans){
    if(A==NULL) return;
    long long int curr = (lastVal*10 + A->val)%1003;
    if(A->left==NULL && A->right==NULL){
        ans = ans + curr;
        ans = ans % 1003;
    }
    else{
        solve(A->left,curr,ans);
        solve(A->right,curr,ans);
    }
}
int Solution::sumNumbers(TreeNode* A) {
    long long int ans = 0;
    solve(A,0,ans);
    return ans%1003;
}
