 /* How this works: https://en.wikipedia.org/wiki/Quicksort */

void quick_sort(int *array, int n)
{
        int count = 0;
        int j = 0;
        int p = 0;
        int temp = 0; /* used to temp store values before rewriting to the array*/

        if (n < 2) {
                return;
        }

        p = array[n / 2]; /* using the midpoint of the array as a pivot. Why? The worst pivot creates an empty partition (for example, if the pivot is the first or last element of a sorted array). */ 
        for (count = 0, j = n - 1;; count++, j--) { /* For each in the array */
                while (array[count] < p) /* greater */
                        count++;
                while (p < array[j]) /* less than */
                        j--;
                if (count >= j)
                        break; /* equal - no swap*/
                temp = array[count];
                array[count] = array[j]; 
                array[j] = temp;
        }
        
        quick_sort(array, count);
        quick_sort(array + count, n - count); /* Work done using recursion for each partition*/
}
