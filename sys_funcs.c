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
    if(value == NULL || text == NULL){
        printf("Ошибка передачи параметров в value_input");
        return 1;
    }
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




int my_strcmp(const char *s1, const char *s2){
	while (*s1 && (*s1 == *s2)){ 
        s1++;
        s2++;
    }
	return (*(unsigned char *)s1 - *(unsigned char *)s2); // ансайнд потому что есть приколы с минусовыми кодировками
}


int remove_n(char *s){
    int i = 0;
    if(s == NULL) return -1;
    while(s[i] != '\n' && s[i] != '\0'){
        i++;
    }
    s[i] = '\0';
    return 0;
}


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}