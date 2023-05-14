#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_string(const char* str, char delimiter, size_t* word_count)
{
    char** words = NULL;
    *word_count = 0;
    char* token = strtok((char*)str, &delimiter);

    while (token != NULL) {
        words = realloc(words, sizeof(char*) * (*word_count + 1));
        words[*word_count] = token;
        (*word_count)++;
        token = strtok(NULL, &delimiter);
    }

    return words;
}

int main()
{
    char str[] = "This is a test string.";
    size_t word_count;
    char** words = split_string(str, ' ', &word_count);

    for (size_t i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }

    free(words);
    return 0;
}
