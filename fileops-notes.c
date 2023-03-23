fgetc(): This function reads a single character from a file and returns it as an integer value. For example, if we have a file named "test.txt" with the contents "hello", we can use fgetc() to read the first character ('h') like this:
scss
Copy code
FILE *fp;
int c;
fp = fopen("test.txt", "r");
c = fgetc(fp);
fclose(fp);
In this example, "fp" is our file pointer, "c" is an integer variable that will hold the value of the character we read, "fopen" opens the file in read mode, "fgetc" reads the first character from the file, and "fclose" closes the file.

fputc(): This function writes a single character to a file. For example, we can use fputc() to write the letter 'a' to a file like this:
scss
Copy code
FILE *fp;
fp = fopen("test.txt", "w");
fputc('a', fp);
fclose(fp);
In this example, we open the file in write mode ("w"), write the character 'a' to the file using fputc(), and then close the file using fclose().

fgets(): This function reads a line of text from a file and stores it in a character array. For example, we can use fgets() to read the first line of a file named "test.txt" like this:
scss
Copy code
FILE *fp;
char str[100];
fp = fopen("test.txt", "r");
fgets(str, 100, fp);
fclose(fp);
In this example, "str" is a character array that will hold the line of text we read, "fgets" reads the first line from the file, and we close the file using fclose().

fputs(): This function writes a string of text to a file. For example, we can use fputs() to write the string "hello world" to a file like this:
scss
Copy code
FILE *fp;
fp = fopen("test.txt", "w");
fputs("hello world", fp);
fclose(fp);
In this example, we open the file in write mode ("w"), write the string "hello world" to the file using fputs(), and then close the file using fclose().

fread(): This function reads a block of data from a file and stores it in a memory buffer. For example, we can use fread() to read 10 integers from a file named "test.txt" like this:
scss
Copy code
FILE *fp;
int buffer[10];
fp = fopen("test.txt", "rb");
fread(buffer, sizeof(int), 10, fp);
fclose(fp);
In this example, "buffer" is an array of integers that will hold the data we read, "fread" reads 10 integers from the file, and we close the file using fclose().

fwrite(): This function writes a block of data from a memory buffer to a file. For example, we can use fwrite() to write 10 integers to a file named "test.txt" like this:
scss
Copy code
FILE *fp;
int buffer[10];
fp = fopen("test.txt", "wb");
fwrite(buffer, sizeof(int), 10, fp);
fclose(fp);



