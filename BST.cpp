#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
class BST{
private:
	struct Node{
		int data;
		Node *left;
		Node *right;
	};
	Node *root=NULL;
	int getheighthelper(Node *tmp){
		if(tmp==NULL)
			return -1;
		int left=getheighthelper(tmp->left);
		int right=getheighthelper(tmp->right);
		return 1+max(left,right);
	}
	void inorderhelper(Node *root){
		if(root==NULL) return;
		cout<<root->data<<" ";
		inorderhelper(root->left);
		inorderhelper(root->right);
	}
	void preorderhelper(Node *root){
		if(root==NULL) return ;
		preorderhelper(root->left);
		cout<<root->data<<" ";
		preorderhelper(root->right);
	}
	void postorderhelper(Node *root){
		if(root==NULL) return ;
		postorderhelper(root->left);
		postorderhelper(root->right);
		cout<<root->right<<" ";
	}
public:
	void add(int data){
		Node *newNode=new Node;
		newNode->data=data;
		newNode->left=NULL;
		newNode->right=NULL;
		if(root==NULL){
			root=newNode;
			return;
		}
		Node *Tmp=root;
		Node *top=root;
		while(Tmp!=NULL){
			top=Tmp;
			if(data < root->data)
				Tmp=Tmp->left;
			else
				Tmp=Tmp->right;
		}
		if(data <= top->data)
			top->left=newNode;
		else
			top->right=newNode;
	}
	int getMax(){
		Node *curr=this->root;
		while(curr->right!=NULL){
			curr=curr->right;
		}
		return curr->data;
	}
	int getMin(){
		Node *curr=this->root;
		while(curr->left!=NULL)
			curr=curr->left;
		return curr->data;
	}
	int getheight(){
		if(this->root==NULL)
			return -1;
		else
			getheighthelper(this->root);
	}
	void displayOrderLevel(){
		if(this->root==NULL)
			return;
		queue<Node *>q;
		q.push(root);
		while(!q.empty()){
			Node *curr=q.front();
			q.pop();
			cout<<curr->data<<" ";
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
	}
	void inorder(){
		if(this->root==NULL)
			return ;
		else
			inorderhelper(this->root);
	}
	void preorder(){
		if(this->root==NULL)
			return ;
		else
			preorderhelper(this->root);
	}
	void postorder(){
		if(this->root==NULL) return ;
		else
			postorderhelper(root);
	}
};
int main(){
	BST tree;
	tree.add(2);
	tree.add(3);
	tree.add(6);
	tree.add(0);
	tree.add(1);
	cout<<tree.getMax()<<endl;
	cout<<tree.getMin()<<endl;
	cout<<tree.getheight()<<endl;
	tree.displayOrderLevel();
	cout<<"inorder"<<endl;
	tree.inorder();
	return 0;
}
