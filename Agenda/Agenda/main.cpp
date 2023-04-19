#include <iostream>
#include <fstream>

using namespace std;

void nombremateria(char materias[][15],int m,int x){

    int i = 0;

    while (materias[m][i] != '\0'){

        i++;
    }

    i += x;

    cout<<" "<<materias[m];

    while(i < 15){

        cout<<" ";
        i++;
    }

    cout<<"|";


}

void contar(int &n_mate, int &n_hora){


    char linea[30] = {};
    n_mate = 0;
    n_hora = 0;

    ifstream base;
    base.open("base.txt");

    while(base.getline(linea,30)){

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

void leerbase(int codigos[],int h_estudio[],char materias[][15],int n_mate,int h_program[],int n_hora){

    int n = 0;

    ifstream base;
    base.open("base.txt");


    while(n < n_mate){

        base>>codigos[n];
        base>>materias[n];
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

    cout<<"\nMENU PRINCIPAL\n";
    cout<<"\n1.Ver horario\n2.Programar horas de estudio\n3.Agregar materia al horario\n4.Salir\n\nSelecciona:";
    cin>>menu;
    cout<<"__________________________________________________\n";


}

void imprimir(int n_mate,int codigos[],char materias[][15],int n_hora,int h_program[]){

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

                for (int m = 0; m < n_mate; m++){

                    if (valor == codigos[m]){

                        int x = 0;

                        for (int t = 0; t < n_hora; t++) {

                            if (posicion == h_program[t]){

                                cout<<"*";
                                x++;

                            }

                        }

                        nombremateria(materias,m,x);

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

void agregarmateria(int &codigo){

    char nombre[15];
    int credito = 0;
    int h_clase = 0;

    ofstream base;
    base.open("base.txt",ios::app);


    cout<<"Codigo : ";cin>>codigo;
    cout<<"Materia: ";cin>>nombre;
    cout<<"Creditos : ";cin>>credito;
    cout<<"Horas de clase a la semana: ";cin>>h_clase;

    base<<codigo<< " ";
    base<<nombre<<" ";
    base<<((credito*48)/16-h_clase);

    base.close();

}

void modificarhorario(int codigo,int &resta,int menu){

    ifstream horariotxt;
    horariotxt.open("horario.txt");

    ofstream auxtxt;
    auxtxt.open("aux.txt");

    ofstream estudio;
    estudio.open("horasestudio.txt",ios::app);

    int hora_ini = 6;
    int hora_fin = 22;
    int dia = 0;
    int valor = 0;
    int n_dias = 7;

    int hora_modif = 0;
    int dia_modif = 0;
    int n_hora = 0;


    cout<<"Que dia estudiaras esta materia? \n";
    cout<<"1.Lunes  2.Martes   3.Miercoles   4.Jueves   5.Viernes  6.Sabado  7.Domingo\n Selecciona: ";cin>>dia_modif;
    cout<<"\nA que hora?(6:00-22:00): ";cin>>hora_modif;
    cout<<"\nCuantas horas?: ";cin>> n_hora;

    resta = n_hora;


    int pos_modif = ((hora_modif - hora_ini)*n_dias)+dia_modif;

    if (menu == 2){

      estudio<<pos_modif<<"\n";

    }

    int posicion = 1;


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

void infoestudio(int h_estudio[],int n_mate,char materias[][15]){

    int total = 0;

    for(int j = 0; j < n_mate; j++){

        total += h_estudio[j];

    }

    cout<<"Tienes un total de "<<total<<" horas de estudio por programar: \n\n";

    for(int j = 0; j < n_mate; j++){

        if (h_estudio[j] > 0){

            cout<<j<<".";
            nombremateria(materias,j,0);
            cout<<"Debes programar "<<h_estudio[j]<<" horas\n";

        }
    }

}

void actualizarbase(int codigos[],int h_estudio[],char materias[][15],int n_mate){

    ofstream base;
    base.open("base.txt");

    for (int i = 0; i < n_mate; i++) {

        base<<codigos[i]<<" ";
        base<<materias[i]<<" ";
        base<<h_estudio[i]<<'\n';

    }

    base.close();

}

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
        char materias[n_mate][15] = {};
        int h_program[n_hora] = {};

        leerbase(codigos,h_estudio,materias,n_mate,h_program,n_hora);

        menuprincipal(menu);

        if (menu == 1){

            imprimir(n_mate,codigos,materias,n_hora,h_program);

        }

        if (menu == 2){


            while (repetir == 's'){


                imprimir(n_mate,codigos,materias,n_hora,h_program);

                infoestudio(h_estudio,n_mate,materias);

                cout<<"Selecciona: ";cin>>opcion;

                codigo = codigos[opcion];

                modificarhorario(codigo,resta,menu);

                h_estudio[opcion] = h_estudio[opcion] - resta;

                actualizarhorario();

                cout<< "Quieres programar mas horas de estudio?(s/n):  ";cin>>repetir;


            }

            actualizarbase(codigos,h_estudio,materias,n_mate);
            repetir = 's';

        }


        if (menu == 3){

            agregarmateria(codigo);

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


}


