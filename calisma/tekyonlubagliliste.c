#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
{
    int veri;
    struct dugum *adres;
}liste;


liste *dugumolustur(liste *adres,int veri)
{
    liste *veri1;
	veri1 = (liste *)malloc(sizeof(liste));  
    if (veri1)
    {
		veri1 -> veri = veri; 
		veri1 -> adres = NULL;
    }
    return veri1;

}

void ListeyiYazdir(liste *bastan, int a){
    printf("%d. dugum ", a);
    liste * ekle = bastan;
    printf("= [");
    while (ekle)
    {
        printf("%d  ", ekle -> veri);
        ekle = ekle -> adres;
    }
    printf("]\n");
}

void listeleribagla()
{
    

}

int main()
{
    int q,w,e,r,t;
    liste * ekle = NULL;
    liste * veri1 = NULL;
    liste * bastan = NULL;
    
    bastan = dugumolustur(NULL, 1);
    veri1 = bastan;
    for (int i = 1; i < 5; i++)
    {
        ekle = dugumolustur(veri1, i+1);
        veri1 -> adres = ekle;
        veri1 = ekle;
    }
    ListeyiYazdir(bastan, 1);
    
    bastan = dugumolustur(NULL, 6);
    veri1 = bastan;
    for (int i = 6; i < 10; i++)
    {
        ekle = dugumolustur(veri1, i+1);
        veri1 -> adres = ekle;
        veri1 = ekle;
    }
    ListeyiYazdir(bastan, 2);
    
    bastan = dugumolustur(NULL, 11);
    veri1 = bastan;
    for (int i = 11; i < 15; i++)
    {
        ekle = dugumolustur(veri1, i+1);
        veri1 -> adres = ekle;
        veri1 = ekle;
    }
    ListeyiYazdir(bastan, 3);
    
    bastan = dugumolustur(NULL, 16);
    veri1 = bastan;
    for (int i = 16; i < 20; i++)
    {
        ekle = dugumolustur(veri1, i+1);
        veri1 -> adres = ekle;
        veri1 = ekle;
    }
    ListeyiYazdir(bastan, 4);
    
    bastan = dugumolustur(NULL, 21);
    veri1 = bastan;
    for (int i = 21; i < 25; i++)
    {
        ekle = dugumolustur(veri1, i+1);
        veri1 -> adres = ekle;
        veri1 = ekle;
    }
    ListeyiYazdir(bastan, 5);
    
    //printf("Listeleri siralamak icin bosluklar birakarak deger giriniz(ornek: 1 2 3 4 5 ): ");
    //scanf("%d %d %d %d %d", &q, &w, &e, &r, &t);
    if (veri1 == 1)
    {
        printf("%d", &veri1);
    }


    return 0;
}
