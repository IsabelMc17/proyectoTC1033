#ifndef BANCO_H_H
#define BANCO_H_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Cuentas.h"

class Banco{
    
    private:
        CuentaCheques cheq[1000];
        CuentaAhorro ahorro[1000];
        int idAhorro, idCheques;
        double balanceC[1000];
        double balanceA[1000];
    public:

        Banco();
        void muestraCuentas();
        void agregaCuentaAhorro(string cliente, string lastn, double cant);
        void agregaCuentaCheque(string cliente, string lastn, double cant);
        void buscaCuenta(int num);
        void editarCuenta(int num, string cliente, string lastn, double cant); 
        void ejemploCuentaA();
        void ejemploCuentaC();
        void retirarDinero(int num,double cant);
        void depositarDinero(int num, double cant);

};

Banco::Banco(){
    idCheques = 0;
    idAhorro = 0;
}

void Banco::ejemploCuentaA(){
    ahorro[0] = CuentaAhorro(idAhorro + 100, "Isabel", "Moreno", 2500);
    balanceA[0] = ahorro[idAhorro].balanceCuenta();
    idAhorro+=1;
    ahorro[1] = CuentaAhorro(idAhorro + 100, "Fermin", "Moreno", 3000);
    balanceA[1] = ahorro[idAhorro].balanceCuenta();
}

void Banco::ejemploCuentaC(){
    cheq[0] = CuentaCheques(idCheques, "Carla", "Serrano",1000);
    balanceC[0] = cheq[idCheques].balanceCuenta();
    idCheques+=1;
    cheq[1] = CuentaCheques(idCheques, "Antonio", "Sanchez",2500);
    balanceC[1] = cheq[idCheques].balanceCuenta();
}

void Banco::muestraCuentas(){
    for (int i = 0; i<=idCheques; i++){
        cout << "\nCuenta de cheques\n";
        cout << "__________________________________\n"; 
        cout << cheq[i].toString()<<"\n";
        cout << "Balance\n" << balanceC[i]<<"\n";
    }
    for(int j = 0; j <= idAhorro; j++){
        
        cout << "\nCuenta de ahorro\n"; 
        cout << "__________________________________\n";
        cout << ahorro[j].toString()<<"\n";
        cout << "Balance\n" << balanceA[j]<<"\n";        
    }
}

void Banco::agregaCuentaCheque(string cliente, string lastn, double cant){
    idCheques +=1;
    CuentaCheques aux(idCheques, cliente, lastn,cant);
    cheq[idCheques] = aux;
    balanceC[idCheques] = cant;

}

void Banco::agregaCuentaAhorro(string cliente, string lastn, double cant){
    idAhorro +=1;
    CuentaAhorro aux(idAhorro + 100, cliente, lastn,cant);
    ahorro[idAhorro] = aux;
    balanceA[idAhorro] = cant;
}

void Banco::buscaCuenta(int num){
    int k = 0;
    for(int i = 0; i <= idCheques;i++){
        if(num == i){
            cout<< "\nCuenta de Cheques\n" <<"__________________________________\n"<< cheq[i].toString()<<"\n";
            cout << balanceC[i]<< endl;
            k = num;
            break;
        } 
    }
    for(int j = 0; j <= idAhorro; j++){
        if((num - 100) == j){
            cout << "\nCuenta de Ahorro\n" <<"__________________________________\n" << ahorro[j].toString() << "\n";
            cout << balanceA[j];
            k = num;
            break;
        }
    }
    if(k != num){
    cout << "El numero de cuenta no existe. Intente de nuevo\n";  
    }
}
void Banco::retirarDinero(int num, double cant){
    int k = 0;
    for(int i = 0; i <= idCheques;i++){
        if(num == i){
            if(cheq[num].balanceCuenta() > cant){
                balanceC[num] = cheq[i].balanceCuenta() - cant;
            }
            else{
                cout << "Fondos insuficientes.\n";
            }
            k = num;
            break;
        } 
    }
    for(int j = 0; j <= idAhorro; j++){
        if((num - 100) == j){
            if(ahorro[j].balanceCuenta() > cant){
                balanceA[j] = ahorro[j].balanceCuenta() - cant;
            }
            else{
                cout << "Fondos insuficientes.\n";
            }
            k = num;
            break;
        }
    }
    if(k != num){
    cout << "ERROR. La transacción no se pudo completar porque el número de cuenta no existe. Intente de nuevo.\n";  
    }
}


void Banco::depositarDinero(int num, double cant){
    int k = 0;
    for(int i = 0; i <= idCheques;i++){
        if(num==i){
            balanceC[num] = cheq[num].balanceCuenta() + cant;
            k = num;
            break;
        }
    }
    for(int j = 0; j <= idAhorro; j++){
        if(num-100 == j){
            balanceA[j] = ahorro[j].balanceCuenta() + cant;
            k = num;
            break;
        }
    }
    if (k != num){
        cout << "ERROR. La transacción no se pudo completar porque el número de cuenta no existe. Intente de nuevo.\n";        
    }
}

void Banco::editarCuenta(int num, string cliente, string lastn, double cant){
    int k = 0;
    for (int i = 0; i <= idCheques; i++){
        if(num==i){
            CuentaCheques aux(i, cliente, lastn, cant);
            cheq[i] = aux;
            balanceC[i] = cant;
            k = num;
            break;
        }
    }
    for(int j = 0; j <= idAhorro; j++){
        if(num-100 == j){
            CuentaAhorro aux(j + 100, cliente,lastn, cant);
            ahorro[j] = aux;
            balanceA[j] = cant;
            k = num;
            break;
        }
    }
    if (k != num){
        cout << "ERROR. La información no se pudo editar porque el número de cuenta no existe. Intente de nuevo.\n";        
    }
}   

#endif