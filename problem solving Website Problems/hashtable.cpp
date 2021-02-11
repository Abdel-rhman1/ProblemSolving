#include<bits/stdc++.h>
using namespace std;
class linkedListNode{
private:
	int key;
	int value;
	linkedListNode *Next;
public:
	linkedListNode(int k , int v){
		this->key = k;
		this->value=v;
		this->Next=NULL;
	}
	int getKey(){
		return this->key;
	}
	int getvalue(){
		return this->value;
	}
	linkedListNode *getNext(){
		return this->Next;
	}
	void setNext(linkedListNode * next){
		this->Next = next;
	}
};
const int TABLE_SIZE = 128;
class hashTable{
private:
	linkedListNode **table;
public:
	hashTable(){
		table = new linkedListNode*[TABLE_SIZE];
		for(int i=0;i<TABLE_SIZE;i++){
			table[i] = NULL;
		}
	}
		int getValue(int key){
		
			int index = key % TABLE_SIZE;
			if(table[index]==NULL) return -1;
			else{
				linkedListNode * current = table[index];
				while(current!=NULL && current->getKey()!=index){
					current =current->getNext();
				}
				if(current==NULL) return -1;
				else{
					return current->getvalue();
				}
			}
		}
		void put(int key , int value){
			int index = key % TABLE_SIZE;
			if(table[index] ==NULL){
				linkedListNode *node = new linkedListNode(key,value);
				node->setNext(NULL);
				table[index] = node;
			}else{
				linkedListNode *current = table[index];
				while(current->getNext()!=NULL){
					current=current->getNext();
				}
				current->setNext(new linkedListNode(key,value));
			}
		}
		void remove(int key){
			int hash = key % TABLE_SIZE;
			if(table[hash]!=NULL){
				linkedListNode * Pri = NULL;
				linkedListNode *current = table[hash];
				while(current->getNext()!=NULL && current->getKey()!=key){
					Pri = current;
					current=current->getNext();
				}
				if(current->getKey() == key){
					if(Pri == NULL){
						linkedListNode *next = current->getNext();
						delete current;
						table[hash] = next;						
					}else{
						linkedListNode *next = current->getNext();
						delete current;
						Pri->setNext(next);
					}
				}
			}
		}
		~hashTable(){
			//deconstructor
		}
};
int main(){
	hashTable *object = new hashTable();
	object->put(1,120);
	object->put(2,130);
	cout<<object->getValue(2)<<endl;
	return 0;
}
