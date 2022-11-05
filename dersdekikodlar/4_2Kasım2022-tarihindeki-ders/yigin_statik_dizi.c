#include <stdio.h>
#define N 10

int yigin[N];
int us = -1; // -> top
void ekle(int [], int);
void cikar(int []);
void listele(int []);
int bosmu(int []);
int kapasite(int []);
void tepe(int []);

int main(){
    printf("Yigin bosmu: %d\n", bosmu(yigin));
    printf("Yiginin kapasitesi: %d\n", kapasite(yigin));
    tepe(yigin);
    ekle(yigin, 1);
    printf("Yigin bosmu: %d\n", bosmu(yigin));
    tepe(yigin);
    ekle(yigin, 2);
    ekle(yigin, 3);
    ekle(yigin, 4);
	ekle(yigin, 5);
    printf("Yiginin kapasitesi: %d\n", kapasite(yigin));
    tepe(yigin);
    listele(yigin);
	cikar(yigin);
	listele(yigin);
	ekle(yigin, 5);
	listele(yigin);
    tepe(yigin);
    printf("Yigin bosmu: %d\n", bosmu(yigin));
    printf("Yiginin kapasitesi: %d\n", kapasite(yigin));
    ekle(yigin, 55);
    ekle(yigin, 45);
    ekle(yigin, 35);
    ekle(yigin, 25);
    ekle(yigin, 15);
    ekle(yigin, 65);
    cikar(yigin);
    listele(yigin);
    printf("Yiginin kapasitesi: %d\n", kapasite(yigin));
    return 0;
}
void ekle(int dizi[], int eleman){ // -> push
    if(N - 1 == us)
        printf("Yigin doludur! %d eklenemedi\n", eleman);
    else{
        us = us + 1;
        yigin[us] = eleman;
    }
}
void cikar(int dizi[]){ // -> pop
    if(us == -1)
        printf("Yigin bos! Yigindan silinecek eleman yoktur\n");
    else{
        int silindi = dizi[us];
        us = us - 1;
        printf("%d elemani yigindan cikartildi\n", silindi);
    }  
}
void listele(int dizi[]){
    if(us == -1)
        printf("Yigin bos! Listelenecek eleman yoktur\n");
    else{
        int temp = us;
        while(temp != -1){
        	printf("%d ", dizi[temp]);
        	temp = temp - 1;
		}
		printf("\n");
    }
}
int bosmu(int dizi[]){ // -> isEmpty
    return us == -1;
}
int kapasite(int dizi[]){ // -> size veya capacity
    if(us == -1)
        return 0;
    else
        return us + 1;
}
void tepe(int dizi[]){ // -> peek
    if(us == -1)
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %d\n", dizi[us]);
}
