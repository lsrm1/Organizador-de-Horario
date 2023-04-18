#ifndef LEERINFO_H
#define LEERINFO_H
#include <fstream>
using namespace std;

void contarhoraest(int &n_horaest){

    int i = 0;

    ifstream estudio;
    estudio.open("horasestudio.txt");

    while(estudio.good()){

        estudio >> i;
        n_horaest++;
    }


    materia.close();
}

void contarmater (int &n_mate){

    char linea[15] = {};

    ifstream materia;
    materia.open("materia.txt");

    while(materia.good()){

        materia>>linea;
        n_mate++;
    }


    materia.close();
}

void leerbase(int codigos[],int h_estudio[],int n_mate){

    int n = 0;

    ifstream base;
    base.open("base.txt");

    while(n < n_mate){

        base>>codigos[n];
        base>>h_estudio[n];


        n++;
    }

    base.close();

}

void nombre_mate (int line_materia,int posicion){

    ifstream archivo;
    archivo.open("materia.txt");
    char nombre [15] = {};
    int i = 0;
    int t = 0

    for (t = 0; t <= line_materia; t++)
    {
        archivo>>nombre;
    }


    while (nombre[i] != '\0'){

        i++;
    }

    cout<<" ";

    //for (t
    cout<<nombre;

    while(i < 15){

        cout<<" ";
        i++;
    }

    cout<<"|";

    i = 0;

    archivo.close();



}

void imprimir(int n_mate,int codigos[]){

    cout<<"                                                 TU HORARIO                                                                  \n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
    cout<<" Hora|       Lunes     |    Martes      |    Miercoles   |     Jueves     |     Viernes    |    Sabado      |     Domingo   |\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";


    ifstream horariotxt;
    horariotxt.open("horario.txt");



    int hora = 6;
    int n_horas = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;

    int posicion = 1;


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

                cout<<"       -        ";
                cout<<"|";
            }

            dia++;
            posicion++;

        }

        dia = 0;
        hora ++;
        cout<<"\n";

    }

    horariotxt.close();

    cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
}

void modificarhorario(int codigo,int &resta,int menu){

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


    materia = codigo;


    cout<<"Que dia estudiaras esta materia? \n";
    cout<<"1.Lunes  2.Martes   3.Miercoles   4.Jueves   5.Viernes  6.Sabado  7.Domingo\n Selecciona: ";cin>>dia_modif;
    cout<<"\nA que hora?(6:00-22:00): ";cin>>hora_modif;
    cout<<"\nCuantas horas?: ";cin>> n_hora;

    resta = n_hora;


    int pos_modif = ((hora_modif - hora_ini)*n_dias)+dia_modif;

    if (menu == 2){

        ofstream estudio;
        estudio.open("horasestudio.txt",ios::app);

        estudio<<pos_modif<<" ";

        estudio.close();

    }

    int posicion = 1;


    while (hora_ini <= hora_fin){

        while (dia < n_dias){

            horariotxt >> valor;

            if (posicion == pos_modif){

                auxtxt<<materia;

                if (n_hora > 1){

                    pos_modif += n_dias;
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

    char nombre[15];
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

void menuprincipal(int &menu){

    cout<<"\nMENU PRINCIPAL\n";
    cout<<"\n1.Ver horario\n2.Programar horas de estudio\n3.Agregar materia al horario\n4.Salir\n\nSelecciona:";
    cin>>menu;
    cout<<"__________________________________________________\n";


}

void infoestudio(int h_estudio[], int n_mate){

    int total = 0;

    for(int j = 0; j < n_mate; j++){

        total += h_estudio[j];

    }

    cout<<"Tienes un total de "<<total<<" horas de estudio por programar: \n\n";

    for(int j = 0; j < n_mate; j++){

        if (h_estudio[j] > 0){

            cout<<j<<".";
            nombre_mate(j);
            cout<<"Debes programar "<<h_estudio[j]<<" horas\n";

        }
    }

}

void actualizarbase(int codigos[],int h_estudio[],int n_mate){

    ofstream base;
    base.open("base.txt");

    for (int i = 0; i < n_mate; i++) {

        base<<codigos[i]<<" ";
        base<<h_estudio[i]<<"\n";

    }

    base.close();

}


#endif // LEERINFO_H
