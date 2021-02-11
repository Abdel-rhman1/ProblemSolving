#include <iostream>
using namespace std;
class BtreeNode {
    int* keys; // array of keys in the node
    int t;     // The Maximum elements in the node
    BtreeNode **c; // pointer to the array of childs
    int n;        // the current number of the key in the node
    bool leaf;    // this node is leaf or not
public:
    BtreeNode(int _t,bool _leaf); // contstructor btreeNode
    void traverse(); // method to traverse the NodeKeys
    BtreeNode* search(int k); // method to search in the Node Keys
    void insertNonFull(int k); // Insert in Non Full array of Keys node
    void splitChild(int i, BtreeNode* y); // split Node that its keys array is Full
    friend class Btree; // make Btree class friend to make it access priv pro
};
class Btree {
    BtreeNode* root; // root of the Btree
    int t; // Order of tree
public:
    Btree(int t) { // constructor that take the order
        this->root = NULL; // the head of the tree
        this->t = t; // order of the tree
    }
    void traverse() { // function to traverse the Btree
		// if the root Not equal NULL traverse its keys 
        if (this->root != NULL) root->traverse();
    }
    BtreeNode* search(int k) { // function to search in the whole Btree
    	// if the root is eqyual to NULL return Null otherwise Search in its keys
        return (root == NULL) ? NULL : root->search(k);
    }
    void insert(int k);
};
BtreeNode::BtreeNode(int _t,bool _leaf) { // BtreeNode Constructor
    this->t = _t; // minmum keys
    this->leaf = _leaf; // leaf or not
    keys = new int[2 * t - 1]; // array of maximum keys in the node
    c = new BtreeNode * [2 * t];// points to the array of child of the node
    n = 0; // set root no node
}
void BtreeNode::traverse() { // BtreeNode Traverse Method
    int i; // traverse the node
    for (i = 0; i < n; i++) { 
        if (leaf == false) // if the node is not a leaf node 
            // get down and traverse it childs
            c[i]->traverse();
        // else print its keys
        cout << "  " << keys[i]<<"\t";
    }
    // print last node keys
    if (leaf == false)
        c[i]->traverse();
}
// Method to search k in the BTree
BtreeNode* BtreeNode::search(int k) {
    int i = 0;
    // while we connat reach to n (the current elements in the keys array and k
	// k > keys[i] increament index)
    while (i < n && k > keys[i])
        i++;
    // if the keys[i] equal to k return this
    if (k == keys[i])
        return this;
    // else if (if the leaf is true)
    // return NULL
    else if (leaf == true)
        return NULL;
    // else Recursive the Function with new child
    return c[i]->search(k);
}
// Method to Insert new element in the Btree
void Btree::insert(int k) {
	// if the root is NULL
	// create new node
	// make root[0] is equal to k;
	// increaemt n by 1
	if (this->root == NULL) {
        root = new BtreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    // else the root is not eqyal to NULL
    // that have elements
    else {
    	// if the root is full
    	// create New Node called s 
        if (root->n == 2 * t - 1) {
            BtreeNode* s = new BtreeNode(t, false);
            // That Point to the root
            s->c[0] = root;
            // call function split node
            s->splitChild(0,root);
            int i = 0;
            // if the k is greater than keys[0]
            // k must insert into the other child
            if (s->keys[0] < k)
                i++;
            s->c[i]->insertNonFull(k);
            // the s will become the new root
            root = s;
        }
        // else the root is not full
        else {
            root->insertNonFull(k);
        }
    }
}
// method to insert into nonfull tree
void BtreeNode::insertNonFull(int k) {
	// begin from the end of keys array
    int i = n - 1;
    // if the this node is leaf node
    // chift to get the corect position
    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        // then insert the element in the i+1 position
        keys[i + 1] = k;
        // increment the current element by 1
        n = n + 1;
    }
    // else this node is leaf node
    else {
    	// loop to get the correct child
        while (i >= 0 && keys[i] > k) 
            i--;
        // if this child is full
		// split the node 
        if (c[i + 1]->n == 2 * t - 1){
            splitChild(i + 1, c[i + 1]);
	        if (keys[i + 1] < k)
	            i++;
        }
    c[i + 1]->insertNonFull(k);
	}
}
// method to split the node
void BtreeNode::splitChild(int i, BtreeNode* y) {
    BtreeNode* z = new BtreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->c[j] = y->c[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) {
        c[j + 1] = c[j];
    }
    c[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n = n + 1;
}

int main()
{
    cout << "Hello World" << endl;
    Btree t(3); // A B-Tree with minium degree 3 
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    cout << "Traversal of the constucted tree is ";
    t.traverse();
   cout << "Hello World!\n";
}
