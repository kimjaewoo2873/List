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
	p = head->link; // ��尡 ����Ű�� ù��° ��尡 �ȴ�
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link); // ó�� �����ߴ�, ù��° ���� ���ƿ��� ����
}

ListNode* insert_first(ListNode* head, element item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	if (head == NULL) { // ���� ����Ʈ�� ����ִ� ���
		head = p; // ���� ���θ���� p�� �ȴ�
		p->link = head; // ���� ����Ʈ�� �ƹ� ��嵵 ������ ��ũ�� �ڱ��ڽſ��� ����
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

