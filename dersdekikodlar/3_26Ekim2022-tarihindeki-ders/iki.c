#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum dairesel_ty_bliste;

dairesel_ty_bliste *bas = NULL;
void toplu_dugum_olustur(int [], int);
void listele(dairesel_ty_bliste*);
int eleman_say(dairesel_ty_bliste*);
void eleman_ara(dairesel_ty_bliste*, int);
void basa_ekle(dairesel_ty_bliste*, int);
void sona_ekle(dairesel_ty_bliste*, int);
void araya_ekle(dairesel_ty_bliste*, int, int);
void bastan_sil(dairesel_ty_bliste*);
void sondan_sil(dairesel_ty_bliste*);
void aradan_sil(dairesel_ty_bliste*, int);

int main(){
	int dizi1[] = {20, 10, 7, 40};
	toplu_dugum_olustur(dizi1, 4);
	listele(bas);
	basa_ekle(bas, 1000);
	sondan_sil(bas);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	bastan_sil(bas);
	listele(bas);
	bastan_sil(bas);
	listele(bas);
	eleman_ara(bas, 200);
	eleman_ara(bas, 20);
	int dizi2[] = {200};
	toplu_dugum_olustur(dizi2, 1);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	eleman_ara(bas, 200);
	eleman_ara(bas, 20);
	int dizi3[] = {-2, -1, 1, 0, 2, 3, 4};
	toplu_dugum_olustur(dizi3, 7);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	eleman_ara(bas, 200);
	eleman_ara(bas, 20);
	sona_ekle(bas, -7);
	listele(bas);
	int dizi4[] = {};
	toplu_dugum_olustur(dizi4, 0);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	basa_ekle(bas, 1);
	basa_ekle(bas, 2);
	sona_ekle(bas, -7);
	sona_ekle(bas, 7);
	basa_ekle(bas, 100);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	araya_ekle(bas, 3, 70);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	sondan_sil(bas);
	listele(bas);
	printf("listedeki toplam eleman sayisi = %d\n", eleman_say(bas));
	return 0;
}
void toplu_dugum_olustur(int dizi[], int N){
	int i;
	dairesel_ty_bliste *yeni;
	dairesel_ty_bliste *eski;
	if(N == 0){
		bas = NULL;
	}
	for(i = 0; i < N; i++){
		yeni = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
		if(i == 0){
			bas = yeni;
			yeni -> veri = dizi[i];	
			yeni -> sonraki = bas;
		}
		else{
			yeni -> veri = dizi[i];
			eski -> sonraki = yeni;
			yeni -> sonraki = bas;
		}
		eski = yeni;		
	}
}
void listele(dairesel_ty_bliste *ilk){
	dairesel_ty_bliste *temp = ilk;
	if(ilk == NULL){
		printf("Listede eleman yok\n");
		return;
	}
	do{
		printf("%d\n", temp -> veri);
		temp = temp -> sonraki;
	}while(temp != ilk);
}
int eleman_say(dairesel_ty_bliste *ilk){
	dairesel_ty_bliste *temp = ilk;
	int sayac = 0;
	if(ilk == NULL)
		return 0;
	do{
		temp = temp -> sonraki;
		sayac++;
	}while(temp != ilk);
	return sayac;
}
void eleman_ara(dairesel_ty_bliste *ilk, int aranan){
	dairesel_ty_bliste *temp = ilk;
	if(ilk == NULL){
		printf("Bos liste!\n");
		return;
	}
	do{
		if(temp -> veri == aranan){
			printf("aranan %d listede bulundu\n", aranan);
			return;
		}
		temp = temp -> sonraki;
	}while(temp != ilk);
	printf("aranan %d listede bulunamadi\n", aranan);
}
void basa_ekle(dairesel_ty_bliste *ilk, int veri){
	dairesel_ty_bliste *temp = ilk;
	dairesel_ty_bliste *yeni;
	yeni = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
	if(temp == NULL){
		bas = yeni;
		yeni -> veri = veri;	
		yeni -> sonraki = bas;
	}
	else{
		while(temp -> sonraki != ilk)
			temp = temp -> sonraki;
		yeni -> sonraki = ilk;
		yeni -> veri = veri;
		bas = yeni;
		temp -> sonraki = yeni;
	}
}
void sona_ekle(dairesel_ty_bliste *ilk, int veri){
	dairesel_ty_bliste *temp = ilk;
	dairesel_ty_bliste *yeni;
	yeni = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
	if(temp == NULL){
		bas = yeni;
		yeni -> veri = veri;	
		yeni -> sonraki = bas;
	}
	else{
		while(temp -> sonraki != bas)
			temp = temp -> sonraki;
		temp -> sonraki = yeni;
		yeni -> veri = veri;
		yeni -> sonraki = bas;
	}
}
void araya_ekle(dairesel_ty_bliste *ilk, int konum, int veri){
	dairesel_ty_bliste *temp = ilk;
	dairesel_ty_bliste *yeni;
	yeni = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
	int sayac = 1;
	if(konum == 1){
		basa_ekle(ilk, veri);
	}
	else{
		while(sayac != konum){
			temp = temp -> sonraki;
			sayac++;
		}
		if(temp -> sonraki == ilk){
			sona_ekle(ilk, veri);
		}
		else{
			yeni -> veri = veri;
			yeni -> sonraki = temp -> sonraki;
			temp -> sonraki = yeni;
		}
	}
}
void bastan_sil(dairesel_ty_bliste *ilk){
	dairesel_ty_bliste *temp = ilk;
	if(temp == NULL){
		printf("Bos liste!");
		return;
	}
	while(temp -> sonraki != ilk)
		temp = temp -> sonraki;
	temp -> sonraki = ilk -> sonraki;
	bas = ilk -> sonraki;
	free(ilk);
}
void sondan_sil(dairesel_ty_bliste *ilk){
	dairesel_ty_bliste *temp = ilk;
	if(temp == NULL){
		printf("Bos liste!");
		return;
	}
	while(temp -> sonraki -> sonraki != ilk)
		temp = temp -> sonraki;
	free(temp -> sonraki);
	temp -> sonraki = ilk;
}
