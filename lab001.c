#include <stdio.h>
#include <string.h>

/**
 * main - checks for even nums and calculates their avg
 *
 * Return: 0 on success.
 */
int main(void)
{
  int bus[10];
  int i;
  int count, sum;
  float avg;

  sum = 0;

  /* getting user input */
  printf("Enter total number of integers to operate\n");
  
  scanf("%d", &count);
  /*
  count = sizeof(bus) / sizeof(int);
  */
  printf("count is: %d\n", count);
  printf("Enter a series of integers\n");

  for (i = 0; i < count; i++)
    {
      scanf("%d", &bus[i]);
    }
  /*for (i = 0; i < count; i++)
    {
      printf("%d", bus[i]);
    }
    printf("\n");*/
      
  /* check for even numbers */

  for (i = 0; i < count && bus[i] % 2 == 0; i++)
  {
    sum = sum + bus[i];
  }
  
  /* calculate avg */
  
  avg = sum / i;
  printf("average of all even numbers is: %f\n", avg);
  
  return (0);
}