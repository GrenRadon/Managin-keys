#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "CuentaUsuario.h"
#include<locale.h>
#include <wchar.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(_unix_)||defined(__unix)||defined(_APPLE_)||defined(_MACH_)
#define CLEAR "clear"
#else
#error "S.O no soportado para la limpieza de pantalla"
#endif



using namespace std;

void menu(CuentaUsuario *a);

int main()
{
    setlocale(LC_CTYPE, "");

    CuentaUsuario usuario;
    //variables locales
    int dd,mm,yy;


    wcout << L"\n\n***Bienvenido al sistema automático de creación de cuentas*** ";
    wcout << L"\n\n\nPor favor, digite el nombre: ";
    wcin.getline(usuario.Nombre,sizeof(usuario.Nombre)/sizeof(wchar_t));
    wcout << L"\nPor favor, digite el apellido paterno: ";
    wcin.getline(usuario.ApellidoPaterno,sizeof(usuario.ApellidoPaterno)/sizeof(wchar_t));
    wcout << L"\nPor favor, digite el apellido materno: ";
    wcin.getline(usuario.ApellidoMaterno,sizeof(usuario.ApellidoMaterno)/sizeof(wchar_t));
    wcout << L"\nPor favor, digite el departamento: ";
    wcin.getline(usuario.Departamento,sizeof(usuario.Departamento)/sizeof(wchar_t));

    wcout<<L"\n\nFormato de fecha: (dd,mm,yyyy)";
    wcout<<L"\n Por favor, digite el día: ";
    wcin>>dd;
    wcout<<L"\n Por favor, digite el mes: ";
    wcin>>mm;
    wcout<<L"\n Por favor, digite el año: ";
    wcin>>yy;

    usuario.setDate(dd,mm,yy);



    //creaciónn de puntero a objeto usuario
    CuentaUsuario *Pointer_usuario;
    Pointer_usuario=&usuario;
    menu(Pointer_usuario);


    system(CLEAR);
    return 0;
}

void menu(CuentaUsuario *a){

//Sección menu.

    int answer=0;
    do{


        wcout<<"|---------------------------------------------------------|\n";
        wcout<<"|---------------------------------------------------------|\n";
        wcout<<"|------------      MENU  de  Examen de C++         -------|\n";
        wcout<<"|---------------------------------------------------------|\n";
        wcout<<"|- 1. Obtener clave                                    ---|\n";
        wcout<<"|- 2. Modificar nombre y apellidos                     ---|\n";
        wcout<<"|- 3. Modificar fecha de nacimiento                    ---|\n";
        wcout<<"|- 4. Obtener nombre completo                          ---|\n";
        wcout<<"|- 5. Obtener departamento                             ---|\n";
        wcout<<"|- 6. Obtener edad aproximada                          ---|\n";
        wcout<<"|- 7. Mostrar todos los datos                          ---|\n";
        wcout<<"|- 8. Salir                                            --|\n";
        wcout<<"|---------------------------------------------------------|\n";
        wcout<<"|-Ingrese una opcion          -|\n";
        wcout<<"|-";
        fflush(stdin);
        wcin>>(answer);


        switch(answer)
        {
            case 1:
                system(CLEAR);
                a->AsignarClave(a);
                system(CLEAR);
                break;

            case 2:
                system(CLEAR);
                a->Mod_NombreApellidos(a);
                a->AsignarClave(a);
                system(CLEAR);
                break;


            case 3:
                system(CLEAR);
                a->Mod_FechaNacimiento(a);
                a->AsignarClave(a);
                system(CLEAR);
                break;

            case 4:
                system(CLEAR);
                a->Get_FullName(a);
                system(CLEAR);


                break;

            case 5:

                system(CLEAR);
                a->Get_Departament(a);
                system(CLEAR);


                break;

            case 6:
                system(CLEAR);
                a->Get_DatesDifference(a);
                system(CLEAR);

                break;

            case 7:
                system(CLEAR);
                a->MostrarDatos(a);
                system(CLEAR);
                break;

            case 8:
                break;

            default:

                printf("Error! Opcion no valida");
                break;

        }
    }while (answer!=8);
}







