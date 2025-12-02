#include <stdio.h>
#include "file_work.h"
#include "sys_funcs.h"

#define IS_HEADER(s) \
    (my_strcmp("===START_OF_SAVE===", (s)) == 0 || \
     my_strcmp("===END_OF_SAVE===", (s)) == 0)


int save_to_file(char *file_name, const char *method, element *stack_start){
    FILE *file = fopen(file_name, method); // w - перезапись a - дозапись
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        clear_input();
        return 1;
    }
    if(my_strcmp(method, "w") == 0){
        fprintf(file, "===START_OF_SAVE===\n");
        fprintf(file, "===STACK===\n");
        while(stack_start != NULL){
            fprintf(file, "%d ", stack_start->data);
            stack_start = stack_start->next;
        }
        fprintf(file, "\n");
    }
    else{
        fprintf(file, "===SORTED_STACK===\n");
        while(stack_start != NULL){
            fprintf(file, "%d ", stack_start->data);
            stack_start = stack_start->next;
        }
        fprintf(file, "\n");
        fprintf(file, "===END_OF_SAVE===\n");
    }
    fclose(file);
    return 0;
}


int read_file(char *file_name){
    char result[64];
    FILE *file = fopen(file_name, "r");
    printf("Прошлые данные:\n");
    if (file == NULL) {
        printf("Ошибка открытия файла в read_file");
        return 1;
    }
    do{
        fgets(result, sizeof(result), file);
        remove_n(result);
        if(IS_HEADER(result)){
            continue;
        }
        printf("%s\n", result);
    }while(my_strcmp("===END_OF_SAVE===", result));
    clear_input();
    clear_screen();
    fclose(file);
    return 0;
    
}