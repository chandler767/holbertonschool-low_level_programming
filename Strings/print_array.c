int print_char(char c);

void print_number(int n)         
{
int v,t,d,i,u;
char p;
if (n == 0) {
  print_char('0'); /* Print '0' id n = 0. */
}
else
{
  if (n < 0) {
  print_char('-'); /* negative numbers need a '-' first. */
  }
  n = (((n<=0)-(n>0)) * n); /* We need n to be an absolute number (always positive) */
   for (t = 0, v = n; v<=-1; t++) 
    v /= 10;  /* make v = n and then / by 10 until < -1 */
    for (u = t; u > 0; u--) /* for each digit loop once*/
    {
      for (i=1, d=-1; u>i; i++) /* loop to figure out what to divide by */
      d *= 10; /* Multiply X 10 */
      p = ((n-(n%d))/d); /* This is how the first digit is determined */
      print_char('0' + p); /* Print */
      n -= (p * d); /* Remove the digit we printed from n */
    }
}
}

void print_array(int *a, int n)
{
	int i = 0;
	for(i = 0; i < n; i++) {
		print_number(a[i]);
		if ((i+1) == n) {
			print_char('\n');
		}else{
			print_char(',');
			print_char(' ');
		}
	}
}
