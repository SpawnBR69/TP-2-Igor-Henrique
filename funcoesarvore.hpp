#ifndef FUNCOES_H
#define FUNCOES_H

#include "funcoesarvore.cpp"

typedef struct date;
typedef struct address;
typedef struct element;
typedef struct node * pointer;
typedef struct node;
void includeNodeName(pointer *n, element value);
void includeNodeCPF(pointer *n, element value);
void predecessor(pointer q, pointer *n);
void removeNodeName(pointer *n, element value);
void removeNodeCPF(pointer *n, element value);
void searchName(pointer *n, element *v);
void searchCPF(pointer *n, element *v);

#endif