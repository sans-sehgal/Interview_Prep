// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

Node *newNode(Node *temp)
{
    if(!temp)
        return NULL;
    Node* n = new Node(temp->val);
    n->next = newNode(temp->next);
    return n;
}
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node *head1 = newNode(head);
        Node *temp1 = head1 , *temp2 = head;
        map <Node* , Node*> mp;
        while(temp1 && temp2)
        {
            mp[temp2] = temp1;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        temp1 = head1;
        temp2 = head;
        // for(auto itr:mp)
        //     cout<<itr.first<<" "<<itr.second<<endl;
        while(temp1)
        {
            temp1->random = mp[temp2->random];
            temp1 = temp1->next;
            temp2=temp2->next;
        }
        return head1;
    }
};