// This file includes all functions used for reader

#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<string>
#include"Functions.h"
#include"DataStructure.h"
#include"Message.h"

extern ReaderList * readers;

void ReaderManagementFunction() {
	using namespace std;
	int isLoop = 1, orderIndex;
	while (isLoop) {
		system("cls");
		cout << RM_MENU;
		cout << ACQUIRE_ORDER;
		cin >> orderIndex;
		switch (orderIndex) {
		case 0:
			isLoop = 0;
			break;
		case 1:
			AddReader();
			break;
		case 2:
			SearchForReader();
			break;
		case 3:
			PrintReaders();
			break;
		case 4:
			SaveReaders();
			break;
		case 5:
			LoadReaders();
			break;
		}
	}
}

void AddReader() {
	using namespace std;
	Reader * headReader;
	int isLoop = 1;
	unsigned int tempint, count = readers->count;
	string tempStr;
	headReader = readers->head;
	while (isLoop) {
		cout << RM_ADD_ID;
		cin >> tempint;
		if (tempint == 0) {
			isLoop = 0;
			continue;
		}
		headReader = (Reader*)realloc(headReader, sizeof(Reader) * (count + 1));
		headReader[count].stdID = tempint;
RN:		cout << RM_ADD_NAME;
		cin >> tempStr;
		if (tempStr.length() > 30) {
			cout << RM_INLLEGAL_NAME;
			goto RN;
		}
		for (int i = 0; i <= tempStr.length(); i++)
			headReader[count].name[i] = tempStr[i];
		count++;
	}
	readers->head = headReader;
	readers->count = count;
	readers->tail = &(headReader[count - 1]);
	QuickSortForReader(0, count - 1);
}

void PrintReaders() {
	using namespace std;
	unsigned int count = readers->count;
	Reader * readerPtr = readers->head;
	for (unsigned int i = 0; i < count; i++) {
		cout << readerPtr[i].stdID << "\t" << readerPtr[i].name << endl;
	}
	system("Pause");
}

void QuickSortForReader(unsigned int begin, unsigned int end) {
	unsigned int standard = begin, frontP = begin, backP = end;
	Reader * headReader = readers->head;
	if (begin == end)
		return;
	if (begin + 1 == end) {
		if (headReader[begin].stdID > headReader[end].stdID) {
			SwapDataForReader(begin, end);
		}
		return;
	}
	while (frontP < backP) {
		for (; backP > frontP; backP--) {
			if (headReader[standard].stdID > headReader[backP].stdID) {
				break;
			}
		}
		for (; frontP < backP; frontP++) {
			if (headReader[standard].stdID < headReader[frontP].stdID) {
				break;
			}
		}
		SwapDataForReader(frontP, backP);
	}
	SwapDataForReader(frontP, standard);
	QuickSortForReader(begin, frontP);
	if (backP < end)
		QuickSortForReader(backP + 1, end);
}

void SwapDataForReader(unsigned int one, unsigned int two) {
	Reader * headReader = readers->head;
	char tempStr[31];
	unsigned int tempID = headReader[one].stdID;
	headReader[one].stdID = headReader[two].stdID;
	headReader[two].stdID = tempID;
	for (int i = 0; i < 30; i++) {
		if (headReader[one].name[i] != '\0') {
			tempStr[i] = headReader[one].name[i];
		}
		else {
			tempStr[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < 30; i++) {
		if (headReader[two].name[i] != '\0') {
			headReader[one].name[i] = headReader[two].name[i];
		}
		else {
			headReader[one].name[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < 30; i++) {
		if (tempStr[i] != '\0') {
			headReader[two].name[i] = tempStr[i];
		}
		else {
			headReader[two].name[i] = '\0';
			break;
		}
	}
}

void SearchForReader() {
	using namespace std;
	Reader * headReader = readers->head;
	string tempStr;
	unsigned int targetID = 0, result = 0;
	cout << RM_SEARCH_INPUT;
	cin >> tempStr;
	for (unsigned int i = 0; i < tempStr.length(); i++) {
		if (tempStr[i] >= '0' && tempStr[i] <= '9') {
			targetID = targetID * 10 + tempStr[i] - 48;
		}
		else
			break;
	}
	if (readers->count > 0)
		result = SearchReaderByID(targetID);
	if (result) {
		result--;
		cout << RM_SEARCH_SUCCESS << setw(7) << headReader[result].stdID << "\t" << setw(15) << headReader[result].name << endl;
	}
	else
		cout << RM_SEARCH_FAILURE;
	system("Pause");
}

unsigned int SearchReaderByID(unsigned int id) {
	Reader * headReader = readers->head;
	unsigned int target = 0;
	unsigned upBound = readers->count - 1, downBound = 0;
	while (1) {
		if (upBound == downBound) {
			if (headReader[upBound].stdID == id) target = upBound + 1;
			else target = 0;
			break;
		}
		if (upBound == downBound + 1) {
			if (headReader[upBound].stdID == id) target = upBound + 1;
			else if (headReader[downBound].stdID == id) target = downBound + 1;
			else target = 0;
			break;
		}
		target = (upBound - downBound) / 2;
		if (headReader[target].stdID == id) {
			target++;
			break;
		}
		else {
			if (headReader[target].stdID > id) {
				upBound = target;
			}
			else {
				downBound = target + 1;
			}
		}
	}
	return target;
}