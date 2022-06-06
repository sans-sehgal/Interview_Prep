// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/?page=1&category[]=Recursion&sortBy=submissions

/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
//Function to count number of subtrees having sum equal to given sum.

int countSubtrees(Node*root, int target, int &count)
{
    if(!root) return 0;
    // if(!root->left && !root->right) return root->data;
    int l = countSubtrees(root->left, target, count);
    int r = countSubtrees(root->right, target, count);
    if(root->data + l + r == target)
        count++;
    return root->data + l + r;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0;
	countSubtrees(root,X,count);
	return count;
}