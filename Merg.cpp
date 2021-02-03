#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
void Add(Node **head,int data){
	Node *NewNode=new Node(data);
	if(*head==NULL)
		*head=NewNode;
	else{
		Node *curent=*head;
		while(curent->next!=NULL){
			curent=curent->next;
		}
		curent->next=NewNode;
	}
}
void Print(Node *head){
	Node *current=head;
	while(current!=NULL){
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
}
Node * MergeLists(Node *currA, Node *currB) {
    if (currA == NULL) {
        return currB;
    } else if (currB == NULL) {
        return currA;
    }
    
    /* Find new head pointer */
    Node *head = NULL;
    if (currA->data < currB->data) {
        head = currA;
        currA = currA->next;
    } else {
        head = currB;
        currB = currB->next;
    }
    
    /* Build rest of list */
    Node *n = head;
    while (currA != NULL && currB != NULL) {
        if (currA->data < currB->data) {
            n->next = currA;
            currA = currA->next;
        } else {
            n->next = currB;
            currB = currB->next;
        }
        n = n->next;
    }
    
    /* Attach the remaining elements */
    if (currA == NULL) {
        n->next = currB;
    } else {
        n->next = currA;
    }

    return head;
}
int main(){
	Node *head=NULL;
	Add(&head,1);
	Add(&head,3);
	Add(&head,7);
	Node *head1=NULL;
	Add(&head1,1);
	Add(&head1,2);
	Print(head);
	Print(head1);
	Node *head2=MergeLists(head,head1);
	Print(head2);
	return 0;
}
