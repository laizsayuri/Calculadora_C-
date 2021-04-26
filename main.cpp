#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

int binarioParaDecimal(int binario)
{
    int decimal, potenciaFinal;
    string stringBinario;

    decimal = 0;
    stringBinario = std::to_string(binario);

    potenciaFinal = (stringBinario.length() - 1);

    for (int i = 0; i <= potenciaFinal; i++)
    {
        decimal = decimal + pow(2, i) * (binario % 10);
        binario = binario / 10;
    }

    return decimal;
}

bool validaBinario(int binario)
{
    int indiceFinal;
    string binarioString;
    bool sucesso;

    if (binario > 1111111111 || binario < 0)
    {
        return false;
    }

    binarioString = std::to_string(binario);
    indiceFinal = (binarioString.length() - 1);

    sucesso = true;
    for(int i = 0; i <= indiceFinal; i++)
    {
        if(binarioString[i] != '0' && binarioString[i] != '1')
        {
            sucesso = false;
            break;
        }
    }

    return sucesso;
}

void binarioParaDecimalMenu()
{
    int binario;
    int decimal;
    bool valido;

    system("clear || cls");
    cout << "Você escolheu Binário para Decimal.\nDigite um valor em Binário menor ou igual a 11 1111 1111: ";
    cin >> binario;

    valido = validaBinario(binario);

    if(valido){
        decimal = binarioParaDecimal(binario);
        cout << "O valor convertido é: " << decimal << endl;
    }
    else{
        cout << "\nValor não válido!\nDigite um valor Binário com um valor menor ou igual a 11 1111 1111" << endl;
    }

    getch();
}

int decimalParaBinario(int decimal)
{
    int tamanhoVetor, ultimaPosicao, contador, primeiraPosicao;
    int binarios[8];
    string binarioString;

    tamanhoVetor = 8;
    ultimaPosicao = tamanhoVetor - 1;
    contador = 0;

    for (int i = ultimaPosicao; i >= 0; i--)
    {
        binarios[i] = decimal % 2;
        decimal = decimal / 2;
        contador++;

        if (decimal == 0){
            break;
        }
    }

    primeiraPosicao = tamanhoVetor - contador;
    for (int i = primeiraPosicao; i < tamanhoVetor; i++)
    {
        binarioString = binarioString + std::to_string(binarios[i]);
    }

    return std::stoi(binarioString);
}

bool validaDecimal(int decimal)
{
    return decimal >= 0 && decimal <= 255;
}

void decimalParaBinarioMenu()
{
    int decimal;
    int binario;
    bool valido;

    system("clear || cls");
    cout << "Você escolheu Decimal para Binário.\nDigite um valor em Decimal positivo menor ou igual a 255: ";
    cin >> decimal;

    valido = validaDecimal(decimal);

    if(valido){
        binario = decimalParaBinario(decimal);
        cout << "O valor convertido é: " << binario << endl;
    }
    else{
        cout << "\nValor não válido!\nDigite um valor Decimal positivo menor ou igual a 255" << endl;
    }

    getch();
}

int main()
{
    int operador;
    bool executando = true;

    setlocale(LC_ALL, "Portuguese");

    while(executando){
        system("clear || cls");
        cout << "** Minha calculadora **" << endl;
        cout << "Escolha uma opção: " << endl;
        cout << "1 - Binário para Decimal" << endl;
        cout << "2 - Decimal para Binário" << endl;
        cout << "0 - Para sair\n" << endl;

        cin >> operador;

        switch(operador){
            case 1:
                binarioParaDecimalMenu();
                break;
            case 2:
                decimalParaBinarioMenu();
                break;
            case 0:
                executando = false;
                break;
            default:
                cout << "\nOpção inválida! Tente novamente";
                getch();
                break;
        }
    }

    return 0;
}
