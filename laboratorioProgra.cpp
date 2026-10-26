#include <iostream>

using namespace std;

float calcularTarifa(float desbloqueo, float euroMin);

const float descuentoEst = 0.20; //descuento estudiante
const float maxCost = 12.00; //coste maximo
const float recargoHora = 1.2;

int main(){

    const float desbB = 0.50; //coste de desbloqueo bicis
    const float desbP = 1.00; //coste de desbloqueo patinetes
    const float biciMin = 0.10; //coste de bici por minuto
    const float patiMin = 0.20; //coste de patinete por minuto
   

    const int totalB = 10; //nº total de bicis
    const int totalP = 6; //nº total patinetes

    int bicisUso = 0;
    int bicisUsoHist = 0;
    int patinUso = 0;
    int patinUsoHist = 0;

    int opcion;

    char tipoV;

    float totalTarifas = 0.0;

    cout << "Bienvenido/a a CampusRide - Estacion Pirineos" << endl;
    cout << "==============================" << endl;
    cout << " CampusRide - Menu principal" << endl;
    cout << "==============================" << endl;

    while (true){

        float tarifa = 0.0;

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
            cout << "--- Alquilar vehiculo ---" << endl;

            while(true){
                cout << "Tipo [B = bicicleta, P = patinete, Q = salir]: ";
                cin >> tipoV;
                cout << endl;
                if(tipoV == 'B'){
                    if(totalB-bicisUso != 0){

                        bicisUso += 1;
                        bicisUsoHist += 1;
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
                        patinUsoHist += 1;
                        cout << "Patinete alquilado. Patinetes disponibles:" << totalP - patinUso << "/6" << endl;
                        cout << endl;
                        break;

                    }
                    else{

                        cout << "No hay patinetes disponibles, disculpe las molestias." << endl;
                        break;

                    }
                }
                else if(tipoV == 'Q'){
                    break;
                }
                else{
                    cout << "Introduzca 'P', 'B' o 'Q' (en mayuscula)." << endl;
                }
            }

        }
        else if(opcion == 4){

            //Devolver el vehiculo
            cout << "--- Devolver vehiculo ---" << endl;

            while(true){
                cout << "Tipo [B = bicicleta, P = patinete, Q = salir]: ";
                cin >> tipoV;
                cout << endl;
                if(tipoV == 'B'){
                    if(bicisUso != 0){

                        bicisUso -= 1;
                        tarifa = calcularTarifa(desbB, biciMin);
                        totalTarifas += tarifa;
                        cout << "Total a pagar: " << tarifa << " EUR" << endl;
                        cout << "Bicicletas disponibles: " << totalB - bicisUso <<"/10" << endl;
                        break;
                    }
                    else{

                        cout << "Todas las bicicletas ya estan en la estacion." << endl;
                        
                    }
                }
                else if(tipoV == 'P'){
                    if(patinUso != 0){

                        patinUso -= 1;
                        tarifa = calcularTarifa(desbP, patiMin);
                        totalTarifas += tarifa;
                        cout << "Total a pagar: " << tarifa << " EUR" << endl;
                        cout << "Patinetes disponibles: " << totalB - bicisUso <<"/10" << endl;
                        break;

                    }
                    else{

                        cout << "Todos los patinetes ya estan en la estacion." << endl;

                    }
                }
                else if(tipoV == 'Q'){
                    break;
                }
                else{

                    cout << "Introduzca 'P', 'B' o 'Q' (en mayuscula)." << endl;

                }
            }
        }
        else if(opcion == 5){
            //Resumen de dia
            cout << "--- Resumen de dia ---" << endl;
            cout << "Viajes realizados: " << bicisUsoHist + patinUsoHist << endl;
            cout << "Recaudacion total: " << totalTarifas << " EUR" << endl;
            cout << "Importe medio por viaje: " << totalTarifas/(bicisUsoHist + patinUsoHist) << " EUR" << endl;

            if(bicisUsoHist < patinUsoHist){
                cout << "Tipo mas usado: patinete" << endl;
            }
            else if(bicisUsoHist > patinUsoHist){
                cout << "Tipo mas usado: bicicleta" << endl;
            }
            else{
                cout << "Ambos se utilizaron la misma cantidad de veces" << endl;
            }

        }
        else if(opcion == 6){
            break;
        }
        else{
            cout << "Introduce un numero del 1 al 6" << endl;
        }
    
    }
}

float calcularTarifa(float desbloqueo, float euroMin){

    int tiempo;
    char estudiante;
    float tarifa;
    float descuento;
    int count = 0;

    cout << "Duracion del viaje (numero entero de minutos): ";
    cin >> tiempo;
    cout << endl;

    do{
        if(count == 0){
            tarifa = desbloqueo + (euroMin * tiempo);
            count = 1;
            tiempo -= 60;
        }
        else{

            tarifa += (euroMin * tiempo) * recargoHora;
            tiempo -= 60;

        }

    }while(tarifa > 60);

    while(true){
        cout << "Es estudiante? (S/N): ";
        cin >> estudiante;
        cout << endl;
        if(estudiante == 'S'){

            descuento = tarifa * descuentoEst;
            break;

        }
        else if(estudiante == 'N'){

            descuento = 0.0;
            break;

        }
        else{
            cout << "Introduzca 'S' o 'N' (en mayusculas)" << endl;
        }
    }

    

    cout << "Desbloqueo: " << desbloqueo << " EUR" << endl;
    cout << "Tiempo: " << tiempo << " min x " << euroMin << " EUR = " << tarifa << " EUR" << endl;
    cout << "Descuento estudiante (20%): -" << descuento << " EUR" << endl;

    if(tarifa-descuento >= 12.00){

        tarifa = 12.00;

    }

    return tarifa;

}