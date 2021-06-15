#include <iostream>

struct Node {
	int value;
	Node* next;
};

/*
	this will insert at beginning
*/
void addToList(Node** list, int value) {
	Node* head = *list;

	Node* newNode = (Node*)calloc(1, sizeof(Node));

	newNode->value = value;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}

	*list = head;
}

void reverseList(Node** list) {
	Node* head = *list;

	Node* prev = NULL;	//when done, prev will be the head of reversed list
	Node* curr = head;
	Node* next = NULL;

	while (curr != NULL) {
		next = curr->next;	//march the 'next' to the 'curr's next node
		curr->next = prev;	//point the 'curr's next to the 'prev' node
		prev = curr;		//now march 'prev' to 'curr' node
		curr = next;		//since we saved the 'curr's next node before, we can march 'curr' to 'next' node
	}

	*list = prev;	//'prev' node now became the head
}

void enumerateNodes(Node* list) {
	while (list != NULL) {
		std::cout << list->value << "\n";
		list = list->next;
	}
}

int main() {
	Node* myList = NULL;

	addToList(&myList, 1);
	addToList(&myList, 2);
	addToList(&myList, 3);
	addToList(&myList, 4);
	addToList(&myList, 5);

	std::cout << "before reversing\n";
	enumerateNodes(myList);

	reverseList(&myList);

	std::cout << "after reversing\n";
	enumerateNodes(myList);

	return 0;
}