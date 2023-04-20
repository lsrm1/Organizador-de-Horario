#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void infomateria(int n_mate){

    if (n_mate > 0){

        ifstream general;
        general.open("general.txt");

        int valor = 0 ;
        int i = 0;
        char nombre[15] = {};


        cout<< "|  Codigo   |    Materia     |  Creditos |  H. clase | H.Estudio |\n";

        while(n_mate > 0){

            i = 0;


            general>>valor;
            cout<<"|"<<valor<<"    "<<"|";;
            general>>nombre;
            cout<<" "<<nombre;

            while (nombre[i] != '\0'){

                i++;
            }



            while(i < 15){

                cout<<" ";
                i++;
            }

            cout<<"|";

            general>>valor;
            cout<<"     "<<valor<<"     |";
            general>>valor;
            cout<<"     "<<valor<<"     |";
            general>>valor;
            cout<<"     "<<valor<<"     |\n";

            n_mate--;
        }
        general.close();
    }

    else{
        cout<<"No tienes materias registradas\n";
    }

}

void terminarsemestre(){

    int hora_ini = 6;
    int hora_fin = 22;
    int dia = 0;
    int n_dias = 7;
    int posicion = 1;

    ofstream archivo;
    archivo.open("materia.txt");
    archivo.close();

    ofstream base;
    base.open("base.txt");
    base.close();

    ofstream estudio;
    estudio.open("horasestudio.txt");
    estudio.close();

    ofstream horariotxt;
    horariotxt.open("horario.txt");

    while (hora_ini <= hora_fin){

        while (dia < n_dias){

            horariotxt << 0;
            horariotxt<<" ";
            dia++;
            posicion++;

        }
        dia = 0;
        hora_ini ++;
        horariotxt<<"\n";

    }

    horariotxt.close();

}

void verifica(int &n_hora, int &pos_modif){

    ifstream horariotxt;
    horariotxt.open("horario.txt");

    int hora_ini = 6;
    int hora_fin = 22;
    int valor = 0;
    int n_dias = 7;
    bool verificar = false;
    int totalp = ((hora_fin-hora_ini)*n_dias) + n_dias;

    int hora_modif = 0;
    int dia_modif = 0;
    int posicion = 0;
    int n_horaprov = 0;


    do{

        posicion = 1;

        while(verificar == false){

            cout<<"Que dia estudiaras esta materia?\n";
            cout<<"1.Lunes  2.Martes   3.Miercoles   4.Jueves   5.Viernes  6.Sabado  7.Domingo\n Selecciona: ";cin>>dia_modif;

            if (dia_modif >= 1 && dia_modif<= n_dias){
                verificar = true;
            }


            else{
                cout<<"\nIngresa un dia valido!\n";
            }

            cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
        }

        verificar = false;

        while(verificar == false){

            cout<<"\nA que hora?(6:00-22:00): ";cin>>hora_modif;

            if (hora_modif >= hora_ini && hora_modif<= hora_fin){
                verificar = true;
            }


            else{
                cout<<"\nIngresa una hora valida!\n";
            }

            cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
        }


        verificar = false;


        cout<<"Cuantas horas?: ";cin>> n_horaprov;
        n_hora = n_horaprov;

        pos_modif = ((hora_modif - hora_ini)*n_dias)+dia_modif;

        while(posicion <= totalp){

            horariotxt >> valor;

            if (posicion == pos_modif){

                if (valor == 0){

                    verificar = true;

                    if (n_horaprov > 1){

                        pos_modif += n_dias;
                        n_horaprov--;
                    }
                }

                else{

                    verificar = false;
                    cout<<"No tienes espacios de tiempo suficiente en ese momento!\n";
                    break ;
                }

            }

            posicion++;

        }

        pos_modif = ((hora_modif - hora_ini)*n_dias)+dia_modif;

        cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";

    } while(verificar == false);

    horariotxt.close();


}

void nombremateria(int posicion,int x){

    ifstream archivo;
    archivo.open("materia.txt");

    char nombre [15] = {};
    int i = 0;
    int t = 0;

    for (t = 0; t <= posicion; t++)
    {
        archivo>>nombre;
    }

    while (nombre[i] != '\0'){

        i++;
    }

    i += x;

    cout<<" "<<nombre;

    while(i < 15){

        cout<<" ";
        i++;
    }

    cout<<"|";

    archivo.close();


}

void contar(int &n_mate, int &n_hora){


    char linea[20] = {};
    n_mate = 0;
    n_hora = 0;

    ifstream base;
    base.open("base.txt");

    while(base.getline(linea,20)){

        n_mate++;
    }


    base.close();

    ifstream htp;
    htp.open("horasestudio.txt");

    while(htp.getline(linea,3)){

        n_hora++;
    }

    htp.close();

}

