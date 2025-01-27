#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

void push(LinkedStackType* s, element item) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = item;
	p->link = s->top;
	s->top = p;
}

void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr,"스택 공백 상태\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int item = temp->data;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 상태\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

