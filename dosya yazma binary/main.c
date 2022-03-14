#include <stdio.h>
#include <stdlib.h>

typedef struct musteri {
    int hesapNum;
    char isim[30];
    char soyisim[30];
    double bakiye;


}Musteri;

int main()
{
    Musteri kayit = {0,"", "", 0.0};

    FILE *musteriDosyasi;

    musteriDosyasi = fopen("musteri.dat","rb+");

    if(musteriDosyasi == NULL){

        printf("Dosya olusmadi ");
        return 1;
    }
    else{
        printf("Hesap Numarasi: ");
        scanf("%d",&kayit.hesapNum);
        while(kayit.hesapNum !=0)
        {
            printf("Musteri Bilgileri: ");
            scanf("%s%s%lf",
                  kayit.isim,
                  kayit.soyisim,
                  &kayit.bakiye);

            fseek(
                  musteriDosyasi,
                  (kayit.hesapNum-1)* sizeof(Musteri),
                  SEEK_SET
                  );
            fwrite(&kayit, sizeof(Musteri), 1, musteriDosyasi);
            printf("Hesap numarasi: ");
            scanf("%d", &kayit.hesapNum);

        }
        fclose(musteriDosyasi);
    }


    return 0;
}
