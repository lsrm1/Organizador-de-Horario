#include <iostream>
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

void leerbase(int codigos[],int h_clase[],int h_estudio[],int creditos[],int n_mate){

    int n = 0;

    ifstream base;
    base.open("base.txt");

    while(n < n_mate){

        base>>codigos[n];
        base>>h_clase[n];
        base>>h_estudio[n];
        base>>creditos[n];

        n++;
    }

    base.close();

}

void horario (int dia[],ifstream &horariotxt,int n_horas)
{
    int u = 0;
    while (u < n_horas)
    {
     horariotxt >> dia[u];
     u++;
    }

}

void nombre_mate (int line_materia,char nombre[])
{
    ifstream archivo;
    archivo.open("materia.txt");

    for (int t = 0; t <= line_materia; t++)
    {
        nombre [12] = {};
        archivo>>nombre;

    }
    archivo.close();

}

void imprimehora(int dia[],int hora,int codigos[], char nombre[],int n_mate)
{
    int line_materia = 0;

    if (dia[hora] != 0)
    {
        for (int line_materia = 0; line_materia < n_mate; line_materia++)
         {
            if (dia[hora] == codigos[line_materia])
            {
                nombre_mate(line_materia,nombre);
                cout<<"  ";
                cout<<nombre;
                cout<<"  |";
            }

        }

    }

    else
    {
        cout<<"     -     ";
        cout<<"|";
    }
}

void imprimehorario(int lunes[],int martes[],int miercole[],int jueves[],int viernes[],int sabado[],int domingo[],int codigos[],int n_horas,int n_mate){

    ifstream horariotxt;
    horariotxt.open("horario.txt");

    horario(lunes,horariotxt,n_horas);
    horario(martes,horariotxt,n_horas);
    horario(miercole,horariotxt,n_horas);
    horario(jueves,horariotxt,n_horas);
    horario(viernes,horariotxt,n_horas);
    horario(sabado,horariotxt,n_horas);
    horario(domingo,horariotxt,n_horas);

    horariotxt.close();


    cout<<"                                  TU HORARIO                                            \n";
    cout<<"------------------------------------------------------------------------------------------\n";
    cout<<" Hora|   Lunes   | Martes    | Miercoles |  Jueves   |  Viernes  | Sabado    | Domingo   |\n" ;
    cout<<"------------------------------------------------------------------------------------------\n";


    int hora = 0;
    int reloj = 6;


    while (hora < n_horas){

        char nombre [12] = {};

        if (reloj < 10 ){

         cout<<reloj<<":00 |";
        }
        else{
            cout<<reloj<<":00|";
        }

        imprimehora(lunes,hora,codigos,nombre,n_mate);
        imprimehora(martes,hora,codigos,nombre,n_mate);
        imprimehora(miercole,hora,codigos,nombre,n_mate);
        imprimehora(jueves,hora,codigos,nombre,n_mate);
        imprimehora(viernes,hora,codigos,nombre,n_mate);
        imprimehora(sabado,hora,codigos,nombre,n_mate);
        imprimehora(domingo,hora,codigos,nombre,n_mate);

        cout<<"\n";
        hora++;
        reloj++;

    }

    cout<<"------------------------------------------------------------------------------------------\n";

}


int main(){

    int n_mate = 0;
    int n_horas = 17;

    contarmater(n_mate);

    int codigos  [n_mate] = {};
    int h_clase  [n_mate] = {};
    int h_estudio[n_mate] = {};
    int creditos [n_mate] = {};

    int lunes   [n_horas] = {};
    int martes  [n_horas] = {};
    int miercole[n_horas] = {};
    int jueves  [n_horas] = {};
    int viernes [n_horas] = {};
    int sabado  [n_horas] = {};
    int domingo [n_horas] = {};

    leerbase(codigos,h_clase,h_estudio,creditos,n_mate);
    imprimehorario(lunes,martes,miercole,jueves,viernes,sabado,domingo,codigos,n_horas,n_mate);


    return 0;



}
