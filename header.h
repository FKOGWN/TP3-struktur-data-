#include <stdio.h>
#include <string.h>

typedef struct{
	int nomor;
	char nama[50];
	int stok;
	int harga;
}dataObat;


typedef struct{
	dataObat elmt;
	int prev;
	int next;
}elemen;


typedef struct{
	int first;
	int tail;
	elemen data[10];
}list;

void createList( list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(int nomor, char nama[], int stok, int harga, list *L);
void addAfter(int prev, int nomor, char nama[], int stok, int harga, list *L);
void addLast(int nomor, char nama[], int stok, int harga, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);
void printtoHead(list L);
void alergi(list L);
void nyeri(list L);
void demam(list L);
void sorting(list *L);