/*Generar numeros aleatorios
Nombre: Erik Villarreal
Fecha: 12 de diciembre 2022
*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

void escribir(int dato, int numeros);
ofstream archivo;

int main(){
    int min = 0, max = 0, numeros;
    cout << "***Ingrese el rango***"<<endl;
    cout << "MIN: ";
    cin >> min;
    cout << "MAX: ";
    cin >> max;
    cout << "Cantidad de numeros: ";
    cin >> numeros;
    int random;
    string nombre_archivo = "random_numbers_";
    stringstream ss;
    ss << numeros;
    string aux;
    ss >> aux;
    nombre_archivo = nombre_archivo + aux;
    nombre_archivo = nombre_archivo + ".dat";
    archivo.open(nombre_archivo.c_str(), ios::out);
    for(int i=0; i<numeros; i++){
        random = min + rand() % (max - min);
        cout <<"["<<i+1<<"]: "<< random << endl;
        escribir(random, numeros);
        if (i<numeros-1)
            archivo<<endl;
    }
    
    archivo.close();
    return 0;
}
void escribir(int dato, int numeros){

    if (archivo.fail()){
        cout << "¡No se pudo crear el archivo!" << endl;
        exit(1);
    }
    else{
        archivo << dato;
    }
}