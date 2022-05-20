// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head, *slow = head;
        int count = 1;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            count++;
        }
        int total_nodes = 0;
        if(fast)
        {
            total_nodes = 2 * count - 1;
        }
        else if(!fast)
        {
            
            total_nodes = 2*(count-1);
        }
        int n_front = total_nodes - n + 1;
        // handles case where only one node is present in the ll
        if(total_nodes == 1)
        {
            if(n==1)
                return NULL;
            else
                return head;
        }
        if(n_front == 1)
            return head->next;
        if(n_front-1 > count)
        {
            while(n_front-1 > count)
            {
                slow = slow->next;
                count++;
            }
            slow->next = slow->next->next;
            return head;
        }
        else if(n_front -1 == count)
        {
            slow->next = slow->next->next;
            return head;
        }
        else if(n_front - 1 < count)
        {
            ListNode* temp = head;
            count = 1;
            while(count != n_front - 1)
            {
                temp = temp->next;
                count++;
            }
            temp->next = temp->next->next;
            return head;
        }
        return NULL;
    }
};