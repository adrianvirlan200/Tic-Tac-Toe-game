using namespace std;
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

char tabla[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

void mutare0()
{

    int sw = -1;
    char caract[2] = {'0', 'X'};
    for (int k = 0; k < 2 && sw == -1; k++)
    {

        for (int i = 0; i < 3 && sw == -1; i++) // pentru coloane
        {
            if (tabla[i] == caract[k] && tabla[i + 3] == tabla[i] && sw == -1 && tabla[i + 6] == '-')
            {
                tabla[i + 6] = '0';
                sw++;
            }
            if (tabla[i] == caract[k] && tabla[i + 6] == tabla[i] && sw == -1 && tabla[i + 3] == '-')
            {
                tabla[i + 3] = '0';
                sw++;
            }
            if (tabla[i + 3] == caract[k] && tabla[i + 6] == tabla[i] && sw == -1 && tabla[i] == '-')
            {
                tabla[i] = '0';
                sw++;
            }
        }

        int i = 0;
        while (i < 7) // pentru linii
        {
            if (tabla[i] == caract[k] && tabla[i + 1] == tabla[i] && sw == -1 && tabla[i + 2] == '-')
            {
                tabla[i + 2] = '0';
                sw++;
            }
            if (tabla[i] == caract[k] && tabla[i + 2] == tabla[i] && sw == -1 && tabla[i + 1] == '-')
            {
                tabla[i + 1] = '0';
                sw++;
            }
            if (tabla[i + 1] == caract[k] && tabla[i + 2] == tabla[i] && sw == -1 && tabla[i] == '-')
            {
                tabla[i] = '0';
                sw++;
            }

            i += 3;
        }

        // diag pr
        i = 0;
        if (tabla[i] == caract[k] && tabla[i + 4] == tabla[i] && sw == -1 && tabla[i + 8] == '-')
        {
            tabla[i + 8] = '0';
            sw++;
        }
        if (tabla[i] == caract[k] && tabla[i + 8] == tabla[i] && sw == -1 && tabla[i + 4] == '-')
        {
            tabla[i + 4] = '0';
            sw++;
        }
        if (tabla[i + 4] == caract[k] && tabla[i + 8] == tabla[i] && sw == -1 && tabla[i ] == '-')
        {
            tabla[i] = '0';
            sw++;
        }

        // diag sec
        i = 0;
        if (tabla[i + 2] == caract[k] && tabla[i + 4] == tabla[i] && sw == -1 && tabla[i + 6] == '-')
        {
            tabla[i + 6] = '0';
            sw++;
        }
        if (tabla[i + 2] == caract[k] && tabla[i + 6] == tabla[i] && sw == -1 && tabla[i + 4] == '-')
        {
            tabla[i + 4] = '0';
            sw++;
        }
        if (tabla[i + 4] == caract[k] && tabla[i + 6] == tabla[i] && sw == -1 && tabla[i + 8] == '-')
        {
            tabla[i + 8] = '0';
            sw++;
        }
    }
    // daca tot nu s-a alocat
    while (sw == -1)
    {
        sw = rand() % 9;
        if (tabla[sw] == '-')
        {
            tabla[sw] = '0';
            cout << "Arduino a ales pozitia: " << sw + 1 << endl;
            break;
        }
        else
            sw = -1;
    }
}

void mutareX()
{
    bool valid = false;
    int m0 = 0;
    while (!valid)
    {
        cout << "Alege o pozitie de la 1 la 9." << endl;
        do
        {
            cin >> m0;

            cout << "Ati ales pozitia: " << m0 << endl;
            if (tabla[m0 - 1] != '-')
                cout << "Pozitie eronata!" << endl;
            else
            {
                tabla[m0 - 1] = 'X';
                valid = true;
            }
        } while (m0 < 1 || m0 > 9);
    }
}

void afisare()
{
    for (int i = 0; i < 9; i++)
    {
        cout << tabla[i];
        cout << " ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

bool victorie()
{
    char winner = '-';
    if (winner == '-' && tabla[0] == tabla[1] && tabla[1] == tabla[2])
        winner = tabla[0]; // linie 1
    if (winner == '-' && tabla[3] == tabla[4] && tabla[4] == tabla[5])
        winner = tabla[3]; // linie 2
    if (winner == '-' && tabla[6] == tabla[7] && tabla[7] == tabla[8])
        winner = tabla[6]; // linie 3
    if (winner == '-' && tabla[0] == tabla[3] && tabla[3] == tabla[6])
        winner = tabla[0]; // coloana 1

    if (winner == '-' && tabla[1] == tabla[4] && tabla[4] == tabla[7])
        winner = tabla[1]; // coloana 2
    if (winner == '-' && tabla[2] == tabla[5] && tabla[5] == tabla[8])
        winner = tabla[2]; // coloana 3
    if (winner == '-' && tabla[0] == tabla[4] && tabla[4] == tabla[8])
        winner = tabla[0]; // diagonala principala
    if (winner == '-' && tabla[2] == tabla[4] && tabla[4] == tabla[6])
        winner = tabla[2]; // diagonala secundara
    if (winner == '-')
    {
        winner = '*';
        for (int i = 0; i < 9; i++)
            if (tabla[i] == '-')
                winner = '-';
    }
    if (winner == '-')
        return false;
    else
    {
        if (winner == 'X')
        {
            afisare();
            cout << "Ati castigat! Felicitari!" << endl;
        }
        if (winner == '0')
            cout << "Arduino a castigat! Mai incercati!" << endl;
        if (winner == '*')
            cout << "Remiza! Plictisitor!" << endl;
        return true;
    }
}

int main()
{
    srand(time(0));
    cout << "Salut!" << endl;
    cout << "Tu vei muta primul - esti cu X." << endl;
    cout << "Tabla de joc are pozitiile numerotate de la 1 la 9." << endl;
    cout << ("1 2 3") << endl;
    cout << ("4 5 6") << endl;
    cout << ("7 8 9") << endl;
    while (1)
    {
        do
        {
            mutareX();
            if (victorie())
                break;
            mutare0();
            afisare();
        } while (!victorie());

        sleep(3);
        for (int i = 0; i < 100; i++)
            cout << endl;
        for (int i = 0; i < 9; i++)
            tabla[i] = '-';
    }
}
