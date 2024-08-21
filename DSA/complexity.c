// Linear space complexity:
#include<stdio.h>
int Sum(int arr[],int n)
{
    printf("Array size %d Bytes\n ",sizeof(arr));// Array:-8n
    int sum=0,i;
    printf("%d Bytes\n ",sizeof(n));
    printf("%d Bytes\n ",sizeof(int));
    printf("%d Bytes\n ",sizeof(sum));
    printf("%d Bytes\n ",sizeof(i));
    for(i=0;i<n;i++)
    {
        sum=sum+arr[i];
       
    }
    return sum;
}
int main()
{
    int size,i,value;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int a[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    value=Sum(a,size);
    printf("\nSum: %d",value);
    return 0;
}