// https://leetcode.com/problems/rotate-list/description/

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        
        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        if(!head || len == 1)
            return head;
        temp = head;
        if(k >= len)
        {
            k = k % len;
        }
        if(k==0)
            return head;
        
        int check_point = len - k;
        while(check_point - 1)
        {
            temp = temp->next;
            check_point--;
        }
        ListNode *prev = temp;
        temp = temp->next;
        ListNode* new_temp = temp;
        prev->next = NULL;

        while(new_temp->next)
        {
            new_temp = new_temp->next;
        }
        new_temp->next = head;
        // cout<<"hello"<<endl;
        return temp;
        
        
        
        return head;
    }
};