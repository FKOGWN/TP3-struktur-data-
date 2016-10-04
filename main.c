 /* Saya Fiko Gunawan tidak melakukan kecurangan seperti yang telah dispesifikasikan
 pada mata kuliah struktur data ,jika saya melakukan
 kecurangan maka Allah adalah saksi saya, dan saya bersedia menerima hukuman-Nya. Amiin */


#include "header.h"


int main(){
	list L;
	createList(&L);

	int i;//variabel iterasi
	int n;/*banyak data yang akan dimasukan*/

	scanf("%d", &n);
	dataObat temp;
	for(i=0; i<n; i++){
		scanf("%d %s %d %d", &temp.nomor, temp.nama, &temp.stok, &temp.harga);
		addFirst(temp.nomor, temp.nama, temp.stok, temp.harga, &L);
	}

	char penyakit[25];
	scanf("%s", penyakit);

	if(strcmp(penyakit,"nyeri")==0){
		nyeri(L);
	}else if(strcmp(penyakit,"demam")==0){
		demam(L);
	}else if(strcmp(penyakit,"alergi")==0){
		alergi(L);
	}

	return 0;
}