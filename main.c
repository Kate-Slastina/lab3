#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.h"
#include "sys_funcs.h"
#include "file_work.h"


int main(int argc, char *argv[]){
    int check;
    if(argc > 3 || argc == 2){
        printf("Неподходящее количество параметров на входе.");
        return 0;
    }
    srand(time(NULL));// cемя генерации, выстраивания под рандомные подпоследоватенльности
    if(argc == 3 && my_strcmp(argv[1], "--file") == 0){
        check = read_file(argv[2]);
        if(check == 1){
            return check;
        }
    }
    check = main_logic();
    return check;
}