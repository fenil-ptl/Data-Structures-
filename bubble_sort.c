# include<stdio.h> 

void bubbleSort(int arr[], int length);

int main()
{
    
    int length, i;

    printf("\nEnter number of elements : ");
    scanf("%d", &length); 
    int arr[length];

    printf("\nEnter elements in array : \n");
    for(i=0; i<length; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using bubbleSort
    bubbleSort(arr, length);

    printf("Sorted array is : \n");
    for(int i=0; i<length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void bubbleSort(int arr[], int length)
{
    int i, j, temp, exchange;
    for(i=0; i<length - 1; i++)
    {
        exchange = 0;
        for(j=0; j<length - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchange += 1;
            }
        }
    }

    if(exchange == 0)
    {
        printf("Array is sorted\n");
    }
}