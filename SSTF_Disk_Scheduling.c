#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int req[n][2];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i][0]);
        req[i][1]=0;
    }
    
    int first;
    scanf("%d",&first);
    
    int head=0;
    int p=0;
    while(p<n)
    {
        int min=9999;
        
        int j;
        for(int i=0;i<n;i++)
        {
            
            if(req[i][1]==0)
            {
                if(min>abs(req[i][0]-first) && req[i][0]!=first)
                {
                    j=i;
                    min=abs(req[i][0]-first);
                }
            }
        }
        head=head+abs(req[j][0]-first);
        req[j][1]=1;
        first=req[j][0];
        printf("%d %d %d\n",head,first,req[j][0]);
        p++;
    }
    printf("Total Head movement: %d",head);
}