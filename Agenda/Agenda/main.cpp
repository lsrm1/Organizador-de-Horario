#include <iostream>
#include "LeerInfo.h"

using namespace std;


int main(){


    int n_mate = 0;
    int codigo = 0;

    int menu = 0;
    int opcion = 0;
    int resta = 0;
    int n_horaest = 0;

    char repetir = 's';
    bool ejecutar = true;

    contarmater(n_mate);

    int codigos  [n_mate] = {};
    int h_estudio[n_mate] = {};
    int pos_est[n_horaest] ={};

    leerbase(codigos,h_estudio,n_mate);


    while (ejecutar){

        menuprincipal(menu);


        if (menu == 1){

            imprimir(n_mate,codigos);

        }


        if (menu == 2){

            while (repetir == 's'){

                imprimir(n_mate,codigos);
                infoestudio(h_estudio,n_mate);

                cout<<"Selecciona: ";cin>>opcion;
                codigo = codigos[opcion];

                modificarhorario(codigo,resta,menu);

                h_estudio[opcion] = h_estudio[opcion] - resta;

                actualizarhorario();

                cout<< "Quieres programar mas horas de estudio?(s/n):  ";cin>>repetir;


            }

            actualizarbase(codigos,h_estudio,n_mate);

            repetir = 's';

        }



        if (menu == 3){

            agregarmateria(codigo);
            contarmater(n_mate);
            leerbase(codigos,h_estudio,n_mate);

            while (repetir == 's'){

                modificarhorario(codigo,resta,menu);
                actualizarhorario();
                cout<< "Estudiaras esta materia otro dia en la semana?(s/n):  ";cin>>repetir;

            }

            cout<<"Hecho!";

        }


        if (menu == 4){

            ejecutar = false;

        }


    }


    return 0;

}
