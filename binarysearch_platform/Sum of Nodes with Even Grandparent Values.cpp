//We keep the track of grandparent and parent for every node, at every node when we go deep, we update the parent as root and grandparent as parent, and if the 
//grandparent is even, then we add the node.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void inorder(Tree* root, Tree* parent, Tree* grandparent, int &ans)
{
    if(root==NULL)
        return;
    inorder(root->left,root,parent,ans);
    inorder(root->right,root,parent,ans);
    if(grandparent!=NULL&&grandparent->val%2==0)
        ans+=root->val;    
    return;    
} 
int solve(Tree* root) {
    int ans=0;
    Tree*parent=NULL,*grandparent=NULL;
    inorder(root,parent,grandparent,ans);
    return ans;
    
}
