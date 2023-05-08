#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int
main (void)
{
  int i;
  mpz_t fact;
  mpz_init (fact);

  mpz_set_ui (fact, 1);
  for (i = 1; i <= 50; i++)
    {
      mpz_mul_ui (fact, fact, i);
      char *str = mpz_get_str (NULL, 10, fact);
      printf ("%2d! = %s\n", i, str);
      free (str);
    }
  return 0;
}

/*
line 3:  the <gmp.h> header file contains all the entities needed to successfully compile the program – this is mandatory; by the way, when compiling the code, you’ll need an option denoted as
  -lgmp (the option points the library to the link)

  line 9: we declare a multi-precision integer value named fact of type mpz_t;

  line 10: each multi-precision variable has to be initialized before the first use – if the variable is a multi-precision integer, 
  the initialization is done by the mpz_init() function;

  line 12: the regular assignment operator = does not work with mpz_t values – it can’t assign an integer value to the variable; this kind of operation is done, for example, by the function mpz_set_ui (it sets an mpz 
  variable with a regular unsigned integer value passed through the second argument)

 line 15: nor can the good old * operator multiply mpz_t values; we have to use one of the dedicated functions, e.g. mpz_mul_ui(); note: an invocation of the form:
mpz_mul_ui(x,y,z)
acts as:

x = y * z

where x and y are of mpz_t type and z is an unsigned integer:

line 16: mpz_t values cannot be directly printed by the printf() function – they have to be explicitly converted into strings first – this can be done by the function mpz_get_str() using the following arguments:
a pointer to the target buffer, or NULL if the function should allocate the result buffer itself;
a radix for the result;
an mpz_t value to convert;
line 15: the memory allocated by the mpz_get_str() should be explicitly freed to avoid memory leaks.
*/