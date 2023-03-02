#include<stdio.h>
//#include<limits.h>

int a =9;
int main(){

    extern int a;
   /*int var1 = INT_MIN;
    int var2= INT_MAX;

    printf("range of signed interger is from %d to %d\n",var1,var2);
*/ 
    printf("%d",a);

    return 0;
}