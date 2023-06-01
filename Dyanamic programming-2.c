
Floyd washell code
#include<stdio.h>
main()
{
     int a[20][20],n;
     printf("Enter No of vertices\n");
     scanf("%d",&n);
     printf("enter the elements of adjacency matrix\n");
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               scanf("%d",&a[i][j]);
               if(a[i][j]==0)
               {
                    a[i][j]=999;
               }
          }
     }
     floyd_washell(a,n);
}
void floyd_washell(int a[20][20],int n)
{
     for(int k=0;k<n;k++)
     {
          for(int i=0;i<n;i++)
          {
               for(int j=0;j<n;j++)
               {
                    if(a[i][j]>a[i][k]+a[k][j])
                    {
                         a[i][j]=a[i][k]+a[k][j];
                    }
               }
          }
     }
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               printf("%d ",a[i][j]);

          }
          printf("\n");
     }


}
