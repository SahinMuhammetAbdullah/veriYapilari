/* beş tane bağlı listeyi kulanıcının istediği sıra göre düznele */
#include<stdio.h>
#include<stdlib.h>

typedef struct DUGUM1
{
    int x;
    struct DUGUM1 * sonra1;
    struct DUGUM1 * once1;  

}DUGUM1;
typedef struct DUGUM2
{
    int y;
    struct DUGUM2 * sonra2;
    struct DUGUM2 * once2;  

}DUGUM2;
typedef struct DUGUM3
{
    int z;
    struct DUGUM3 * sonra3;
    struct DUGUM3 * once3;  

}DUGUM3;
typedef struct DUGUM4
{
    int t;
    struct DUGUM4 * sonra4;
    struct DUGUM4 * once4;  

}DUGUM4;
typedef struct DUGUM5
{
    int k;
    struct DUGUM5 * sonra5;
    struct DUGUM5 * once5;  

}DUGUM5;
typedef struct SIRALIDUGUM
{
    int a;
    struct SIRALIDUGUM * sonrax;
    struct SIRALIDUGUM * oncex;

}SIRALIDUGUM;

DUGUM1 * DugumOlustur1(DUGUM1 * once1,int x){
	DUGUM1 * dugum1;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum1 = (DUGUM1 *)malloc(sizeof(DUGUM1));
	if(dugum1){
		//Yeni düğüme veri kaydediliyor.
		dugum1 -> x = x; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		dugum1 -> sonra1 = NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(once1){
			dugum1 -> once1 = once1;
			once1 -> sonra1 = dugum1;
		}else{
			//root ise önceki düğümü yok.
			dugum1 -> once1 = NULL;
		}
	}
	return dugum1;
}
DUGUM2 * DugumOlustur2(DUGUM2 * once2,int y){
	DUGUM2 * dugum2;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum2 = (DUGUM2 *)malloc(sizeof(DUGUM2));
	if(dugum2){
		//Yeni düğüme veri kaydediliyor.
		dugum2 -> y = y; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		dugum2 -> sonra2 = NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(once2){
			dugum2 -> once2 = once2;
			once2 -> sonra2 = dugum2;
		}else{
			//root ise önceki düğümü yok.
			dugum2 -> once2 = NULL;
		}
	}
	return dugum2;
}
DUGUM3 * DugumOlustur3(DUGUM3 * once3,int z){
	DUGUM3 * dugum3;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum3 = (DUGUM3 *)malloc(sizeof(DUGUM3));
	if(dugum3){
		//Yeni düğüme veri kaydediliyor.
		dugum3 -> z = z; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		dugum3 -> sonra3 = NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(once3){
			dugum3 -> once3 = once3;
			once3 -> sonra3 = dugum3;
		}else{
			//root ise önceki düğümü yok.
			dugum3 -> once3 = NULL;
		}
	}
	return dugum3;
}
DUGUM4 * DugumOlustur4(DUGUM4 * once4,int t){
	DUGUM4 * dugum4;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum4 = (DUGUM4 *)malloc(sizeof(DUGUM4));
	if(dugum4){
		//Yeni düğüme veri kaydediliyor.
		dugum4 -> t = t; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		dugum4 -> sonra4 = NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(once4){
			dugum4 -> once4 = once4;
			once4 -> sonra4 = dugum4;
		}else{
			//root ise önceki düğümü yok.
			dugum4 -> once4 = NULL;
		}
	}
	return dugum4;
}
DUGUM5 * DugumOlustur5(DUGUM5 * once5,int k){
	DUGUM5 * dugum5;
	//Yeni düğüm için bellekten yer ayrılıyor.
	dugum5 = (DUGUM5 *)malloc(sizeof(DUGUM5));
	if(dugum5){
		//Yeni düğüme veri kaydediliyor.
		dugum5 -> k = k; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		dugum5 -> sonra5 = NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(once5){
			dugum5 -> once5 = once5;
			once5 -> sonra5 = dugum5;
		}else{
			//root ise önceki düğümü yok.
			dugum5 -> once5 = NULL;
		}
	}
	return dugum5;
}

SIRALIDUGUM * DugumleriSirala(SIRALIDUGUM * oncex, int a){
    SIRALIDUGUM * siralidugum;
    siralidugum = (SIRALIDUGUM *)malloc(sizeof(SIRALIDUGUM));
    if (siralidugum){

        siralidugum -> a = a;
        siralidugum -> sonrax = NULL;

        if (oncex){
            siralidugum -> oncex = oncex;
            oncex -> sonrax = siralidugum;
        }else{
            siralidugum -> oncex = NULL;
        }
        

    }
    

    return siralidugum;
}