void leerbase(int codigos[],int h_estudio[],int n_mate,int h_program[],int n_hora){

    int n = 0;

    ifstream base;
    base.open("base.txt");


    while(n < n_mate){

        base>>codigos[n];
        base>>h_estudio[n];

        n++;
    }

    base.close();

    ifstream estudio;
    estudio.open("horasestudio.txt");

    n = 0;

    while(n < n_hora){

        estudio>>h_program[n];
        n++;
    }

    estudio.close();





}

void menuprincipal(int &menu){

    cout<<"____________________________________________________________________________________________________________________________\n";
    cout<<"\nMENU PRINCIPAL\n";
    cout<<"\n1.Ver horario\n2.Programar horas de estudio\n3.Gestion de materias\n4.Terminar semestre\n5.Salir\n\nSelecciona:";
    cin>>menu;


}

void imprimir(int n_mate,int codigos[],int n_hora,int h_program[]){

    cout<<"____________________________________________________________________________________________________________________________\n";
    cout<<"                                                 TU HORARIO                                                                  \n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
    cout<<" Hora|       Lunes    |    Martes      |    Miercoles   |     Jueves     |     Viernes    |    Sabado      |     Domingo   |\n";
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

                for (int m = 0; m < n_mate; m++){

                    if (valor == codigos[m]){

                        int x = 0;

                        for (int t = 0; t < n_hora; t++) {

                            if (posicion == h_program[t]){

                                cout<<"*";
                                x++;

                            }

                        }

                        nombremateria(m,x);

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
    cout<<"*Horas de estudio personal\n";
     cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";
}

void agregarmateria(int &codigo,int codigos[],int n_mate,int &h_clase){

    int credito = 0;
    int htp = 0;
    bool verificar = true;

    char nombre[15]={};

    ofstream base;
    base.open("base.txt",ios::app);

    ofstream materia;
    materia.open("materia.txt",ios::app);

    ofstream general;
    general.open("general.txt",ios::app);



    while(verificar){

        verificar = false;
        cout<<"Codigo : ";cin>>codigo;

        for (int t = 0; t < n_mate;t++){

            if (codigo == codigos[t]){
                verificar = true;
                break;
            }
        }

        if (verificar){
            cout<<"\nEsta materia ya esta registrada!\n";
        }

    }


    cout<<"Materia: ";
    cin>>nombre;

    cout<<"Creditos : ";cin>>credito;
    cout<<"Horas de clase a la semana: ";cin>>h_clase;


    base<<codigo<< " ";
    materia<<nombre<<'\n';
    general<<codigo<<" "<<nombre<<" "<<credito<<" "<<h_clase<<" ";

    htp = (credito*48)/16-h_clase;

    if (htp > 1){

        base<<htp<<'\n';
        general<<htp<<'\n';
    }

    else{

        base<<1<<'\n';
        general<<1<<'\n';
    }



    base.close();
    materia.close();
    general.close();
}

void modificarhorario(int codigo,int &resta,int menu){

    int hora_ini = 6;
    int hora_fin = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;

    int n_hora = 0;
    int posicion = 1;
    int pos_modif = 0;

    verifica(n_hora,pos_modif);

    ofstream auxtxt;
    auxtxt.open("aux.txt");

    ofstream estudio;
    estudio.open("horasestudio.txt",ios::app);

    ifstream horariotxt;
    horariotxt.open("horario.txt");


    resta = n_hora;

    if (menu == 2){

      estudio<<pos_modif<<"\n";

    }



    while (hora_ini <= hora_fin){

        while (dia < n_dias){

            horariotxt >> valor;

            if (posicion == pos_modif){

                auxtxt<<codigo;

                if (n_hora > 1){

                    pos_modif += n_dias;
                    n_hora--;

                    if (menu == 2){

                      estudio<<pos_modif<<"\n";
                    }

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
    estudio.close();
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

void infoestudio(int h_estudio[],int n_mate,int &total){

    total = 0;

    for(int j = 0; j < n_mate; j++){

        total += h_estudio[j];

    }

    if (total <= 0){

        cout<<"No tienes horas de estudio por programar: \n\n";
    }

    else{

        cout<<"Tienes un total de "<<total<<" horas de estudio por programar: \n\n";

        for(int j = 0; j < n_mate; j++){

            if (h_estudio[j] > 0){

                cout<<j<<".";
                nombremateria(j,0);
                cout<<"Debes programar "<<h_estudio[j]<<" horas\n";

            }
        }
    }
}

void actualizarbase(int codigos[],int h_estudio[],int n_mate){

    ofstream base;
    base.open("base.txt");

    for (int i = 0; i < n_mate; i++) {

        base<<codigos[i]<<" ";
        base<<h_estudio[i]<<'\n';

    }

    base.close();

}

#endif // FUNCIONES_H
