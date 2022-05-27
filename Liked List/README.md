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
2) To detect a cycle, use slow pointer, fast pointer approach until they become equal or fast reaches NULL.
3) To find out at which point the cycle exists, change the fast pointer to head, keep incrementing both fast and slow until they meet.
```
ListNode* cycleExists(ListNode * head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return slow;
    }
    return NULL;
}
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = cycleExists(head);
        if(slow!=NULL)
        {
            while(slow!=head)
            {
                slow = slow->next;
                head = head->next;
            }
        }
        return slow;
    }
};
```
4) In an unordered_map, the key cannot be a vector, as the hashtable will give some errors during compilation. Keep in mind! In a simple map, it will work. In an unordered map, search is O(1), in a map, it is O(logn). 
