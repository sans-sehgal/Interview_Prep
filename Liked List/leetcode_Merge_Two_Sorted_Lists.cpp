// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *head;
        ListNode *curr;
        if(!list1 && !list2)
            return NULL;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        int init_flag = 0;
        while(list1 && list2)
        {
            if(init_flag == 0)
            {
                if(list1->val > list2->val)
                {    
                    head = list2;
                    curr = list2;
                    list2 = list2->next;
                }
                else
                {
                    head = list1;
                    curr = list1;
                    list1 = list1->next;
                }
                init_flag = 1;
                continue;
               
            }
             if(list1->val < list2->val)
                {
                    curr->next = list1;
                    curr = curr->next;
                    list1=list1->next;
                    
                }
                else
                {
                    curr->next = list2;
                    curr = curr->next;
                    list2 = list2->next;
                    
                }
        }
        if(list1)
        {
            curr->next = list1;
        }
        else if(list2)
        {
            curr->next = list2;
        }
        return head;
    }
};