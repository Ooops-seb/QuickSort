/*Quick sort con archivos de alta carga
Nombre: Erik Villarreal
Fecha: 8 de diciembre 2022
*/
#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<sys/time.h>

using namespace std;

void menu();
void menu_print();
int pivotear(int *V, int b, int t);
double QuickSort(int *V, int b, int t);
double read(int array[], int arrayAux[], string file_path);
void sort(int array[], int arrayAux[], string path, int dim);
void print_array(int array[], int arrayAux[], int dim);
void print_time();

long getTime(){
    struct timeval inicio;
    gettimeofday(&inicio, NULL);
    return inicio.tv_sec*5000 + inicio.tv_usec;
}

int v5[5000]; //Vector leido
int v50[50000]; //Vector leido
int v350[350000]; //Vector leido
int V5[5000]; //Vector ordenado
int V50[50000]; //Vector ordenado
int V350[350000]; //Vector ordenado

double time_exe_5k;
double time_exe_50k;
double time_exe_350k;
double time_sort_5k;
double time_sort_50k;
double time_sort_350k;

int main(){
    string path;
    int op;
    bool salida=false;
    int dim;
    do{
        menu();
        cout<<"Ingrese una opcion: ";
        cin>>op;
        switch (op)
        {
            case 1:
                system("cls");
                cout << "|-------------------------------------|" << endl;
                cout << "|       Archivo con 5.000 datos       |" << endl;
                cout << "|-------------------------------------|" << endl;
                path = "C:\\Users\\seb_3\\OneDrive - UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\\202251 - Oct22-Mar23\\ESTRUCTURA DE DATOS\\QuickSortArchivos\\random_numbers_5000.dat";
                dim = 5000;
                sort(v5, V5, path, dim);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "|-------------------------------------|" << endl;
                cout << "|       Archivo con 50.000 datos      |" << endl;
                cout << "|-------------------------------------|" << endl;
                path = "C:\\Users\\seb_3\\OneDrive - UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\\202251 - Oct22-Mar23\\ESTRUCTURA DE DATOS\\QuickSortArchivos\\random_numbers_50000.dat";
                dim = 50000;
                sort(v50, V50, path, dim);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "|-------------------------------------|" << endl;
                cout << "|      Archivo con 350.000 datos      |" << endl;
                cout << "|-------------------------------------|" << endl;
                path = "C:\\Users\\seb_3\\OneDrive - UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\\202251 - Oct22-Mar23\\ESTRUCTURA DE DATOS\\QuickSortArchivos\\random_numbers_350000.dat";
                dim = 350000;
                sort(v350, V350, path, dim);
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "|-------------------------------------|" << endl;
                cout << "|         Visualizar vectores         |" << endl;
                cout << "|-------------------------------------|" << endl;
                menu_print();
                break;
            case 5:
                system("cls");
                print_time();
                system("pause");
                break;
            case 6:
                cout<<endl<<"Saliendo del programa..."<<endl;
                salida=true;
                break;
            default:
                cout<<"***OPCION INVALIDA - INGRESE NUEVAMENTE***"<<endl;
                system("pause");
                break;
        }
    }while(!salida);
    return 0;
}

