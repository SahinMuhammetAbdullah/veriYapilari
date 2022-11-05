#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *adres;
};
typedef struct dugum bliste;

bliste *dugumolustur(int);
bliste *dugum1 = NULL;

void dugumyazdir();
void bul(int);
int elemansay();


int main(){
	dugum1 = dugumolustur(10);
	bliste *dugum2 = dugumolustur(20);
	bliste *dugum3 = dugumolustur(30);
	bliste *dugum4 = dugumolustur(40);
	bliste *dugum5 = dugumolustur(50);
	dugum1 -> adres = dugum2;
	dugum2 -> adres = dugum3;
	dugum3 -> adres = dugum4;
	dugum4 -> adres = dugum5;
	dugumyazdir();
	printf("Bagli listede %d tane eleman vardir\n", elemansay());
	bul(10);
	bul(-1);
	return 0;
}

bliste *dugumolustur(int veri){
	bliste *yenidugum = (bliste*)malloc(sizeof(bliste));
	yenidugum -> veri = veri;
	yenidugum -> adres = NULL;
	return yenidugum;
}

void dugumyazdir(){
	bliste *temp = dugum1;
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> adres;
	}
	printf("\n");
}

int elemansay(){
	int sayac = 0;
	bliste *temp = dugum1;
	while(temp != NULL){
		sayac += 1;
		temp = temp -> adres;
	}
	return sayac;
}

void bul(int aranan){
	bliste *temp = dugum1;
	while(temp != NULL){
		if(temp -> veri == aranan){
			printf("Aranilan %d elemani bulundu \n", aranan);
			return;
		}
		temp = temp -> adres;
	}
	printf("Aranilan %d elemani listede yok \n", aranan);
}
