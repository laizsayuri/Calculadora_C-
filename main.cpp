#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value = dec_value + (last_digit * base);

        base = base * 2;
    }

    return dec_value;
}

int decimalToBinary(int n){

    int binary_num[32];
    string binary_string;
    int binary_value;

    int i = 0;
    while (n > 0){
        binary_num[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--){
        binary_string = binary_string + std::to_string(binary_num[j]);
    }

    binary_value = std::stoi(binary_string);
    return binary_value;
}

int main()
{
    int valor;
    setlocale(LC_ALL, "Portuguese");
    do {
        system("clear || cls");
        cout << "** Minha calculadora **" << endl;
        cout << "Escolha uma op��o: " << endl;
        cout << "1- Bin�rio para Decimal" << endl;
        cout << "2- Decimal para Bin�rio" << endl;
        cout << "0- Para sair" << endl;


        cin >> valor;
        system("clear || cls");
        if(valor == 1) {
            int binario;
            cout << "Voc� escolheu Bin�rio para Decimal, digite um n�mero em Bin�rio: ";
            cin >> binario;
            cout << "O n�mero digitado foi: " << binario << endl;
            int decimal = binaryToDecimal(binario);
            cout << "O valor convertido �: " << decimal << endl;
            getch();

        }else if(valor == 2) {
            int decimal;
            cout << "Voc� escolheu Decimal para Bin�rio, digite um n�mero em Decimal: ";
            cin >> decimal;
            cout << "O n�mero digitado foi: " << decimal << endl;
            int binario = decimalToBinary(decimal);
            cout << "O valor convertido �: " << binario << endl;
            getch();

        }else if (valor != 0){
            cout << "Op��o inv�lida!";
            getch();
        }

    }  while( valor != 0);
    cout << "At� breve!" << endl;

    return 0;
}


