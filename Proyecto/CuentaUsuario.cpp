#include "CuentaUsuario.h"

//posibles soluciones -------------------------------------------
/*Declaración de variables string(para convertir char a string)
    string s1 = "";
    string s2 = "";
    //Definicion de tamaños
    int s_size=sizeof(b->Departamento) / sizeof(char);
    int s2_size=sizeof(condi1) / sizeof(char);
    */

    /*//Conversiones a string
    for (int i = 0; i < s_size; i++) {
        s1 = s1 + b->Departamento[i];
    }
    for (int i = 0; i < s_size; i++) {
        s2 = s2 + condi1[i];
    }*/

    //cin.getline(usuario.ApellidoPaterno,30);
//Cierre de posibles soluciones ------------------------------------

//Para averiguar el tipo de una variable en c++ typeid(aquí va el nombre de la variable).name()

CuentaUsuario::CuentaUsuario()
{
    dd=mm=yy=0;
}

CuentaUsuario::~CuentaUsuario()
{
    //dtor
}

//Setters definition
void CuentaUsuario::setDate(unsigned int i, unsigned int j, unsigned int k){
            dd = i;
            mm = j;
            yy = k;
}

//Getters definition

unsigned int CuentaUsuario::getDay() {
    return dd;
}
unsigned int CuentaUsuario::getMonth() {
    return mm;
}
unsigned int CuentaUsuario::getYear(){
    return yy;
}


//Functions definition
void CuentaUsuario::pausa()
{
    std::wcout<<L"\n\nPresiona Enter para continuar..."<< std::endl;
    system("read REPLY");
    //En caso de ser el sistema operativo de windows, borrar anterior línea y dejar la de abajo
    //system("pause");

}


void CuentaUsuario::AsignarClave(CuentaUsuario *b){

    //Comparador 1
    wchar_t condi1[30]= {'E', 'L', 'E', 'C', 'T', 'R', 'I', 'C', 'A', ' ', '(', 'I', 'E', ')'};
    //Comparador 1
    wchar_t condi2[30]= { 'C', 'O', 'N', 'T', 'R', 'O', 'L', ' ', '(', 'I', 'C', ')'};
  //Comparador 3
    wchar_t condi3[30]= { 'A', 'U', 'T', 'O', 'M', 'O', 'T', 'R', 'I', 'Z', ' ', '(', 'I', 'A', ')'};

    wchar_t NumDaysMonths[2];
    wchar_t NumYears[4];
    int NumDaysMonths_size=sizeof(NumDaysMonths)/sizeof(wchar_t);
    int NumYears_size=sizeof(NumYears)/sizeof(wchar_t);



    if(wcscasecmp(b->Departamento,condi1)==0){

        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){

            if(i<4){
                b->clave[i]=b->ApellidoPaterno[i];
            }
            else if(i==4){
                b->clave[i]=L'_';
            }
            else if(i<7 && i>4){
                b->clave[i]=b->Nombre[i-5];
            }
            else{

                swprintf(NumDaysMonths,NumDaysMonths_size+1, L"%d", b->getDay());
                b->clave[i]=NumDaysMonths[i-7];
            }
        }
        wcout<<L"\nClave Asignada: ";
        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){
            wcout<<b->clave[i];
        }
        b->pausa();
    }

    else if(wcscasecmp(b->Departamento,condi2)==0){

        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){
            if(i<3){
                if(i==0){
                    b->clave[i]=L'I';
                }
                if(i==1){
                    b->clave[i]=L'C';
                }
                if(i==2){
                    b->clave[i]=L'_';
                }
            }
            else if(i<7 && i>2){
                b->clave[i]=b->ApellidoPaterno[i-3];
            }
            else{
                swprintf(NumDaysMonths,NumDaysMonths_size+1, L"%d", b->getMonth());//ASIGNANDO un entero a un char
                b->clave[i]=NumDaysMonths[i-7];
            }
        }
        wcout<<L"\nClave Asignada: ";
        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){
            wcout<<b->clave[i];
        }
        b->pausa();
    }

    else if(wcscasecmp(b->Departamento,condi3)==0){

        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){

                if(i<3){
                    if(i==0){
                        b->clave[i]=L'I';
                    }
                    if(i==1){
                        b->clave[i]=L'A';
                    }
                    if(i==2){
                        b->clave[i]=L'_';
                    }
                }
                else if(i<7 && i>2){
                    b->clave[i]=b->ApellidoMaterno[i-3];
                }
                else{
                    swprintf(NumYears, NumYears_size+1, L"%d", b->getYear());//ASIGNANDO un entero a un char
                    b->clave[i]=NumYears[i-5];
                }
            }

        wcout<<L"\nClave Asignada: ";
        for(int i=0;i<sizeof(b->clave)/sizeof(wchar_t);i++){
            wcout<<b->clave[i];
        }
        b->pausa();


    }
    else{

        //reinitializing department
        for(int i=0;i<sizeof(b->Departamento)/sizeof(wchar_t);i++){
            b->Departamento[i] = '\0';
        }
        wcin.ignore();
        wcout<<L"Departamento invalido, digite nuevamente el departamento: ";
        wcin.getline(b->Departamento,sizeof(b->Departamento)/sizeof(wchar_t));
        wcout<<L"\n¡Departamento modificado satisfactoriamente!";
        b->pausa();
        b->AsignarClave(b);
    }

    wcout<<"\n";

}

