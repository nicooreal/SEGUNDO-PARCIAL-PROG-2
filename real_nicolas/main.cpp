#include <iostream>
#include <cstring>
using namespace std;
#include "clasesp2.h"


bool modificarArchivo(Programador prog, int pos)
{
    FILE* p;
    p = fopen("programadores.dat", "rb+");
    if (p==NULL) return false;
    fseek(p, sizeof(Programador)* pos, 0);
    bool grabo = fwrite(&prog, sizeof(Programador), 1, p);
    fclose(p);
    return grabo;



}



class Punto1
{
private:
    int _numero;
    int _legajoProgramador;
    int _codigoProyecto;
    int _localidad;
    bool _estado;
public:

   void mostrar(){
   cout <<_numero<< endl;
    cout <<_legajoProgramador<< endl;
      cout <<_codigoProyecto<< endl;
      cout <<_localidad<< endl;
      cout <<_estado<< endl;
   }



       int leerDeDisco(int pos){
        FILE *p;
        p=fopen("punto1", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }



    int setNumero(int num)
    {
        _numero = num;
    }

    int setLegajoProgramador(int legajoProg )
    {
        _legajoProgramador = legajoProg;
    }


    int setCodigoDelProyecto(int codProyecto)
    {
        _codigoProyecto = codProyecto;
    }


    int setLocalidad( int localidad)
    {
        _localidad = localidad;
    }

    bool setEstado(bool estado)
    {

        _estado = estado;

    }




    int grabarEnDisco()
    {
        FILE* p;
        p = fopen("punto1", "ab");
        if (p == NULL) return -1;
        int grabo = fwrite(this, sizeof (Punto1), 1, p);
        fclose(p);
        return grabo;
    }



        bool operator == (int codigo){
        if(_codigoProyecto == codigo) return true;
        return false;
        }


/*



void punto3(){
    cout<<"Dentro de la clase Punto1 se sobrecarg� el operador '==' de la siguiente manera"<<endl<<endl;
    cout<<"bool operator==(int codigo){\nif(codigo==_codigoProyecto){\n\treturn true;\n}\nelse{\n\treturn false;\n}"<<endl<<endl;

 //if ( asig.getFechaAsignacion().getAnio() == 2021  && asig.getCodigoProyecto() == codigoDelProyecto  && asig.getEstado() == true  )
*/



};

void primerEjercicio1()
{
    /*Crear un archivo con las asignaciones realizadas para el proyecto Gesti�n de producci�n TM en el a�o 2021.
     El archivo debe tener el mismo formato que el archivo de asignaciones, pero sin la fecha.
    */

    int i = 0;
    int j = 0;
    int codigoDelProyecto;
    Proyecto proy;
    Asignacion asig;
    Punto1 punto1;
    while (proy.leerDeDisco(i) == 1 )
    {
        if ( strcmp(proy.getDescripcion(), "Gestion de produccion TM" ) == 0  &&  proy.getEstado() == true)
        {
            codigoDelProyecto = proy.getCodigo();
            break;

        }

        i++;
    }

    while (asig.leerDeDisco(j) == 1 )
    {
        if ( asig.getFechaAsignacion().getAnio() == 2021  && asig.getCodigoProyecto() == codigoDelProyecto  && asig.getEstado() == true  )
        {


            punto1.setNumero(asig.getNumero());
            punto1.setLegajoProgramador ( asig.getLegajoProgramador());
            punto1.setCodigoDelProyecto( asig.getCodigoProyecto());
            punto1.setLocalidad (asig.getLocalidad());
            punto1.setEstado (asig.getEstado());


            punto1.grabarEnDisco();

        }


        j++;

    }


int x = 0;

   while (punto1.leerDeDisco(x) == 1 ) {

cout <<"x"<< endl;

    punto1.mostrar();
    cout << endl<< endl;
  x++;
    }


}

void segundoEjercicio()
{
    /*
    Modificar el archivo de programadores, subiendo 1 cargo a los programadores
    que ingresaron en el a�o 2015 (por ejemplo, si ten�a cargo 5, debe pasar al 4).
    Listar el archivo modificado.*/

    Programador prog;
    int i = 0;
    int j = 0;
    while ( prog.leerDeDisco(i) == 1)
    {

        if (prog.getFechaIngreso().getAnio() == 2015   && prog.getActivo() == true  )
        {
            prog.setCargo( prog.getCargo() - 1 );

            modificarArchivo(prog,i);


        }

        i++;
    }

//Crear un vector din�mico para copiar y mostrar el archivo luego de las modificaciones del punto 2.       PUNTO 4 !!!

    int tam = 0;
    j = 0;
    Programador *punteroProg;
    punteroProg = new Programador[tam];
if ( punteroProg == NULL    ) { cout <<"no se pudo abrir ";}

    while (prog.leerDeDisco(j) == 1  )
    {

        if ( prog.getActivo() == true )
        {

            punteroProg[tam] = prog;
            tam++;
        }

       j++;
    }


for (int x = 0; x < tam; x++){


punteroProg[x].Mostrar();

cout <<1;

}

delete []punteroProg;

/*


    while (prog.leerDeDisco(j) == 1  )
    {
        if ( prog.getActivo() == true )
        {
            prog.Mostrar();
        }
        j++;
    }


}


*/



}







                if  (reserva.leerDeDisco(j+1) == false  )
                {
                    puntoa.setCodigo(   restau.getCodigoRestaurante()    ) ;
                    puntoa.setNombreRestaurante(   restau.getNombre()  ) ;
                    puntoa.setCantidadDeReservas( contadorDeReservas2021 );

                    puntoa.grabarEnDisco();

                }






int main()
{

    primerEjercicio1();
    /*Modificar el archivo de programadores, subiendo 1 cargo a los programadores que ingresaron en el a�o 2015 (por ejemplo,
     si ten�a cargo 5, debe pasar al 4).
    Listar el archivo modificado.*/


  // segundoEjercicio();
    /*
    Modificar el archivo de programadores, subiendo 1 cargo a los programadores que ingresaron en el a�o 2015 (por ejemplo, si ten�a cargo 5, debe pasar al 4).

    Listar el archivo modificado.*/



    return 0;
}





puntoA *pr;
int contadorDeRestaurantes;
int i = 0;

 while (res.leerDeDisco(i) == true) {
    contadorDeRestaurantes++;

    i++;
    }




pr = new puntoA[contadorDeRestaurantes];
if ( pr == NULL ) {return;}
