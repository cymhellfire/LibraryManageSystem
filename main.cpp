// This is main program function

#include<iostream>
#include<stdlib.h>
#include"Message.h"
#include"DataStructure.h"
#include"Functions.h"

BookList * library = NULL;
ReaderList * readers = NULL;

int main() {
	using namespace std;
	int inputOrder, isLoop = 1;

	// Initialization
	InitializationLibrary();
	InitializationReaders();

	cout << WELCOME;

	while (isLoop) {
		cout << HELP << ACQUIRE_ORDER;
		cin >> inputOrder;
		switch (inputOrder)
		{
		case 0:
			isLoop = 0;
			break;
		case 1:
			BookManagementFunction();
			break;
		case 2:
			ReaderManagementFunction();
			break;
		case 3:
			break;
		default:
			break;
		}
		if (isLoop) system("cls");
		if (isLoop) cout << SYSTEM_NAME;
	}
	if (library != NULL)
		library = DeleteLibrary(library);
	if (readers != NULL)
		readers = DeleteReaderList(readers);
	system("Pause");
	return 0;
}