## Linked List – Important notes and Questions

1) Remember the slow pointer, fast pointer approach:
```
ListNode* middleNode(ListNode* head) 
{

	ListNode* fast = head;
	ListNode* slow = fast;

	while (fast && fast->next) 
	{
	    slow = slow->next;
	    fast = fast->next->next;
	}

	return slow;        
}
```