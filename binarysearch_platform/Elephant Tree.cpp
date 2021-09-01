//Approach is quite tricky: We want to return the nodes with sum of its left subtreee and right subtree. So, we start the calculation from bottom to top on reaching the
//leaf node, a non-tail recursion of modifies inorder. If the left child was not null, he would add it up to the sum. Similarly, if right child was not null, it would
//be get added to the sum and then that sum would be added to the root's value before returning upwards.


/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
//                   1
//                  / \
//                 2   3
//                / \ / \ 
//               4  5 6  7
//

Tree* solve(Tree* root) {
    if(root==NULL)
       return root;
    int sum=0;   
    Tree* lt=solve(root->left);
    if(lt!=NULL)
        sum+=lt->val;
    Tree* rt=solve(root->right);
    if(rt!=NULL)
        sum+=rt->val;
  //As, we reach 4's child we return 4 to lt , sum becomes 4 then 5 is returned to rt, sum becomes 9.Now, the sum is added to 2 making it 12 and then the root with now
  //value 12 is returned to its caller function i.e. 1's left and so on....
    root->val+=sum;
    return root;        

    
}
