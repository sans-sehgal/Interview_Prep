// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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