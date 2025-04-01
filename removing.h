#include <stdio.h>
#include <string.h>

void removing() {
    FILE *file = fopen("logs.csv", "r"); // Open original file in read mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w"); // Create a temporary file
    if (temp == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return;
    }

    char line[200], word[50];
    printf("Enter word to remove its line: ");
    gets(word);

    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) { // Read file line by line
        if (strstr(line, word) != NULL) { // Check if the line contains word
            found = 1;
            fprintf(temp, "\n"); // Replace the line with an empty space
        } else {
            fprintf(temp, "%s", line); // Copy other lines as it is
        }
    }
  
    fclose(file);
    fclose(temp);

    // Replace original file with modified temp file
    remove("logs.csv");
    rename("temp.csv", "logs.csv");

    if (found)
        printf("Line containing '%s' replaced with blank space.\n", word);
    else
        printf("Word '%s' not found in any line.\n", word);
            
}


