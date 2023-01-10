// Online C compiler to run C program online
#include <stdio.h>

int faktoriyel(int);
int faktoriyel_(int);
int topla(int);
void ters_yaz1(char [], int);
void ters_yaz2(char *, int);
int fib(int);
int main() {
    printf("%d\n", faktoriyel(5));
    printf("%d\n", topla(7));
    char cumle[] = "durmus";
    ters_yaz2(cumle, 6);
    printf("%d\n", fib(7));
    return 0;
}

int faktoriyel(int sayi) {
    if(sayi == 1)
        return 1;
    else
        return sayi * faktoriyel(sayi - 1);
}

int faktoriyel_(int sayi) {
    return sayi == 1 ? 1 : sayi * faktoriyel(sayi - 1);
}

int topla(int sayi) {
    if(sayi == 1)
        return 1;
    else
        return sayi + topla(sayi - 1);
}

void ters_yaz1(char cumle[], int uzunluk) {
    if(uzunluk == 0)
        printf("%c", cumle[0]);
    else {
        printf("%c", cumle[uzunluk--]);
        ters_yaz1(cumle, uzunluk);
    }
}

void ters_yaz2(char *cumle, int uzunluk) {
    if(uzunluk == 0)
        printf("%c", cumle);
    else {
        printf("%c", *(cumle + uzunluk));
        ters_yaz1(cumle, --uzunluk);
    }
}

int fib(int sayi) {
    return sayi == 0 || sayi == 1 ? 1 : fib(sayi - 1) + fib(sayi - 2);
}