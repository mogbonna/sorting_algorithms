#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using Quick sort with Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in @array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);

	/* Recursively sort the sub-arrays */
		quicksort_recursive(array, low, partition - 1, size);
		quicksort_recursive(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
	/* Swap elements */
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
	/* Print the array after each swap */
			print_array(array, size);
		}
	}
	/* Swap the pivot element to its correct position */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after the final swap */
	print_array(array, size);

	return (i + 1);
}
