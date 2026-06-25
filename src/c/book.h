#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char titulo[64];
    char autor[64];
    char isbn[20];
    int ano;
    int quantidade;
} book;

#endif
