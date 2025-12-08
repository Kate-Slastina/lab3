#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.h"

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


// -----------------------------------------------------------------


element* get_middle(element *head) {
    if (!head) return NULL;
    element *slow = head;
    element *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


element* merge(element *left, element *right) {
    if (!left) return right;
    if (!right) return left;

    element dummy = {0, NULL};
    element *tail = &dummy;

    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;
    return dummy.next;
}


int merge_sort_stack(element **se) {
    if (!se || !*se || !(*se)->next){
        return 1;
    }

    element *mid = get_middle(*se);
    
    
    element *right_head = mid->next;
    mid->next = NULL;
    
    element *left_head = *se;

    
    merge_sort_stack(&left_head);
    merge_sort_stack(&right_head);

    *se = merge(left_head, right_head);
    return 0;
    //
}