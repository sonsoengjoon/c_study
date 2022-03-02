#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode *link;
} listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
 typedef struct {
 	listNode * head;
 } linkedList_h;
 
 // ���� ���� ���� ����Ʈ�� �����ϴ� ����
 linkedList_h *createLinkedList_h(void) {
 	linkedList_h *CL;
 	CL = (linkedList_h*)malloc(sizeof(linkedList_h)); // ��� ��� �Ҵ�  
 	CL -> head = NULL; // ���� ����Ʈ�̹Ƿ� NULL�� ����  
 	return CL;
 } 
 
 // ���� ����Ʈ�� ������� ����ϴ� ����
 void printList(linkedList_h *CL) {
 	listNode *p;
	printf("CL = ("); //�������  
	p = CL -> head;  
	do {
		printf("%s", p->data);
		p = p -> link; // ���� �� 
		if (p != CL -> head) printf(", "); // �������ϳ� ����Ҷ����� ��ǥ 
	} while (p != CL -> head);
	printf(") \n"); // ���� �� 
 } 
 
 void insertFirstNode(linkedList_h *CL, char *x) { // ������ �Է��� �����͸� �Է�  
 	listNode *newNode, *temp;
 	newNode = (listNode*)malloc(sizeof(listNode)); // ������ �� ��� �Ҵ�  
 	strcpy(newNode -> data, x); // newNode�� �����ͺκп� x�� ����  
 	if (CL -> head == NULL) { // ���࿡ CL����� ���κ��� NULL�̶��  
 		CL -> head = newNode; // �� ��带 ����Ʈ�� ���� ���� ���� 
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
 	printf("(1) ���� ���� ����Ʈ �����ϱ� \n ");
 	getchar();
 	
 	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ� \n");
 	insertFirstNode(CL, "��");
 	printList(CL); getchar();
	 
	 return 0; 
 }
