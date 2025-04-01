#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"adding.h"
#include"removing.h"
#include"searching.h"
int main(){
    int choice;
    while(1){
    printf("press 1 to add events\npress 2 to remove events\npress 3 to search event\npress 4 to show all events\npress 5 to sort events\npress 6 to exit\n");
            scanf("%d", &choice);
            while (getchar() != '\n');
            if(choice==1) add();
            else if(choice==2) removing();
            else if(choice==3) search();
            else if(choice==6) exit(0);
            else printf("Invalid choice");
    
    }
    return 0;
}

