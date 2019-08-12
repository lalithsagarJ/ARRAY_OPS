#include<stdio.h>
#include<stdlib.h>
int insert(int n,int a[100],int p,int e);
int delete(int n ,int a[n],int p);
int search(int n,int a[n],int e);
int traverse(int n,int a[n]);
int element(int i)
{
   int e=0;
   if(i==1)
   {
      printf("enter the element to be inserted :\n");
      scanf("%d",&e);
   }
   if(i==3)
   {
      printf("enter the element to be searched :\n");
      scanf("%d",&e);
   }
   return e; 
}
int position(int i)
{
   int p=0;
   if(i==1)
   {
      printf("enter the position to be inserted :\n");
      scanf("%d",&p);
   }
   else if(i==2)
   {
      printf("enter the position to be deleted :\n");
      scanf("%d",&p);
   }
   return p;
}
int main()
{
   int n,p;
   printf("enter the number of elements :\n");
   scanf("%d",&n);
   int a[n];
   printf("enter the elements :");
   for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
   int ele;
   int ch;
   printf("enter 1 for insertion\t2 for deletion\t3 for searching\t4 for traversing :\n");
   scanf("%d",&ch);
   ele=element(ch);
   p=position(ch);
   switch(ch)
   {
      case 1:insert(n,a,p,ele);
             break;
      case 2:
             delete(n,a,p);
             break;
      case 3:
             search(n,a,ele);
             break;
      case 4:traverse(n,a);
             break;
      default:printf("wrong choice");
              break;
   }
   return 0;
}
int insert(int n,int a[n],int p,int e)
{
   if(p>n+1)
   {
      printf("insertion is not possible ");
      exit(0);
   }
   p=p-1;
   for(int i=n-1;i>=p;i--)
   {
      a[i+1]=a[i];
   }
   a[p]=e;
   n=n+1;
   printf("the elements after insertion are :");
   for(int i=0;i<n;i++)
      printf("%d ",a[i]);
   return 0;
}
int delete(int n,int a[n],int p)
{
   if(n<0)
   {
     printf("array is empty \n");
     exit(0);
   }
   p=p-1;
   int e=a[p];
   for(int i=p;i<n;i++)
      a[i]=a[i+1];
   n=n-1;
   printf("the elements after deletion are :\n");
   for(int i=0;i<n;i++)
      printf("%d ",a[i]);
   return 0;
}
int search(int n,int a[n],int e)
{
   int i;
   for(i=0;i<n;i++)
   {
      if(a[i]==e)
      {
        printf("element %d is present in position %d",e,i+1);
        break;
      }
   }
   if(i==n)
     printf("element %d is not present ",e);
}
int traverse(int n,int a[n])
{
   if(n<0)
     printf("array is empty ");
   else
   {
      for(int i=0;i<n;i++)
         printf("%d ",a[i]);
   }
}
