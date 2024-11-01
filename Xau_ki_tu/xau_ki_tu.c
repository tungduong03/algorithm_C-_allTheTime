#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char c[100],p[100];
	fflush(stdin);
	fgets(c,100,stdin);
	int i=0,len=strlen(c),dem=0;
	c[len-1]='\0';
	while (c[i]==' ') i++; 
	
	for (; i<strlen(c); i++) 
	{
		if (c[i]==c[i+1] && c[i]==' ') continue;
		if (c[i]!=' ') strcpy(&l[dem],&c[i]),dem++;
	}
	for (int i=0; i<dem;i++) printf("%c",l[i]);
	
	
}
