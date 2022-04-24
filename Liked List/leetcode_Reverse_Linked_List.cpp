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
// recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* node = reverseList(head->next)
        head = head->next->next;
        head->next = NULL;
        return node;
    }
};
// iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {

        if(!head || !head->next)
                    return head;

                ListNode* temp = head->next;
                ListNode* prev = head;
                ListNode* after = head->next->next;
                while(after!=NULL)
                {
                    temp->next = prev;
                    prev = temp;
                    temp = after;
                    after = after->next;
                }
                temp->next = prev;
                head->next = NULL;
                return temp;
    }
};