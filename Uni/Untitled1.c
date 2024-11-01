#include <string.h>
#include <stdio.h>
void sort_char(char a[]){
	for (int i=0; i<strlen(a)-1; i++)
		for (int j=i+1; j<strlen(a); j++)
		if (a[i]>a[j]){
			char p = a[j];
			a[j]=a[i];
			a[i]=p;
		}
}
int main(){
	int dem[100],nho=0;
	char s[100],t[100],st[100];
	fflush(stdin);
	fgets(s,100,stdin);
	fgets(t,100,stdin);
	s[strlen(s)-1]="\0";
	t[strlen(t)-1]="\0";
	strcat(s,t);
	sort_char(s);
	
	//for (int i=0; i<strlen(s); i++) printf("%c",s[i]);
	
	//printf("\n");
	
	dem[nho]=1;
	for (int i=0; i<strlen(s); i++)
	if (s[i]!=s[i+1]) 
	{
		printf("%c",s[i]);
		nho++;
		dem[nho]=1;
	}	
	else dem[nho]++;
	printf("\n");
	for (int i=0; i<nho; i++) printf("%d\n",dem[i]);
}
