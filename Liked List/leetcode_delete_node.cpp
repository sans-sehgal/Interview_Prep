// https://leetcode.com/problems/delete-node-in-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// idea: dont delete just shift
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* prev = node;
        while(node && node->next)
        {
            node->val = node->next->val;         
            prev = node;
            node = node->next;
        }
        prev->val = node->val;
        prev->next = NULL;
    }
};