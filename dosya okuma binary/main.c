#include <stdio.h>
#include <stdlib.h>

typedef struct musteri{
    int hesapNum;
    char isim[30];
    char soyisim[30];
    double bakiye;
}Musteri;

int main()
{
    Musteri kayit = {0, "", "", 0.0};

    FILE *musteriDosyasi;

    if((musteriDosyasi=fopen("musteri.dat","rb+")) == NULL){
        printf("Dosya oluþturalamadi ");
        return 1;
    }

    fread(&kayit, sizeof(Musteri), 1, musteriDosyasi);

    while(!feof(musteriDosyasi)){
        if(kayit.hesapNum !=0){

            printf("%5d%30s%30s%10.3lf\n",
                   kayit.hesapNum,
                   kayit.isim,
                   kayit.soyisim,
                   kayit.bakiye);
        }

        fread(&kayit, sizeof(Musteri),1,musteriDosyasi);

    }

fclose(musteriDosyasi);


    return 0;
}
