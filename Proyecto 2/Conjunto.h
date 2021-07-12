#ifndef CONJUNTO_H
#define CONJUNTO_H


template <class A_Type, class B_type, class C_type> class Conjunto
{
    A_Type a;
    B_type b;
    C_type c;
    public:
        Conjunto(A_type x, B_Type y);
        Conjunto(A_type x, B_Type y, C_Type z);
        virtual ~Conjunto();
        void VisualizationFunction_2(A_Type x, A_Type y);



    protected:

    private:
};
//Funciones de visualización
template <class A_Type, class B_type, class C_type> void Conjunto<A_Type, B_type, C_Type>::VisualizationFunction_2(A_Type x,A_Type y)
{
  return x*y;
}



#endif // CONJUNTO_H
