#include "swap.h"
/* Swaps strings by swapping pointers */
void swap_strings(char **str1_ptr, char **str2_ptr)
{
	char *temp = *str1_ptr;
	*str1_ptr = *str2_ptr;
	*str2_ptr = temp;
}
//function that return the smaller lenght of the compared strings
int str_len_compare(char *str, char *str1)
{
    int len = strlen(str);
    int len1 = strlen(str1);
    if (len < len1)
    {
        return len;
    }
    else
    {
        return len1;
    }
}
bool string_compare(char *str, char *str1)
{
    int len = str_len_compare(str,str1);
    int i = 0;
    while (i < len)
    {
        if (str[i] < str1[i])
        {
            return true;
        }
        else if(str[i] > str1[i])
        {
            return false;
        }
        i++;
    }
    if (strlen(str) < strlen(str1))
    {
        return true;
    }
    return false;
}
//a function that sort strings in the alphabetical order
char** sort_strings(int tab_size, char *tab[])
{
    int tmp = 0;
    char **tab1 = malloc(tab_size * sizeof(char*));
    for (int t = 0; t < tab_size; t++)
    {
        tab1[t] = malloc((strlen(tab[t]) + 1) * sizeof(char));
        strncpy(tab1[t],tab[t],strlen(tab[t]));
    }
    for (int i = 0; i < tab_size - 1; i++)
    {
        for (int j = 0; j < tab_size - 1 - i; j++)
        {
            if (string_compare(tab1[j + 1], tab1[j]))
            {
                swap_strings(&tab1[j],&tab1[j+1]);
            }
        }
    }
    return tab1;
}
int main(int argc,char *argv[])
{
	char **sorted_strings = sort_strings(argc - 1, &argv[1]);
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%s\n", sorted_strings[i]);
        free(sorted_strings[i]);
    }
    free(sorted_strings);

	return 0;
}

