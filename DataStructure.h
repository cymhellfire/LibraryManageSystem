// This file includes all custom data structures

#ifndef _DATA_DEFINE
#define _DATA_DEFINE

typedef struct book {
	unsigned int id;
	char name[31];
	char author[21];
	char press[21];
	struct borrowerList * borrowers;
}Book;

typedef struct bookNode {
	struct book * book;
}BookNode;

typedef struct bookList{
	struct bookNode * head, * tail;
	unsigned int count;
}BookList;

typedef struct reader{
	unsigned int stdID;
	char name[31];
}Reader;

typedef struct readerList {
	struct reader * head, *tail;
	unsigned int count;
}ReaderList;

typedef struct borrowerList{
	struct borrowNode * head;
	int count;
}BorrowerList;

typedef struct borrowNode {
	struct reader * borrower;
	struct borrowNode * next;
}BorrowNode;

#endif