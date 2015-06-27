// This file includes all function used to initialization

#include<iostream>
#include<stdlib.h>
#include"DataStructure.h"

extern BookList * library;
extern ReaderList * readers;

void InitializationLibrary() {
	library = (BookList *)malloc(sizeof(BookList));
	library->count = 0;
	library->head = NULL;
	library->tail = NULL;
}

void InitializationReaders() {
	readers = (ReaderList *)malloc(sizeof(ReaderList));
	readers->head = NULL;
	readers->tail = NULL;
	readers->count = 0;
}