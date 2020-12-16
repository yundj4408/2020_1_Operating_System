#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Real {
   struct Real* next;  
   char name[30];
   int number;
};

struct Real* AddNode(struct Real* Point, char newname[30], int newnumber)            
{
   struct Real* newNode;                                          
   newNode = malloc(sizeof(struct Real));                              
   newNode->next = Point->next;                                     
   strcpy(newNode->name, newname);                                    
   newNode->number = newnumber;                                    
   Point->next = newNode;                                          
   return newNode;                                               
}
int main() {
   struct Real* head = malloc(sizeof(struct Real));                    
   head->next = NULL;                                             
   struct Real* temp = malloc(sizeof(struct Real));                    
   temp = AddNode(head, "q1", 1);                                    
   AddNode(temp, "q2", 1234);                                          
   AddNode(temp, "q3", 3);
   AddNode(temp, "q4", 4);
   AddNode(temp, "q5", 5);
   AddNode(temp, "q6", 6);
   AddNode(temp, "q7", 7);
   AddNode(temp, "q8", 8);
   AddNode(temp, "q9", 9);
   AddNode(temp, "q10", 10);


   struct Real* curr = head->next;

   printf("student info \n");
   while (curr != NULL)
   {
      printf("%s   %d\n", curr->name, curr->number);
      curr = curr->next;
   }
   
   


   
   while (1) {
      int input = 0;
      int flag = 0;
      printf("name:1, number:2= ");
      scanf("%d", &input);
     
      if (input == 1) {
         char StudentName[20];
         printf("Put your name in: ");
         scanf("%s", &StudentName);
         struct Real* curr = head->next;

         while (curr != NULL)
         {
            if (strcmp(curr->name, StudentName) == 0) {
               printf("Number: %d \n", curr->number);
               flag = 1;
               break;
            }
            curr = curr->next;
         }
      if (flag == 0) {
            printf("Not Found\n");
         }
      }

      if (input == 2) {
         int SearchNumber;
         printf("Put your number in: ");
         scanf("%d", &SearchNumber);
   
         struct Real* curr = head->next;                        
     
         while (curr != NULL)
         {
            if (curr->number == SearchNumber) {                                          
         
               printf("Name: %s \n", curr->name);                                    
               flag = 1;                                                        
               break;
            }
            curr = curr->next;
         }
         if (flag == 0) {
            printf("Not Found\n");
         }
      }
     
     
   }
   return 0;
}
