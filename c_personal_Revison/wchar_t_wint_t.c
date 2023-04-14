#include <stdio.h>
#include <wchar.h>

int main()
{
    printf("%ld, %ld",sizeof(wchar_t), sizeof(wint_t));

    return 0;
    
}