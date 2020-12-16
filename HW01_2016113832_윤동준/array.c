#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>       //���� �޸� �Ҵ� malloc�Լ��� ����ϱ� ���ؼ� ��������� �߰��Ͽ���.
#include <string.h>        //strcpy, strcmp�Լ��� ����ϱ� ���ؼ� ��������� �߰��Ͽ���.


typedef struct Student {
	char name[30];
	char number[11];
}Student;                               //ó�� ����ü�� �����Ͽ� �̸� �й��� �Է¹��� �� �ִ� ������ ����� �־���. �迭=������, �ٸ� �Լ� �Ķ���ͷ� �޾ƿ÷��� ������ ��������. (like swap �Լ�)





void PPAP(Student* student);
void Find(Student* student, char* input);
void Insert(Student* student, char* name, char* number);

int main() {
	Student student[100];
	char* input;
	input = (char*)malloc(sizeof(char) * 1000);



	Insert(student, "YUN", "2016113832");
	Insert(student + 1, "YUN1", "2016113834");
	Insert(student + 2, "YUN2", "2016113836");
	Insert(student + 3, "YUN3", "2016113838");
	Insert(student + 4, "YUN4", "2016113840");
	Insert(student + 5, "YUN5", "2016113842");
	Insert(student + 6, "YUN6", "2016113844");
	Insert(student + 7, "YUN7", "2016113846");
	Insert(student + 8, "YUN8", "2016113848");
	Insert(student + 9, "YUN9", "2016113850");

	PPAP(student);

	printf("Search : ");

	scanf("%s", input);

	Find(student, input);
	system("pause > nul");
	return 0;
}



void Insert(Student* student, char* name, char* number) {
	strcpy(student->name, name);
	strcpy(student->number, number);

}

void PPAP(Student* student) {
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%s, %s\n", student[i].name, student[i].number);
	}
}

void Find(Student* student, char* input) {
	int i;
	int flag = 0;

	for (i = 0; i < 10; i++) {
		if (strcmp(student[i].name, input) == 0) {
			printf("%s", student[i].number);
			flag = 1;
		}
		else if (strcmp(student[i].number, input) == 0) {
			printf("%s", student[i].name);
			flag = 1;
		}

	}
	if (flag == 0) {
		printf("Not Found!");
	}
}

