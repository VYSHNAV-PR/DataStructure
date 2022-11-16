#include<stdio.h>
#include<stdlib.h>
#define size 10
int q[size];
int rear=0;front=0;
void insertq(int item)
{
 int r1=rear;
 r1=(r1+1)%size;
if(r1==front)
 printf("Queue is full");
else{

rear=r1;
q[rear]=item;
}
}

int deleteq(int * status)
{

if(front==rear){
*status=0;
printf("Queue is empty");}
 else
{
 front=(front+1)%size;
*status=1;
return q[front];
}
}

int searchq(int item)
{
  if(front!=rear)
{
  int t;
  t=front;
  t=(t+1)%size;
  while(t!=rear&&q[t]!=item)
    t=(t+1)%size;
  if(q[t]==item)
  return t;
else
 return 0;
}
else
return 0;
}


void main()
{
  int item,opt,ans,status;
  do
{
   printf("1.Insert the element\n");
   printf("2.Delete the element\n");
   printf("3.Search the element\n");
   printf("4.Exit\n");
   printf("Enter the option:");
   scanf("%d",&opt);

   switch(opt)
{
   case 1:printf("Enter the data:");
         scanf("%d",&item);
         insertq(item);
	 break;
  case 2:item=deleteq(&status);
         if(status==1)
        printf("Deleted=%d\n",item);
        break;
 case 3:printf("Enter the number to search:");
       scanf("%d",&item);
       ans=searchq(item);
        if(ans==0)
	   printf("Item not Found\n");
        else 
          printf("Found at %d location\n",ans);
        break;
  case 4:exit(0);
}	    	
}
while(1);
}
