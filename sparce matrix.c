#include<stdio.h>
#include<ctype.h>

int main(){

char ch;
int lines,words,digit,alpha;
lines=words=digit=alpha=0;

FILE *fptr;

fptr=fopen("file1.txt","r");
ch=fgetc(fptr);

while(ch!=EOF){

	if(ch=='\n'){lines++;words++;}
	else if(ch==' ')words++;
	else if(isalpha(ch))alpha++;
	else if(isdigit(ch))digit++;
	printf("%c ",ch);
	ch=fgetc(fptr);

	}

printf("\nNo of lines = %d ",lines);
printf("\nNo of words = %d ",words);
printf("\nNo of alphabets = %d ",alpha);
printf("\nNo of digits = %d \n ",digit);

fclose(fptr);

return 0;
}
