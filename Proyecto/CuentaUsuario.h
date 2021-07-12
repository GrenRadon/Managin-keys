//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(_unix_)||defined(__unix)||defined(_APPLE_)||defined(_MACH_)
#define CLEAR "clear"
#else
#error "S.O no soportado para la limpieza de pantalla"
#endif



#ifndef CUENTAUSUARIO_H
#define CUENTAUSUARIO_H

//includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include <wchar.h>


using namespace std;

class CuentaUsuario
{

    public:
        //Constructor
        CuentaUsuario();

        //Destructor
        virtual ~CuentaUsuario();

        //Functions
        void Mod_NombreApellidos(CuentaUsuario *d);
        void AsignarClave(CuentaUsuario *b);
        void Mod_FechaNacimiento(CuentaUsuario *e);
        void Get_FullName(CuentaUsuario *f);
        void Get_Departament(CuentaUsuario *g);
        void Get_DatesDifference(CuentaUsuario *h);
        void MostrarDatos(CuentaUsuario *c);
        void pausa();

        //Setters
        void setDate(unsigned int i, unsigned int j, unsigned int k);

        //Getters
        unsigned int getDay();
        unsigned int getMonth();
        unsigned int getYear();


        //Member class attributes
        wchar_t Nombre[30];
        wchar_t ApellidoPaterno[30];
        wchar_t ApellidoMaterno[30];
        wchar_t Departamento[30];
        wchar_t clave[9];



        //void AsignacionClave();

    protected:


    private:
        short int dd, mm, yy;

};

#endif // CUENTAUSUARIO_H
