#include "header.h"

void createList( list *L){
	(*L).first= -1;
	(*L).first= -1;
	int i;


	for(i=0; i<10; i++){
		/*proses menginisialisasi array*/
		(*L).data[i].prev= -2;
		(*L).data[i].next= -2;
	}
}

int countElement(list L){

	int hasil= 0;

	if(L.first!= -1){
		/*list tidak kosong*/
		int hitung;


		/*inisialisasi*/
		hitung= L.first;

		while(hitung!= -1){
			/*proses*/
			hasil= hasil+1;

			/*iterasi*/
			hitung= L.data[hitung].next;
		}
	}

	return hasil;
}


int emptyElement(list L){
	int hasil= -1;

	if(countElement(L)< 10){
		/*proses pencarian menggunakan sequential search*/
		int ketemu= 0;

		int i=0;
		while((ketemu== 0) && (i<10)){
			if(L.data[i].next== -2){
				hasil= i;
				ketemu= 1;
			}else{
				i++;
			}
		}
	}

	return hasil;
}


void addFirst(int nomor, char nama[], int stok, int harga, list *L){
	if(countElement(*L)<50){
		int baru=emptyElement(*L);

		(*L).data[baru].elmt.nomor= nomor;
		strcpy((*L).data[baru].elmt.nama,nama);
		(*L).data[baru].elmt.stok= stok;
		(*L).data[baru].elmt.harga= harga;


		if((*L).first== -1){
			/*jika list kosong*/
			(*L).data[baru].prev= -1;
			(*L).data[baru].next= -1;
			(*L).tail= baru;
		}else{
			/*jika list tidak kosong*/
			(*L).data[baru].prev= -1;
			(*L).data[baru].next= (*L).first;
			(*L).data[(*L).first].prev= baru;
		}

		(*L).first= baru;
	}else{
		/*proses jika array penuh*/

		printf("sudah tidak dapat ditambah\n");
	}
}

void addAfter(int prev, int nomor, char nama[], int stok, int harga, list *L){
	if(countElement(*L)< 50){
		int baru= emptyElement(*L);

		(*L).data[baru].elmt.nomor= nomor;
		strcpy((*L).data[baru].elmt.nama,nama);
		(*L).data[baru].elmt.stok= stok;
		(*L).data[baru].elmt.harga= harga;

		if((*L).data[prev].next !=-1){
			// jika baru bukan menjadi elemen terakhir
			(*L).data[baru].prev= prev;
			(*L).data[baru].next= (*L).data[prev].next;
			(*L).data[prev].next= baru;
			(*L).data[(*L).data[baru].next].prev= baru;
		}else{
			// jika baru elemen terakhir
			(*L).data[baru].prev= prev;
			(*L).data[prev].next= baru;
			(*L).data[baru].next= -1;
			(*L).tail= baru;
		}		
	}else{
		// prosses jika array penuh
		printf("sudah tidak dapat ditambahkan\n");
	}
}

void addLast(int nomor, char nama[], int stok, int harga, list *L){
	if((*L).first== -1){
		/*prosses jika list masih kosong*/
		int baru=0;

		(*L).data[baru].elmt.nomor= nomor;
		strcpy((*L).data[baru].elmt.nama,nama);
		(*L).data[baru].elmt.stok= stok;
		(*L).data[baru].elmt.harga= harga;


		(*L).data[baru].prev= -1;
		(*L).data[baru].next= -1;
		(*L).first= baru;
		(*L).tail= baru;
	}else{
		/*proses jika list telah berisi elemen*/
		if(countElement(*L)<10){
			/*proses jika array belum penuh*/
			int baru= emptyElement(*L);

			(*L).data[baru].elmt.nomor= nomor;
			strcpy((*L).data[baru].elmt.nama,nama);
			(*L).data[baru].elmt.stok= stok;
			(*L).data[baru].elmt.harga= harga;


			(*L).data[baru].next= -1;
			(*L).data[(*L).tail].next= baru;
			(*L).data[baru].prev= (*L).tail;
			(*L).tail= baru;
		}else{
			/*jika array sudah penuh*/
			printf("sudah tidak dapat ditambah\n");
		}
	}
}


void delFirst(list *L){
	if((*L).first!= -1){
		int hapus= (*L).first;

		if(countElement(*L)== 1){
			(*L).first= -1;
			(*L).tail= -1;
		}else{
			(*L).first= (*L).data[(*L).first].next;
			(*L).data[(*L).first].prev= -1;
		}

		/*elemen awal sebelumnya dikosongkan*/
		(*L).data[hapus].prev= -2;
		(*L).data[hapus].next= -2;
	}else{
		/*proses jika list kosong*/
		printf("list kosong\n");
	}
}


void delAfter(int prev, list *L){
	int hapus= (*L).data[prev].next;
	if(hapus!= -1){
		if((*L).data[hapus].next== -1){
			(*L).tail= prev;
			(*L).data[prev].next= -1;
		}else{
			(*L).data[prev].next= (*L).data[hapus].next;
			(*L).data[(*L).data[hapus].next].prev= prev;
		}

		/*pengosongan elemen*/
		(*L).data[hapus].prev= -2;
		(*L).data[hapus].next= -2;
	}
}



