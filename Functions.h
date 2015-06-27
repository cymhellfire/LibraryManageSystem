// Include all functions

#ifndef _FUNCTION
#define _FUNCTION

#include"DataStructure.h"

// Initialization
void InitializationLibrary();
void InitializationReaders();

// Book Management
void BookManagementFunction();
void AddBooks();
void PrintLibrary();
void QuickSort(unsigned int begin, unsigned int end);
void SwapData(BookNode * one, BookNode * two);
void SearchForBook();
unsigned int SearchByID(unsigned int id);

// Reader Management
void ReaderManagementFunction();
void AddReader();
void PrintReaders();
void QuickSortForReader(unsigned int begin, unsigned int end);
void SwapDataForReader(unsigned int one, unsigned int two);

// File System
int SaveLibrary();
int LoadLibrary();
int SaveReaders();
int LoadReaders();

// Dispose
BookList * DeleteLibrary(BookList * list);
ReaderList * DeleteReaderList(ReaderList * list);

#endif