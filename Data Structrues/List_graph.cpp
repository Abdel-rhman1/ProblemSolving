#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	void setData(int data) {
		this->data = data;
	}
	int getData() {
		return this->data;
	}
	Node *getNext() {
		return next;
	}
	void setNext(Node* Next) {
		this->next = Next;
	}
	
};
class graph {
private:
	Node** list;
	int n;
public:
	graph(int numberOfNodes) {
		this->n = numberOfNodes;
		list = new Node * [numberOfNodes];
		for (int i = 0; i < numberOfNodes; i++) {
			list[i] = NULL;
		}
	}
	void put(int u, int v) {
		Node* newNodeu = new Node(v);
		Node* newNodev = new Node(u);
		if (list[u] == NULL) {
			list[u] = newNodeu;
		}
		else {
			Node* current = list[u];
			while (current->getNext()!= NULL){
				current=current->getNext();
			}
			current->setNext(newNodeu);
		}
		if (list[v] == NULL) {
			list[v] = newNodev;
		}
		else {
			Node* current = list[v];
			while (current->getNext() != NULL) {
				current = current->getNext();
			}
			newNodev->setNext(NULL);
			current->setNext(newNodev);	
		}
	}
	void print() {
		for (int i = 0; i < this->n; i++) {
			cout << "\n Adjacency list of vertex "
				<< (i) << "\n head ";
			Node* current = this->list[i];
			while (current!= NULL) {
				cout << "-> " << current->getData();
				current = current->getNext();
			}
			cout << "\n";
		}
	}
};
int main() {
	graph* object = new graph(5);
	object->put(0, 1);
	object->put(0, 4);
	object->put(1, 2);
	object->put(1,3);
	object->put(1,4);
	object->put(2, 3);
	object->put(3, 4);
	object->print();
	return 0;
}
