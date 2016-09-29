 /* How this works: https://en.wikipedia.org/wiki/Insertion_sort */
void insertion_sort(int *array, int n)
{
        int c;
        int d;
        int temp; /* used to temp store values before rewriting to the array*/
        for (c = 1 ; c <= n - 1; c++) {
                d = c;
                while ( d > 0 && array[d] < array[d-1]) { /*  Arrange the numbers in the array in ascending order. */
                        temp = array[d];
                        array[d] = array[d-1];
                        array[d-1] = temp;
                        d--;
                }
        }
}
