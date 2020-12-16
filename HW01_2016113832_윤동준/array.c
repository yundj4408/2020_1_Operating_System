#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>       //동적 메모리 할당 malloc함수를 사용하기 위해서 헤더파일을 추가하였다.
#include <string.h>        //strcpy, strcmp함수를 사용하기 위해서 헤더파일을 추가하였다.


typedef struct Student {
	char name[30];
	char number[11];
}Student;                               //처음 구조체를 정의하여 이름 학번을 입력받을 수 있는 공간을 만들어 주었다. 배열=포인터, 다른 함수 파라미터로 받아올려면 포인터 형식으로. (like swap 함수)





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

