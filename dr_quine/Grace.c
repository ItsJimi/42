#include <stdio.h>
#define SALAD() int main() { char *a = "#include <stdio.h>%1$c#define SALAD() int main() { char *a = %2$c%3$s%2$c; FILE *f; f = fopen(%2$cGrace_kid.c%2$c, %2$cw+%2$c); fprintf(f, a, 10, 34, a); fclose(f); }%1$c#define TOMATO MIAM%1$c#define ONION MIAM%1$c/*%1$c** Pita%1$c*/%1$cSALAD()%1$c"; FILE *f; f = fopen("Grace_kid.c", "w+"); fprintf(f, a, 10, 34, a); fclose(f); }
#define TOMATO MIAM
#define ONION MIAM
/*
** Pita
*/
SALAD()
