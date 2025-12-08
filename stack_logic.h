#ifndef STACK_LOGIC_H
#define STACK_LOGIC_H

typedef struct el{
    int data;
    struct el* next;
}element;



int push(element** s_s, int value);
int main_logic();
#endif