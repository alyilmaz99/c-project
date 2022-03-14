#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#define sayi 10
int sayi_turet();


int main(int argc, char** argv) {

	int A[sayi];
	srand(time(NULL));
    for(int i =0; i <sayi ; i++){
        A[i] = sayi_turet();
    }
    dizi_yazdir(A[sayi]);

	ortalama_bul(A[sayi]);
	en_buyuk_bul(A[sayi]);
	en_kucuk_bul(A[sayi]);
	sonuc_goster(A[sayi]);
	return 0;
}

void en_buyuk_bul(int a[sayi]){

	int enBuyuk = a[0];

	for(int i = 0; i < sayi; i++){
		if( a[i] >= enBuyuk){
			enBuyuk = a[i];

		}
	}
	printf("En buyuk = %d \n", enBuyuk);
}
void en_kucuk_bul(int a[sayi]){

	int enKucuk = a[0];
	for(int i=0;i<sayi;i++)
	{
		if(a[i]<=enKucuk)//son bulunan >=, ilk bulunan sadece >
		{
			enKucuk = a[i];
		}
	}
	printf("En kucuk: %d \n",enKucuk);

}

int dizi_topla(int a[sayi]){

	int diziToplam = 0;
	for(int i = 0; i <sayi;i++){
		diziToplam += a[i];
	}

	return diziToplam;
}

void sonuc_goster(int a[sayi]){

	float ortalama =ortalama_bul(a[sayi]);
	float toplam = dizi_topla(a[sayi]);

	printf("Ortalama: %d\n", ortalama);
	printf("Toplam: %d\n", toplam);
}

int ortalama_bul(int a[sayi]){
		float ortalama =0;
		int toplam =0;
		for(int i =0; i< sayi ; i++){
			toplam += a[i];
		}
        ortalama = toplam /sayi;
		return ortalama;

}
void dizi_yazdir(int a[sayi]){

	for(int i =0; i < sayi ; i++){
		printf("%d \n ", a[i]);
	}

}
int sayi_turet(){

		int random=0;
		random= 1+ rand() %20 ;

	return random;
}

int gecti_kaldi(){


}




