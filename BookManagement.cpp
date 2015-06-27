// This file includes all function in book management

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include"Message.h"
#include"DataStructure.h"
#include"Functions.h"

extern BookList * library;

void BookManagementFunction() {
	using namespace std;
	int order, isLoop = 1;
	while (isLoop) {
		system("cls");
		cout << BM_NAME << BM_MENU;
		cout << ACQUIRE_ORDER;
		cin >> order;
		switch (order)
		{
		case 0:
			isLoop = 0;
			break;
		case 1:
			AddBooks();
			break;
		case 2:
			SearchForBook();
			break;
		case 3:
			PrintLibrary();
			break;
		case 4:
			SaveLibrary();
			break;
		case 5:
			LoadLibrary();
			break;
		default:
			break;
		}
	}
}

void AddBooks() {
	using namespace std;
	int isLoop = 1, count = 0, curID = library->count;
	unsigned int inputID;
	string tempStr;
	Book * bookInfo = NULL;
	BookNode * headBook = library->head;
	while (isLoop) {
		cout << BM_ADD_ID;
		cin >> inputID;
		if (inputID == 0) {
			isLoop = 0;
			continue;
		}
		bookInfo = (Book *)malloc(sizeof(Book));
		bookInfo->id = inputID;
RN:		cout << BM_ADD_NAME;
		cin >> tempStr;
		if (tempStr.length() > 30) {
			cout << INLLEGAL_NAME;
			goto RN;
		}
		for (int i = 0; i <= tempStr.length(); i++)
			bookInfo->name[i] = tempStr[i];
RA:		cout << BM_ADD_AUTHOR;
		cin >> tempStr;
		if (tempStr.length() > 20) {
			cout << INLLEGAL_AUTHOR;
			goto RA;
		}
		for (int i = 0; i <= tempStr.length(); i++)
			bookInfo->author[i] = tempStr[i];
RP:		cout << BM_ADD_PRESS;
		cin >> tempStr; 
		if (tempStr.length() > 20) {
			cout << INLLEGAL_PRESS;
			goto RP;
		}
		for (int i = 0; i <= tempStr.length(); i++)
			bookInfo->press[i] = tempStr[i];
		headBook = (BookNode *)realloc(headBook, sizeof(BookNode) * (curID + 1));
		headBook[curID].book = bookInfo;
		cout << BM_ADD_COMPLETE;
		count++;
		curID++;
	}
	library->head = headBook;
	library->tail = &(headBook[curID - 1]);
	library->count = library->count + count;
	QuickSort(0, curID - 1);
}

void PrintLibrary() {
	using namespace std;
	BookNode * headBook = library->head;
	unsigned int count = library->count;
	cout << setw(7) << "序号" << "\t" << setw(7) << "书号" << "\t" << setw(15) << "书名" << "\t" << setw(15) << "作者" << "\t" << setw(15) << "出版社" << endl;
	for (unsigned int i = 0; i < count; i++) {
		cout << setw(7) << i + 1 << "\t" << setw(7) << headBook[i].book->id << "\t" << setw(15) << headBook[i].book->name << "\t" << setw(15) << headBook[i].book->author << "\t" << setw(15) << headBook[i].book->press << endl;
	}
	system("Pause");
}

void QuickSort(unsigned int begin, unsigned int end) {
	BookNode *headBook = library->head;
	unsigned int frontP = begin, backP = end, standard = begin;
	if (begin == end)
		return;
	if (begin + 1 == end) {
		if (headBook[begin].book->id > headBook[end].book->id) {
			SwapData(&(headBook[begin]), &(headBook[end]));
		}
		return;
	}
	while (frontP < backP) {
		for (; backP > frontP; backP--) {
			if (headBook[backP].book->id < headBook[standard].book->id) {
				break;
			}
		}
		for (; frontP< backP; frontP++) {
			if (headBook[frontP].book->id > headBook[standard].book->id) {
				break;
			}
		}
		SwapData(&(headBook[frontP]), &(headBook[backP]));
	}
	SwapData(&(headBook[frontP]),&(headBook[standard]));
	QuickSort(begin, frontP);
	if (backP < end)
		QuickSort(backP + 1, end);
}

void SwapData(BookNode * one, BookNode * two) {
	Book * tempPtr = one->book;
	one->book = two->book;
	two->book = tempPtr;
}

void SearchForBook() {
	using namespace std;
	BookNode * headBook = library->head;
	string tempStr;
	unsigned int targetID = 0, result;
	cout << BM_SEARCH_INPUT;
	cin >> tempStr;
	for (unsigned int i = 0; i < tempStr.length(); i++) {
		if (tempStr[i] >= '0' && tempStr[i] <= '9') {
			targetID = targetID * 10 + tempStr[i] - 48;
		}
		else
			break;
	}
	result = SearchByID(targetID);
	if (result)
		cout << BM_SEARCH_SUCCESS << setw(7) << headBook[result].book->id << "\t" << setw(15) << headBook[result].book->name << "\t" << setw(15) << headBook[result].book->author << "\t" << setw(15) << headBook[result].book->press << endl;
	else
		cout << BM_SEARCH_FAILURE;
 }

unsigned int SearchByID(unsigned int id) {
	BookNode * headBook = library->head;
	unsigned int target = 0;
	unsigned upBound = library->count - 1, downBound = 0;
	while (upBound != downBound) {
		if (upBound == downBound + 1) {
			if (headBook[upBound].book->id == id) target = upBound;
			else if(headBook[downBound].book->id == id) target = downBound;
			else target = 0;
			break;
		}
		target = (upBound - downBound) / 2;
		if (headBook[target].book->id == id) {
			break;
		}
		else {
			if (headBook[target].book->id > id) {
				upBound = target;
			}
			else {
				downBound = target;
			}
		}
	}
	return target;
}