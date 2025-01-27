#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{ // ����ü �����Ҷ� �̸��� ����ؾ�, ����ü ���ο��� linkó�� ����ü ��� ����
	element data;
	struct ListNode* link; // �ڱ��ڽ��� �����ϴ� �����͸� �����ϴ� ����ü
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // p�� ����Ű�� ��ũ�� ���� ��尡 ����Ű�� ���� ����
	head = p; // ���� p�� �ȴ�
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head; // ���� ��忡 ��� ����
	head = removed->link; // ���� ��尡 ����Ű�� �ι�° ��尡 ��尡 ��
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link; 
	pre->link = removed->link; // ���� ����� ��ũ�� �����尡 ����Ű�� ��带 ����Ű�ԉ�
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

