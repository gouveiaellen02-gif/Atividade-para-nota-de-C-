#include <iostream>
using namespace std;

class Calendario {
public:
    int ano, mes, dia;

    Calendario(int ano, int mes, int dia) {
        this->ano = ano;
        this->mes = mes;
        this->dia = dia;
    }


    bool AnoBissexto(int ano) {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }

   
    int DiaDaSemana(int d, int m, int a) {
        if (m < 3) {
            m += 12;
            a -= 1;
        }
        int k = a % 100;
        int j = a / 100;
        int f = d + 13*(m + 1)/5 + k + k/4 + j/4 + 5*j;
        f = f % 7;
    
        return (f + 6) % 7 + 1; 
    }

    void ImprimirCalendario(int mes, int ano) {
        cout << "\n\tCalendário de " << mes << "/" << ano << "\n\n";
        cout << "DOM\tSEG\tTER\tQUA\tQUI\tSEX\tSAB\n";

        short TamanhoDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (AnoBissexto(ano))
            TamanhoDoMes[1] = 29;

        int primeiroDia = DiaDaSemana(1, mes, ano);

       
        for (int i = 1; i < primeiroDia; i++)
            cout << "\t";

        
        for (int d = 1; d <= TamanhoDoMes[mes - 1]; d++) {
            if (d < 10)
                cout << "0" << d << "\t";
            else
                cout << d << "\t";

            if (DiaDaSemana(d, mes, ano) == 7)
                cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    int ano, mes;
    cout << "Ano: ";
    cin >> ano;
    cout << "Mês (1-12): ";
    cin >> mes;

    Calendario cal(ano, mes, 1);
    cal.ImprimirCalendario(mes, ano);

    return 0;
}
