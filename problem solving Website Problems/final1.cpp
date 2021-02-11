#include<iostream>
#include<string>
#include<assert.h>
#include<cmath>
using namespace std;
class QueueNode{
public:
	string copyDate;
	bool available;
	string borrower;
	string borrowDate;
	int numOfDays;
	QueueNode *next;
};
class Queue{
public:
	QueueNode *front , *rear;
	Queue(){
		front=rear=NULL;
	}
	void enququq(string copDate,bool ava,string Name,string borrowDate,int numOfDays){
		QueueNode *newNode=new QueueNode();
		newNode->copyDate=copDate;
		newNode->available=ava;
		newNode->borrower=Name;
		newNode->borrowDate=borrowDate;
		newNode->numOfDays=numOfDays;
		newNode->next=NULL;
		if( this->front==NULL && this->rear==NULL){
			this->rear=this->front=newNode;
			return;
		}
		else{
			this->rear->next=newNode;
			this->rear=newNode;
			return;
		}
	}
	void dequeue(){
		if(this->front==NULL){
			return;
		}
		QueueNode *Tmp=front;
		this->front=this->front->next;
		if(this->front==NULL)
			this->rear=NULL;
		delete(Tmp);
	}
	int queueSize(){
		QueueNode *current=front;
		int size=0;
		while(current!=NULL){
			size++;
			current=current->next;
		}
		return size;
	}
	void print(){
		QueueNode *cur=front;
		while(cur!=NULL && rear!=NULL){
			cout<<"Copy Date: "<<cur->copyDate<<endl;
			cout<<"Avaiable: "<<cur->available<<endl;
			cout<<"Name: "<<cur->borrower<<endl;
			cout<<"Borrow Date: "<<cur->borrowDate<<endl;
			cout<<"Number Of Days to Return: "<<cur->numOfDays<<endl;
			cur=cur->next;
			cout<<"___________________________________________________"<<endl;
		}
	}
};
class Node{
public:
	string bookName;
	int bookISBN;
	int numOfCopies;
	Queue *copies=new Queue();
	Node *next;
};

Node * createNode(string Name,int ID,int copy){
	Node *newNode=new Node();
	newNode->bookName=Name;
	newNode->bookISBN=ID;
	newNode->numOfCopies=copy;
	newNode->next=NULL;
	return newNode;
}
void AddingNewBook(Node **head,string Name,int ID,int copy){
	Node *newNode=createNode(Name,ID,copy);
	Node *current=*head;
	if((*head)==NULL){
		*head=newNode;
		return;
	}
	while(current->next!=NULL)
		current=current->next;
	current->next=newNode;
	return;
}
void print(Node *head){
	Node *cur=head;
	while(cur!=NULL){
		cout<<"Book Name: "<<cur->bookName<<endl;
		cout<<"Book ISBN: "<<cur->bookISBN<<endl;
		cout<<"Book Copy: "<<cur->numOfCopies<<endl;
		cout<<"_____________________Book Copies________________________"<<endl;
		cur->copies->print();
		cout<<"_____________________End Book Copies_____________________"<<endl;
		cur=cur->next;
		cout<<"______________________________________"<<endl;
	}
}
void AddCopy(Node *head,string copDate,bool Avaiable,string Name,string borrowDate,int num){
	head->copies->enququq(copDate,Avaiable,Name,borrowDate,num);
}
void retuenCopy(Node *head){
	head->copies->dequeue();
}
void Library(Node *head){
	cout<<"__________________________Library Inventory____________________"<<endl;
	Node *current=head;
	while(current!=NULL){
		cout<<"________________"<<current->bookName<<"________________"<<endl;
		cout<<"Total Copies In Library: "<<current->numOfCopies<<endl;
		cout<<"Brrow Copies: "<<current->copies->queueSize()<<endl;
		current=current->next;
	}
}
int main(){
	Node *head=NULL;
	AddingNewBook(&head,"DS",1,12);
	AddingNewBook(&head,"AI",2,14);
	AddCopy(head,"1/1/2020",true,"Ali","1/10/2020",12);
	AddCopy(head,"1/1/2019",false,"Ahmed","1/10/2018",13);
	retuenCopy(head);
	AddCopy(head->next,"1/1/2017",true,"Abdelrhman","1/7/2018",15);
	AddingNewBook(&head,"SW",3,13);
	print(head);
	Library(head);
	return 0;
}
