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



fscanf(): This function reads formatted data from a file. It's similar to scanf(), but instead of reading from the keyboard, it reads from a file. For example, we can use fscanf() to read two integers from a file named "test.txt" like this:
perl
Copy code
FILE *fp;
int num1, num2;
fp = fopen("test.txt", "r");
fscanf(fp, "%d %d", &num1, &num2);
fclose(fp);
In this example, "num1" and "num2" are integer variables that will hold the values we read, "fscanf" reads two integers from the file using the format string "%d %d", and we close the file using fclose().

fputs(): This function writes a string to a file, similar to puts() which writes to the console. For example, we can use fputs() to write the string "hello world" to a file like this:
scss
Copy code
FILE *fp;
fp = fopen("test.txt", "w");
fputs("hello world", fp);
fclose(fp);
In this example, we open the file in write mode ("w"), write the string "hello world" to the file using fputs(), and then close the file using fclose().

fprintf(): This function writes formatted data to a file, similar to printf() which writes to the console. For example, we can use fprintf() to write an integer variable to a file named "test.txt" like this:
scss
Copy code
FILE *fp;
int num = 42;
fp = fopen("test.txt", "w");
fprintf(fp, "The answer is %d", num);
fclose(fp);
In this example, we open the file in write mode ("w"), write the formatted string "The answer is 42" to the file using fprintf(), and then close the file using fclose().

ftell(): This function returns the current position of the file pointer. For example, we can use ftell() to find out where we are in a file named "test.txt" like this:
scss
Copy code
FILE *fp;
long pos;
fp = fopen("test.txt", "r");
pos = ftell(fp);
fclose(fp);
In this example, "pos" is a long integer variable that will hold the position of the file pointer, "ftell" returns the current position of the file pointer, and we close the file using fclose().

fseek(): This function moves the file pointer to a specific position in the file. For example, we can use fseek() to move the file pointer to the 10th byte in a file named "test.txt" like this:
scss
Copy code
FILE *fp;
fp = fopen("test.txt", "r");
fseek(fp, 10, SEEK_SET);
fclose(fp);
In this example, "fseek" moves the file pointer to the 10th byte in the file using SEEK_SET (which means to start counting from the beginning of the file), and we close the file using fclose().

feof(): This function checks if the end of a file has been reached. For example, we can use feof() to check if we have reached the end of a file named "test.txt" like this:
scss
Copy code
FILE *fp;
int c;
fp = fopen("test.txt", "r");
while ((c = fgetc(fp)) != EOF) {
  // Do something with the character
}
if (feof(fp)) {
  printf("End of file reached");
}
fclose(fp);
In this example, "feof" is used inside a loop that reads characters from the




