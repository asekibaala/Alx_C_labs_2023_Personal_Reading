#include <stdio.h>
#include <stdlib.h>

int 
main(void)
{
    char *nam = "CPPINSTITUTE";
    char *val = "YES";
    char *prg = "5.1.1.6_Processes_and_threads.exe";
    int ret = system (prg);//first execute the program with out value set and store the return code in ret
    printf ("ret=%d\n---------------\n", ret);//print return code
    char buff[100];//define a variable buff since the function for windows putenv() expects one parameter
    sprintf (buff, "%s=%s", nam, val);// we format the name and value into the buff vairable using sprintf 
    putenv(buff);// we supply the buff into the function putenv()
    ret = system (prg);//we execute the app again to check if the value has been set and we stored the return code in ret
    printf ("ret=%d\n---------------\n", ret);//print return code
    sprintf(buff, "%s=",nam);//we format the buff again and set it to an empty value (unseting the value set)
    putenv(buff);//we supply the buff into the function putenv()
    ret = system (prg);//we execute the app again to check if the value has been set and we stored the return code in ret
    printf ("ret=%d\n---------------\n", ret);//print return code


    return 0;
}