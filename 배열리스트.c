#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) { // pos 인덱스 값 반환
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L) {
	int i;
	for (int i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item) { // 맨끝에 삽입하기
	if (L->size >= MAX_LIST_SIZE)
		error("리스트 오버플로우");
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item) { // 인덱스pos 위치에 삽입하기
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) 
			L->array[i + 1] = L->array[i]; 
		L->array[pos] = item;
		L->size++; // pos에 하나 더 집어넣었으니 size하나 증가시켜둬야함
	}
}

element delete(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) // 하나 줄어가지고 굳이 마지막 요소까지 i로 접근할 필요가 없음
		L->array[i] = L->array[i + 1];
	L->size--; // 하나 삭제했으니까 
	return item;
}

int main(void) {
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
}