 /* How this works: https://en.wikipedia.org/wiki/Bubble_sort */

void bubble_sort(int *array, int n)
{
  int count;
  int dire;
  int temp; /* used to temp store values before rewriting to the array*/

  for (count = 0 ; count < ( n - 1 ); count++)
  {
    for (dire = 0 ; dire < n - count - 1; dire++)
    {
      if (array[dire] > array[dire+1])
      { 
        temp = array[dire]; /* assign to temp */
        array[dire] = array[dire+1]; /* name current = the next */
        array[dire+1] = temp; /* make the next equal the current */
      }
    }
  }
}
