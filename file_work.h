#ifndef SAVING_H
#define SAVING_H
#include "stack_logic.h"

int save_to_file(char *file_name, const char *method, element *stack_start); 
int read_file(char *file_name);
#endif