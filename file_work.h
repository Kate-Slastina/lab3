#ifndef SAVING_H // если еще не за дефайнено
#define SAVING_H //то мы определяем две функции
#include "stack_logic.h"

int save_to_file(char *file_name, const char *method, element *stack_start); 
int read_file(char *file_name);
int read_from_file(char *file_name, element **stack_start);
#endif // конец
