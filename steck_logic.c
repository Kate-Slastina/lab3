#include <stdio.h>
#include <stdlib.h>
#include "steck_logic.h"
#include "sys_funcs.h"


int push(element** se, int value){
    if (se == NULL){
        printf("Отсутствует указатель на stack_end\n");
        return 1;
    }
    element* new_el=malloc(sizeof(element));
    if(new_el==NULL){
        printf("Новый элемент не создался\n");
        return 1;
    }
    new_el->data = value;
    new_el->next = *se;
    *se = new_el;
    return 0;
}


int pop(element** se){
    if (se == NULL){
        printf("Отсутствует указатель на stack_end\n");
        return 1;
    }
    if(*se == NULL){
        printf("В стеке ничего нет\n");
        return 2;
    }
    element* cur_element = *se;
    *se = (*se)->next;
    free(cur_element);
    return 0;

}


int clear(element** se){
    int check = 0;
    if (se == NULL){
        printf("Отсутствует указатель на stack_end\n");
        return 1;
    }
    while(*se != NULL){
        check = pop(se);
        if(check != 0){
            return check;
        }
    }
    return 0;

}


int show(element** se){
    if (se == NULL){
        printf("Отсутствует указатель на stack_end\n");
        return 1;
    }
    if(*se==NULL){
        printf("В стеке ничего нет\n");
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
    while(choice != 6){
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
                }
                else{
                    clear(&stack_end);
                    return 1;
                }
                break;
            case 2:
            value = 1000000;
                while(value < 1 || value > 100000){
                    value_input(&value, count_text);
                    if(value < 1 || value > 100000){
                        printf("Значение должно быть в промежутке от 1 до 10^5\n");
                    }
                }
                for(int i = 0; i < value; i++){
                    rand_num = rand()%1000;
                    check = push(&stack_end, rand_num);
                    if(check != 0){
                        break;
                    }
                }
                if(check == 0){
                    printf("Числа добавлены.");
                }
                else{
                    clear(&stack_end);
                    return 1;
                }
                break;
            case 3:
                check = pop(&stack_end);
                if(check == 0){
                    printf("Число удалено.");
                }
                else if(check == 1){
                    clear(&stack_end);
                    return 1;
                }
                break;
            case 4:
                check = clear(&stack_end);
                if(check == 1){
                    return 1;
                }
            case 5:
                check = show(&stack_end);
                if(check != 0){
                    clear(&stack_end);
                    return 1;
                }
                break;
            case 6:
                check = clear(&stack_end);
                if(check == 0){
                    printf("Стек удален. Завершение работы программы...");
                }
                else{
                    clear(&stack_end);
                    return 1;
                }
                break;
            default:
                printf("Такого варианта нема...");
                break;
        }
        clear_input();
        clear_screen();

    }
    return 0;
}