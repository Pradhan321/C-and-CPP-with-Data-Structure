#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char* inputString()
{
  char ch,*p=NULL,*q=NULL;
  int size=1,i;
  printf("Enter your text : ");
  p=(char*)malloc(size);
  p[0]='\0';
  while(1)
  {
    ch=getchar();
    if(ch=='\n')
      break;
    q=(char*)malloc(size+1);
    for( i=0;i<size;i++)
      q[i]=p[i];
    q[i-1]=ch;
    q[i]='\0';
    free(p);
    size++;
    p=(char*)malloc(size);
    strcpy(p,q);
    free(q);
  }
  return p;
}


void f1(){
  char*ptr=NULL;
  ptr=inputString();
  printf("%s",ptr);
  printf("\n");
}

void f2()
{
  int *p,size,i,s=0;
  float avg;
  printf("Enter the number that you want to store : ");
  scanf("%d",&size);
  p=(int*)malloc(sizeof(int)*size);
  printf("Enter %d numbers : ",size);
  for(i=0;i<size;i++)
    scanf("%d",p+i);
  for(i=0;i<size;i++)
    s=s+p[i];
  avg=(float)s/size;
  printf("Average is %f",avg);
}
void f3()
{
  int *p,size,i,s=0;
  
  printf("Enter the number that you want to store : ");
  scanf("%d",&size);
  p=(int*)malloc(sizeof(int)*size);
  printf("Enter %d numbers : ",size);
  for(i=0;i<size;i++)
    scanf("%d",p+i);
  for(i=0;i<size;i++)
    s=s+p[i];
  printf("Sum is %d",s);
  free(p);
}
int* mergeArray(int* sizeOut)
{
  int size1,size2,i,*arr;
  printf("Enter the size of first array : ");
  scanf("%d",&size1);
  int arr1[size1];
  printf("Enter %d element : ",size1);
  for(i=0;i<size1;i++)
  {
    scanf("%d",&arr1[i]);
  }
  printf("Enter the size of second array : ");
  scanf("%d",&size2);
  int arr2[size2];
  printf("Enter %d element : ",size2);
  for(i=0;i<size2;i++)
  {
    scanf("%d",&arr2[i]);
  }
  int size=size1+size2;
  arr=(int*)malloc(sizeof(int)*size);
  
  for(i=0;i<size1;i++)
  {
    arr[i]=arr1[i];
  }
  for(int i=0;i<size2;i++)
  {
    arr[size1+i]=arr2[i];
  }
  *sizeOut=size;
  return arr;
}
void f4(){
  int size;
  int *ptr=NULL;
  ptr=mergeArray(&size);
  
  for(int i=0;i<size;i++)
  {

    printf("%d ",ptr[i]);
  }
  free(ptr);
  printf("\n");
}

struct Student
{
  char name[20];
  int rollNumber;
  char CollegeName[20];
};
struct Team
{
  struct Student s1;
  struct Student s2;
};
struct Student* newStudent(char n[],int r,char c[])
{
  struct Student *p;
  p=(struct Student*)malloc(sizeof(struct Student));
  strcpy(p->name,n);
  p->rollNumber=r;
  strcpy(p->CollegeName,c);
  return p;
}
struct Team* newTeam(struct Student x,struct Student y)
{
  struct Team *p;
  p=(struct Team*)malloc(sizeof(struct Team));
  p->s1=x;
  p->s2=y;
  return p;
}
void display_DataofStudent(struct Student s){
  printf("\nName of the Student : %s",s.name);
  printf("\nRoll Number of Student : %d",s.rollNumber);
  printf("\nCollege-Name of the Student : %s\n",s.CollegeName);
}
void display_DataofTeam(struct Team t){
  printf("\nTeam:\n");
  display_DataofStudent(t.s1);
  display_DataofStudent(t.s2);
}
struct Student**createStudentArray(int size){
  struct Student **ptr;
  ptr=(struct Student**)malloc(size*sizeof(struct Student*));
  return ptr;
}
struct Team**createTeamArray(int size)
{
  struct Team **ptr;
  ptr=(struct Team**)malloc(size*sizeof(struct Team*));
  return ptr;
}
void driverFunction(){
  char n[6][10]={"Aman","Raghav","Ganesh","Som","Avinash","Pawan"};
  int i,r[6]={101,102,103,104,105,106};
  char c[6][10]={"CKC","MKC","LPU","CU","BIT","IIT"};
  struct Student**sptr;
  struct Team **tptr;
  sptr=createStudentArray(6);
  tptr=createTeamArray(3);
  for(i=0;i<=5;i++)
    sptr[i]=newStudent(n[i],r[i],c[i]);
  tptr[0]=newTeam(*sptr[0],*sptr[2]);
  tptr[1]=newTeam(*sptr[4],*sptr[1]);
  tptr[2]=newTeam(*sptr[3],*sptr[5]);
  for(i=0;i<=2;i++)
    display_DataofTeam(*tptr[i]);

}
int main()
{
  // f2();
  // f3();
  // f4();
  driverFunction();
  printf("\n");
  return 0;
}