void ListeyiYazdir1(DUGUM1 *bastan1){
    DUGUM1 * ekle1 = bastan1;
    printf("1. liste = [");
    while (ekle1)
    {
        printf("%d  ", ekle1 -> x);
        ekle1 = ekle1 -> sonra1;
    }
    printf("]\n");
    return;
    
    
}
void ListeyiYazdir2(DUGUM2 *bastan2){
    DUGUM2 * ekle2 = bastan2;
    printf("2. liste = [");
    while (ekle2)
    {
        printf("%d  ", ekle2 -> y);
        ekle2 = ekle2 -> sonra2;
    }
    printf("]\n");
    return;
    
    
}
void ListeyiYazdir3(DUGUM3 *bastan3){
    DUGUM3 * ekle3 = bastan3;
    printf("3. liste = [");
    while (ekle3)
    {
        printf("%d  ", ekle3 -> z);
        ekle3 = ekle3 -> sonra3;
    }
    printf("]\n");
    return;
    
    
}
void ListeyiYazdir4(DUGUM4 *bastan4){
    DUGUM4 * ekle4 = bastan4;
    printf("4. liste = [");
    while (ekle4)
    {
        printf("%d  ", ekle4 -> t);
        ekle4 = ekle4 -> sonra4;
    }
    printf("]\n");
    return;
    
    
}
void ListeyiYazdir5(DUGUM5 *bastan5){
    DUGUM5 * ekle5 = bastan5;
    printf("5. liste = [");
    while (ekle5)
    {
        printf("%d  ", ekle5 -> k);
        ekle5 = ekle5 -> sonra5;
    }
    printf("]\n");
    return;
    
    
}

/*void listeleriSirala(SIRALIDUGUM * bastanx){
    printf("1. dugumun sirasini belirleyiniz: ");
    scanf("%d", &ekle*);
    SIRALIDUGUM * eklex = bastanx;
    while (eklex)
    {
        printf("%d ", eklex -> a);
        eklex = eklex -> sonrax;
    }
    


    return;
}*/


int main(void)
{
    DUGUM1 * ekle1 = NULL;
    DUGUM1 * dugum1 = NULL;
    DUGUM1 * bastan1 = NULL;

    DUGUM2 * ekle2 = NULL;
    DUGUM2 * dugum2 = NULL;
    DUGUM2 * bastan2 = NULL;

    DUGUM3 * ekle3 = NULL;
    DUGUM3 * dugum3 = NULL;
    DUGUM3 * bastan3 = NULL;

    DUGUM4 * ekle4 = NULL;
    DUGUM4 * dugum4 = NULL;
    DUGUM4 * bastan4 = NULL;

    DUGUM5 * ekle5 = NULL;
    DUGUM5 * dugum5 = NULL;
    DUGUM5 * bastan5 = NULL;

    SIRALIDUGUM * eklex = NULL;
    SIRALIDUGUM * dugumx = NULL;
    SIRALIDUGUM * bastanx = NULL;

    bastan1 = DugumOlustur1(NULL, 1);
    dugum1 = bastan1;
    for (int i = 1; i < 5; i++)
    {
        ekle1 = DugumOlustur1(dugum1, i+1);
        dugum1 -> sonra1 = ekle1;
        dugum1 = ekle1;
    }

    bastan2 = DugumOlustur2(NULL, 6);
    dugum2 = bastan2;
    for (int i = 6; i < 10; i++)
    {
        ekle2 = DugumOlustur2(dugum2, i+1);
        dugum2-> sonra2 = ekle2;
        dugum2 = ekle2;
    }

    bastan3 = DugumOlustur3(NULL, 11);
    dugum3 = bastan3;
    for (int i = 11; i < 15; i++)
    {
        ekle3 = DugumOlustur3(dugum3, i+1);
        dugum3 -> sonra3 = ekle3;
        dugum3 = ekle3;
    }

    bastan4 = DugumOlustur4(NULL, 16);
    dugum4 = bastan4;
    for (int i = 16; i < 20; i++)
    {
        ekle4 = DugumOlustur4(dugum4, i+1);
        dugum4 -> sonra4 = ekle4;
        dugum4 = ekle4;
    }

    bastan5 = DugumOlustur5(NULL, 21);
    dugum5 = bastan5;
    for (int i = 21; i < 25; i++)
    {
        ekle5 = DugumOlustur5(dugum5, i+1);
        dugum5 -> sonra5 = ekle5;
        dugum5 = ekle5;
    }

    ListeyiYazdir1(bastan1);
    ListeyiYazdir2(bastan2);   
    ListeyiYazdir3(bastan3);
    ListeyiYazdir4(bastan4);   
    ListeyiYazdir5(bastan5);     
    return 0;
}