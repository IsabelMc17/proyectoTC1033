#ifndef CUENTA_H_
#define CUENTA_H_
#include<string>
#include <sstream>

using namespace std;

class Cuenta{
protected:
    int numcuenta;
    string cliente;
    string apellido;

public:
    Cuenta();
    Cuenta (int numcuenta,string cliente, string apellido);

    int getnumCuenta() const;
    string getCliente() const;
    string getApellido() const;
    virtual double balanceCuenta()= 0;
    string toString()const;
};

Cuenta::Cuenta(){
    numcuenta=0;
    cliente = "";
}

Cuenta::Cuenta(int nacc, string clte, string ln){
    numcuenta = nacc;
    cliente = clte;
    apellido = ln;
}

string Cuenta::getCliente()const{
    return cliente;
}

string Cuenta::getApellido()const{
    return apellido;
}

int Cuenta::getnumCuenta()const{
    return numcuenta;
}

string Cuenta::toString()const{
    stringstream aux;
    aux << "Numero de cuenta: " << numcuenta << "\nNombre Cliente: " << cliente << "\nApellido Cliente:" << apellido;
    return aux.str();
}


class CuentaCheques: public Cuenta{
    private:
        double balance, retiro;
        int opcion;
    public:

        CuentaCheques();
        CuentaCheques(int numcuenta,string cliente, string apellido, double balance);
        int getnumCuenta() const;
        string getCliente() const;
        double balanceCuenta();
        double balanceRetiro();
        string toString();     
};

CuentaCheques::CuentaCheques(){
    numcuenta = 0;
    cliente = "";
}

CuentaCheques::CuentaCheques(int nacc, string clte, string ln, double bal){
    numcuenta = nacc;
    cliente = clte;
    apellido = ln;
    balance = bal;
}

/*
int CuentaCheques::getnumCuenta()const{
    return numcuenta;
}

string CuentaCheques::getCliente()const{
    return cliente;
}
*/

double CuentaCheques::balanceCuenta(){
    return balance;
}

string CuentaCheques::toString(){
    stringstream aux;
    aux << "Numero de cuenta: " << numcuenta << "\nNombre Cliente: " << cliente << "\nApellido Cliente:" << apellido;
    return aux.str();
}
class CuentaAhorro: public Cuenta{
    private:
        double balance;
    public:

        CuentaAhorro();
        CuentaAhorro(int numcuenta, string cliente, string apellido, double bal);
        double balanceCuenta();
        string toString();
};

CuentaAhorro::CuentaAhorro(){
    numcuenta = 0;
    cliente = "";
}

CuentaAhorro::CuentaAhorro(int nacc, string clte, string ln, double bal){
    numcuenta = nacc;
    cliente = clte;
    apellido = ln;
    balance = bal;
}

double CuentaAhorro::balanceCuenta(){
    return balance;
}

string CuentaAhorro::toString(){
    stringstream aux;
    aux << "Numero de cuenta: " << numcuenta << "\nNombre Cliente: " << cliente << "\nApellido Cliente:" << apellido;
    return aux.str();
}


#endif





