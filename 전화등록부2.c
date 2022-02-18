#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define CAPCITY 100
#define BUFFER_SIZE 20

char* names[CAPCITY];
char* numbers[CAPCITY];
int n = 0;

void add();
void find();
void status();
void remove2();
void load();
void save();
int search(char *name);

int main() {
	char buffer[BUFFER_SIZE];
	
	while (1) {
		printf("$ ");
		scanf("%s", buffer);

		if (strcmp(buffer, "read") == 0)
			load();
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "find") == 0)
			find();
		else if (strcmp(buffer, "status") == 0)
			status();
		else if (strcmp(buffer, "delete") == 0)
			remove2();
		else if (strcmp(buffer, "save") == 0)
			save();
		else if (strcmp(buffer, "exit") == 0)
			break;
	}
	return 0;
}

int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, names[i]) == 0) {
			return i;
		}
	}
	return -1;
}

void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int index = search(buf);
	if (index == -1)
		printf("No person named '%s' exists. \n", buf);
	else
		printf("%s\n", numbers[index]);

}

void status() {
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}

void remove2() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int index = search(buf);
	if (index == -1) {
		printf("No person named '%s' exists. \n", buf);
		return;
	}
	int j = index;
	for (; j < n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}

	n--;
	printf("'%s' was deleted successfully. \n", buf);

}


void load() {
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	scanf("%s", fileName);

	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed. \n");
		return;
	}

	while ((fscanf(fp, "%s", buf1) != EOF)) {
		fscanf(fp, "%s", buf2);
		names[n] = strdup(buf1);
		numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp);
}

void save() {
	int i;
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	scanf("%s", tmp);  //  which is "as", discarded
	scanf("%s", fileName);

	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed. \n");
		return;
	}
	for (i = 0; i < n; i++) {
		printf( "%s %s \n", names[i], numbers[i]);
		fprintf(fp, "%s %s \n", names[i], numbers[i]);
	}
	fclose(fp);
}

void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	int i = n - 1; //마지막 
	// i번째사람이 buf1로 들어온 사람보다 크면 양수 출력
	while (i > 0 && strcmp(names[i], buf1) > 0) {
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = strdup(buf1);
	numbers[i + 1] = strdup(buf2);

	n++;
	printf("%s was added successfully. \n", buf1);
}


