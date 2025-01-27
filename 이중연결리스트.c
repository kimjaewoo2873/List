#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element item) {
	DListNode* p = (DListNode*)malloc(sizeof(DListNode));
	p->llink = before;
	p->rlink = before->llink;
	before->rlink->llink = p;
	before->rlink = p;
}

void delete(DListNode* head, DListNode* removed) {
	if (removed == head) // ���߿��Ḯ��Ʈ���� ������� ����Ʈ�� ���۰� ���� ��Ÿ���� ����, �����Ͱ� ���ٰ� ���� ���� ��带 ����������
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
}