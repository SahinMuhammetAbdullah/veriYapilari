#include <stdio.h>
#include <stdlib.h>

struct dinamik_dizi{
	int us;
	int kapasite;
	int *dizi;
};
typedef struct dinamik_dizi yigin;

yigin *olustur();
int dolumu(yigin*);
int bosmu(yigin*);
void boyut_arttir(yigin*);
void ekle(yigin*, int);
void tepe(yigin*);
void cikar(yigin*);
void yigin_bosalt(yigin*);
void listele(yigin*);

int main(){
	yigin *yigin1 = olustur();
	printf("Yigin bosmu: %d\n", bosmu(yigin1));
    tepe(yigin1);
    ekle(yigin1, 1);
    printf("Yigin bosmu: %d\n", bosmu(yigin1));
    tepe(yigin1);
    ekle(yigin1, 2);
    ekle(yigin1, 3);
    ekle(yigin1, 4);
	ekle(yigin1, 5);
    tepe(yigin1);
    listele(yigin1);
	cikar(yigin1);
	listele(yigin1);
	ekle(yigin1, 55);
	listele(yigin1);
    tepe(yigin1);
    printf("Yigin bosmu: %d\n", bosmu(yigin1));
    ekle(yigin1, 21);
    listele(yigin1);
    cikar(yigin1);
    ekle(yigin1, 22);
    cikar(yigin1);
    cikar(yigin1);
	ekle(yigin1, -1);
	ekle(yigin1, -2);
	ekle(yigin1, -3);
	ekle(yigin1, -4);
	ekle(yigin1, -5);
	ekle(yigin1, -100);
	ekle(yigin1, -200);
	ekle(yigin1, -300);
	ekle(yigin1, -400);
	ekle(yigin1, -500);
	int i;
	for(i = 0; i < 100; i++){
		ekle(yigin1, i);
	}
	listele(yigin1);
	cikar(yigin1);
	cikar(yigin1);
	return 0;
}
yigin *olustur(){
	yigin *yeni = (yigin*)malloc(sizeof(yigin));
	if(!yeni)
		return NULL;
	yeni -> kapasite = 1;
	yeni -> us = -1;
	yeni -> dizi = malloc(yeni -> kapasite * sizeof(yigin));
	if(!yeni -> dizi)
		return NULL;
	return yeni;
}
int dolumu(yigin *S){
	return S -> us == S -> kapasite - 1;
}
int bosmu(yigin *S){
    return S -> us == -1;
}
void boyut_arttir(yigin *S){
	S -> kapasite = S -> kapasite * 2;
	S -> dizi = realloc(S -> dizi, sizeof(S -> dizi) * S -> kapasite);
}
void ekle(yigin *S, int eleman){
	if(dolumu(S))
		boyut_arttir(S);
	S -> dizi[++S -> us] = eleman;
}
void tepe(yigin *S){
	if(bosmu(S))
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %d\n", S -> dizi[S -> us]);	
}
void cikar(yigin *S){
	if(bosmu(S))
        printf("Yigin bos! Yigindan silinecek eleman yoktur\n");
    else{
    	printf("%d elemani yigindan cikartildi\n", S -> dizi[S -> us]);
    	S -> us--;
	}
}
void yigin_bosalt(yigin *S){
	if(S){
		if(S -> dizi)
			free(S -> dizi);
		free(S);
	}
}
void listele(yigin *S){
	if(bosmu(S))
        printf("Yigin bos! Listelenecek eleman yoktur\n");
    else{
        int temp = S -> us;
        while(temp != -1){
        	printf("%d ", S -> dizi[temp]);
        	temp = temp - 1;
		}
		printf("\n");
    }
}