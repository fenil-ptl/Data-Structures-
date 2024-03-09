# include<stdio.h> 

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    int temp;

    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            // Swapping values of start and end
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Swapping values of lb and end
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void quickSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1); /* Recursive calling */
        quickSort(arr, loc + 1, ub);
    }
}

int main()
{
	
	int size;
	printf("Enter number of elements in array : ");
	scanf("%d", &size);
	int arr[size];
	
	printf("Enter elements in array : \n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	quickSort(arr, 0, size - 1);
	
	printf("Sorted array : ");
	for(int i = 0; i < size; i++)
	{
		printf("%d  ", arr[i]);
	}
    return 0;
}