#include<stdio.h>
#include<stdlib.h>

typedef struct DUGUM
{
    int x;
    struct DUGUM * sonra;
    struct DUGUM * once;  

}DUGUM;

DUGUM * DugumOlustur(DUGUM * once,int x, int a){
	printf("%d. dugum ", a);
    DUGUM * dugum;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum = (DUGUM *)malloc(sizeof(DUGUM));
	if(dugum){

		dugum -> x = x; 
		dugum -> sonra = NULL;

		if(once){
			dugum -> once = once;
			once -> sonra = dugum;
		}else{
			dugum -> once = NULL;
		}
        
	}
	return dugum;
}

void ListeyiYazdir(DUGUM *bastan){
    DUGUM * ekle = bastan;
    printf("= [");
    while (ekle)
    {
        printf("%d  ", ekle -> x);
        ekle = ekle -> sonra;
    }
    printf("]\n");
    return;
    
    
}



int main()
{
    DUGUM * ekle = NULL;
    DUGUM * dugum = NULL;
    DUGUM * bastan = NULL;

    bastan = DugumOlustur(NULL, 1, 1);
    dugum = bastan;
    for (int i = 1; i < 5; i++)
    {
        ekle = DugumOlustur(dugum, i+1, 1);
        dugum -> sonra = ekle;
        dugum = ekle;
    }
    ListeyiYazdir(bastan);

    bastan = DugumOlustur(NULL, 6, 2);
    dugum = bastan;
    for (int i = 6; i < 10; i++)
    {
        ekle = DugumOlustur(dugum, i+1, 2);
        dugum -> sonra = ekle;
        dugum = ekle;
    }
    ListeyiYazdir(bastan);
    
    bastan = DugumOlustur(NULL, 11, 3);
    dugum = bastan;
    for (int i = 11; i < 15; i++)
    {
        ekle = DugumOlustur(dugum, i+1, 3);
        dugum -> sonra = ekle;
        dugum = ekle;
    }
    ListeyiYazdir(bastan);

    bastan = DugumOlustur(NULL, 16, 4);
    dugum = bastan;
    for (int i = 16; i < 20; i++)
    {
        ekle = DugumOlustur(dugum, i+1, 4);
        dugum -> sonra = ekle;
        dugum = ekle;
    }
    ListeyiYazdir(bastan);

    bastan = DugumOlustur(NULL, 21, 5);
    dugum = bastan;
    for (int i = 21; i < 25; i++)
    {
        ekle = DugumOlustur(dugum, i+1, 5);
        dugum -> sonra = ekle;
        dugum = ekle;
    }
    ListeyiYazdir(bastan);


    
    return 0;
}

