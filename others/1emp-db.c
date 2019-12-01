#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    unsigned  id;
    char name[20];
    unsigned salary;
    char dept[10];
    unsigned age;
}EMPLOYEE;

void fnAddData(FILE *fp,int n)
{
    EMPLOYEE e;
    int i;
    for(i=0;i<n;i++)
    {
      printf("\nenter the record no:%d\n",i+1);
      printf("\nenter EMP-id:");
      scanf("%d",&e.id);
      getchar();
      printf("\nenter Emp-name:");
      scanf("%s",e.name);
       printf("\nenter Emp-Salary:");
      scanf("%d",&e.salary);
      getchar();
      printf("\nenter Emp-dept:");
      scanf("%s",e.dept);
      printf("\nenter EMP-age:");
      scanf("%d",&e.age);

        fprintf(fp,"%d\t%s\t%d\t%s\t%d\n",e.id,e.name,e.salary,e.dept,e.age);
    }

}

void display(FILE *fp)
{
    EMPLOYEE e;
       printf("\n Emp-id         Emp-name     Emp-salary    DEPT.       AGE\n");
    while(fscanf(fp,"%d%s%d%s%d",&e.id,e.name,&e.salary,e.dept,&e.age)!=EOF)
    {

        printf("\n%u             %s            %u             %s          %u \n",e.id,e.name,e.salary,e.dept,e.age);
    }
}

int search_id(FILE *fp,unsigned id)
{
    EMPLOYEE e;
    printf("\n Emp-id         Emp-name     Emp-salary    DEPT.       AGE\n");
    while(fscanf(fp,"%u%s%u%s%u",&e.id,e.name,&e.salary,e.dept,&e.age)!=EOF)
    {

        if(id==e.id)
        {

            printf("\n%u             %s            %u             %s          %u \n",e.id,e.name,e.salary,e.dept,e.age);
            return 1;
        }
    }

    return 0;
}


int search_sal(FILE *fp,unsigned sal)
{
    EMPLOYEE e;
    int count=0;
           printf("\n Emp-id         Emp-name     Emp-salary    DEPT.       AGE\n");
    while(fscanf(fp,"%u%s%u%s%u",&e.id,e.name,&e.salary,e.dept,&e.age)!=EOF)
    {

        if(sal==e.salary)
        {

            printf("\n%u\t%s\t%u\t%s\t%u \n",e.id,e.name,e.salary,e.dept,e.age);
           count++;
        }
    }

   if(count==0)
   return 0;
}

int search_age(FILE *fp,unsigned age)
{
    EMPLOYEE e;
    int count=0;
       printf("\n Emp-id         Emp-name     Emp-salary    DEPT.       AGE\n");
    while(fscanf(fp,"%u%s%u%s%u",&e.id,e.name,&e.salary,e.dept,&e.age)!=EOF)
    {
        if(age==e.age)
        {

             printf("\n%u             %s            %u             %s          %u \n",e.id,e.name,e.salary,e.dept,e.age);
             count++;
        }
    }

   if(count==0)
   return 0;
}

int search_dept(FILE *fp,char dept[])
{
    EMPLOYEE e;
    int count=0;
         printf("\n Emp-id         Emp-name     Emp-salary    DEPT.       AGE\n");
    while(fscanf(fp,"%u%s%u%s%u",&e.id,e.name,&e.salary,e.dept,&e.age)!=EOF)
    {

        if(strcmp(e.dept,dept)==0)
        {

             printf("\n%u             %s            %u             %s          %u \n",e.id,e.name,e.salary,e.dept,e.age);
        }
    }

     if(count==0)
      return 0;
}
int main()
{
    int n,ch,flag;
    EMPLOYEE key;
    FILE *fp;
    printf("MENU for Employee DTA base");
     while(1)
    {
    printf("\n 1.ADDdata\n2.display\n3.search record-id\n 4.search record-salary\n5.search record-age\n6.search record-dept\n");
    printf("Enter your chpice\n");
    scanf("%d",&ch);

        switch(ch)
        {
            case 1:fp=fopen("EMP_DATA","a+");
                        if(fp==NULL)
                        {
                            printf("file operation error\n");
                            break;
                        }
                    printf("enter the num of records to be entered\n");
                    scanf("%d",&n);
                    fnAddData(fp,n);
                    fclose(fp);
                    break;
            case 2: fp=fopen("EMP_DATA","r");
                     if(fp==NULL)
                        {
                            printf("file operation error\n");
                            break;
                        }
                        display(fp);
                         fclose(fp);
                        break;

            case 3: fp=fopen("EMP_DATA","r");
                            if(fp==NULL)
                            {
                            printf("file operation error\n");
                            break;
                            }
                           printf("enter the emp-id to be searched\n");
                           scanf("%u",&key.id) ;
                           flag= search_id(fp,key.id);
                           if(flag==1)
                           printf("\n serach succesful");
                           else
                            printf("\n serach UNsuccesful");
                             fclose(fp);
                            break;
                case 4:fp=fopen("EMP_DATA","r");
                            if(fp==NULL)
                        {
                            printf("file operation error\n");
                            break;
                        }
                           printf("enter the emp-salary to be searched\n");
                           scanf("%u",&key.salary) ;


                           flag=search_sal(fp,key.salary);

                           if(flag==1)
                           printf("\n serach succesful");
                           else
                            printf("\n serach UNsuccesful");
                             fclose(fp);
                            break;
                    case 5:fp=fopen("EMP_DATA","r");
                            if(fp==NULL)
                            {
                            printf("file operation error\n");
                            break;
                            }
                           printf("enter the emp-age to be searched\n");
                           scanf("%u",&key.age) ;
                           flag= search_age(fp,key.age);
                           if(flag==1)
                           printf("\n serach succesful");
                           else
                            printf("\n serach UNsuccesful");

                        fclose(fp);
                            break;


                    case 6:fp=fopen("EMP_DATA","r");
                            if(fp==NULL)
                        {
                            printf("file operation error\n");
                            break;
                        }
                           printf("enter the emp-dept to be searched\n");
                           scanf("%s",key.dept) ;
                           flag= search_dept(fp,key.dept);
                           if(flag==1)
                           printf("\n serach succesful");
                           else
                            printf("\n serach UNsuccesful");
                            fclose(fp);
                            break;
                    default:exit(0);
        }

    }
    return 0;
}
