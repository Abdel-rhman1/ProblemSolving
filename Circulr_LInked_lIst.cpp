#include<iostream>
#include<string>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
void push(Node **head_ref, int data) 
{ 
	Node *ptr1 = new Node(); 
	Node *temp = *head_ref; 
	ptr1->data = data; 
	ptr1->next = *head_ref; 

	/* If linked list is not NULL then 
	set the next of last node */
	if (*head_ref != NULL) 
	{ 
		while (temp->next != *head_ref) 
			temp = temp->next; 
		temp->next = ptr1; 
	} 
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1; 
} 
void PrintList(Node *head){
	Node *Tmp=head;
	if(head!=NULL){
		do{
			cout<<Tmp->data<<" ";
			Tmp=Tmp->next;
		}while(Tmp!=head);
		cout<<endl;
	}
}
void SortInsert(Node **head,int data){
	Node *curr=*head;
	Node *New_Node=new Node();
	New_Node->data=data;
	if(curr==NULL){
		New_Node->next=New_Node;
		*head=New_Node;
	}else if(curr->data >= data){
		while(curr->next !=*head)
			curr=curr->next;
		curr->next=New_Node;
		New_Node->next=*head;
		*head=New_Node;
	}else{
		while(curr->next !=*head && curr->next->data < data)
			curr=curr->next;
		New_Node->next=curr->next;
		curr->next=New_Node;
	}
}
bool isCir(Node *head){
	if(head==NULL)
		return true;
	Node *curr=head;
	while(curr->next!=NULL && curr->next!=head)
		curr=curr->next;
	return(curr->next==head);
}
int main()
{
	Node *head=NULL;
	push(&head,6);
	push(&head,5);
	push(&head,3);
	push(&head,1);
	PrintList(head);
	SortInsert(&head,4);
	SortInsert(&head,2);
	PrintList(head);
	if(isCir(head)==true){
		cout<<"Good"<<endl;
	}else{
		cout<<"Bad"<<endl;
	}
	return 0;
}
