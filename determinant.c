#include<stdio.h>
#include<stdlib.h>
int h=0,r,c;
void det(int i,int d,int **a,int *b,int k)
 {
   int q,z=-1,e,j,m=1,s;
   for(j=0;j<c;j++)
    {
      q=0;
      e=d;
      for(s=0;s<k;s++)
       {
         if(*(b+s)==j)
          {
            q=1;
            break;
          }
       }
      if(q==0)
       {
             z=z+1;
             if((z%2)==0)
               {
                 m=1;
               }
             else
               {
                 m=-1;
               }
         d=d*m*(*(*(a+i)+j));
         if(i!=(r-1))
          {
            *(b+k)=j;
            k=k+1;
            det(i+1,d,a,b,k);
            k=k-1;
          }
         else
          {
               h=h+d;
          }
         d=e;
      }
   }
 }
void main()
 {
   int **a,*b,i,j;
   printf("ENTER THE NUMBER OF ROWS AND COLUMNS OF THE MATRIX:");
   scanf("%d%d",&r,&c);
   a=(int **)malloc(r*sizeof(int *));
   b=(int *)malloc(c*sizeof(int));
   printf("ENTER THE ELEMENTS IN TO THE MATRIX:");
   for(i=0;i<r;i++)
    { 
     *(a+i)=(int *)malloc(c*sizeof(int));
      for(j=0;j<c;j++)
       {
         scanf("%d",(*(a+i)+j));
       }
    }
   det(0,1,a,b,0);
   printf("%d\n",h);
 }         
