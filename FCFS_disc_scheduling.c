/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int mod(int a,int b)
{
    if(a>b)
    {
        return a-b;
    }
    else return b-a;
}

int main()
{
    int n;
    printf("Enter no. of tracks: ");
    scanf("%d",&n);
    
    int track[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&track[i]);
    }
    
    int s;
    printf("Enter Starting point: ");
    scanf("%d",&s);
    int sum=0;
    for(int i=1;i<n;i++)
    {
        int temp=mod(track[i],track[i-1]);
        sum=sum+temp;
        printf("%d\t%d\n",track[i],temp);
    }
    sum=sum+mod(track[0],s);
    
    printf("%d\n",sum);
    float f=sum/n;
    printf("Average Header movement: %f",f);
    
    return 0;
}
