// All function to dispose memory taken during process

#include<iostream>
#include<stdlib.h>
#include"DataStructure.h"

BookList * DeleteLibrary(BookList * list) {
	using namespace std;
	BookNode * headBook = list->head;
	free(headBook);
	cout << "�ͷ��鱾ռ�ÿռ�" << endl;
	free(list);
	return NULL;
}

ReaderList * DeleteReaderList(ReaderList * list) {
	using namespace std;
	Reader * headReader = list->head;
	free(headReader);
	cout << "�ͷŶ���ռ�ÿռ�" << endl;
	free(list);
	return NULL;
}