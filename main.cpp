#include <iostream>
#include <windows.h>
#include "funcoesarvore.hpp"
 
using namespace std;

void menu(){
    cout << "___________________________" << endl;
    cout << "|      MENU PRINCIPAL     |" << endl;
    cout << "|1. Cadastrar Funcionário |" << endl;
    cout << "|2. Buscar Funcionário    |" << endl;
    cout << "|3. Remover Funcionário   |" << endl;
    cout << "|4. Imprimir              |" << endl;
    cout << "|5. Sair                  |" << endl;
    cout << "___________________________" << endl;
}

void search(){
    cout << "___________________________" << endl;
    cout << "|         BUSCA           |" << endl;
    cout << "|1. Busca por CPF         |" << endl;
    cout << "|2. Busca por Nome        |" << endl;
    cout << "___________________________" << endl;
}

void print(){
    cout << "____________________________" << endl;
    cout << "|         IMPRIMIR         |" << endl;
    cout << "|1. Impressão por CPF      |" << endl;
    cout << "|2. Impressão por nome     |" << endl;
    cout << "____________________________" << endl;
}
 
int main() {
    int choice = 0,size = 0;
    pointer cpfTree = NULL;
    pointer nameTree = NULL;
    element aux;
    while (choice != 5){
        system("cls");
        menu();
        cout << "Digite o que deseja fazer: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            size++;
            aux.value = size;
            cout << "Digite o nome do Funcionário: ";
            cin >> aux.name;
            cout << "Digite o CPF do Funcionário: ";
            cin >> aux.cpf;
            cout << "Digite o cargo do Funcionário: ";
            cin >> aux.role;
            cout << "Digite o número de telefone do Funcionário: ";
            cin >> aux.phonenumber;
            cout << "Digite a Rua do Funcionário: ";
            cin >> aux.address.street;
            cout << "Digite o número do Funcionário: ";
            cin >> aux.address.number;
            cout << "Digite o logradouro do Funcionário: ";
            cin >> aux.address.complement;
            cout << "Digite o bairro do Funcionário: ";
            cin >> aux.address.district;
            cout << "Digite a cidade do Funcionário: ";
            cin >> aux.address.city;
            cout << "Digite o estado do Funcionário: ";
            cin >> aux.address.state;
            cout << "Digite o CEP do Funcionário: ";
            cin >> aux.address.cep;
            cout << "Digite o dia de nascimento do funcionário: ";
            cin >> aux.birth_date.day;
            cout << "Digite o mês de nascimento do funcionário: ";
            cin >> aux.birth_date.month;
            cout << "Digite o ano de naxcimento do funcionário: ";
            cin >> aux.birth_date.year;
            includeNodeCPF(&cpfTree,aux);
            includeNodeName(&nameTree,aux);
            break;
        case 2:
            system("cls");
            int schoice;
            search();
            cin >> schoice;
            switch (schoice)
            {
            case 1:
                system("cls");
                cout << "Digite o cpf que deseja buscar: " << endl;
                cin >> aux.cpf;
                searchCPF(&cpfTree,&aux);
                printElement(aux);
                break;
            case 2:
                system("cls");
                cout << "Digite o nome que deseja buscar: " << endl;
                cin >> aux.name;
                searchName(&nameTree,&aux);
                printElement(aux);
                break;
            default:
                break;
            }
            break;
        case 3:
            system("cls");
            cout << "Digite o CPF que deseja remover: " << endl;
            cin >> aux.cpf;
            cout << "Digite o nome que deseja remover: " << endl;
            cin >> aux.name;
            removeNodeCPF(&cpfTree,aux);
            removeNodeName(&nameTree,aux);
            break;
        case 4:
            system("cls");
            int pchoice;
            print();
            cout << "Digite sua escolha: " << endl;
            cin >> pchoice;
            switch (pchoice)
            {
            case 1:
                system("cls");
                printTree(&cpfTree);
                break;
            case 2:
                system("cls");
                printTree(&nameTree);
                break;
            default:
                break;
            }
            break;
        default:
            char lchoice;
            cout << "Deseja sair da aplicação(s/n)? " << endl;
            cin >> lchoice;
            if(lchoice == 's'){
                choice = 5;
            }else{
                choice = 0;
            }
            break;
        }
    }
}