//We follow the same approach as on reversing the linked list, maintain 3 pointers prev, curr and next and keep on updating them as moving forward. There are two 
//conditions that might require some time to think: once we have swapped the first two nodes, then before going on to the next pair and updating the prev, curr and 
//next again we have to make sure that our prev is connected to the node->next i.e. the now 2nd node of the 1st pair is connected to the prev node of 2nd pair
//i.e. if we have 1->2->3->4
//we make sure that after swapping 2->1 3->4, we make sure that 1 is connected to 4 before pairwise swapping 4 and 3.
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    LLNode* prev=NULL, *next_node=NULL;
    if(node==NULL||node->next==NULL)
        return node;
    LLNode* new_head=node->next;
    while(node!=NULL&&node->next!=NULL)
    {
        if(node!=NULL&&node->next!=NULL&&prev!=NULL)
            prev->next=node->next;
        prev=node;
        next_node=node->next;
        node=node->next->next;  
        next_node->next=prev;
        if(node!=NULL&&node->next==NULL)//if the length of linked list is odd, so the last node do not forms tha pair so before exiting the while loop , we connect
          //the pairwise swapped node to the last node i.e. in 1->2->3
          //Once we have swapped 2->1 3, we connect 2->1->3 before getting out of loop
        prev->next=node;
              
    }
    if(node==NULL) //imp to make the tail's next node NULL to avoid infinite loop(REMEMBER!!!!!!!!!!!!!!!!)
    prev->next=NULL;
    return new_head;

}
