#pragma once

void Swap(int* array, int x, int y)
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0; j--)
			if (array[j] < array[j - 1])
				Swap(array, j, j - 1);
}

void SelectSort(int* array, int size)
{
	int minIndex;

	for (int i = 0; i < size; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (array[minIndex] > array[j])
				minIndex = j;

		if (minIndex != i)
			Swap(array, i, minIndex);
	}
}

void Merge(int* array, int left, int mid, int right)
{
	int* temp = new int[right - left + 1];
	int i = left, j = mid + 1, m = 0;

	while (i <= mid && j <= right)
	{
		if (array[i] < array[j])
			temp[m++] = array[i++];
		else
			temp[m++] = array[j++];
	}

	while (i <= mid)
		temp[m++] = array[i++];

	while (j <= right)
		temp[m++] = array[j++];

	for (int n = left, m = 0; n <= right; n++, m++)
		array[n] = temp[m];

	delete temp;
}

void MergeSort(int* array, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}