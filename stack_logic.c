#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack_logic.h"
#include "sorting.h"
#include "file_work.h"
#include "sys_funcs.h"
#define MAX_RAND_NUM 10000
#define MAX_STACK_ITEMS 50000

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


element* copy_stack(element* original) {
    if (!original) return NULL;

    element *new_stack = NULL;
    element *current = original;

    while (current) {
        element *new_node = malloc(sizeof(element));
        if (!new_node) {
            printf("Новый элемент не создался в copy_stack\n");
            clear(&new_stack);
            return NULL;
        }
        new_node->data = current->data;
        new_node->next = new_stack;
        new_stack = new_node;

        current = current->next;
    }

    return new_stack;
}


int main_logic(){
    int choice = 0, value = 0, check = 0, rand_num = 0, save_flag = 0;
    char value_text[] = "Введи значение для вставки\n>", count_text[] = "Введи количество значений для вставки\n>"; 
    element*  stack_start=NULL;
    while(choice != 6){
        printf("[1] - добавить число в стек \n");
        printf("[2] - заполнить стек рандомными элементами \n");
        printf("[3] - удалить число из стека \n");
        printf("[4] - очистить стек \n");
        printf("[5] - вывести стек \n");
        printf("[6] - закончить ввод стека \n>");
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
                do{
                    value_input(&value, count_text);
                    if(value > MAX_STACK_ITEMS){
                        printf("Слишком долго заполняться будет, выбери число поменьше\n");
                    }
                }while(value > MAX_STACK_ITEMS);
                for(int i = 0; i < value; i++){
                    rand_num = rand()%MAX_RAND_NUM;
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
                break;
            case 5:
                check = show(&stack_start);
                if(check != 0){
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 6:
                break;
            default:
                printf("Такого варианта нема...");
                break;
        }
        if(choice != 6){
        clear_input();
        }
        clear_screen();
    }
    if(stack_start == NULL){
        printf("Stack пуст, в сортировке нет смысла.");
        check = save_to_file("data.txt", "w", NULL);
        return 0;
    }
    check = save_to_file("data.txt", "w", stack_start);
    if(check != 0){
        return check;
    }

    while(choice != 5){
        printf("[1] - отсортировать стек методом прямой вставки\n");
        printf("[2] - отсортировать стек методом слияния\n");
        printf("[3] - сравнить скорость сортировки прямой вставкой и слиянием\n");
        printf("[4] - вывести стек \n");
        printf("[5] - закончить работу с программой \n>");
        scanf("%d", &choice);
        clear_input();
        switch(choice){
            case 1:
                check = direct_inlusion_sort(&stack_start);
                if(check == 0){
                    printf("Сортировка выполнена успешно.");
                }
                else{
                    clear(&stack_start);
                    return 1;
                }
                save_flag = 1;
                break;
            case 2:
                check = merge_sort_stack(&stack_start);
                if(check == 0){
                    printf("Сортировка выполнена успешно.");
                }
                else{
                    clear(&stack_start);
                    return 1;
                }
                save_flag = 1;
                break;
            case 3:
                element *copy1 = copy_stack(stack_start);
                element *copy2 = copy_stack(stack_start);
                if(copy1 == NULL || copy2 == NULL){
                    return 1;
                }
                clock_t t1 = clock();
                direct_inlusion_sort(&copy1);
                t1 = clock() - t1;

                clock_t t2 = clock();
                merge_sort_stack(&copy2);
                t2 = clock() - t2;

                printf("Вставками: %.6f с\n", (double)t1 / CLOCKS_PER_SEC);
                printf("Слиянием:  %.6f с\n", (double)t2 / CLOCKS_PER_SEC);
                clear(&copy1);
                clear(&copy2);
                clear_input();
                break;
            case 4:
                check = show(&stack_start);
                if(check != 0){
                    clear(&stack_start);
                    return 1;
                }
                break;
            case 5:
                if(save_flag == 0){
                    direct_inlusion_sort(&stack_start);
                }
                save_to_file("data.txt", "a", stack_start);
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
