#include<stdio.h>
#include<string.h>
void removing(){
     FILE* ptr = fopen("logs.csv","r+");
     char eventID[10];
     printf("Enter ID of event you want to remove: ");
     gets(eventID);
     char word[50]; 
     while (fscanf(ptr, "%s", word) != EOF) { // Read word by word
         if(strcmp(eventID,word)==0){
            fprintf(ptr," ");
            break;
         } 
    }
    fclose(ptr);
}