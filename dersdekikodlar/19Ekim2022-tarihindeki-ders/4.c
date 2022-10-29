#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum{
    int veri1;
    double veri2;
    struct dugum *onceki;
    struct dugum *sonraki;
};
typedef struct dugum cift_yonlu_bliste;
cift_yonlu_bliste *ilk = NULL;
void listele(cift_yonlu_bliste*, char []);
void basa_ekle(int, double);
void sona_ekle(int, double);
void bastan_sil();
void sondan_sil();

int main(){
    basa_ekle(3, 1.2);
    basa_ekle(5, 2.9);
    //listele(ilk, "ileri");
    sona_ekle(21, 3.2);
    //listele(ilk, "ileri");
    bastan_sil();
    //listele(ilk, "ileri");
    sona_ekle(33, 3.3);
    basa_ekle(55, 5.5);
    //listele(ilk, "ileri");
    sondan_sil();
    sondan_sil();
    listele(ilk, "ileri");
    return 0;
}
void listele(cift_yonlu_bliste *baslama_noktasi, char mesaj[]){
    cift_yonlu_bliste *temp = baslama_noktasi;
    while(temp != NULL){
        printf("%d %f\n", temp -> veri1, temp -> veri2);
        if(!strcmp(mesaj, "geri"))
            temp = temp -> onceki;
        else
            temp = temp -> sonraki;
    }
}
void basa_ekle(int veri1, double veri2){
	
	if(ilk == NULL){ 
		ilk = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		ilk -> veri1 = veri1;
		ilk -> veri2 = veri2;
		ilk -> onceki = NULL;
    	ilk -> sonraki = NULL;
	}
	else{
		cift_yonlu_bliste 
		*temp = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		temp -> veri1 = veri1;
		temp -> veri2 = veri2;
		ilk -> onceki = temp;
		temp -> sonraki = ilk;
		temp -> onceki = NULL;
		ilk = temp;
	}
}
void sona_ekle(int veri1, double veri2){
	if(ilk == NULL){ 
		ilk = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		ilk -> veri1 = veri1;
		ilk -> veri2 = veri2;
		ilk -> onceki = NULL;
    	ilk -> sonraki = NULL;
	}
	else{
		cift_yonlu_bliste *temp1 = ilk;
		cift_yonlu_bliste 
		*temp2 = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		while(temp1 -> sonraki != NULL)
			temp1 = temp1 -> sonraki;
		temp2 -> veri1 = veri1;
		temp2 -> veri2 = veri2;
		temp1 -> sonraki = temp2;
		temp2 -> onceki = temp1;
		temp2 -> sonraki = NULL;
	}
}
void bastan_sil(){
	if(ilk == NULL){
		printf("Bos liste!");
	}
	else if(ilk -> sonraki == NULL){
		ilk = NULL;
		printf("Listede eleman kalmadi");
	}
	else{
		cift_yonlu_bliste *ikinci = ilk -> sonraki;
		ikinci -> onceki = NULL;
		free(ilk);
		ilk = ikinci;
	}
}
void sondan_sil(){
	if(ilk == NULL){
		printf("Bos liste!");
	}
	else if(ilk -> sonraki == NULL){
		ilk = NULL;
		printf("Listede eleman kalmadi");
	}
	else{
		cift_yonlu_bliste *temp = ilk;
		while(temp -> sonraki != NULL)
			temp = temp -> sonraki;
		cift_yonlu_bliste *sondanonceki = temp -> onceki;
		sondanonceki -> sonraki = NULL;
		free(temp);
	}
}
