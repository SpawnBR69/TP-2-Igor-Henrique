#include <iostream>
#include <windows.h>
#include "funcoesarvore.hpp"

using namespace std;

//Menus feitos em forma de função pra fins de comodidade
void menu()
{
    cout << "___________________________" << endl;
    cout << "|      MENU PRINCIPAL     |" << endl;
    cout << "|1. Cadastrar Funcionário |" << endl;
    cout << "|2. Buscar Funcionário    |" << endl;
    cout << "|3. Remover Funcionário   |" << endl;
    cout << "|4. Imprimir              |" << endl;
    cout << "|5. Sair                  |" << endl;
    cout << "___________________________" << endl;
}

void search()
{
    cout << "___________________________" << endl;
    cout << "|         BUSCA           |" << endl;
    cout << "|1. Busca por CPF         |" << endl;
    cout << "|2. Busca por Nome        |" << endl;
    cout << "___________________________" << endl;
}

void print()
{
    cout << "____________________________" << endl;
    cout << "|         IMPRIMIR         |" << endl;
    cout << "|1. Impressão por CPF      |" << endl;
    cout << "|2. Impressão por nome     |" << endl;
    cout << "____________________________" << endl;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    int choice = 0, size = 0;
    pointer cpfTree = NULL;
    pointer nameTree = NULL;
    element aux;

    //Inicio do laço de repetição que mantém o usuário no menu até o momento desejado
    while (choice != 5)
    {
        choice = 0;

        system("cls");
        menu();

        cout << "\nOpção desejada: ";
        cin >> choice;

        switch (choice)
        {
        //Caso escolha cadastro
        case 1:
            system("cls");
            size++;
            aux.value = size;

            cout << "Digite o nome do funcionário: ";
            cin >> aux.name;
            cout << "Digite o CPF do funcionário: ";
            cin >> aux.cpf;
            cout << "Digite o cargo do funcionário: ";
            cin >> aux.role;
            cout << "Digite o número de telefone do funcionário: ";
            cin >> aux.phonenumber;
            cout << "Digite a rua do funcionário: ";
            cin >> aux.address.street;
            cout << "Digite o número da casa: ";
            cin >> aux.address.number;
            cout << "Digite o logradouro do funcionário: ";
            cin >> aux.address.complement;
            cout << "Digite o bairro do funcionário: ";
            cin >> aux.address.district;
            cout << "Digite a cidade do funcionário: ";
            cin >> aux.address.city;
            cout << "Digite o estado do funcionário: ";
            cin >> aux.address.state;
            cout << "Digite o CEP do funcionário: ";
            cin >> aux.address.cep;
            cout << "Digite o dia de nascimento do funcionário: ";
            cin >> aux.birth_date.day;
            cout << "Digite o mês de nascimento do funcionário: ";
            cin >> aux.birth_date.month;
            cout << "Digite o ano de nascimento do funcionário: ";
            cin >> aux.birth_date.year;
            includeNodeCPF(&cpfTree, aux);
            includeNodeName(&nameTree, aux);
            break;

        //Caso escolha busca
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
                searchCPF(&cpfTree, &aux);
                printElement(aux);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Digite o nome que deseja buscar: " << endl;
                cin >> aux.name;
                searchName(&nameTree, &aux);
                printElement(aux);
                system("pause");
                break;
            default:
                break;
            }
            break;

        //Caso escolha remoção
        case 3:
            system("cls");
            cout << "Digite o CPF que deseja remover: " << endl;
            cin >> aux.cpf;
            cout << "Digite o nome que deseja remover: " << endl;
            cin >> aux.name;
            removeNodeCPF(&cpfTree, aux);
            removeNodeName(&nameTree, aux);
            break;

        //Caso escolha impressão
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
                system("pause");
                break;
            case 2:
                system("cls");
                printTree(&nameTree);
                system("pause");
                break;
            default:
                break;
            }
            break;

        default:
            //Caso decida sair do programa ou tenha feito uma escolha que não estivesse prevista
            //no menu
            char lchoice;
            system("cls");
            cout << "Deseja sair da aplicação (s/n)? " << endl;
            cin >> lchoice;
            if (lchoice == 's')
            {
                choice = 5;
            }
            else
            {
                choice = 0;
            }
            break;
        }
    }
}
