//We have to go through every root to leaf sum and then return the maximum among all at the end. Now, to calculate every root to leaf sum, what we do is that while
//going deep down in inorder recursion, we keep on adding the node's data and when we reach the leaf node, we update the answer. And, while returning i.e. 
//coming up we subtract the same node's value in order to keep track of sum of other paths from root to leaf also. Eg:
//                         1
//                        / \
//                       5   4
//                          / \
//                         7   12
//                        / \
//                       4   8
//On following inorder traversal, we first reach to 1,5 and as we are storing the path's sum, we update the answer to 6 and on returing we subtract 5 as for going
//forward along other paths like 1->4->7->4 and 1->4->12, we need to take 1 as total sum not 6. Similarly, on going down we get 1+4+7+4=16 and update the answer.
//Similarly, on returning back , we subtract 7 and then on calling for right children add 8 to get the updated sum 20.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* inorder(Tree* root, int &curr_sum, int &sum)
{
    if(root==NULL)
       return root;
    curr_sum+=root->val;   
    if(root->left==NULL&&root->right==NULL)
    {
        sum=max(sum,curr_sum);
        return NULL;
    }
    
    inorder(root->left,curr_sum,sum);
    if(root->left)
        curr_sum-=root->left->val;
    // cout<<curr_sum<<" left"<<endl;
    inorder(root->right,curr_sum,sum);
    if(root->right)
        curr_sum-=root->right->val;
    // cout<<curr_sum<<" right"<<endl;
    return NULL;

}
int solve(Tree* root) {
    int curr_sum=0,sum=0;
    inorder(root,curr_sum,sum);
    return sum;
}
