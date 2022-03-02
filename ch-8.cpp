#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode *link;
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
 typedef struct {
 	listNode * head;
 } linkedList_h;
 
 // 공백 원형 연결 리스트를 생성하는 연산
 linkedList_h *createLinkedList_h(void) {
 	linkedList_h *CL;
 	CL = (linkedList_h*)malloc(sizeof(linkedList_h)); // 헤드 노드 할당  
 	CL -> head = NULL; // 공백 리스트이므로 NULL로 설정  
 	return CL;
 } 
 
 // 연결 리스트를 순서대로 출력하는 연산
 void printList(linkedList_h *CL) {
 	listNode *p;
	printf("CL = ("); //문장시작  
	p = CL -> head;  
	do {
		printf("%s", p->data);
		p = p -> link; // 다음 노 
		if (p != CL -> head) printf(", "); // 데이터하나 출력할때마다 쉼표 
	} while (p != CL -> head);
	printf(") \n"); // 문장 끝 
 } 
 
 void insertFirstNode(linkedList_h *CL, char *x) { // 헤드노드와 입력할 데이터를 입력  
 	listNode *newNode, *temp;
 	newNode = (listNode*)malloc(sizeof(listNode)); // 삽입할 새 노드 할당  
 	strcpy(newNode -> data, x); // newNode의 데이터부분에 x값 복사  
 	if (CL -> head == NULL) { // 만약에 CL노드의 헤드부분이 NULL이라면  
 		CL -> head = newNode; // 새 노드를 리스트의 시작 노드로 연결 
 		newNode -> link = newNode; 
	 }
	 else {
	 	temp = CL -> head;
	 	while (temp -> link != CL -> head) temp = temp -> link;
	 	newNode -> link = temp -> link;
	 	temp -> link = newNode;
	 	CL -> head = newNode;
	 }
 }
 
 int main() {
 	linkedList_h *CL;
 	listNode *p;
 	CL = createLinkedList_h();
 	printf("(1) 원형 연결 리스트 생성하기 \n ");
 	getchar();
 	
 	printf("(2) 원형 연결 리스트의 [월] 노드 삽입하기 \n");
 	insertFirstNode(CL, "월");
 	printList(CL); getchar();
	 
	 return 0; 
 }
