int main()
{
	char buffer[100]; // Declare a char array to hold the content of each line read from a file
	FILE *fileSource = fopen("main.c", "r"); // Open the file "main.c" for reading
	if (fileSource == NULL) // Check if the file was opened successfully
	{
		puts("Error opening file."); // Print an error message to the console
		return 1; // Exit the program with a non-zero status code to indicate an error
	}
	char filename[FILENAME_MAX] = "maincopy.c"; // Declare a string to hold the filename of the copy file FILENAME_MAX is a 
    //constant defined in the C standard library stdio.h. 
    //It represents the maximum length of a file name on the system and is usually defined as a macro
	FILE *fileExistsHandler = fopen(filename, "r"); // Open the copy file for reading to check if it exists
	int triesLimit = 1000; // Declare a limit to the number of copy files that can be created
	int triesCount = 0; // Declare a counter to keep track of the number of copy files created
	while(fileExistsHandler) // Keep checking for copy files until one with a unique name is found
	{
		fclose(fileExistsHandler); // Close the file handle
		triesCount++; // Increment the counter
		if (triesCount > triesLimit) // Check if the number of copy files has exceeded the limit
		{
			puts("File count limit reached."); // Print an error message to the console
			return 1; // Exit the program with a non-zero status code to indicate an error
		}
		sprintf(filename, "maincopy_%d.c", triesCount); // Create a new filename with a suffix based on the counter
		fileExistsHandler = fopen(filename, "r"); // Open the copy file for reading to check if it exists
	}
	FILE *fileDestination = fopen(filename, "w"); // Open the copy file with a unique name for writing
	if (fileDestination == NULL) // Check if the file was opened successfully
	{
		puts("Error opening file."); // Print an error message to the console
		return 1; // Exit the program with a non-zero status code to indicate an error
	}
	while (fgets(buffer, sizeof(buffer), fileSource)) // Read each line of the source file
	{
		fprintf(fileDestination, "%s", buffer); // Write each line to the copy file
	}
	fclose(fileSource); // Close the source file handle
	fclose(fileDestination); // Close the copy file handle
	return 0; // Exit the program with a status code of 0 to indicate success
}
