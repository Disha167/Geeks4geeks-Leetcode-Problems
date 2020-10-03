//FUNCTION PROBLEM
//Problem Link: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
//The idea is to change the value of answer if needed at every step then keep
//returning the final value of ans from leaf node to root node
//I.e. no calculation occurs while returning to recursion calls, only the returning step
//occurs, the idea is somewhat similar to tail recursion

int helper(Node *root, int input, int &ans)
{
    //using the below first three if conditions to determine the value of ans at
    //every step of recursion call stack
    if (root == NULL)
        return -1;
    if(root->data==input)
        ans=input;
    if(root->data>input&&root->data<ans)
        ans=root->data;
    if(root->data<input)
        helper(root->right,input,ans);
    if (root->data>input)
        helper(root->left,input,ans);
    👀 👀//while backtracking from the leaf node, returning the ans value got at
    //the end to the previous recursion call stacks
    return ans;
}
// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
int findCeil(Node* root, int input)
{
    int ans=INT_MAX;
    int result=helper(root,input,ans);
    ⭐️⭐️//for no value greater than the input value found
    if(result==INT_MAX)
        return -1;
    else
        return result;
    // Base case

    // Your code here
}
