#include<stdio.h>
#include<string.h>

void search(){
    FILE* file = fopen("logs.csv","r");
    int found;
    char line[100],eventID[50];
    printf("Enter the event ID: ");
    gets(eventID);
    while(fgets(line,sizeof(line),file)!=NULL){
        if(strstr(line,eventID)!=NULL){
            puts(line);
            return;
        }
    }
    printf("No event found");
    fclose(file);
}