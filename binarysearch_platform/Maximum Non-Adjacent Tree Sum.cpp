//This is a very good question of tree. 
//A very intersting approach to solve this is to maintain two sums, one including the root and another wihout including root. For the sum including root,
//we add root and the left children's children and right children's children and for the sum excluding root, we tak the max of left children and left children's children
//plus max of right children and right children's children(as we can take only one out of adjacent parent, child). As, we are returning {with_root,without_root}, so
//left[1] and right[1] will have the sum of children's children and left[0] and right[0] will have the sum including root.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int>recurse(Tree* root)
{
    if(root==NULL)
        return{0,0};
    vector<int>left=recurse(root->left);
    vector<int>right=recurse(root->right);
    int with_root=root->val+left[1]+right[1];
    int without_root=max(left[0],left[1])+max(right[0],right[1]);
    return {with_root,without_root};
}
int solve(Tree* root) {
    
    vector<int>ans=recurse(root);
    return max(ans[0],ans[1]);
    
}
