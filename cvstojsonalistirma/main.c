#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ogrenci{
	int no;
	int kayit;
	char ad[20];
	char soyad[20];
};
//csv
/*
	const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

*/
int main(int argc, char *argv[]) {
	FILE *fp;
	int sayac=1;
	int i=0;
	struct ogrenci o1;
	
	
	char kategori[200];
	fp =fopen("ogrenciler.csv","r");
	char satir[200];
	while(fgets(satir,200,fp)){
		printf("%s\n",satir);
		char *parca;
		
		parca = strtok(satir,",");
		//int parcaIndex=0;
		while(parca!=NULL){
			//parcaIndex++;
			//printf("parca2.indeks:\n",parca);
			
			strcat(kategori,parca);
			strcat(kategori," ");
			printf("parca: %s\n",parca);
			parca=strtok(NULL,",");
			
		}
	}
	printf("\n\n%s",kategori);
	
	fp=fopen("ogrenciler.csv","w+");
	if(fp==NULL){
		printf("Dosya acilamadi");
		exit(1);
	}
	else{
		fprintf(fp,"Kayit No,Ogrenci No,Adi,Soyadi\n");
		while(sayac<=3){
			o1.kayit=sayac;
			//fprintf(fp,"%d,",o1.kayit);
			
			printf("numara giriniz: ");
			scanf("%d",&o1.no);
			//fprintf(fp,"%d,",o1.no);
		
			printf("ad giriniz:");
			scanf("%s",o1.ad);
			//fprintf(fp,"%s,",o1.ad);
		
			printf("soyad giriniz:");
			scanf("%s",o1.soyad);
			//fprintf(fp,"%s\n",o1.soyad);
			fprintf(fp,"%d,%d,%s,%s\n",o1.kayit,o1.no,o1.ad,o1.soyad);
			sayac++;
		}
		fclose(fp);
	}
	
	fp=fopen("ogrenciler.csv","r");
	char line[200];
	char *token;
	while(fgets(line,sizeof(line),fp)){
		token = strtok(line,",");
		while(token!=NULL){
			printf("%s ",token);
			token=strtok(NULL,",");
		}
	}
	fclose(fp);
	
		
    FILE* stream = fopen("ogrenciler.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Field 3 would be %s\n", getfield(tmp, 1));    	
		// NOTE strtok clobbers tmp
        //i++;
        free(tmp);
    }

	
	return 0;
}
