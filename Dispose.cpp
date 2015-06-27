// All function to dispose memory taken during process

#include<iostream>
#include<stdlib.h>
#include"DataStructure.h"

BookList * DeleteLibrary(BookList * list) {
	using namespace std;
	BookNode * headBook = list->head;
	free(headBook);
	cout << "释放书本占用空间" << endl;
	free(list);
	return NULL;
}

ReaderList * DeleteReaderList(ReaderList * list) {
	using namespace std;
	Reader * headReader = list->head;
	free(headReader);
	cout << "释放读者占用空间" << endl;
	free(list);
	return NULL;
}