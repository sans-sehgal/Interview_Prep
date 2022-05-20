// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

ListNode* reverseNodes(ListNode* begin , ListNode* end)
{
    ListNode* prev = NULL;
    ListNode* curr = begin->next;
    ListNode* tail = begin;
    while(prev!=end)
    {
        begin->next = prev;
        prev = begin;
        begin = curr;
        if(curr)
            curr=curr->next;
    }
    tail->next = begin;
    return end;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // ListNode* begin = head;
        int flag = 0;
        ListNode* end = head;
        ListNode* begin = head;
        if(k==1)
            return head;
        int count = 0;
        while(end)
        {
            int temp = flag==0?k-1:k;
            ListNode* prev_end = head;
            begin = head;
            int mul = temp*count; 
            while(mul)
            {
                prev_end = begin;
                begin = begin->next;
                mul--;
            }
            
            end = prev_end;
            while(temp)
            {
                if(!end)
                    break;
                end = end->next;
                temp--;
            }
            
           
            if(!flag)
            {
                cout<<head->val<<" "<<end->val<<endl;
                head = reverseNodes(head , end);
                flag = 1;
                count++;
            }
            else if(flag)
            {
                if(!end)
                    break;
                cout<<begin->val<<" "<<end->val<<endl;
                prev_end->next = reverseNodes(begin , end);
                count++;
            }
        }
        return head;
    }
};