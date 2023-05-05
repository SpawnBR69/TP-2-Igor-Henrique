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

void remove(){
    cout << "___________________________" << endl;
    cout << "|         REMOÇÃO         |" << endl;
    cout << "|1. Remoção por CPF       |" << endl;
    cout << "|2. Remoção por nome      |" << endl;
    cout << "___________________________" << endl;
}
 
int main() {
    int choice,size = 0;
    pointer cpfTree = NULL;
    pointer nameTree = NULL;
    element aux;
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
        int schoice;
        search();
        cin >> schoice;
        switch (schoice)
        {
        case 1:
            
            break;
        case 2:

            break;
        default:
            break;
        }
        break;
    case 3:
        int rchoice;
        remove();
        cin >> rchoice;
        switch (rchoice)
        {
        case 1:
        
            break;
        case 2:

            break;
        default:
            break;
        }
        break;
    case 4:

        break;
    default:
        break;
    }
}