#include <iostream>
using namespace std;

enum CarType { engine, tanker, box, passenger, caboose };

class Node {
public:
	int carNumber;
	int carType;
	bool isFULL;
	Node* next;

};


//this function inserts a new node in FRONT of the list---------------------------------------------------
void addFront(Node** head, int num, int type, bool full) {
	//make a new car
	Node* newNode = new Node;

	//give it its data
	newNode->carNumber = num;
	newNode->carType = type;
	newNode->isFULL = full;

	//set next of new node as head
	newNode->next = (*head);

	//move the head to point to the new node 
	(*head) = newNode;
}

//this function adds a new node AFTER a given node------------------------------------------------------
void addAfter(Node* prev_node, int num, int type, bool full) {
	//check if previous node is NULL, give error message if it is
	if (prev_node != NULL) {
		//make a new car
		Node* newNode = new Node;
		//give it its data
		newNode->carNumber = num;
		newNode->carType = type;
		newNode->isFULL = full;

		//set next to the "next" of the previous node
		newNode->next = prev_node;
		//move the next of the previous node as the new node
		prev_node = newNode;
	}
	else {
		cout<<"does not have a previous node"<<endl;
	}
	


}

//this function prints out the whole list----------------------------------------------------------------
void displayList(Node* node) {

	cout << "Printing Train! Choo Choo!" << endl << endl;
	//traverse the list to display each node
	while (node != NULL) {
		cout << "[ ";
		if (node->carType == 0)
			cout << "engine";
		else if (node->carType == 1)
			cout << "tanker";
		else if (node->carType == 2)
			cout << "boxcar";
		else if (node->carType == 3)
			cout << "passenger";
		else
			cout << "caboose!";

		cout << " # ";
		cout << node->carNumber;
		cout << node->isFULL << " ] --> ";
		node = node->next;
	}

	if (node == NULL)
		cout << "end" << endl << endl; //end of train
}


int main() {
	Node* head = NULL;
	addFront(&head, 100, box,true);
	addFront(&head, 2394, engine,false);
	addAfter(head->next , 200, tanker,false);
	displayList(head);
}
