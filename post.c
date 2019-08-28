#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
 char k;
 struct node *next;
}*head=NULL,*curr=NULL;
int top=-1;
void push(char *a,char ch)
{
  if(top==-1)
   {
     top=0;
   }
  else
   {
     top=top+1;
   }
  a[top]=ch;
}
char pop(char *a)
{
  char ch;
  if(top==-1)
   {
     top=0;
   }
  else
   {
     ch=a[top];
     top=top-1;
   }
return ch;
}

void insert(char ch)
{
 struct node *new1;
 new1=(struct node*)malloc(sizeof(struct node));
 printf("%c",ch);
 new1->k=ch;
 new1->next=NULL;
 if(head==NULL)
   {
     head=new1;
     curr=new1;
   }
 else
   {
     curr->next=new1;
     curr=new1;
   }
}
void main()
{
  int i=0,j=0,z=0,m=0,l=0,v;
  char s[20],ch,a[20];
  char b[2]={"*/"};
 // char c[2]={"+-("};
  printf("ENTER THE EXPRESSION:");
  scanf("%s",s);
  while(s[i]!='\0')
   {
    if(s[i]=='('){
      push(a,s[i]);
      i=i+1;}
    if(!(isalpha(s[i])))
     { 
     
     if(s[i]==')')
       {
         do
          {
            ch=pop(a);
            if(ch!='('){
            insert(ch);}
          }
         while(ch!='(');
       i=i+1;
       }
    if(l==1)
     {
     v=1;
     
     while(v==1){
      z=0;
     m=0;
     while(b[j]!='\0')
      {
       if(b[j]==s[i])
        {
          z=1;
         
        }
       j=j+1; 
      }
      j=0;
      while(b[j]!='\0')
       {
       if(a[top]==b[j])
        {
          m=1;
         
        }
       j=j+1;
       }
       j=0;
       if(s[top]=='('){
         m=-1;}
       if(m<z)
        {
       //  printf("%d",1);
         push(a,s[i]);
         v=0;
        }
        
 
       else
        {
         if(top!=-1){
         ch=pop(a);
     //     printf("%d",2);
       //  push(a,s[i]);
         insert(ch);}
         else{
           push(a,s[i]);
           v=0;} 
        }
      }
    }
    else
    {
      push(a,s[i]);
      l=1;
    }
   }
   else

    {
     insert(s[i]);
    }
   i=i+1;
  }
 do
  {
    ch=pop(a);
    insert(ch);
  }
 while(top!=-1); 
}
