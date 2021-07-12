#include <iostream>
#include "Conjunto.h"

using namespace std;

int main()
{
    char decision;
    cout << "***Bienvenido al template de la clase conjunto" << endl;
    cout <<"Desea manejar un conjunto con 2 o 3 elementos?: "<<endl;
    getline(cin, decision);
    if(decision=='1'){
    //objetos con el constructor de 2 argumentos
        Conjunto <float, int> test1;
        Conjunto <float, char> test2;
        float tmp1,tmp2;
        int tmp3;
        char tmp4;

        //sección de lectura
        cout<<"Por favor, digite el primer elemento de tipo float: "<<endl;
        getline(cin, tmp1);
        cout<<"Por favor, digite el segundo elemento de tipo int: "<<endl;
        getline(cin, tmp3);

        cout<<"\n\nCambiando de panorama, ahora vamos a asignar dependiendo de un nuevo tipo de variables...";
        cout<<"Por favor, digite el primer elemento de tipo float: "<<endl;
        getline(cin, tmp1);
        cout<<"Por favor, digite el segundo elemento de tipo char: "<<endl;
        getline(cin, tmp1);

        //Seccion de asignación
        test1.Conjunto(tmp1,tmp3);
        test2.Conjunto(tmp2,tmp4);

        //sección de visualización


    }
    else if(decision=='2'){


        //objetos con el constructor de 2 argumentos
        Conjunto <float, int, float> test1;
        Conjunto <float, char, char> test2;
        float tmp1,tmp2,tmp3;
        int tmp4;
        char tmp5,tmp6

        //Sección de lectura
        cout<<"Por favor, digite el primer elemento de tipo float: "<<endl;
        getline(cin, tmp1);
        cout<<"Por favor, digite el segundo elemento de tipo int: "<<endl;
        getline(cin, tmp4);
        cout<<"Por favor, digite el tercer elemento de tipo float: "<<endl;
        getline(cin, tmp2);

        cout<<"\n\nCambiando de panorama, ahora vamos a asignar dependiendo de un nuevo tipo de variables...";
        cout<<"Por favor, digite el primer elemento de tipo float: "<<endl;
        getline(cin, tmp3);
        cout<<"Por favor, digite el segundo elemento de tipo char: "<<endl;
        getline(cin, tmp5);
        cout<<"Por favor, digite el tercer elemento de tipo char: "<<endl;
        getline(cin, tmp6);

        //sección de asignación
        test1.Conjunto(tmp1,tmp4, tmp2);
        test2.Conjunto(tmp3,tmp5,tmp6);

        //Sección de visualizacón
        cout<<""
    }
    else {
        cout<<"Opcion no valida"
    }
    return 0;
}
