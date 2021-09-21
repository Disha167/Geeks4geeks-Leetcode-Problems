//We have to do this iteratively so the recursion call stack that we were usingwill be transformed into stacks. In recursion, what we were doing was we were going
//to left left deep down untill left becomes null, so we keep on pushing in stack untill left becomes null. Then we cout the ans and call for right child so here
//we will pop from the stack and make curr as right child then again repeating the process by going through another iteration of while loop.
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int>ans;
    Tree*curr=root;
    stack<Tree*>st;
   
    while(!st.empty()||curr!=NULL)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        ans.push_back(curr->val);
        st.pop();
        curr=curr->right;
    }
    return ans;
}
