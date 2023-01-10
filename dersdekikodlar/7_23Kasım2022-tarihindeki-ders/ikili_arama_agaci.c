#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sol;
	struct dugum *sag;
};
typedef struct dugum agac;

agac *dugumolustur(int);
agac *elemanekle(agac*, int);
agac *elemanara(agac*, int);
void inorder(agac*);
agac *enkucuk(agac*);
agac *enbuyuk(agac*);
agac *elemansil(agac*, int);

int main() {
	agac *kok = NULL;
	int dizi[] = {5, 7, 4, 21, 34, 10, 13, 17, 26};
	int i;
	for(i = 0; i < 9; i++){
		kok = elemanekle(kok, dizi[i]);
	}
	printf("\n");
	inorder(kok); // siralama bir sekilde listeleme yapar
	printf("\n%d", elemanara(kok, -1));
	printf("\n%d", elemanara(kok, 21));
	printf("\n%d", elemanara(kok, 5));
	printf("\n%d", elemanara(kok, 13));
	printf("\n%d", elemanara(kok, 100));
	printf("\n%d", enbuyuk(kok) -> veri);
	printf("\n%d", enkucuk(kok) -> veri);
	kok = elemanekle(kok, 123);
	kok = elemanekle(kok, -5);
	printf("\n");
	inorder(kok);
	printf("\n%d", enbuyuk(kok) -> veri);
	printf("\n%d", enkucuk(kok) -> veri);
	
	kok = elemansil(kok, 34);
	printf("\n");
  	inorder(kok);
	return 0;	
}
agac *dugumolustur(int gelen) {
    agac *yenidugum = (agac*)malloc(sizeof(agac));
    yenidugum -> veri = gelen;
    yenidugum -> sol = NULL;
    yenidugum -> sag = NULL;
    return yenidugum;
}
agac *elemanekle(agac *dugum, int gelen) {
	if(dugum == NULL)
		return dugumolustur(gelen);
	else if(gelen < dugum -> veri)
		dugum -> sol = elemanekle(dugum -> sol, gelen);
	else
		dugum -> sag = elemanekle(dugum -> sag, gelen);
}
agac *elemanara(agac *baslangic, int aranan) {
	if(baslangic == NULL)
    	return NULL;
	if(aranan == baslangic -> veri) 
    	return baslangic;
	if(aranan < baslangic -> veri) 
    	return elemanara(baslangic -> sol, aranan);
	if(aranan > baslangic -> veri)
    	return elemanara(baslangic -> sag, aranan);
}
void inorder(agac *baslangic) {
	if(baslangic != NULL) {
		inorder(baslangic -> sol);
		printf("%d ", baslangic -> veri);
		inorder(baslangic -> sag);
	}
}
agac *enkucuk(agac *baslangic) {
	if(baslangic -> sol == NULL)
		return baslangic;
	return enkucuk(baslangic -> sol);
}
agac *enbuyuk(agac *baslangic) {
	if(baslangic -> sag == NULL)
		return baslangic;
	return enbuyuk(baslangic -> sag);
}
agac *elemansil(agac *baslangic, int gelen) {
	if(baslangic == NULL) return baslangic;
  	// silinecek dugumu bul
  	if(gelen < baslangic -> veri)
    	baslangic -> sol = elemansil(baslangic -> sol, gelen);
	else if(gelen > baslangic -> veri)
    	baslangic -> sag = elemansil(baslangic -> sag, gelen);
	else {
    	// dugumun 1 veya 0 cocugu varsa
    	if (baslangic -> sol == NULL) {
      		agac *temp = baslangic -> sag;
      		free(baslangic);
      		return temp;
    	} 
		else if (baslangic -> sag == NULL) {
      		agac *temp = baslangic -> sol;
      		free(baslangic);
      		return temp;
    	}
    	// dugumun 2 cocugu varsa
    	agac *temp = enkucuk(baslangic -> sag);
    	baslangic -> veri = temp -> veri;
    	baslangic -> sag = elemansil(baslangic -> sag, temp -> veri);
  	}
  	return baslangic;
}
