#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int veri1;
    double veri2;
    struct dugum *onceki;
    struct dugum *sonraki;
};
typedef struct dugum cift_yonlu_bliste;

int main(){
    cift_yonlu_bliste *dugum1;
	dugum1 = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
    dugum1 -> veri1 = 10;
    dugum1 -> veri2 = 1.2;
    dugum1 -> onceki = NULL;
    dugum1 -> sonraki = NULL;
    dugum1 -> sonraki = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
    dugum1 -> sonraki -> veri1 = 20;
    dugum1 -> sonraki -> veri2 = 2.7;
    dugum1 -> sonraki -> onceki = dugum1;
    dugum1 -> sonraki -> sonraki = NULL;
    dugum1 -> sonraki -> sonraki = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
    dugum1 -> sonraki -> sonraki -> veri1 = 30;
    dugum1 -> sonraki -> sonraki -> veri2 = -4.9;
    dugum1 -> sonraki -> sonraki -> onceki = dugum1 -> sonraki;
    dugum1 -> sonraki -> sonraki -> sonraki = NULL;
    cift_yonlu_bliste *temp = dugum1;
	while(temp != NULL){
		printf("%d ", temp -> veri1);
        printf("%f\n", temp -> veri2);
		temp = temp -> sonraki;
	}
    return 0;
}