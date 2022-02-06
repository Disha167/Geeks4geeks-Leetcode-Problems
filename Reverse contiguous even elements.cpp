// Problem Description
// Given a singly linked list of integers, reverse every contiguous set of nodes that have only even values.

// Input format
// N - An integer denoting the number of nodes in the linked list.

// N integers follow where ith integer denotes the ith node value in the linked list

// Output format
// Return the head of the modified list

// Constraints
// 0 <= N <= 10^5

// -10^9 <= value <= 10^9

// Sample Input 1
// 8

// 1 2 3 3 4 6 8 5

// Sample Output 1
// 1 2 3 3 8 6 4 5

// Explanation 1
// There are two sublists of even elements, which [2] and [4->6->8]. The sublist [4->6->8] has been reversed and the single sublist [2] need not be reversed.

// Sample Input 2
// 6

// 1 3 2 5 4 6

// Sample Output 2
// 1 3 2 5 6 4

// Explanation 2
// There are two sublists of even elements which are [2] and [4 6]. The [4,6] sublist has been reversed and the single sublist [2] need not be reversed. Rest of the odd values remain constant.

//SOLUTION:
/*We create a seperate function for reversing the linked list that contains even elements, the head & tail of the linked list is passed to that function and then 
after reversing the list is attached to the original list*/
pair<ListNode*,ListNode*> reverse_even(ListNode* start, ListNode* end)
 {
	pair<ListNode*,ListNode*> ans;
	ListNode *curr=start,*prev=NULL, *nextNode=NULL;
	ans.second=curr;
	end->next=NULL;
  /*we have to keep on reversing untill curr is not NULL as the link of last element also needs to be changesd so we first make end->next NULL before starting reversal*/
	while(curr!=NULL)
	{
		nextNode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextNode;
	}
	ans.first=prev;

	return ans;
 }

ListNode * reverseEvenElements(ListNode *head) {
	if(head==NULL) return NULL;
	ListNode *new_head=NULL;
	if(head->val%2!=0) new_head=head;
	ListNode *curr=head,*prev=NULL;
	while(curr!=NULL)
	{
		if(curr->val%2==0)
		{
			ListNode *evenhead=curr;
			ListNode *eventail;
			while(curr!=NULL&&curr->val%2==0)
			{
				eventail=curr;
				// prev=curr; /*the prev is not updated here as we have to attach the even list to the non-even list*/
				curr=curr->next;
			}
			pair<ListNode*,ListNode*>ans=reverse_even(evenhead,eventail);
			/*if the first element of list is even, then new_head returned needs to be updated after reversing*/
			if(new_head==NULL) 
			new_head=ans.first;
      /*Now , we have to attach the reversed list to our original list.*/
			if(prev!=NULL)
			{
				prev->next=ans.first;
			}
           
			ans.second->next=curr;
		}
		else 
		{
      /*we will update the prev everytime it is odd, as we want prev for attaching it to the even list*/
			prev=curr;
		    curr=curr->next;
		}
	}
	return new_head;
}
