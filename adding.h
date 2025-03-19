#include<stdio.h>
#include<string.h>
void add(){
    FILE* ptr;
    ptr = fopen("logs.csv","a+");
    if (ptr == NULL) { //checking if file properly opened
        printf("Error opening file");
        return;  
    }
    char date[10], event[100];
    fseek(ptr, 0, SEEK_END);  //checking if file is empty
    if (ftell(ptr) == 0) {
        fputs("date, name\n", ptr); 
    }
    //taking data from user
    printf("Enter Date: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    printf("Enter event name: ");
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = '\0';

    char str[112];
    sprintf(str,"%s,%s\n",date,event); //concatenating date and time
    fputs(str,ptr); //puting data into the file
    fclose(ptr);
}