void menu(){
    system("cls");
    cout << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                  QuickSort con archivos               |" << endl;
    cout << "|                      de alta carga                    |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "| 1. Archivo 5.000 datos    | 2. Archivo 50.000 datos   |" << endl;
    cout << "| 3. Archivo 350.000 datos  | 4. Visualizar vectores    |" << endl;
    cout << "| 5. Tiempos de ejecucion   | 6. SALIR                  |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
}
void menu_print(){
    int op;
    bool salida=false;
    int dim;
    do{
        system("cls");
        cout << endl;
        cout << "|-------------------------------------------------------|" << endl;
        cout << "|                   Visualizar vectores                 |" << endl;
        cout << "|-------------------------------------------------------|" << endl;
        cout << "| 1. Vector 5.000 datos     | 2. Vector 50.000 datos    |" << endl;
        cout << "| 3. Vector 350.000 datos   | 4. Menu principal         |" << endl;
        cout << "|-------------------------------------------------------|" << endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        switch (op)
        {
            case 1:
                dim = 5000;
                print_array(v5, V5, dim);
                system("pause");
                break;
            case 2:
                dim = 50000;
                print_array(v50, V50, dim);
                system("pause");
                break;
            case 3:
                dim = 350000;
                print_array(v350, V350, dim);
                system("pause");
                break;
            case 4:
                salida=true;
                break;
            default:
                cout<<"***OPCION INVALIDA - INGRESE NUEVAMENTE***"<<endl;
                system("pause");
                break;
        }
    }while(!salida);
}
int pivotear(int *V, int b, int t){
    int pivote, valor_pivote;
    int temp;
    pivote = b;
    valor_pivote = V[pivote];
    for(int i = b+1; i<=t; i++){
        if(V[i] < valor_pivote){
            pivote++;
            temp = V[i];
            V[i] = V[pivote];
            V[pivote] = temp;
        }
    }
    temp = V[b];
    V[b] = V[pivote];
    V[pivote] = temp;
    return pivote;
}
double QuickSort(int *V, int b, int t){
    long inicio = getTime();
    double timeSec;
    long timeMicroSec;
    double exe_time;
    int pivote;
    if(b < t){
        pivote = pivotear(V, b, t);
        QuickSort(V, b, pivote-1);
        QuickSort(V, pivote+1, t);
    }
    long final = getTime();
    timeMicroSec = final - inicio;
    timeSec = timeMicroSec * pow(10,-6);
    exe_time = timeSec;
    return exe_time;
}
double read(int array[], int arrayAux[], string file_path){
    long inicio = getTime();
    double timeSec;
    long timeMicroSec;
    double exe_time;
    ifstream file;
    string dato;
    file.open(file_path.c_str(), ios :: in);
    if(file.fail()){
        cout<<"Error al abrir el archivo."<<endl;
        exit(1);
    }
    int i = 1;
    cout << "Procesado archivo..." << endl;
    string aux_s;
    while(!file.eof()){
        getline(file, dato) >> aux_s;
        array[i] = atoi(aux_s.c_str());
        arrayAux[i] = atoi(aux_s.c_str());
        i++;
    }
    cout << endl;
    file.close();
    long final = getTime();
    timeMicroSec = final - inicio;
    timeSec = timeMicroSec * pow(10,-6);
    exe_time = timeSec;
    return exe_time;

}
void sort(int array[], int arrayAux[], string path, int dim){
    cout << endl << "Se leeran los datos del archivo"<< endl;
    system("pause");
    if (dim==5000)
        time_exe_5k = read(array, arrayAux, path);
    else if (dim==50000)
        time_exe_50k = read(array, arrayAux, path);
    else if (dim==350000)
        time_exe_350k = read(array, arrayAux, path);
    cout << "Lectura completa..." << endl;
    cout << "***Aplicar Quick Sort***" << endl;
    system("pause");
    cout << "Se estan ordenando los datos..." << endl;
    if (dim==5000)
        time_sort_5k = QuickSort(arrayAux, 0, dim-1);
    else if (dim==50000)
        time_sort_50k = QuickSort(arrayAux, 0, dim-1);
    else if (dim==350000)
        time_sort_350k = QuickSort(arrayAux, 0, dim-1);
    cout << "Orden completo...." << endl;
}
void print_array(int array[], int arrayAux[], int dim){
    cout << endl;
    cout << "\t|-------------------|-------------------|" << endl;
    cout << "\t|       VECTOR      |  VECTOR ORDENADO  |" << endl;
    cout << "\t|-------------------|-------------------|"  << endl;
    for(int i=0; i<dim; i++){
        cout << "[" << i+1 << "]:\t" << array[i] <<"\t|\t"<< arrayAux[i]<< endl;
    }
}
void print_time(){
    cout << endl;
    cout << "|------------------------|-------------------|-------------------|-------------------|" << endl;
    cout << "|                        |      5.000 datos  |    50.000 datos   |   350.000 datos   |" << endl;
    cout << "|------------------------|-------------------|-------------------|-------------------|" << endl;
    cout << "| Tiempo de lectura:     |     "<<time_exe_5k<<"             "<<time_exe_50k<<"           "<<time_exe_350k<<"      |" << endl;
    cout << "| Tiempo ordenamiento:   |     "<<time_sort_5k<<"             "<<time_sort_50k<<"           "<<time_sort_350k<<"      |" << endl;
    cout << "|------------------------|-------------------|-------------------|-------------------|" << endl;
}