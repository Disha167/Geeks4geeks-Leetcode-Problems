//FOR DRIVER CODE REFER TO G4G PROBLEM STATEMENT :https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

int height(Node* root)
{
//BASE CONDITION
    if(root==NULL)
        return 0;
    //HYPOTHESIS DESIGN
    int lh=height(root->left);
    int rh=height(root->right);
    //INDUCTION STEP
    return 1+max(lh,rh);

   }
