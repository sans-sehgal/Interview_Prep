// https://leetcode.com/problems/add-two-numbers/

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum;
        int carry = 0;
        ListNode* head = NULL, *curr = NULL;
        while(l1 && l2)
        {
            ListNode* n = new ListNode();
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            n->val = sum;
            if(head==NULL)
            {
                head = n;
                curr = n;
                l1 = l1->next;
                l2 = l2->next;
                n->next = NULL;
                continue;
            }
            
            curr->next = n;
            curr = curr->next;
            n->next = NULL;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            ListNode* n = new ListNode();
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = n;
            curr= curr->next;
            n->val = sum;
            n->next = NULL;
            l1 = l1->next;
        }
        while(l2)
        {
            ListNode* n = new ListNode();
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = n;
            curr= curr->next;
            n->val = sum;
            n->next = NULL;
            l2 = l2->next;

        }
        if(carry!=0)
        {
            ListNode* n = new ListNode();
            n->val = carry;
            curr->next = n;
            n->next = NULL;
        }
        return head;
    }
};