#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int debug;

int printstr(char *a){	
	char*p=a;
	
	while(*p){
		putchar(*p);
		p++;
	}

	printf("\"\n");
	return 0;
}

int mystrlen(char *a){
	char*x = a;
	int y = 0; 
	while (*x){
		x++;
		y++;
	}

	if (debug){
		printf("\ndebugging mystrlen\na = \"");
		printstr(a);
		printf("len of a = %d\n",y);
	}
	
	return y;
}


char* mystrcpy(char *a, char *b){
	char*x = a;
	char*y = b;
	if (debug){
		printf("\ndebugging mystrcpy\n");
		printf("a = \"");
		printstr(a);
		printf("b = \"");
		printstr(b);
		printf("starting copying!\n");
	}
	while (*y){
		*x = *y;
		if (debug){
			
			printf("a = \"");
			printstr(a);
		}
		x++;
		y++;
	}
	return a;
}

char* mystrncat(char *a, char *b, int n){
	char*p = a + mystrlen(a);
	if (debug){
		printf("\ndebugging mystrncat\n");
		printf("a = \"");
		printstr(a);
		printf("b = \"");
		printstr(b);
		printf("starting concatenation!\n");
	}
	while (*b && n > 0 ){
		*p = *b;
		p++;
		b++;
		n--;
		if (debug){
			printf("a = \"");
			printstr(a);
		}
	}
	return a;
}
int mystrcmp(char *a, char *b){
	char *p1 = a;
	char *p2 = b;
	if (debug){
		printf("\ndebugging mystrcmp\n");
		printf("a = \"");
		printstr(a);
		printf("b = \"");
		printstr(b);
		printf("starting comparison\n");
	}
	
	while (*p1 && *p2){
		if (debug){
			printf("p1 = ");
			putchar(*p1);
			printf(", p2 = ");
			putchar(*p2);
			printf("\n");
		}
		if (*p1 > *p2){	
			return 1;
		}else if (*p1 < *p2){
			return -1;
		}
		p1++;
		p2++;
	}
	
	if (*p1 == *p2){
		return 0;
	}else if (*p1){
		return 1;
	}else{
		return -1;
	}
}

	
	
	

char* mystrchr(char *a, int c){
	char *p = a;
	if (debug){
		printf("\ndebugging mystrchr\n");
		printf("a = \"");
		printstr(a);
		printf("c = \"");
		putchar(c);
		printf("\nstarting find\n");
	}
	
	while (*p){
		if (debug){
			printf("*p = ");
			putchar(*p);
			printf(", c = ");
			putchar(c);
			printf(", p = %d",p);
			printf("\n");
		}
		
		if (*p == c){			
			break;
		}
		p++;
	}
	return p;
}






int main(){
	char a[5] = "12346";
	char b[6] = "123467";
	char c[10] = "1414145";
	
	//set to 0 for no debug
	debug = 1;
	
	mystrlen(a);
	mystrcpy(a,c);
	mystrncat(a,b,10);
	printf("%d\n",mystrcmp(a,b));
	printf("%d",mystrchr(a,'3'));
	return 0;

}
