#include <stdio.h>
#include <stdlib.h>
#include "steck_logic.h"
#include "sys_funcs.h"

int push(element** se, int value){
    if (se ==NULL){
        return 1;
    }
    element* new_el=malloc(sizeof(element));
    if(new_el==NULL){
        return 1;
    }
    new_el->data = value;
    new_el->next = *se;
    *se = new_el;
    return 0;
}
int pop(element** se){
    if (se==NULL){
        return 1;
    }
    if(*se==NULL){
        printf("Nothing in stack");
        return 0;
    }
    element* cur_element = *se;
    *se = (*se)->next;
    free(cur_element);
    return 0;

}
int show(element** se){
    if (se==NULL){
        return 1;
    }
    if(*se==NULL){
        printf("Nothing in stack");
        return 0;
    }
    element* cur_element = *se;
    while (cur_element != NULL){
        printf("%d ",(cur_element)->data);
        cur_element = cur_element->next;
    }
    return 0;
}


int main_logic(){
    int choice = 0, value = 0, check = 0, rand_num = 0;
    char value_text[] = "Введи значение для вставки\n>", count_text[] = "Введи количество значений для вставки\n>"; 
    element*  stack_end=NULL;
    while(choice != 5){
        printf("[1] - добавить число в стек \n");
        printf("[2] - заполнить стек рандомными элементами \n");
        printf("[3] - удалить число из стека \n");
        printf("[4] - очистить стек \n");
        printf("[5] - вывести стек \n");
        printf("[6] - закончить работу с программой \n>");
        scanf("%d", &choice);
        clear_input();
        switch(choice){
            case 1:
                value_input(&value, value_text);
                check = push(&stack_end, value);
                if(check == 0){
                    printf("Число добавлено.");
                    clear_input();
                    clear_screen();
                }
                else{
                    //destroy
                    return 1;
                }
                break;
            case 2:
                value_input(&value, value_text);
                for(int i = 0; i < value; i++){
                    rand_num = rand();
                    check = push(&stack_end, rand_num);
                    if(check != 0){
                        break;
                    }
                }
                if(check == 0){
                    printf("Числа добавлены.");
                    clear_input();
                    clear_screen();
                }
                else{
                    //destroy
                    return 1;
                }
                break;
            default:
                break;
        }

    }
    return 0;
}