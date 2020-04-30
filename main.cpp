#include <iostream>
#include <fstream>
#include "Bancos.h"
#include "Cuentas.h"

using namespace std;

void menu(){

    cout<<"************** BANK MENU **************\n";
    cout<<"Digite el número con la opción deseada\n";
    cout<<"1. Crear una cuenta\n";
    cout<<"2. Mostrar TODAS las cuentas\n";
    cout<<"3. Buscar una cuenta\n";
    cout<<"4. Realizar un movimiento\n";
    cout<<"5. Editar una cuenta\n";
    cout<<"6. Salir del sistema\n";
}

int main(){

Banco banco;
banco.ejemploCuentaA();
banco.ejemploCuentaC();
 
int opcion = 0, acc_num = 0, select = 0;
double add_balance = 0, withdraw = 0, deposit = 0;
string add_nombre, add_lastn;

while(opcion < 6 && opcion > -1){

    menu();

    cin >> opcion;

    switch(opcion){

        case 1:
            cout << "Para crear una cuenta de Cheques digite 1\n";
            cout << "Para crear una cuenta de Ahorro digite 2\n";
            cin >> select;
            cout << "Ingresar el nombre del Cliente\n";
            cin >> add_nombre;
            cout << "Ingresar el apellido del cliente\n";
            cin >> add_lastn;
            cout << "Ingresar el balance inicial\n";
            cin >> add_balance;
            if(select == 1){
                banco.agregaCuentaCheque(add_nombre,add_lastn,add_balance);
            }
            else{
                banco.agregaCuentaAhorro(add_nombre,add_lastn,add_balance);
            }

        break;

        case 2:
            banco.muestraCuentas();
        break;

        case 3:
            cout << "Ingrese el numero de cuenta\n";
            cin >> acc_num;
            banco.buscaCuenta(acc_num);
        break;
        
        case 4:
            cout << "Ingresar el número de cuenta\n";
            cin >> acc_num;
            cout << "Para realizar un retiro digite 1\n";
            cout << "Para realizar un deposito digite 2\n";
            cin >> select;
            if(select == 1){
                cout << "Ingresar la cantidad a retirar\n";
                cin >> withdraw;
                banco.retirarDinero(acc_num, withdraw);
            }
            else if (select == 2){
                cout << "Ingresar la cantidad a depositar\n";
                cin >> deposit;
                banco.depositarDinero(acc_num, deposit);
            }
            else{
                cout << "Opcion inválida.\n";
            }
        break;

        case 5:
            cout << "Ingresar el número de cuenta\n";
            cin >> acc_num;
            cout << "Ingresar el nuevo nombre\n";
            cin >> add_nombre;
            cout << "Ingresar el nuevo Apellido\n";
            cin >> add_lastn;
            cout << "Ingresa el nuevo balance\n";
            cin >> add_balance;
            banco.editarCuenta(acc_num,add_nombre, add_lastn,add_balance);
            banco.buscaCuenta(acc_num);
        break;

    }
}
}  

