#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i = 5;
	if (i < 0) return (0);
	if (strstr(__FILE__, "Sully_0.c") != NULL) return(0);
	if (!strstr(__FILE__, "Sully.c")) i--;
	char *a = "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$cint main()%1$c{%1$c%4$cint i = %5$d;%1$c%4$cif (i < 0) return (0);%1$c%4$cif (strstr(__FILE__, %2$cSully_0.c%2$c) != NULL) return(0);%1$c%4$cif (!strstr(__FILE__, %2$cSully.c%2$c)) i--;%1$c%4$cchar *a = %2$c%3$s%2$c;%1$c%4$cFILE *f;%1$c%4$cchar str[70];%1$c%4$csprintf(str, %2$cSully_%6$cd.c%2$c, i);%1$c%4$cf = fopen(str, %2$cw+%2$c);%1$c%4$cif (f) {%1$c%4$c%4$cfprintf(f, a, 10, 34, a, 9, i, 37);%1$c%4$c%4$cfclose(f);%1$c%4$c%4$csprintf(str, %2$cgcc Sully_%6$c1$d.c -o Sully_%6$c1$d; ./Sully_%6$c1$d%2$c, i);%1$c%4$c%4$csystem(str);%1$c%4$c}%1$c}%1$c";
	FILE *f;
	char str[70];
	sprintf(str, "Sully_%d.c", i);
	f = fopen(str, "w+");
	if (f) {
		fprintf(f, a, 10, 34, a, 9, i, 37);
		fclose(f);
		sprintf(str, "gcc Sully_%1$d.c -o Sully_%1$d; ./Sully_%1$d", i);
		system(str);
	}
}
