#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

void
is (wchar_t ch)
{
  printf ("%d %d %d\n", ! !iswlower (ch), ! !iswupper (ch), ! !iswalnum (ch));
}

int
main (void)
{
  setlocale (LC_ALL, "");
  is (L'N2');
  is (towupper (L'N2'));
  is (L'N(');
  is (L'\u03B3');		// lower gamma
  is (0x3A0);			// upper pi but as an int
  return 0;
}