void delLast(list *L){
	if((*L).first!= -1){
		if(countElement(*L)==1){
			/*proses jika list hanya berisi satu elemen*/
			delFirst(L);
		}else{
			int hapus= (*L).tail;
			(*L).tail= (*L).data[hapus].prev;
			(*L).data[(*L).tail].next= -1;
			/*elemen terakhir sebelumnya dikosongkan*/
			(*L).data[hapus].prev= -2;
			(*L).data[hapus].next= -2;
		}
	}else{
		/*proses jika list kosong*/
		printf("list kosong\n");
	}
}

void sorting(list *L){
	dataObat temp;//penampung sementara
	int batas_1,batas_2;

	batas_1= (*L).first;/*inisialisasi batas pertama*/
	while(batas_1!= -1){
		batas_2= (*L).data[batas_1].next;/*inisialisasi baris kedua*/
		while(batas_2!= -1){
			if((*L).data[batas_1].elmt.harga< (*L).data[batas_2].elmt.harga){
				temp= (*L).data[batas_1].elmt;
				(*L).data[batas_1].elmt= (*L).data[batas_2].elmt;
				(*L).data[batas_2].elmt= temp;
			}
			batas_2= (*L).data[batas_2].next;
		}
		batas_1= (*L).data[batas_1].next;
	}
}

void delAll(list *L){
	int i;

	for(i= countElement(*L); i>=1; i--){
		/*proses menghapus elemen list*/
		delLast(L);
	}
}

void alergi(list L){
	sorting(&L);
	int temp_mahal1=0,temp_mahal2=0,mahal=0;
	int temp_murah1=100000,temp_murah2=100000,murah=100000;
	if(L.first!= -1){
		int elmt= L.first;
		int ketemu=0;

		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==2 || L.data[elmt].elmt.nomor==5)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==2){
					if(temp_mahal1<= L.data[elmt].elmt.harga){
						temp_mahal1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==5){
					if(temp_mahal2<= L.data[elmt].elmt.harga){
						temp_mahal2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].next;
		}

		if(ketemu!=0){
			mahal= temp_mahal1+ temp_mahal2;
			printf("%d\n", mahal);
			printf("======\n");
		}

		elmt= L.tail;
		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==2 || L.data[elmt].elmt.nomor==5)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==2){
					if(temp_murah1>= L.data[elmt].elmt.harga){
						temp_murah1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==5){
					if(temp_murah2>= L.data[elmt].elmt.harga){
						temp_murah2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].prev;
		}
	
		if(ketemu==0){
			printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
		}else{
			murah= temp_murah1+ temp_murah2;
			printf("%d\n", murah);
		}
	}else{
		printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
	}
}

void nyeri(list L){
	sorting(&L);
	int temp_mahal1=0,temp_mahal2=0,mahal=0;
	int temp_murah1=100000,temp_murah2=100000,murah=100000;
	if(L.first!= -1){
		int elmt= L.first;
		int ketemu=0;

		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==1 || L.data[elmt].elmt.nomor==4)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==1){
					if(temp_mahal1<= L.data[elmt].elmt.harga){
						temp_mahal1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==4){
					if(temp_mahal2<= L.data[elmt].elmt.harga){
						temp_mahal2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].next;
		}

		if(ketemu!=0){
			mahal= temp_mahal1+ temp_mahal2;
			printf("%d\n", mahal);
			printf("======\n");
		}

		elmt= L.tail;
		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==1 || L.data[elmt].elmt.nomor==4)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==1){
					if(temp_murah1>= L.data[elmt].elmt.harga){
						temp_murah1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==4){
					if(temp_murah2>= L.data[elmt].elmt.harga){
						temp_murah2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].prev;
		}

		if(ketemu==0){
			printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
		}else{
			murah= temp_murah1+ temp_murah2;
			printf("%d\n", murah);
		}
	}else{
		printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
	}
}

void demam(list L){
	int temp_mahal1=0,temp_mahal2=0,mahal=0;
	int temp_murah1=100000,temp_murah2=100000,murah=100000;
	sorting(&L);
	if(L.first!= -1){
		int elmt= L.first;
		int ketemu=0;

		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==1 || L.data[elmt].elmt.nomor==3)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==1){
					if(temp_mahal1<= L.data[elmt].elmt.harga){
						temp_mahal1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==3){
					if(temp_mahal2<= L.data[elmt].elmt.harga){
						temp_mahal2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].next;
		}

		if(ketemu!=0){
			mahal= temp_mahal1+ temp_mahal2;
			printf("%d\n", mahal);
			printf("======\n");
		}

		elmt= L.tail;
		while(elmt!= -1){
			if((L.data[elmt].elmt.nomor==1 || L.data[elmt].elmt.nomor==3)
				&& L.data[elmt].elmt.stok!=0){
				printf("%d %s %d\n", L.data[elmt].elmt.nomor, L.data[elmt].elmt.nama,
				L.data[elmt].elmt.harga);
				ketemu++;
				if(L.data[elmt].elmt.nomor==1){
					if(temp_murah1>= L.data[elmt].elmt.harga){
						temp_murah1= L.data[elmt].elmt.harga;
					}
				}
				if(L.data[elmt].elmt.nomor==3){
					if(temp_murah2>= L.data[elmt].elmt.harga){
						temp_murah2= L.data[elmt].elmt.harga;
					}
				}
				// L.data[elmt].elmt.stok--;
			}
			elmt= L.data[elmt].prev;
		}

		if(ketemu==0){
			printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
		}else{
			murah= temp_murah1+ temp_murah2;
			printf("%d\n", murah);
		}
	}else{
		printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
	}
}