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

cift_yonlu_bliste *dugumolustur(int, double);
void listele(cift_yonlu_bliste*, char []);
int eleman_say(cift_yonlu_bliste*, char []);
void eleman_ara(cift_yonlu_bliste*, int);

int main(){
    cift_yonlu_bliste *dugum1 = dugumolustur(55, 2.3);
    cift_yonlu_bliste *dugum2 = dugumolustur(20, 0.5);
    cift_yonlu_bliste *dugum3 = dugumolustur(34, -1.7);
    cift_yonlu_bliste *dugum4 = dugumolustur(6, 3.14);
    cift_yonlu_bliste *dugum5 = dugumolustur(12, 4.3);
    cift_yonlu_bliste *dugum6 = dugumolustur(8, 7.2);
    dugum1 -> sonraki = dugum2;
    dugum2 -> sonraki = dugum3;
    dugum3 -> sonraki = dugum4;
    dugum4 -> sonraki = dugum5;
    dugum5 -> sonraki = dugum6;
    dugum2 -> onceki = dugum1;
    dugum3 -> onceki = dugum2;
    dugum4 -> onceki = dugum3;
    dugum5 -> onceki = dugum4;
    dugum6 -> onceki = dugum5;
    listele(dugum6, "geri");
    printf("%d tane dugum vardir\n", eleman_say(dugum1, "geri"));
    printf("%d tane dugum vardir\n", eleman_say(dugum1, "ileri"));
    printf("%d tane dugum vardir\n", eleman_say(dugum6, "geri"));
    printf("%d tane dugum vardir\n", eleman_say(dugum6, "ileri"));
    cift_yonlu_bliste *dugum7 = dugumolustur(100, 19.05);
    dugum6 -> sonraki = dugum7;
    dugum7 -> onceki = dugum6;
    listele(dugum7, "geri");
    printf("%d tane dugum vardir\n", eleman_say(dugum7, "geri"));
    eleman_ara(dugum1, 50);
    eleman_ara(dugum1, 100);
    return 0;
}

cift_yonlu_bliste *dugumolustur(int veri1, double veri2)
{
    cift_yonlu_bliste 
	*yenidugum = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
    yenidugum -> veri1 = veri1;
    yenidugum -> veri2 = veri2;
    yenidugum -> onceki = NULL;
    yenidugum -> sonraki = NULL;
    return yenidugum;
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

int eleman_say(cift_yonlu_bliste *sayim_yeri, char mesaj[]){
	cift_yonlu_bliste *temp = sayim_yeri;
	int sayac = 0;
	if(!strcmp(mesaj, "geri")){
		if(temp == NULL)
			return 0;
		else{
			while(temp != NULL){
				sayac += 1;
				temp = temp -> onceki;
			}
		}
	}
    else{
    	if(temp == NULL)
			return 0;
		else{
			while(temp != NULL){
				sayac += 1;
				temp = temp -> sonraki;
			}
		}
	}
	return sayac;
}

void eleman_ara(cift_yonlu_bliste *baslama_noktasi, int aranan){
	cift_yonlu_bliste *temp = baslama_noktasi;
	while(temp != NULL){
		if(temp -> veri1 == aranan){
			printf("aranan %d listede bulundu\n");
			return;
		}
		temp = temp -> sonraki;
	}
	printf("aranan %d listede bulunamadi\n");
}
