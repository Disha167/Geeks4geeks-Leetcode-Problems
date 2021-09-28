//Left side view can be intuitively done by level order traversal by pushing the first element of vector of vector of level order traversal.
//But, if we have to do with inorder traversal, we can apply the logic that the first element that occurs on one level will be included in the left view of the tree
//So, we keep a set to keep a track of all the levels we have visited, if we visit a level first time, we push one element and then go on to next level and
//similarly push the element but if we have more than one elements on same level, we dont need to push those so for that purpouse set will be useful.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void help(Tree* root, vector<int> &ans, int level,unordered_set<int>&seen)
{
    if(root==NULL)
       return ;
    if(seen.find(level)==seen.end())
    {
        seen.insert(level);
        ans.push_back(root->val);
    }   
    help(root->left,ans,level+1,seen);   
    help(root->right,ans,level+1,seen);

}
vector<int> solve(Tree* root) {
    vector<int>ans;
    int level=0;
    unordered_set<int>seen;
    help(root,ans,level,seen);
    return ans;
}
