//You can find the kth smallest element using the property of binary search tree that on left, all the element are smaller than the root and on right, all the 
//elements are greater than root. In inorder traversal, all the elements appear in sorted order in a binary search tree. So, we can keep a count after returning
//of every left call and whenever the count becomes 0, then update our result. 
//Note that k should be passed with address to keep track of changed value every time.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void help(Tree* root, int &ans,int &k)
{
    if(root==NULL)
        return;
    help(root->left,ans,k); 
    if(k==0&&ans==INT_MAX)
    {
        ans=root->val;
        return;
    }
    k--;
    help(root->right,ans,k);     
 
} 
int solve(Tree* root, int k){
    int ans=INT_MAX;
    help(root,ans,k);
    if(ans==INT_MAX)
        return root->val;
    return ans;
}
