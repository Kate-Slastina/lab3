#include <stdio.h>
#include <stdlib.h> 

int clear_input(){
    int c, counter = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        counter++;
    }
    return counter;
}


int value_input(int* value, char* text){
    int check = 0;
    while(check != 1){
        printf("%s", text);
        check = scanf("%d", value);
        if(check != 1){
            clear_input();
            continue;
        }
        check -= clear_input();
    }
    return 0;
}


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}