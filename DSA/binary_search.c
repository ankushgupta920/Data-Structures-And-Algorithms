#include<stdio.h>
int main()
{
    int arr[]={10,20,40,50,60,80,90};
    int size= sizeof(arr)/sizeof(int);
    int lr=0,mid,upr=size,f=0,item;
    printf("Enter the searching item ");
    scanf("%d",&item);
    while(lr<=upr)
    {
        mid=(lr+upr)/2;
        if(arr[mid]==item)
        {
            f=1; break;
        }
        if(arr[mid]< item)
        {
            lr=mid+1;
        }
        else
        {
            upr=mid-1;
        }

    }
    if(f==1)
    {
        printf("Item found: %d",item);
    }
    else
    {
        printf("Item not found ");
    }
    return 0;
}