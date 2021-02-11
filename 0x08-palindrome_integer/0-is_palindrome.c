#include "palindrome.h"

/**
* is_palindrome - checks if a given unsigned integer is a palindrome
* @n: integer to test
*
* Return: 1 if n is a palindrome, and 0 otherwise
*/

int is_palindrome(unsigned long n)
{
int reverse = 0, r, n_copy;
n_copy = n;
while (n != 0)
{
r = n % 10;
reverse = reverse * 10 + r;
n = n / 10;
}
if (n_copy == reverse)
return (1);
else
return (0);
}
