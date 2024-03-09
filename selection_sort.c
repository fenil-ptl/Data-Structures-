# include<stdio.h> 

void selectionSort(int arr[], int n);

int main()
{
    

    int n, i, j, min_index, temp;
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements in array : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted Array is : \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index, temp;
    for(i = 0; i < n-1; i++)
    {
        min_index = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        
        if(min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}