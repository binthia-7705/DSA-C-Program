/* This program replaces all occurrences of a word in a text file with another word */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This function checks if the word matches the string at the given position
int match(char *s, char *word, int pos)
{
    int i=0;
    while(word[i]!='\0' && s[pos + i] != '\0') 
    {
        if (s[pos + i] != word[i])
        {
            return 0;
        }
        i++;
    }
    return (word[i] == '\0'); // Return true if we reached the end of the word
}

//This is the main program
void main()
{
    // Open the file for reading
    FILE *fp;
    char s[1000], old[100], result[100], new[100];
    int i=0, j=0;
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        s[i++] = (char)ch;
    }
    s[i] = '\0';
    fclose(fp);

    // Get the old and new words from the user
    printf("Enter the word to be replaced: ");
    scanf("%s", old);
    printf("Enter the new word: ");
    scanf("%s", new);
    int old_len = strlen(old);
    int new_len = strlen(new);

    //Matching and replacing the old word with the new word
    i=0;
    while(s[i]!='\0')
    {
        if (match(s, old, i))
        {
            for (int k = 0; k < new_len; k++)
            {
                result[j++] = new[k]; // Insert new word
            }
            i += old_len; // Move index forward
        }
        else
        {
            result[j++] = s[i++];
        }
    }
    result[j] = '\0';

    // Open the file for writing
    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        printf("File not found\n");
    }
    fputs(result, fp);
    printf("Replacement done successfully.\n");
    fclose(fp);
}
