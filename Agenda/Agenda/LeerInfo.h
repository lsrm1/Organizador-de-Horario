#ifndef LEERINFO_H
#define LEERINFO_H
#include <fstream>
using namespace std;

void contarmater (int &n_mate){

    char linea[10] = {};

    ifstream materia;
    materia.open("materia.txt");

    while(materia.good()){

        materia>>linea;
        n_mate++;
    }

    n_mate--;

    materia.close();
}

void leerbase(int codigos[],int creditos[],int h_estudio[],int n_mate){

    int n = 0;

    ifstream base;
    base.open("base.txt");

    while(n < n_mate){

        base>>codigos[n];
        base>>creditos[n];
        base>>h_estudio[n];


        n++;
    }

    base.close();

}

void nombre_mate (int line_materia)
{
    ifstream archivo;
    archivo.open("materia.txt");
    char nombre [12] = {};

    for (int t = 0; t <= line_materia; t++)
    {
        archivo>>nombre;
    }

    archivo.close();

    cout<<"  ";
    cout<<nombre;
    cout<<"  |";

}

void imprimir(int n_mate,int codigos[])
{
    cout<<"                                  TU HORARIO                                            \n";
    cout<<"------------------------------------------------------------------------------------------\n";
    cout<<" Hora|   Lunes   | Martes    | Miercoles |  Jueves   |  Viernes  | Sabado    | Domingo   |\n" ;
    cout<<"------------------------------------------------------------------------------------------\n";


    ifstream horariotxt;
    horariotxt.open("horario.txt");



    int hora = 6;
    int n_horas = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;


    while (hora <= n_horas){

        if (hora < 10 ){

         cout<<hora<<":00 |";
        }
        else{
            cout<<hora<<":00|";
        }

        while (dia < n_dias){

            horariotxt >> valor;

            if (valor != 0){

                for (int line_materia = 0; line_materia < n_mate; line_materia++){

                    if (valor == codigos[line_materia]){

                        nombre_mate(line_materia);

                    }

                }

            }

            else{

                cout<<"     -     ";
                cout<<"|";
            }

            dia++;

        }

        dia = 0;
        hora ++;
        cout<<"\n";

    }

    horariotxt.close();

    cout<<"------------------------------------------------------------------------------------------\n";
}

void modificarhorario(int codigo,int opcion){

    ifstream horariotxt;
    horariotxt.open("horario.txt");

    ofstream auxtxt;
    auxtxt.open("aux.txt");

    int hora_ini = 6;
    int hora_fin = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;

    int hora_modif = 0;
    int dia_modif = 0;
    int materia = 0;
    int n_hora = 0;

    if(opcion == 3){

        materia = codigo;
    }

    cout<<"Que dia estudiaras esta materia? \n";
    cout<<"1.Lunes  2.Martes   3.Miercoles   4.Jueves   5.Viernes  6.Sabado\n Selecciona:";cin>>dia_modif;
    cout<<"A que hora?(6:00-22:00): ";cin>>hora_modif;
    cout<<"Cuantas horas?: ";cin>> n_hora;


    int pos_modif = ((hora_modif-6)*7)+dia_modif;
    int posicion = 1;


    while (hora_ini <= hora_fin){

        while (dia < n_dias){

            horariotxt >> valor;

            if (posicion == pos_modif){

                auxtxt<<materia;

                if (n_hora > 1){

                    pos_modif += 7;
                    n_hora--;
                }


            }

            else{

                auxtxt<<valor;
            }

            auxtxt<<" ";

            dia++;

            posicion++;

        }

        dia = 0;
        hora_ini ++;
        auxtxt<<"\n";

    }

    horariotxt.close();
    auxtxt.close();
}

void agregarmateria(int &codigo){

    char nombre[12];
    int credito = 0;
    int h_clase = 0;

    ofstream base;
    base.open("base.txt",ios::app);

    ofstream materia;
    materia.open("materia.txt",ios::app);

    cout<<"Codigo : ";cin>>codigo;
    cout<<"Materia: ";cin>>nombre;
    cout<<"Creditos : ";cin>>credito;
    cout<<"Horas de clase a la semana: ";cin>>h_clase;

    base<<codigo<< " ";
    base<<credito<<" ";
    base<<((credito*48)-(h_clase*16))/16;

    materia<<nombre;

    materia.close();
    base.close();

}

void actualizarhorario(){

    ifstream auxtxt;
    auxtxt.open("aux.txt");

    ofstream horariotxt;
    horariotxt.open("horario.txt");

    int hora_ini = 6;
    int hora_fin = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;

    while (hora_ini <= hora_fin){

        while (dia < n_dias){

            auxtxt >> valor;

            horariotxt<<valor<<" ";

            dia++;


         }

        dia = 0;
        hora_ini ++;
        horariotxt<<"\n";

     }

    horariotxt.close();
    auxtxt.close();

}

void menuprincipal(int &opcion){

    cout<<"                                   MENU PRINCIPAL\n";
    cout<<"________________________________________________________________________________________\n";
    cout<<"\n1.Ver horario\n2.Programar horas de estudio\n3.Agregar materia al horario\n4.Salir\n\nSelecciona:";
    cin>>opcion;


}


#endif // LEERINFO_H
