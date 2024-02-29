#include <Iostream>
#include "cstdio"
#include "cstring"

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
int Partition(int DataSet[],int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];
	++Left;
	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;
		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;
		
		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}
	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}
void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);
		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

void BubbleSort(int DataSet[],int Length)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for ( i = 0; i < Length -1; i++)
	{
		for (j = 0; j < Length -(i+1); j++)
		{
			if (DataSet[j] > DataSet[j+1])
			{
				temp = DataSet[j+1];
				DataSet[j+1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}
void InsertionSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int value = 0;

	for ( i = 1; i < Length; i++)
	{
		if (DataSet[i - 1] <= DataSet[i])
			continue;

		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j] > value)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main()
{
	int dataset[] = { 6,4,2,3,1,5 };
	int Length = sizeof dataset / sizeof dataset[0];
	int i = 0;

	QuickSort(dataset,0, Length-1);
	for ( i = 0; i < Length; i++)
	{
		std::cout << dataset[i]<< "\n";
	}
	return 0;
}