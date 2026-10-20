#include <iostream>

using namespace std;

/*int alquilarV(){


    
}*/

const float DesbB = 0.50; //coste de desbloqueo bicis
const float DesbP = 1.00; //coste de desbloqueo patinetes
const float biciMin = 0.10; //coste de bici por minuto
const float patiMin = 0.20; //coste de patinete por minuto
const float descuentoEst = 0.80; //descuento estudiante
const float maxCost = 12.00; //coste maximo

const float recargoHora = 1.2;

const int totalB = 10; //nº total de bicis
const int totalP = 6; //nº total patinetes

int main(){

    int bicisUso = 0;
    int patinUso = 0;

    int opcion;

    cout << "Bienvenido/a a CampusRide - Estacion Pirineos" << endl;
    cout << "==============================" << endl;
    cout << " CampusRide - Menu principal" << endl;
    cout << "==============================" << endl;

    while (true){

    cout << "1) Estado de la estacion" << endl;
    cout << "2) Simular tarifa" << endl;
    cout << "3) Alquilar vehiculo" << endl;
    cout << "4) Devolver vehiculo" << endl;
    cout << "5) Resumen de dia" << endl;
    cout << "6) Salir" << endl;

    cout << "Eligue una opcion (1-6): ";
    cin >> opcion;
    cout << endl;

    if(opcion == 1){
        //Estado de la estacion
        cout << "--- Estado de la estacion ---" << endl;
        cout << "Bicicletas disponibles: " << totalB - bicisUso << "/10" << endl;
        cout << "Patinetes disponibles: " << totalP - patinUso << "/6" << endl;
        cout << endl;


    }
    else if(opcion == 2){
        //filipe
    }
    else if(opcion == 3){
        //Alquilar vehiculo
        char tipoV;
        cout << "--- Alquilar vehiculo ---" << endl;
        while(true){
            cout << "Tipo [B = bicicleta, P = patinete]: ";
            cin >> tipoV;
            cout << endl;
            if(tipoV == 'B'){
                if(totalB-bicisUso != 0){
                    bicisUso += 1;
                    cout << "Bicicleta alquilada. Bicicletas disponibles:" << totalB - bicisUso << "/10" << endl;
                    break;
                }
                else{
                    cout << "No hay bicicletas disponibles, disculpe las molestias." << endl;
                    break;
                }
            }
            else if(tipoV == 'P'){
                if(totalP-patinUso != 0){
                    patinUso += 1;
                    cout << "Patinete alquilado. Patinetes disponibles:" << totalP - patinUso << "/6" << endl;
                    cout << endl;
                    break;
                }
                else{
                    cout << "No hay patinetes disponibles, disculpe las molestias." << endl;
                    break;
                }
            }
            else{
                cout << "Introduzca 'P' o 'B'." << endl;
            }
        }

    }
    else if(opcion == 4){

    }
    else if(opcion == 5){

    }
    else if(opcion == 6){
        break;
    }
    else{
        cout << "Introduce un numero del 1 al 6" << endl;
    }
    
    }
}