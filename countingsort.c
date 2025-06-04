#include<stdio.h>
#include<stdlib.h>

void countingSort(int arr[], int n) {
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)
            k=arr[i];
    }
    int *count = (int *)malloc((k + 1) * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    

    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }
    

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        printf("\t%d",arr[i]);
    }
    
    free(count);    
    free(output);
}
void main()
{
    int a[100],n;
    printf("enter the size of the array : ");
    scanf("%d",&n);
    printf("enter array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    countingSort(a,n);
}