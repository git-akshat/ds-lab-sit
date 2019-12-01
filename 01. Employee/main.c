/* Write a C program to create a sequential file with at least five records,
  each record having the structure shown below:

EMPLOYEE_ID                      |  NAME            |  DEPARTMENT      |  SALARY               |  AGE
Non-Zero  Positive  integer 25   |  Characters 25   |  Characters 25   |  Positive  Integer    |  Positive  integer

Write necessary functions to perform the following operations:
i)  to display all the records in the file.
ii) to search for a specific record based on
    EMPLOYEE_ID/SALARY/DEPARTMENT/AGE.

In case if the required record is not found, suitable message should be displayed. */



#include<stdio.h>
#include<stdlib.h>

void display();

void search();

struct employee
{
int employee_id;
char name[25];
char department[25];
int salary;
int age;
}s;

FILE *fp;

void main()
{
int i,ch;
fp=fopen("employee.txt","w"); //storing record in file employee.txt
for(i=0;i<5;i++)
{
printf("\nEnter ID of Employee%d            :",i+1);
scanf("%d",&s.employee_id);
fprintf(fp,"%6d\t",s.employee_id);

printf("Enter Name of Employee%d          :",i+1);
scanf("%s",s.name);
fprintf(fp,"%25s\t",s.name);

printf("Enter Department of employee%d    :",i+1);
scanf("%s",s.department);
fprintf(fp,"%25s\t",s.department);

printf("Enter salary of Employee%d        :",i+1);
scanf("%d",&s.salary);
fprintf(fp,"%6d\t",s.salary);

printf("Enter Age of Employee%d           :",i+1);
scanf("%d",&s.age);
fprintf(fp,"%6d\n",s.age);
}
fclose(fp);
while(1)
{
printf("\n\nEnter your choice:");
printf("\n1.Display all records\n2.TO search a particular record\n3.Exit\n");
scanf("%d",&ch);

switch(ch)
{
case 1: display();
		break;

case 2: search();
		break;

case 3: exit(0);

default : printf("\nINVALID CHOICE!");
} //end of switch case
} //end of while loop
} //end of main function

void display()
{
int i;
fp=fopen("employee.txt","r");
printf("Employee_ID\t\tNAME\t\tDEPARTMENT\t\tSALARY\t\tAGE\n");
for(i=0;i<5;i++)
{
fscanf(fp,"%d%s%s%d%d",&s.employee_id,s.name,s.department,&s.salary,&s.age);
printf("%6d\t\t%10s\t\t%10s\t\t%6d\t\t%3d\n",s.employee_id,s.name,s.department,s.salary,s.age);
}
fclose(fp);
}

void search()
{
int i,j=0,ch;
int id,sal,ag,temp;
char naam[25],dept[25],temp1[25];
fp=fopen("employee.txt","r");
printf("\nsearch with?\n1.ID\n2.Department\n3.Salary\n4.Age\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nEnter ID: ");
		scanf("%d",&temp);
		printf("Employee_ID\t\tNAME\t\tDEPARTMENT\t\tSALARY\t\tAGE\n");
		for(i=0;i<5;i++)
		{
		fscanf(fp,"%d%s%s%d%d",&id,naam,dept,&sal,&ag);
		if(temp==id)
		{
		printf("%6d\t\t%10s\t\t%10s\t\t%6d\t\t%3d\n",id,naam,dept,sal,ag);
		printf("\n");
		j=1;
		}
		}
		if(j==0)
		printf("\nRecord not found");
		fclose(fp);
		break;

case 2: printf("\nEnter Department: ");
		scanf("%s",temp1);
		printf("Employee_ID\t\tNAME\t\tDEPARTMENT\t\tSALARY\t\tAGE\n");
		for(i=0;i<5;i++)
		{
		fscanf(fp,"%d%s%s%d%d",&id,naam,dept,&sal,&ag);
		if(strcmp(temp1,dept)==0)
		{
		printf("%6d\t\t%10s\t\t%10s\t\t%6d\t\t%3d\n",id,naam,dept,sal,ag);
		printf("\n");
		j=1;
		}
		}
		if(j==0)
		printf("\nRecord not found");
		fclose(fp);
		break;

case 3: printf("\nEnter salary: ");
		scanf("%d",&temp);
		printf("Employee_ID\t\tNAME\t\tDEPARTMENT\t\tSALARY\t\tAGE\n");
		for(i=0;i<5;i++)
		{
		fscanf(fp,"%d%s%s%d%d",&id,naam,dept,&sal,&ag);
		if(temp==sal)
		{
		printf("%6d\t\t%10s\t\t%10s\t\t%6d\t\t%3d\n",id,naam,dept,sal,ag);
		printf("\n");
		j=1;
		}
		}
		if(j==0)
		printf("\nRecord not found");
		fclose(fp);
		break;

case 4: printf("\nEnter age: ");
		scanf("%d",&temp);
		printf("Employee_ID\t\tNAME\t\tDEPARTMENT\t\tSALARY\t\tAGE\n");
		for(i=0;i<5;i++)
		{
		fscanf(fp,"%d%s%s%d%d",&id,naam,dept,&sal,&ag);
		if(temp==ag)
		{
		printf("%d\t\t%s\t\t%s\t\t%d",id,naam,dept,sal);
		printf("\n");
		j=1;
		}
		}
		if(j==0)
		printf("\nRecord not found");
		fclose(fp);
		break;

default : printf("\nINVALID CHOICE!");
          fclose(fp);
}
}

