#include <stdio.h>
#include <stdlib.h>

typedef struct musteri{
    int hesapNum;
    char isim[30];
    char soyisim[30];
    double bakiye;


}Musteri;

enum ISLEMLER {TEXT=1, EKLE,GUNCELLE, SIL};

void textDosyaDonustur(FILE *musteriDosyasi);

void musteriEkle(FILE *);

void musteriGuncelle(FILE *);

void musteriSil(FILE *);

void listele(FILE *);
int menu();

int main()
{



    FILE *musteriDosyasi;

    if((musteriDosyasi = fopen("musteri.dat","rb+"))==NULL){

        printf("there is some problem in here mtf");
        return 1;
    }

    int secim = menu();
    switch(secim){
    case TEXT:
        textDosyaDonustur(musteriDosyasi);
    break;

    case EKLE:
        //musteriEkle(musteriDosyasi);
        break;
    case GUNCELLE:
        musteriGuncelle(musteriDosyasi);
        break;
    case SIL:
        musteriSil(musteriDosyasi);
        break;
    default:
        printf("Hatali secim");
        break;
    }

    fclose (musteriDosyasi);
    return 0;
}

int menu(){
    int secim;

    printf("islem seciniz \n");
    printf("1) txt ye aktar\n");
    printf("2)musteri ekle\n");
    printf("3)musteri guncelleme\n");
    printf("4)Musteri sil \n ");
    scanf("%d",&secim);

    return secim;

}

void musteriGuncelle(FILE *musteriDosyasi){
    int hesapNumarasi;
    Musteri kayit;

    printf("Guncellenecek kayit no :");
    scanf("%d", &hesapNumarasi);

    fseek(musteriDosyasi, (hesapNumarasi-1)*sizeof(Musteri),
          SEEK_SET
           );

     fread(&kayit, sizeof(Musteri), 1, musteriDosyasi);

     if(kayit.hesapNum == hesapNumarasi){

        printf("Eski isim: %s Yeni isim : ", kayit.isim );
        scanf("%30s",kayit.isim);

        printf("Eski  soyisim: %s Yeni soyisim : ", kayit.soyisim );
        scanf("%30s",kayit.soyisim);

        printf("Eski  bakiye: %lf Yeni bakiye : ", kayit.bakiye );
        scanf("%lf",&kayit.bakiye);

     fseek(musteriDosyasi, (hesapNumarasi-1)*sizeof(Musteri),
          SEEK_SET
           );
           fwrite(&kayit, sizeof(Musteri), 1, musteriDosyasi);

     }
     listele(musteriDosyasi);

}

void musteriSil(FILE *musteriDosyasi){
        int hesapNumarasi;

        Musteri kayit, bosKayit={0,"","",0.0};

        printf("silinecek hesap numarasi: ");
        scanf("%d", &hesapNumarasi);


        //ilgili kayda git

        fseek(musteriDosyasi, (hesapNumarasi-1)*sizeof(Musteri),SEEK_SET);

        //kaydi okuyalim
        fread(&kayit, sizeof(Musteri),1,musteriDosyasi);

        if(kayit.hesapNum== hesapNumarasi && hesapNumarasi !=0){

            fseek(musteriDosyasi, (hesapNumarasi-1)*sizeof(Musteri), SEEK_SET);
            fwrite(&bosKayit, sizeof(Musteri), 1 , musteriDosyasi);

        }
        listele(musteriDosyasi);


}

void textDosyaDonustur(FILE *musteriDosyasi){
        FILE *txtFile;
        Musteri kayit;
        if((txtFile=fopen("musteri.txt","w"))==NULL){

            printf("dosya olusmadi");
            return 1;
           }

        fprintf(txtFile,"%8s%30s%30s%15s\n",
                "Hesap No","Isim","Soyisim","Bakiye");

        fseek(musteriDosyasi,0,SEEK_SET);
        fread(&kayit, sizeof(Musteri),1,musteriDosyasi);

        while(!feof(musteriDosyasi)){

            if(kayit.hesapNum !=0){
                fprintf(txtFile,"%8d%30s%30s%15.3lf\n",
                       kayit.hesapNum,
                       kayit.isim,
                       kayit.soyisim,
                       kayit.bakiye);

            }
            fread(&kayit, sizeof(Musteri), 1, musteriDosyasi);
        }
        fclose(txtFile);

}


void listele (FILE *musteriDosyasi){
    Musteri kayit;

    fseek(musteriDosyasi, 0,SEEK_SET);
    fread(&kayit, sizeof(Musteri), 1, musteriDosyasi);

    while(!feof(musteriDosyasi)){
        if (kayit.hesapNum !=0){

            printf("%5d%30s%30s%10.3lf\n",
                   kayit.hesapNum,
                   kayit.isim,
                   kayit.soyisim,
                   kayit.bakiye);
        }

        fread(&kayit, sizeof(Musteri),1,musteriDosyasi);
    }
}
