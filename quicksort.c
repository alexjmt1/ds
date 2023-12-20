#include <stdio.h>

void quicksort(int a[], int first, int last);

void main() {
    int i, count, a[25];
    printf(" enter the no  element ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, count - 1);

    printf("Sorted elements");
    for (i = 0; i < count; i++)
        printf(" %d", a[i]);

    printf("\n");
}

void quicksort(int a[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
/*1. Choose a pivot: We pick the first element a[first] as the pivot (you can choose other strategies too).
2. Partition the array: We use two pointers, i and j, to scan the array.
•	i starts at first and moves right, searching for elements greater than or equal to the pivot.
•	j starts at last and moves left, searching for elements less than the pivot.
•	If i and j meet before reaching the end, we swap their values. This keeps elements less than the pivot on the left and elements greater than it on the right.
3. Place the pivot: Once i and j cross, we swap the pivot (a[first]) with the element at j. This puts the pivot in its final sorted position.
4. Recursively sort sub-arrays:
•	Call quicksort again on the left sub-array (elements from first to j-1).
•	Call quicksort again on the right sub-array (elements from j+1 to last).
*/
