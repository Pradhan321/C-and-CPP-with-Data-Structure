#include<stdio.h>
#include<string.h>
struct Employee
{
    int id;
    float salary;
    char name[20];
  
  };
  struct Employee inputEmployee()
  {
    struct Employee e;
    printf("Enter your Id : ");
    scanf("%d",&e.id);
    printf("\nEnter your name : ");
    fflush(stdin);
    fgets(e.name,20,stdin);
    printf("\nEnter your salary : ");
    scanf("%f",e.salary);

    return e;
  }

  void displayEmployee(struct Employee e)
  {
    printf("Name : %s || Salary : %f || Id : %d ",e.name,e.salary,e.id);
  }

  struct Employee highestSalaryEmployee(struct Employee e[],int size)
  {
    
    struct Employee highemp=e[0];
    for (int i = 0; i < size; i++)
    {
      if(highemp.salary<e[i].salary)
      {
        highemp=e[i];
      }
    }
    return highemp;
  }
  struct Employee sort_employee_basedOn_salary(struct Employee e[],int size)
  {
    int r,i;
    for(r=1;r<size-1;r++)
    {
      for(i=0;i<size-1-r;i++)
      {
        if(e[i].salary>e[i+1].salary)
        {
          struct Employee temp;
          temp=e[i];
          e[i]=e[i+1];
          e[i+1]=temp;
        }
      }
    }
    return e;
  }
  struct Employee sort_employee_basedOn_Name(struct Employee e[],int size)
  {
    int r,i;
    for(r=1;r<size-1;r++)
    {
      for(i=0;i<size-1-r;i++)
      {
        if(strcmp(e[i].name,e[i+1].name)>0)
        {
          struct Employee temp;
          temp=e[i];
          e[i]=e[i+1];
          e[i+1]=temp;
        }
      }
    }
    return e;
  }
int main(){
 
  return 0;
}