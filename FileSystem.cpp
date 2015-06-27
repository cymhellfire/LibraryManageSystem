// This file includes all functions for file operation

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include"DataStructure.h"
#include"Functions.h"

extern BookList * library;
extern ReaderList * readers;

int SaveLibrary() {
	using namespace std;
	BookNode * headBook = library->head;
	unsigned int count = library->count;
	ofstream lib("lib.data");
	if (!lib) return 1;
	lib << count << endl;
	for (unsigned int i = 0; i < count; i ++) {
		lib << headBook[i].book->id << "\t" << headBook[i].book->name << "\t" << headBook[i].book->author << "\t" << headBook[i].book->press << endl;
	}
	lib.close();
	return 0;
}

int LoadLibrary() {
	using namespace std;
	BookNode * headNode = library->head;
	Book * bookInfo;
	char buff[100];
	unsigned int count = 0, tempID = 0, curID = library->count;
	string tempStr;
	int ptrLoc, inputLoc = 0;
	ifstream libData("lib.data");
	if (!libData) return 1;
	libData.getline(buff, 10);
	for (int i = 0; i < 10; i++) {
		if (buff[i] >= '0' && buff[i] <= '9') {
			count = count * 10 + buff[i] - 48;
		}
		else
			break;
	}
	for (unsigned int i = 0; i < count; i++) {
		bookInfo = (Book*)malloc(sizeof(Book));
		libData.getline(buff, 100);
		for (ptrLoc = 0; ptrLoc < 100; ptrLoc++) {
			if (buff[ptrLoc] != '\t') {
				tempID = tempID * 10 + buff[ptrLoc] - 48;
			}
			else
				break;
		}
		bookInfo->id = tempID;
		ptrLoc++;
		for (; ptrLoc < 100; ptrLoc++) {
			if (buff[ptrLoc] != '\t') {
				bookInfo->name[inputLoc] = buff[ptrLoc];
				inputLoc++;
			}
			else
				break;
		}
		bookInfo->name[inputLoc] = '\0';
		ptrLoc++;
		inputLoc = 0;
		for (; ptrLoc < 100; ptrLoc++) {
			if (buff[ptrLoc] != '\t') {
				bookInfo->author[inputLoc] = buff[ptrLoc];
				inputLoc++;
			}
			else
				break;
		}
		bookInfo->author[inputLoc] = '\0';
		ptrLoc++;
		inputLoc = 0;
		for (; ptrLoc < 100; ptrLoc++) {
			if (buff[ptrLoc] != '\0') {
				bookInfo->press[inputLoc] = buff[ptrLoc];
				inputLoc++;
			}
			else
				break;
		}
		bookInfo->press[inputLoc] = '\0';
		inputLoc = 0;
		headNode = (BookNode*)realloc(headNode, sizeof(BookNode)* (curID + 1));
		headNode[curID].book = bookInfo;
		tempID = 0;
		curID++;
	}
	library->head = headNode;
	library->tail = &(headNode[curID - 1]);
	library->count += count;
	return 0;
}

int SaveReaders() {
	using namespace std;
	Reader * headReader = readers->head;
	ofstream rea("rea.data");
	if (!rea) return 1;
	rea << readers->count << endl;
	for (int i = 0; i < readers->count; i++) {
		rea << headReader[i].stdID << "\t" << headReader[i].name << endl;
	}
	rea.close();
	return 0;
}

int LoadReaders() {
	using namespace std;
	Reader * curReader = readers->head, *prevReader = NULL;
	char buff[100];
	unsigned int count = 0, tempID = 0;
	int inputPtr = 0, ptrLoc = 0;
	ifstream rea("rea.data");
	if (!rea) return 1;
	rea.getline(buff, 10);
	for (int i = 0; i < 10; i++) {
		if (buff[i] >= '0' && buff[i] <= '9') {
			count = count * 10 + buff[i] - 48;
		}
		else
			break;
	}
	for (unsigned int i = 0; i < count; i++) {

		rea.getline(buff, 100);

	}
}