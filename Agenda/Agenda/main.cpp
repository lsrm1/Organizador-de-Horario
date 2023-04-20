#include <iostream>
#include "Funciones.h"

using namespace std;


int main(){


    int codigo = 0;
    int menu = 0;
    int opcion = 0;
    int resta = 0;

    char repetir = 's';
    bool ejecutar = true;

    int n_hora = 0;
    int n_mate = 0;


    while (ejecutar){

        contar(n_mate,n_hora);

        int codigos  [n_mate] = {};
        int h_estudio[n_mate] = {};
        int h_program[n_hora] = {};

        leerbase(codigos,h_estudio,n_mate,h_program,n_hora);

        menuprincipal(menu);

        if (menu == 1){

            imprimir(n_mate,codigos,n_hora,h_program);

        }

        if (menu == 2){


            while (repetir == 's'){


                imprimir(n_mate,codigos,n_hora,h_program);

                infoestudio(h_estudio,n_mate);

                cout<<"Selecciona: ";cin>>opcion;

                codigo = codigos[opcion];

                modificarhorario(codigo,resta,menu);

                h_estudio[opcion] = h_estudio[opcion] - resta;

                actualizarhorario();

                cout<< "Quieres programar mas horas de estudio?(s/n):  ";cin>>repetir;


            }

            actualizarbase(codigos,h_estudio,n_mate);

        }

        repetir = 's';

        if (menu == 3){

            agregarmateria(codigo,codigos,n_mate);

            while (repetir == 's'){

                modificarhorario(codigo,resta,menu);
                actualizarhorario();
                cout<< "Estudiaras esta materia otro dia en la semana?(y/n):  ";cin>>repetir;

            }

            cout<<"Hecho!";

        }

        if (menu == 4){

            ejecutar = false;

        }

    }

    return 0;

}
