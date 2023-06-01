#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
void delete_first(ListNode* head) {
	ListNode* ptr = head->link;
	head->link = ptr->link;
	free(ptr);
	return;

}
ListNode* delete_last(ListNode* head) {
	ListNode* pre = head; // head 이전의 노드 담을 곳
	ListNode* ptr = head; // head 노드

	do {
		pre = pre->link;
	} while (pre->link != ptr);

	pre->link = head->link;
	head = pre;
	free(ptr);
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}


int main(void) {
	ListNode* head = NULL;
	int answer;
	int item;

	while (1) {
		printf("※※※※ MENU ※※※※\n");
		printf("(1) Insert First\n");
		printf("(2) Insert Last\n");
		printf("(3) Delete First\n");
		printf("(4) Delete Last\n");
		printf("(5) Print List\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &answer);
		if (answer == 1) {
			printf("Input a number: ");
			scanf_s("%d", &item);
			head = insert_first(head, item);

		}
		else if (answer == 2) {
			printf("Input a number: ");
			scanf_s("%d", &item);
			head = insert_last(head, item);

		}
		else if (answer == 3) {
			delete_first(head);
			printf("First node has been deleted.\n");

		}
		else if (answer == 4) {
			head = delete_last(head);
			printf("Last node has been deleted.\n");

		}
		else if (answer == 5) {
			print_list(head);
			printf("\n");
		}
		else if (answer == 0) {
			printf("Exit the program.\n");
			exit(1);
		}
		printf("\n");
	}
	return 0;

}
