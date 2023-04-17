#include <iostream>
#include "LeerInfo.h"

using namespace std;

int main(){

    int n_mate = 0;
    int opcion = 0;
    int codigo = 0;
    char repetir = 's';
    bool ejecutar = true;

    contarmater(n_mate);

    int codigos  [n_mate] = {};
    int creditos [n_mate] = {};
    int h_estudio[n_mate] = {};

    leerbase(codigos,creditos,h_estudio,n_mate);

    while (ejecutar == true){

        menuprincipal(opcion);

        if (opcion == 1){

            imprimir(n_mate,codigos);

        }

        if(opcion == 2){


        }


        if (opcion == 3){

            agregarmateria(codigo);
            contarmater(n_mate);
            leerbase(codigos,creditos,h_estudio,n_mate);

            while (repetir == 's'){

                modificarhorario(codigo,opcion);
                actualizarhorario();
                cout<< "Ves esta materia otro dia en la semana?(s/n):  ";cin>>repetir;

            }

            cout<<"Hecho!";

        }

        if (opcion == 4){

            ejecutar = false;


        }

    }

    return 0;
}
