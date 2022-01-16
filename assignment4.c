#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct member
{
 char name[20];
 int prn;
 int roll;
 struct member *next;
};
 
struct member* create()
{
 int r,p;
 char n[20];
 struct member *head;
 head = (struct member*)malloc(sizeof(struct member));
 printf("Enter Name, PRN and Roll number of President of the club\n");
 scanf("%s%d%d",n,&p,&r);
 strcpy(head->name,n);
 head->prn = p;
 head->roll = r;
 head->next = NULL;
 return head;
}
 
void add(int m,struct member *head)
{
 int p,r;
 char n[20];
 struct member *temp;
 for(int i=0;i<m;i++)
 {
   temp = (struct member*)malloc(sizeof(struct member));
   printf("Enter Name, PRN and Roll number of the member\n");
   scanf("%s%d%d",n,&p,&r);
   strcpy(temp->name,n);
   temp->prn = p;
   temp->roll = r;
   head->next = temp;
   head = temp;
 }
}
 
void display(struct member *head)
{
 printf("Name\tPRN\t\tRoll\n");
 while(head != NULL)
 {
   printf("%s\t\t%d\t\t%d\n",head->name,head->prn,head->roll);
   head = head->next;
 }
}
 
void addS(struct member *head)
{
 int r,p;
 char n[20];
 struct member *new;
 new = (struct member*)malloc(sizeof(struct member));
 printf("Enter Name, PRN and Roll number of Secretory of the club\n");
 scanf("%s%d%d",n,&p,&r);
 strcpy(new->name,n);
 new->prn = p;
 new->roll = r;
 new->next = NULL;
 while(head->next != NULL)
 {
   head = head->next;
 }
 head->next = new;
}
 
struct member* delete(struct member *head)
{
 struct member *p;
 p=head->next;
 free(head);
 return p;
}
 
struct member* deleteS(struct member *head)
{
 struct member *pr;
 while(head!=NULL && head->next!=NULL)
 {
   pr = head;
   head=head->next;
 }
 pr -> next=NULL;
 free(head);
 return head;
}
 
int main()
{
 int choice,m;
 struct member *head;
 do
 {
   printf("Menu\n");
   printf("1.Create\n");
   printf("2.Add Member\n");
   printf("3.Delete Member\n");
   printf("4.Add Secretary\n");
   printf("5.Display\n");
   printf("6.Delete Secretary\n");
   printf("7.Exit\n");
   scanf("%d",&choice);
 
   switch(choice)
   {
     case 1:
     head = create();
     break;
 
     case 2:
     printf("Enter number of members:");
     scanf("%d",&m);
     add(m,head);
     break;
    
     case 3:
     head=delete(head);
     break;
 
     case 4:
     addS(head);
     break;
 
     case 5:
     display(head);
     break;
 
     case 6:
     deleteS(head);
     break;
 
     case 7:
     printf("Thank you\n");
     break;
 
     default:
     printf("ERROR\n");
     break;
   }
 }while(choice!=8);
 return 0;
}