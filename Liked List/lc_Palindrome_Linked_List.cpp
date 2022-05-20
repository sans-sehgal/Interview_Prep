// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* reverse(ListNode* head)
{
    ListNode *curr = head->next;
    ListNode *prev = NULL;
    while(head!=NULL)
    {
        head->next = prev;
        prev = head;
        head = curr;
        if(curr)
            curr = curr->next;
        
    }
    return prev;
}
void printList(ListNode* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow = head , *fast = head;
        if(!head || !head->next)
            return true;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        // cout<<slow->val<<endl;
        // printList(head);
        while(head && slow)
        {
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};