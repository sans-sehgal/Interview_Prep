// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    Node* head = root;
    while (root)
    {
        head = merge(head , root->next);
        root = root->next;
    }
    return head;
}

Node *merge(Node* head1 , Node* head2)
{
    Node* temp1 = head1, *temp2 = head2, *temp;
    int init_flag = 0;
    while(temp1 && temp2)
    {
        if(!init_flag)
        {
            if(temp1->data < temp2->data)
            {
                head1 = temp1;
                temp1 = temp->bottom;
            }
            else
            {
                head1 = temp2;
                temp2 = temp2->bottom;
            }
            init_flag = 1;    
            temp = head1;
            
        }
        if(temp1->data < temp2->data)
        {
            Node* prev = temp1;
            temp1 = temp1->bottom;
            temp->bottom = prev;
            temp = temp->bottom;
        }
        else if(temp1->data > temp2->data)
        {
            Node* prev = temp1;
            temp2 = temp2->bottom;
            temp->bottom = prev;
            temp = temp->bottom;
        }
    }

    while(temp1)
    {
        temp->bottom = temp1;
    }
    while(temp2)
    {
    
        temp->bottom = temp2;
    }
    return head1;
}

