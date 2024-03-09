# include<stdio.h> 

void merge(int a[], int lb, int mid, int ub);
void mergeSort(int a[], int lb, int ub);

int main()
{
    
    int n, i;
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements in array : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array is : \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    int b[k];
    
    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if(i > mid)
    {
        while(j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for(k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void mergeSort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}