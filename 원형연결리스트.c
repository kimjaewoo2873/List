#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL)
		return;
	p = head->link; // 헤드가 가리키는 첫번째 노드가 된다
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link); // 처음 시작했던, 첫번째 노드로 돌아오면 종료
}

ListNode* insert_first(ListNode* head, element item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	if (head == NULL) { // 현재 리스트가 비어있는 경우
		head = p; // 헤드는 새로만드는 p가 된다
		p->link = head; // 현재 리스트에 아무 노드도 없으니 링크를 자기자신에게 연결
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head = p;
	}
	return head;
}

