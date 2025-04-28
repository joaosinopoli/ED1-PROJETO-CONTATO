#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct data {
    int dia;
    int mes;
    int ano;	
};

struct contato {
    string nome;
    string email;
    string telefone;
    data dtnasc;
};

int calcularIdade(data nascimento) {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int anoAtual = now->tm_year + 1900;
    return anoAtual - nascimento.ano;
}

int main() {
    contato contatos[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nCadastro do Contato " << (i + 1) << endl;

        cout << "Nome: ";
        getline(cin, contatos[i].nome);

        cout << "Email: ";
        getline(cin, contatos[i].email);

        cout << "Telefone: ";
        getline(cin, contatos[i].telefone);

        cout << "Dia de nascimento: ";
        cin >> contatos[i].dtnasc.dia;

        cout << "Mês de nascimento: ";
        cin >> contatos[i].dtnasc.mes;

        cout << "Ano de nascimento: ";
        cin >> contatos[i].dtnasc.ano;
        cin.ignore(); // limpa o \n do buffer
    }

    cout << "\n--- Lista de Contatos ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nome: " << contatos[i].nome << endl;
        cout << "Email: " << contatos[i].email << endl;
        cout << "Telefone: " << contatos[i].telefone << endl;
        cout << "Idade: " << calcularIdade(contatos[i].dtnasc) << " anos" << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}
