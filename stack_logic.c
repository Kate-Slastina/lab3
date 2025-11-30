#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.h"
#include "sorting.h"
#include "sys_funcs.h"


int push(element** s_s, int value){
    if (s_s == NULL){
        printf("Отсутствует указатель на stack_start\n");
        return 1;
    }
    element* new_el=malloc(sizeof(element));
    if(new_el==NULL){
        printf("Новый элемент не создался\n");
        return 1;
    }
    new_el->data = value;
    new_el->next = *s_s;
    *s_s = new_el;
    return 0;
}


int pop(element** s_s){
    if (s_s == NULL){
        printf("Отсутствует указатель на stack_start\n");
        return 1;
    }
    if(*s_s == NULL){
        printf("В стеке ничего нет\n");
        return 2;
    }
    element* cur_element = *s_s;
    *s_s = (*s_s)->next;
    free(cur_element);
    return 0;

}


int clear(element** s_s){
    int check = 0;
    if (s_s == NULL){
        printf("Отсутствует указатель на stack_start\n");
        return 1;
    }
    while(*s_s != NULL){
        check = pop(s_s);
        if(check != 0){
            return check;
        }
    }
    return 0;

}


int show(element** s_s){
    if (s_s == NULL){
        printf("Отсутствует указатель на stack_start\n");
        return 1;
    }
    if(*s_s==NULL){
        printf("В стеке ничего нет\n");
        return 0;
    }
    element* cur_element = *s_s;
    while (cur_element != NULL){
        printf("%d ",(cur_element)->data);
        cur_element = cur_element->next;
    }
    return 0;
}


int main_logic(){
    int choice = 0, value = 0, check = 0, rand_num = 0;
    char value_text[] = "Введи значение для вставки\n>", count_text[] = "Введи количество значений для вставки\n>"; 
    element*  stack_start=NULL;
    while(choice != 7){
        printf("[1] - добавить число в стек \n");
        printf("[2] - заполнить стек рандомными элементами \n");
        printf("[3] - удалить число из стека \n");
        printf("[4] - очистить стек \n");
        printf("[5] - вывести стек \n");
        printf("[6] - отсортировать стек методом прямой вставки\n");
        printf("[7] - закончить работу с программой \n>");
        scanf("%d", &choice);
        clear_input();
        switch(choice){
            case 1:
                value_input(&value, value_text);
                check = push(&stack_start, value);
                if(check == 0){
                    printf("Число добавлено.");
                }
                else{
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 2:
                value_input(&value, count_text);
                for(int i = 0; i < value; i++){
                    rand_num = rand()%10000;
                    check = push(&stack_start, rand_num);
                    if(check != 0){
                        break;
                    }
                }
                if(check == 0){
                    printf("Числа добавлены.");
                }
                else{
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 3:
                check = pop(&stack_start);
                if(check == 0){
                    printf("Число удалено.");
                }
                else if(check == 1){
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 4:
                check = clear(&stack_start);
                if(check == 0){
                    printf("Стек очищен.");
                }
                else{
                    return 1;
                }
            case 5:
                check = show(&stack_start);
                if(check != 0){
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 6:
                check = direct_inlusion_sort(&stack_start);
                if(check == 0){
                    printf("Сортировка выполнена успешно.");
                }
                else{
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 7:
                check = clear(&stack_start);
                if(check == 0){
                    printf("Стек удален. Завершение работы программы...");
                }
                else{
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
