#include<stdio.h>

void quickSort(int k[], int low, int high)
{
	int I, J, key, flag = 0, temp;
	if(low < high)
	{
		I = low;
		J = high + 1;
		key = k[low];
		while(flag == 0)
		{
			I = I + 1;
			while(k[I] < key)
			{
				I = I + 1;
			}
			J = J - 1;
			while(k[J] > key)
			{
				J = J - 1;
			}
			if(I < J)
			{
				temp = k[I];
				k[I] = k[J];
				k[J] = temp;
			}
			else
			{
				flag = 1;
			}
		}
		temp = k[low];
		k[low] = k[J];
		k[J] = temp;
	
		quickSort(k, low, J - 1);
		quickSort(k, J + 1, high);
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