void CuentaUsuario::Mod_NombreApellidos(CuentaUsuario *d){


    //reinitializing all elements of name, father's name and mother's name
    for(int i=0;i<sizeof(d->Nombre)/sizeof(wchar_t);i++){
        d->Nombre[i] = '\0';
    }
    for(int i=0;i<sizeof(d->ApellidoPaterno)/sizeof(wchar_t);i++){
        d->ApellidoPaterno[i] = '\0';
    }
    for(int i=0;i<sizeof(d->ApellidoMaterno)/sizeof(wchar_t);i++){
        d->ApellidoMaterno[i] = '\0';
    }

    wcin.ignore();

    //Asigning new values
    wcout << "Por favor, digite el nuevo nombre: ";
    wcin.getline(d->Nombre,sizeof(d->Nombre)/sizeof(wchar_t));
    wcout << "\n\nPor favor, digite el nuevo apellido paterno: ";
    wcin.getline(d->ApellidoPaterno,sizeof(d->ApellidoPaterno)/sizeof(wchar_t));
    wcout << "\n\nPor favor, digite el nuevo apellido materno: ";
    wcin.getline(d->ApellidoMaterno,sizeof(d->ApellidoMaterno)/sizeof(wchar_t));

    wcout<<L"\n\nModificación Exitosa de nombres y apellidos";
    d->pausa();

}

void CuentaUsuario::Mod_FechaNacimiento(CuentaUsuario *e){

    int dd,mm,yy;
    wcout<<L"\n\nFormato de fecha: (dd,mm,yyyy)";
    wcout<<L"\n Por favor, digite el día: ";
    wcin>>dd;
    wcout<<L"\n Por favor, digite el mes: ";
    wcin>>mm;
    wcout<<L"\n Por favor, digite el año: ";
    wcin>>yy;
    e->setDate(dd,mm,yy);
    wcout<<L"\n\nModificación Exitosa\n";
    e->pausa();

}

void CuentaUsuario::Get_FullName(CuentaUsuario *f){

   wcout<<L"Nombre completo del usuario: "<<f->Nombre<<" "<<f->ApellidoPaterno<<" "<<f->ApellidoMaterno;
   f->pausa();

}

void CuentaUsuario::Get_Departament(CuentaUsuario *g){

   wcout<<L"El departamento es: "<<g->Departamento;
   g->pausa();

}


void CuentaUsuario::Get_DatesDifference(CuentaUsuario *h){



static int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };

int daysInc = 0;
if (23 - h->getDay() < 0)
{
    int month = 23 - 2; // -1 from zero, -1 previous month.
    if (month < 0)
        month = 11; // Previous month is December.
    daysInc = increment[month];
    if ( (month == 1) && (23%4 == 0) )
        daysInc++; // Increment days for leap year.
}

int total1 = h->getYear()*360 + h->getMonth()*30 + h->getDay();
int total2 = 2017*360 + 2*30 + 23;
int diff = total2 - total1;
int years = diff/360;
int months = (diff - years*360)/30;
int days = diff - years*360 - months*30 + daysInc;

// Extra calculation when we can pass one month instead of 30 days.
if (h->getDay() == 1 && 23 == 31) {
    months--;
    days = 30;
}

if(years<0){
    years*=-1;
}
if(months<0){
    months*=-1;
}
if(days<0){
    days*=-1;
}
wcout<<"La edad aproximada del usuario respecto a la fecha 23/feb/2017 es: "<<years<<"/"<<months<<"/"<<days<<std::endl;
h->pausa();

}

void CuentaUsuario::MostrarDatos(CuentaUsuario *c){

    wcout<<L"Nombre: "<<c->Nombre;
    wcout<<L"\nApellido Paterno: "<<c->ApellidoPaterno;
    wcout<<L"\nApellido Materno: "<<c->ApellidoMaterno;
    wcout<<L"\nDia : "<<c->getDay();
    wcout<<L"\nMes : "<<c->getMonth();
    wcout<<L"\nAño : "<<c->getYear();
    wcout<<L"\nDepartamento: "<<c->Departamento;

    wcout<<L"\nSu clave es: ";
    for(int i=0;i<sizeof(c->clave)/sizeof(wchar_t);i++){
        wcout<<c->clave[i];
    }
    wcout<<"\n\n";
    c->pausa();

}
