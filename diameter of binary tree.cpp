//problem link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
int solve(Node *root,int &res)
{
    //base condition
    if(root==NULL)
        return 0;
    //hypothesis
    int left_dia=solve(root->left,res);
    int right_dia=solve(root->right,res);
    //we add 1 to include the node itself before returning it to another parent node
    int when_node_is_not_in_dia=1+max(left_dia,right_dia);
    //when the node is included in diameter of tree, then the diameter is
    //1+left subtree+right subtree
    //We calculate maximum as diameter is the longest path between two leaf nodes
    int ans_for_every_node=max(when_node_is_not_in_dia,1+left_dia+right_dia);
    res=max(ans_for_every_node,res);
    //we return it for the next above node's recursion call to use it
    return when_node_is_not_in_dia;
}
int diameter(Node* node) {
    int count_of_nodes=INT_MIN;
    solve(node,count_of_nodes);
    return count_of_nodes;
    // Your code here
}
