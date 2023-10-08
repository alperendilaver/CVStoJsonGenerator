#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	FILE *fp;

	fp=fopen(argv[1],"r");
	char line[200];
	char *token;
	while(fgets(line,sizeof(line),fp)){
		token = strtok(line,",");
		while(token!=NULL){
			printf("%s",token);
			token=strtok(NULL,",");
		}
	}
	fclose(fp);
	printf("%s",argv[2]);
	return 0;
}
