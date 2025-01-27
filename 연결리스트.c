#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{ // 구조체 정의할때 이름을 명시해야, 구조체 내부에서 link처럼 구조체 사용 가능
	element data;
	struct ListNode* link; // 자기자신을 참조하는 포인터를 포함하는 구조체
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // p가 가리키는 링크는 기존 헤드가 가리키던 노드로 복사
	head = p; // 헤드는 p가 된다
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
	removed = head; // 지울 노드에 헤드 복사
	head = removed->link; // 지울 노드가 가리키던 두번째 노드가 헤드가 됌
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link; 
	pre->link = removed->link; // 이전 노드의 링크는 지울노드가 가리키던 노드를 가리키게됌
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

