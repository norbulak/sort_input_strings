#include "swap.h"
/* Swaps strings by swapping pointers */
void swap_strings(char **str1_ptr, char **str2_ptr)
{
char *temp = *str1_ptr;
*str1_ptr = *str2_ptr;
*str2_ptr = temp;
}
void swap_strings_deprecated(char *str1, char *str2)
{

	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);

	// copy str1 in tmp
	char *tmp = malloc(sizeof(char) * len1);
	strncpy(tmp, str1, len1);
	// reallocating memory before swaping string contents str1 <> str2
	str1 = realloc(str1, sizeof(char) * len2);
    // cpy str2 -> str1
	strncpy(str1, str2, len2);
	// reallocating memory before swaping string contents str1 <> str2
    realloc(str2, sizeof(char) * len1);
	// cpy tmp -> str2
	strncpy(str2, tmp, len1);

	free(tmp);
}
int main()
{
	char *p1 = malloc(sizeof(char) * 10); 
	char *p2 = malloc(sizeof(char) * 11); 

	strncpy(p1, "first_str", 9);
	strncpy(p2, "second_str", 10);

	printf("%s\n%s\n", p1, p2);
//	swap_str(p1, p2);
	swap1(&p1, &p2);
	printf("%s\n%s\n", p1, p2);
	free (p1);
	free (p2);
}

