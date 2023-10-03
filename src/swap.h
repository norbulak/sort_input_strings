#ifndef __SWAP_H__
#define __SWAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap_strings(char **str1_ptr, char **str2_ptr);
int str_len_compare(char *str, char *str1);
bool string_compare(char *str, char *str1);
char** sort_strings(int tab_size, char *tab[]);

#endif
