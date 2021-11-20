#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of pages : ");
    scanf("%d",&n);
    int page[n];
    printf("Enter pages : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }
    int f;
    printf("Enter Frames : ");
    scanf("%d",&f);
    
    int m[f][2];
    for(int i=0;i<f;i++)
    {
        m[i][0]=-1;
        m[i][1]=0;
    }
    
    int i=1,hit=0,fau=1;
    
    m[0][0]=page[0];
    
    for(int j=0;j<f;j++)
    {
        printf("%d\t",m[j][0]);
    }
    printf("\n");
    
    while(i<n)
    {
        for(int j=0;j<f;j++)
        {
            if(m[j][0]==page[i])
            {
                hit++;
                break;
            }
            if(m[j][0]==-1)
            {
                m[j][0]=page[i];
                fau++;
                break;
            }
            if(j==f-1)
            {
                for(int k=i;k>0;k--)
                {
                    for(int jj=0;jj<f;jj++)
                    {
                        if(page[k]==m[jj][0])
                        {
                            m[jj][1]=1;
                        }
                    }
                    int sum=0;
                    for(int jj=0;jj<f;jj++)
                    {
                        sum=sum+m[jj][1];
                        
                    }
                    
                    if(sum==f-1 || k==1)
                    {
                        for(int jj=0;jj<f;jj++)
                        {
                            if(m[jj][1]==0)
                            {
                                m[jj][0]=page[i];
                                fau++;
                                break;
                            }
                        }
                        break;
                    }
                    
                }
            }
        }
        for(int j=0;j<f;j++)
        {
            printf("%d %d\t",m[j][0],m[j][1]);
        }
        printf("\n");
        for(int kk=0;kk<f;kk++)
        {
            m[kk][1]=0;
        }
        i++;
    }
    printf("hits:%d, fault:%d",hit,fau);
    
    
    return 0;
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1