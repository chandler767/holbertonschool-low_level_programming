#include <unistd.h>

int toInt(char a[]);
int print_char(char c);
void print_line(int i, int len);

int main(int argc, char **argv)
{
  int i = 0;
  int len = toInt(argv[1]) -1;
  if (argc < 2) {
	return (1); /* no size provided */
  }
  for (i=0 ; i<=len; i++) { /* For each row */
	print_line(i, len); /* print_line([Current row], [Size]); */
  	print_char('\n');
  }
  return (0);
}

void print_line(int i, int len) { /* print each row */
	int col = 0;
	for (col = 0; col<=len ; col++) {
		if ((i == (len-i)) && col == i) {
			print_char('X'); /* Center */
		} else if (col == (len-i)) {
			print_char('/'); /* Forward slash */ 
		} else if (col == i) {
			print_char('\\'); /* Backslash */ 
		} else {
			print_char(' '); /* Space */
		}	
	}
}

int toInt(char a[]) {
  int c = 0;
  int sign = 0;
  int offset = 0;
  int n = 0;
  if (a[0] == '-') {  
    sign = -1; /* Is the number positive? */
  }
  if (sign == -1) {  
    offset = 1;
  } else {
    offset = 0;
  } 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0'; /* Step until the entire array has been read */ 
  }
  if (sign == -1) {
    n = -n;
  }
  return n; /* return n as an a[] > int */
}

