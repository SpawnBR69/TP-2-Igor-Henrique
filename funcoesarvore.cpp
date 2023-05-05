#include <iostream>
 
using namespace std;

typedef struct date{
    int day,month,year;
}data;

typedef struct address{
    string district,city,state,cep,complement,street;
    int number;
}endereco;

typedef struct element{
    int value;
    string cpf,name,role,phonenumber;
    date birth_date;
    address address;
}element;

typedef struct node * pointer;
typedef struct node{
    element value;
    pointer left;
    pointer right;
}node;

void includeNodeName(pointer *n, element value){
    if(*n == NULL){
        *n = new node;
        (*n)->value = value;
        (*n)->left = NULL;
        (*n)->right = NULL;
        return;
    }
    if((*n)->value.name > value.name){
        includeNodeName(&(*n)->left,value);
        return;
    }if((*n)->value.name < value.name){
        includeNodeName(&(*n)->right,value);
        return;
    }else{
        cout << "REGISTRO JÁ CADASTRADO NA ARVORE";
        return;
    }
}

void includeNodeCPF(pointer *n, element value){
    if(*n == NULL){
        *n = new node;
        (*n)->value = value;
        (*n)->left = NULL;
        (*n)->right = NULL;
        return;
    }
    if((*n)->value.cpf > value.cpf){
        includeNodeCPF(&(*n)->left,value);
        return;
    }if((*n)->value.cpf < value.cpf){
        includeNodeCPF(&(*n)->right,value);
        return;
    }else{
        cout << "REGISTRO JÁ CADASTRADO NA ARVORE";
        return;
    }
}

void predecessor(pointer q, pointer *n){
    if((*n)->right != NULL){
        predecessor(q,&(*n)->right);
        return;
    }
    q = new node;
    q->value = (*n)->value;
    q = *n;
    *n = (*n)->left;
    delete q;
}

void removeNodeName(pointer *n, element value){
    pointer aux = new node;
    if(*n == NULL){
        cout << "REGISTRO INEXISTENTE";
        return;
    }
    if((*n)->value.name > value.name){
        removeNodeName(&(*n)->left,value);
        return;
    }if((*n)->value.name < value.name){
        removeNodeName(&(*n)->right,value);
        return;
    }if((*n)->right != NULL){
        aux = *n;
        *n = (*n)->left;
        delete aux;
        return;
    }if((*n)->left != NULL){
        predecessor(*n,&(*n)->left);
        return;
    }
    aux = *n;
    *n = (*n)->right;
    delete aux;
}

void removeNodeCPF(pointer *n, element value){
    pointer aux = new node;
    if(*n == NULL){
        cout << "REGISTRO INEXISTENTE";
        return;
    }
    if((*n)->value.cpf > value.cpf){
        removeNodeCPF(&(*n)->left,value);
        return;
    }if((*n)->value.cpf < value.cpf){
        removeNodeCPF(&(*n)->right,value);
        return;
    }if((*n)->right != NULL){
        aux = *n;
        *n = (*n)->left;
        delete aux;
        return;
    }if((*n)->left != NULL){
        predecessor(*n,&(*n)->left);
        return;
    }
    aux = *n;
    *n = (*n)->right;
    delete aux;
}

void searchName(pointer *n, element *v){
    if(*n == NULL){
        cout << "REGISTRO INEXISTENTE";
        return;
    }
    if(v->name < (*n)->value.name){
        searchName(&(*n)->left,v);
        return;
    }if(v->name > (*n)->value.name){
        searchName(&(*n)->right,v);
    }else{
        *v = (*n)->value;
    }
}

void searchCPF(pointer *n, element *v){
    if(*n == NULL){
        cout << "REGISTRO INEXISTENTE";
        return;
    }
    if(v->cpf < (*n)->value.cpf){
        searchCPF(&(*n)->left,v);
        return;
    }if(v->cpf > (*n)->value.cpf){
        searchCPF(&(*n)->right,v);
    }else{
        *v = (*n)->value;
    }
}

void printTree(pointer *n){
    if((*n) != NULL){
        printTree(&(*n)->left);
        cout << "Nome: " << (*n)->value.name;
        cout << "CPF: " << (*n)->value.cpf;
        cout << "Cargo: " << (*n)->value.role;
        cout << "Número de Telefone: " << (*n)->value.phonenumber;
        printTree(&(*n)->right);
    }
}