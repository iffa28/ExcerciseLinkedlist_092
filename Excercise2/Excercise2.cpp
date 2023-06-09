#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** iffatuz, Node** zahra);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here
	int rollno;
	string nm;
	cout << "\nEnter the roll number: ";
	cin >> rollno;
	cout << "\nEnter the name of the student: ";
	cin >> nm;

	Node* newNode = new Node(); // mengalokasikan node baru
	newNode->rollNumber = rollno; //  memasukkan value pada node
	newNode->name = nm; //    memasukkan value pada node


	//insert in the beginning of the list
	if ((LAST == NULL) || (rollno <= LAST->rollNumber)) {
		if ((LAST->next != NULL) || (rollno <= LAST->next->rollNumber)) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST->next; //node setelah newnode sama dengan node seleah node lAST
		if (LAST->next != NULL)
			LAST->next = newNode;
		LAST->next = newNode;       //membuat node setelah node last sama dengan nodebaru
		return;
	}

	//insert between two nodes in the list
	Node* iffatuz = LAST->next;  //membuat current sama dengan node yang pertama
	Node* zahra = NULL;  //membuat node sebelumnya sama dengan null
	while ((iffatuz->next != LAST) && (iffatuz->next->rollNumber < rollno)) {
		iffatuz = zahra; //membuat previous atau iffatuz sama dengan current atau zahra secara berulang
		zahra = zahra->next;//membuat zahra sama dengan node yang ada setelah node zahra
	}
	if (iffatuz->next != LAST && rollno == zahra->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	// inserting a node at the end of the list
	newNode->rollNumber = rollno;
	newNode->name = nm;
	newNode->next = LAST->next;  //membuat field setelah newnode sama dengan node setelah node last
	LAST->next = newNode;
	LAST = newNode;  // menandai point setelah last adalah newnode
	return;
}
bool CircularLinkedList::search(int rollno, Node** iffatuz, Node** zahra) {
	*iffatuz = LAST->next;
	*zahra = NULL;
	while (*zahra != LAST) {
		if (rollno == (*zahra)->rollNumber) {
			return true;
		}
		*iffatuz = *zahra;
		*zahra = (*zahra)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	Node* zahra = LAST->next;
	if (LAST = LAST) { 
		LAST = NULL;
	}
	LAST->next = zahra->next;      

	// deletimg from the end of the list
	if (zahra != LAST) {
		Node* iffatuz = LAST;
		iffatuz = iffatuz->next;
		iffatuz->next = LAST->next;
		LAST = iffatuz;
	}

	delete zahra;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* zahraNode = LAST->next;
		while (zahraNode != LAST) {
			cout << zahraNode->rollNumber << " " << zahraNode->name << endl;
			zahraNode = zahraNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': 
				obj.addNode();
				break;
			case '2': 
				obj.delNode();
				break;
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;

}