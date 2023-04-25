#include <iostream>
#include <vector> 

using namespace std;

class Conta {
protected:
    int numero;
    double saldo;
    string titular;

public:
    Conta(int num, double s, string t) { // define o construtor da classe
        numero = num;
        saldo = s;
        titular = t;
    }

    void depositar(double valor) { // define o método para depositar na conta
        saldo += valor; // soma o valor ao saldo da conta
    }

    virtual bool sacar(double valor) { // define o método para sacar da conta
        if (saldo >= valor) { // verifica se tem saldo suficiente
            saldo -= valor; //// subtrai o valor do saldo da conta
            return true;
        }
        else {
            return false;
        }
    }

    void imprimir() { // define o método para imprimir informações da conta
        cout << "Número: " << numero << endl;
        cout << "Titular: " << titular << endl;
        cout << "Saldo: " << saldo << endl;
    }
};

class ContaCorrente : public Conta { //classe ContaCorrente herdando da classe Conta
private:
    double limite;

public:
    ContaCorrente(int num, double s, string t, double l) : Conta(num, s, t) { // construtor da classe
        limite = l;
    }

    bool sacar(double valor) override { // sobescreve o metodo sacar da classe Conta
        if (saldo + limite >= valor) { // verifica se o saldo é suficiente
            saldo -= valor; // subtrai o valor do saldo da conta
            cout << "Saque realizado" << endl;
            return true;
        }
        else {
            cout << "Saldo insuficiente" << endl;
            return false;
        }
    }
};

class ContaPoupanca : public Conta {
private:
    double rendimento;

public:
    ContaPoupanca(int num, double s, string t, double r) : Conta(num, s, t) { // Define a classe ContaPoupanca herdando da classe Conta
        rendimento = r;
    }

    void atualizarRendimento() {
        saldo += saldo * rendimento;
    }
};

class Banco {
private:
    vector<Conta*> contas;

public:
    Banco() {
        contas.clear();
    }

    ~Banco() {
        for (auto& conta : contas) {
            delete conta;
        }
    }

    void adicionarConta(Conta* conta) {
        contas.push_back(conta);
    }

    void listarContas() {
        for (auto& conta : contas) {
            conta->imprimir();
            cout << endl;
        }
    }
};

int main() {
    Banco banco;

    ContaCorrente* cc = new ContaCorrente(123, 1000.0, "Renan", 500.0);
    ContaPoupanca* cp = new ContaPoupanca(456, 2000.0, "Nicole", 0.01);

    banco.adicionarConta(cc);
    banco.adicionarConta(cp);

    cout << "Antes das operações:" << endl;
    banco.listarContas();

    cc->depositar(200.0);
    cc->sacar(300.0);
    cp->depositar(500.0);
    cp->sacar(2500.0);

    cout << "Depois das operações:" << endl;
    banco.listarContas();

    delete cc;
    delete cp;

    return 0;
}