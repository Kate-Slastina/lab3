#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.h"
#include "sorting.h"

int direct_inlusion_sort(element **s_s){
    if(s_s == NULL){
        printf("Ошибка передачи s_s в сортировку вставкой\n");
        return 1;
    }
    if(*s_s == NULL){
        return 0;
    }
    element* cur_element = (*s_s)->next, *next, *prev_element, *check_element;
    (*s_s)->next = NULL;
    while(cur_element != NULL){
        check_element = *s_s;
        next = cur_element->next;
        prev_element = NULL;
        while(check_element != NULL && cur_element->data > check_element->data){
            prev_element = check_element;
            check_element = check_element->next;
        }
        if(prev_element == NULL){
            cur_element->next = *s_s;
            *s_s = cur_element;
        }
        else{
            cur_element->next = check_element;
            prev_element->next = cur_element;
        }
        cur_element = next;
    }
    return 0;

}