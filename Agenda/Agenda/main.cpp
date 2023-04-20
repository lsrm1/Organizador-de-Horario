#include <iostream>
#include "Funciones.h"

using namespace std;

int main(){

    int codigo = 0;
    int menu = 0;
    int opcion = 0;
    int resta = 0;
    int total = 0;


    bool ejecutar = true;
    char repetir = 'y';

    int n_hora = 0;
    int n_mate = 0;
    int h_clase = 0;


    while (ejecutar){


        contar(n_mate,n_hora);  //Actualiza Informacion
        int codigos  [n_mate] = {};
        int h_estudio[n_mate] = {};
        int h_program[n_hora] = {};
        leerbase(codigos,h_estudio,n_mate,h_program,n_hora);


        menuprincipal(menu);


        if (menu == 1){

            imprimir(n_mate,codigos,n_hora,h_program);
        }


        if (menu == 2){ //Programar horas de estudio

            do{
                imprimir(n_mate,codigos,n_hora,h_program);
                infoestudio(h_estudio,n_mate,total);

                if (total > 0){
                    cout<<"Selecciona: ";cin>>opcion;
                    codigo = codigos[opcion];
                    modificarhorario(codigo,resta,menu);
                    h_estudio[opcion] = h_estudio[opcion] - resta;
                    actualizarhorario();
                    cout<< "Quieres programar mas horas de estudio?(y/n):  ";cin>>repetir;
                }
                else{
                    repetir = 'n';
                }

            } while (repetir == 'y');

            actualizarbase(codigos,h_estudio,n_mate);

        }



        if (menu == 3){ // Gestion de materias

            cout<<"1. Informacion General\n2. Agregar materias al horario\n Selecciona: ";cin>>opcion;

            if (opcion == 1){

                infomateria(n_mate);
            }

            if (opcion == 2){

                do{
                    cout<<"Ingrese los siguientes datos: \n";
                    agregarmateria(codigo,codigos,n_mate,h_clase);

                    contar(n_mate,n_hora);
                    int codigos  [n_mate] = {};
                    int h_estudio[n_mate] = {};
                    int h_program[n_hora] = {};
                    leerbase(codigos,h_estudio,n_mate,h_program,n_hora);


                    do{
                        imprimir(n_mate,codigos,n_hora,h_program);
                        cout<<"Nota: Agrega "<<h_clase<<" horas de clase a la semana\n\n";
                        modificarhorario(codigo,resta,menu);
                        actualizarhorario();
                        h_clase = h_clase-resta;

                    } while (h_clase > 0);

                    cout<<"Guardando cambios...\n";
                    cout<< "Quieres agregar mas de materias?(y/n):  ";cin>>repetir;

                }while(repetir == 'y');
            }
        }



        if (menu == 4){ // Reinicia bases de datos

            cout<<"Vas a eliminar tu horario y horas de estudio\nContinuar? (y/n) "; cin>>repetir;

            if(repetir == 'y'){

                terminarsemestre();

            }
        }



        if (menu == 5){ //Salir

            ejecutar = false;

        }

    }

    return 0;
}


