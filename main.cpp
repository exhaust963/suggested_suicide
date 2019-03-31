#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
double ort;
double topla(int [8]);
int start(float);
void sirala();
void copy();
void ort_bul(double []);
int menu();
int islem(char [],char [], char[]);
int main() {
	int d;
	char karar[1];
	float a,j;
	srand(time(NULL));
	j=rand()%2+10;
	a= ((float)rand())/RAND_MAX;
	if(a<0.5)
	a=a+0.4;
	while(1){
	d=start(j);
	if(d!=1)
		break;
	j=j-a;
}
while(1){
	d=menu();
	printf("\n");
	if(d==1)
	break;
	printf("Girdiginiz degerlerde bir veri bulunmamaktadir.");
	printf("\nIsterseniz tekrar deneyebilir veya cikabilirsiniz\nTekrar denemek icin 1\nCikis icin 2 giriniz\nSeciminiz:");
	scanf("%s",&karar);
	int y=atoi(karar);
	if(y==2)
	break;
}
	system("pause");
	return 0;
}
double topla(int c[8]){
	int i;
	double r=0,s;
	int b=10;
	for(i=0;i<8;i++){
		s=(double)c[i]/b;
		r=r+s;
		b=b*10;
	}
	return r;
}
void sirala(){
char a,b;
int counter=0;
FILE *file,*result,*result2;
file=fopen("copy.txt","r");
result=fopen("result.txt","r");
result2=fopen("result2.txt","w");

while(!feof(file)){
	fscanf(file,"%c",&a);
		if(counter%3==0){
			if(a=='&'){
				while(1){
					if(a=='\t')
					break;
					fscanf(file,"%c",&a);
					fprintf(result2,"%c",a);
				}
				fprintf(result2," ");
				while(1){
					if(a=='%')
					break;
					fscanf(file,"%c",&a);
				}
				while(1){
					if(a=='\t')
					break;
					fscanf(file,"%c",&a);
					fprintf(result2,"%c",a);
				}
				while(1){
					if(a=='!')
					break;
					fscanf(file,"%c",&a);
				}
				while(1){
					if(a=='\t')
					break;
					fscanf(file,"%c",&a);
					fprintf(result2,"%c",a);
				}
				while(1){
					fscanf(result,"%c",&b);
					fprintf(result2,"%c",b);
					if(b=='\n')
					break;
				}
			counter=0;
			}
		}
	if(a=='\n'){
		counter++;
	}
}
fclose(file);
fclose(result);
fclose(result2);
}
void ort_bul(double result[]){
int i;
double top=0;
for(i=0;i<864;i++){
	top=top+result[i];
}	
ort=top/864;
}
int start(float j){
	
	double a[3]={0};
	double result[864]={0};
	int c[8]={0};
	int temp,b,temp2=0;
	char res;
	int counter=0,k,d=0,counter2=0,i;
	FILE *file;
	file=fopen("veritabaný_güncel.txt","r");
	fscanf(file,"%c",&res);
	while(!feof(file)){
		if (res=='*'){
			k=0;
			b=1;
			fscanf(file,"%c",&res);
			while(res!='\n'){
				fscanf(file,"%c",&res);
				if(res==',')
				continue;
				switch(res){
					case '0':temp=0;
							break;
					case '1':temp=1;
							break;
					case '2':temp=2;
							break;
					case '3':temp=3;
							break;
					case '4':temp=4;
							break;
					case '5':temp=5;
							break;
					case '6':temp=6;
							break;
					case '7':temp=7;
							break;
					case '8':temp=8;
							break;
					case '9':temp=9;
							break;
				}
				c[k]=temp;
				k++;
				}
			a[counter]=topla(c);
			counter++;
			d++;
			if(d==3){
				result[counter2]=(a[counter-3]*(j-2)+a[counter-2]*(j-1)+a[counter-1]*(j))/3;
				counter=0;
				counter2++;
				d=0;
			}
		}
	else{
		fscanf(file,"%c",&res);
	}
	}
	fclose(file);
	FILE *file_sonuc;
	file_sonuc=fopen("resutls.txt","w");
	for(i=0;i<864;i++){
		if(result[i]>1){
			temp2=1;
			break;
		}
		fprintf(file_sonuc,"%lf\n",result[i]);
	}
	ort_bul(result);
	if(temp2!=1)
	sirala();
	fclose(file_sonuc);
	return temp2;
}
void copy(){
	FILE *file,*file2;
	char a;
	file=fopen("veritabaný_güncel.txt","r");
	file2=fopen("copy.txt","w");
	fprintf(file2,"&");
	while(!feof(file)){
		fscanf(file,"%c",&a);
		fprintf(file2,"%c",a);
		if(a=='\n'){
			fprintf(file2,"&");
		}
	}
	fclose(file);
	fclose(file2);
}
int menu(){
	char chose[1];
	int donut;
	char ulke[30];
	char cinsiyet[6];
	char yas[6];
	int yassec;
	int a,b,c,d=0;
	while(1){
	printf("Islem seciniz:\n 1.Ulke sec\n 2.Yas araligi sec\n 3.Cinsiyet sec\n 4.Secilenleri goster\n 5.Secimi bitir\n Seciminiz:");
	scanf("%s",&chose);
	int za=atoi(chose);
	switch(za){
		case 1:printf("Ulke adini yaziniz\n");
				scanf("%s",&ulke);
				a=1;
				system("cls");
				break;
		case 2:printf("Yas araligi giriniz\n");
				printf("1. 5-14\n2. 15-24\n3. 25-34\n4. 35-54\n5. 55-74\n6. 75+\n Seciminiz:");
				scanf("%d",&yassec);
				while(1){
				if(yassec>6 || yassec <1){
				printf("Gecerli bir deger seciniz.\n");
				printf("1. 5-14\n2. 15-24\n3. 25-34\n4.35-54\n5. 55-74\n6. 75+\n Seciminiz:");
				scanf("%d",&yassec);
				}
				else
				system("cls");
				break;
				}
				switch(yassec){
					case 1:yas[0]='5';yas[1]='-';yas[2]='1';yas[3]='4';yas[4]='\0';
							break;
					case 2:yas[0]='1';yas[1]='5';yas[2]='-';yas[3]='2';yas[4]='4';yas[5]='\0';
							break;
					case 3:yas[0]='2';yas[1]='5';yas[2]='-';yas[3]='3';yas[4]='4';yas[5]='\0';
							break;
					case 4:yas[0]='3';yas[1]='5';yas[2]='-';yas[3]='5';yas[4]='4';yas[5]='\0';
							break;
					case 5:yas[0]='5';yas[1]='5';yas[2]='-';yas[3]='7';yas[4]='4';yas[5]='\0';
							break;
					case 6:yas[0]='7';yas[1]='5';yas[2]='+';yas[3]='\0';
							break;
					default:break;
				}
				b=1;
				system("cls");
				break;
		case 3:printf("Cinsiyet giriniz\n");
				scanf("%s",&cinsiyet);
				c=1;
				system("cls");
				break;		
		case 4: system("cls");
				printf("Ulke:");
				if(a==1){
					printf(" %s",ulke);
				}
				printf("\n");
				printf("Yas:");
				if(b==1){
					printf(" %s",yas);
				}
				printf("\n");
				printf("Cinsiyet:");
				if(c==1){
					printf(" %s",cinsiyet);
				}
				printf("\n");
				break;
		case 5:	if(a!=1){
				printf("Lutfen ulke seciniz.");
				break;
				}
				if(b!=1){
				printf("Lutfen yas araligi seciniz.");
				break;	
				}
				if(c!=1){
				printf("Lutfen cinsiyet seciniz.");
				break;	
				}
				d=1;
				break;
		default:
				printf("Gecerli bir deger giriniz.");
				break;
		
	}
	if(d==1)
	break;
	}
	donut=islem(ulke,yas,cinsiyet);
	return donut;
}
int islem(char ulke[30],char yas[6],char cinsiyet[6]){
	FILE *file;
	file=fopen("result2.txt","r");
	char result[8];
	char rescontrol[8];
	char tempulke[30];
	char tempyas[6];
	char tempcinsiyet[6];
	int counter=0,i,d=0,e,counteryas,y=0;
	char a='A';
	strcpy(rescontrol,result);
	while(!feof(file)){
			d=0;
			e=0;
			i=0;
			while(1){
			fscanf(file,"%c",&a);
			if(a=='\t')
			break;
			tempulke[i]=a;
			i++;
			}
			tempulke[i]='\0';
			fscanf(file,"%c",&a);
			i=0;
			while(1){
			fscanf(file,"%c",&a);
			if(a=='\t')
			break;
			tempcinsiyet[i]=a;	
			i++;
			}
			tempcinsiyet[i]='\0';
			counteryas=0;
			while(1){
			fscanf(file,"%c",&a);
			if(a=='\t')
			break;
			tempyas[counteryas]=a;
			counteryas++;
			}
			tempyas[counteryas-1]='\0';
			if(strcmp(ulke,tempulke)==0){
			if(strcmp(cinsiyet,tempcinsiyet)==0){
				if(strcmp(yas,tempyas)==0)
					e=1;
			}
			if(e==1){
			i=0;
			printf("2018 tahmini intihar orani:\t");	
			while(1){
			fscanf(file,"%c",&a);
			if(i==8)
			break;
			result[i]=a;	
			i++;
			printf("%c",result[i-1]);
			}
		}
		}
	if(e==1)
	break;
	while(1){
		fscanf(file,"%c",&a);
		if(a=='\n')
			break;
	}
	y++;
	if(y==864)
	break;
}
if(e==1){
if(atof(result)<ort){
	printf("\nSectiginiz verilere sahip ulkedeki intihar orani dusuktur.!!");
	printf("\nUlkelerin ortalama olum orani:%lf\n",ort);
}
else{
	printf("\nSectiginiz verilere sahip ulkedeki intihar orani yuksektir.!!");	
	printf("\nUlkelerin ortalama olum orani:%lf\n",ort);
}
}
fclose(file);
return e;
}
