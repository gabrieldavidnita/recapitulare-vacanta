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
    for(int i=1 ; i<n; i++)
    {
       if(v[i]<mn)
       {
           mn=v[i];
       }
    }
    return mn;
}

int nrAp(int v[], int n , int mn)
{
    int nr=0;
    for(int  i=0; i<n; i++)
    {
        if(v[i]==mn)
        {
            nr++;
        }
    }
    return nr;
}

void frecventa(int v[], int n , int f[])
{
    for(int i = 0 ; i <9999; i++)
    {
        f[i]=0;
    }
    for(int i = 0 ; i < n ; i++)
    {
        f[v[i]]++;
    }
}

int valMinima(int f[])
{
    for(int i=0; i<=9999 ; i++)
    {
        if(f[i]!=0)
        {
            return i;
        }
    }
}
#endif // FISIER_H_INCLUDED
