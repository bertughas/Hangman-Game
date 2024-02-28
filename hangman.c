#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char kelimeler[][20] = {"ARABA", "OGRETMEN", "ZONGULDAK", "HATAY", "YUNUS", "GAMZE", "CICEK", "METRO", "UZAY"};
char *kelime;
char *tahmin;
int size;
int hakSayisi = 6;

void kelimeOlustur() {
    int index = rand() % 9;
    kelime = kelimeler[index];
    size = strlen(kelime);
    tahmin = (char *)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < size; i++) {
        tahmin[i] = '-';
    }
    tahmin[size] = '\0';
}

void harfKontrol(char harf) {
    int yanlisTahmin = 1;
    for (int i = 0; i < size; i++) {
        if (harf == kelime[i]) {
            tahmin[i] = harf;
            yanlisTahmin = 0;
        }
    }
    if (yanlisTahmin) {
        printf("Yanlis tahmin, kalan hak:%d\n", hakSayisi--);
    } else {
        printf("Dogru tahmin:%s\n", tahmin);
    }
}

void adamCiz() {
    switch (hakSayisi) {
        case 6:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      \n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|_\n");
            break;
        case 5:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|_\n");
            break;
        case 4:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |      |\n");
            printf(" |      \n");
            printf("_|_\n");
            break;
        case 3:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\n");
            printf(" |      \n");
            printf("_|_\n");
            break;
        case 2:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |      \n");
            printf("_|_\n");
            break;
        case 1:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     / \n");
            printf("_|_\n");
            break;
        default:
            printf(" ________\n");
            printf(" |      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     / \\\n");
            printf("_|_\n");
            break;
    }
}

int kelimeKontrol() {
    return strcmp(kelime, tahmin) == 0;
}

int main() {
    srand(time(NULL));
    printf("\t\tHANG MAN OYUNUNA HOSGELDINIZ.\n");
    printf("Hak sayiniz:6\n");
    printf("Hak sayisi azaldikca Muhittinin asilma ihtimali artacaktir.\n");
    kelimeOlustur();
    printf("\nHarf sayisi:%d\n", size);
    printf("%s\n", tahmin);
    while (hakSayisi > 0) {
        printf("\nHarf giriniz: ");
        char harf;
        scanf(" %c", &harf);
        harfKontrol(harf);
        adamCiz();
        if (kelimeKontrol()) {
            printf("\nTEBRIKLER KAZANDINIZ.\n");
            break;
        }
    }
    if (hakSayisi == 0) {
        printf("Maalesef kazanamadiniz. Dogru kelime: %s\n", kelime);
    }

    free(tahmin); // Belleði serbest býrak

    return 0;
}
