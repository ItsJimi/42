#include <stdio.h>

/*
** Bacon
*/

int main()
{
	/*
	** Cheese
	*/
	char *a = "#include <stdio.h>%1$c%1$c/*%1$c** Bacon%1$c*/%1$c%1$cint main()%1$c{%1$c%2$c/*%1$c%2$c** Cheese%1$c%2$c*/%1$c%2$cchar *a = %4$c%3$s%4$c;%1$c%2$cprintf(a, 10, 9, a, 34);%1$c}%1$c%1$c";
	printf(a, 10, 9, a, 34);
}