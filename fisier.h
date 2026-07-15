#ifndef FISIER_H_INCLUDED
#define FISIER_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

void citireVector(int v[], int&dim)
{
    ifstream read("data.txt");
    read>>dim;
    for(int i=0; i<dim; i++)
    {
        read>>v[i];
    }
}

void afisareVector(int v[], int dim)

{
    for(int i=0; i<dim ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int valMin(int v[], int n)
{
    int mn=v[0];
    for(int i = 1 ; i<n; i++)
    {
}
}
#endif // FISIER_H_INCLUDED
