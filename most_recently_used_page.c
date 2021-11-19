/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of pages : ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter pages : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    int f;
    printf("Enter Frames : ");
    scanf("%d",&f);
    
    int m[f];
    for(int i=0;i<f;i++)
    {
        m[i]=-1;
    }
    int hit=0,fau=1,i=1;
    m[0]=pages[0];
    for(int j=0;j<f;j++)
    {
        printf("%d\t",m[j]);
    }
    printf("\n");
    while(i<n)
    {
        for(int j=0;j<f;j++)
        {
            if(m[j]==pages[i])
            {
                hit++;
                break;
            }
            if(m[j]==-1)
            {
                fau++;
                m[j]=pages[i];
                break;
            }
            if(j==f-1)
            {
                for(int k=i;k>0;k--)
                {
                    int temp=0;
                    for(int jj=0;jj<f;jj++)
                    {
                        if(pages[k]==m[jj])
                        {
                            m[jj]=pages[i];
                            temp=1;
                            break;
                        }
                        
                    }
                    if(temp==1)
                    {
                        break;
                    }
                }
                fau++;
            }
        }
        for(int j=0;j<f;j++)
        {
            printf("%d\t",m[j]);
        }
        printf("\n");
        
        i++;
    }
    printf("hits=%d\tfault=%d",hit,fau);
    return 0;
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
