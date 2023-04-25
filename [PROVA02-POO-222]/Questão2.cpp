#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
protected:
    string nome;
    int idade;
    string cpf;
public:
    Pessoa(string nome, int idade, string cpf) {
        this->nome = nome;
        this->idade = idade;
        this->cpf = cpf;
    }
};

class Instrutor : public Pessoa { // Definição da classe Instrutor, que herda de Pessoa
private:
    double salario;
public:
    Instrutor(string nome, int idade, string cpf, double salario) : Pessoa(nome, idade, cpf) {
        this->salario = salario;
    }
};

class Aluno : public Pessoa { //classe Aluno herda de pessoa
private:
    double mensalidade;
public:
    Aluno(string nome, int idade, string cpf, double mensalidade) : Pessoa(nome, idade, cpf) {
        this->mensalidade = mensalidade;
    }
};

class Aula {
private:
    string nome;
    string horario;
    int duracao;
    Instrutor* instrutor;
    vector<Aluno*> alunos;
public:
    Aula(string nome, string horario, int duracao, Instrutor* instrutor) {
        this->nome = nome;
        this->horario = horario;
        this->duracao = duracao;
        this->instrutor = instrutor;
    }

    void adicionarAluno(Aluno* aluno) {
        alunos.push_back(aluno);
    }

    void imprimir() {
        cout << "Aula de " << nome << " - Horário: " << horario << ", Duração: " << duracao << "h" << endl;
        cout << "Instrutor: " << instrutor->nome << endl;
        cout << "Alunos:" << endl;
        for (Aluno* aluno : alunos) {
            cout << "- " << aluno->nome << endl;
        }
        cout << endl;
    }
};

class Academia {
private:
    vector<Aula*> aulas;
public:
    Academia() {
        cout << "Academia criada!" << endl;
    }

    ~Academia() {
        for (Aula* aula : aulas) {
            delete aula;
        }
        cout << "Academia destruída!" << endl;
    }

    void adicionarAula(Aula* aula) {
        aulas.push_back(aula);
    }

    void listarAulas() {
        cout << "Aulas na academia:" << endl;
        for (Aula* aula : aulas) {
            aula->imprimir();
        }
    }
};

int main() {
    Instrutor* instrutor1 = new Instrutor("João", 30, "123.456.789-10", 2000.0);
    Instrutor* instrutor2 = new Instrutor("Maria", 25, "987.654.321-00", 2500.0);

    Aluno* aluno1 = new Aluno("Pedro", 20, "111.222.333-44", 200.0);
    Aluno* aluno2 = new Aluno("Ana", 25, "555.666.777-88", 250.0);
    Aluno* aluno3 = new Aluno("Luiz", 30, "999.888.777-66", 180.0);

    Aula* aula1 = new Aula("Pilates", "09:00", 1, instrutor1);
    Aula* aula2 = new Aula("Musculação", "16:00", 2, instrutor2);

aula1->adicionarAluno(aluno1);
aula1->adicionarAluno(aluno2);
aula2->adicionarAluno(aluno3);

Academia* academia = new Academia();
academia->adicionarAula(aula1);
academia->adicionarAula(aula2);
academia->listarAulas();

delete instrutor1;
delete instrutor2;
delete aluno1;
delete aluno2;
delete aluno3;
delete aula1;
delete aula2;
delete academia;

return 0;

}
