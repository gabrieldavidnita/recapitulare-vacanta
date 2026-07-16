#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
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
int valMax(int v[], int n)
{
    int mx=v[0];
    for(int i=1 ; i<n; i++)
    {
       if(v[i]>mx)
       {
           mx=v[i];
       }
    }
    return mx;
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

void frecventaNumarVector(int v[], int n , int f[])
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

void frecventaCifraVector(int v[], int n, int f[])
{
     for(int i = 0 ; i<n; i++)
     {
          int aux=v[i];
           while(aux>0)
             {
                 int uc  = aux%10;
                 f[uc]++;
                 aux=aux/10;
             }
     }
}
int cifMinNumar(int n )
{
    int mini=9;
    while(n!=0)
    {
        int uc=n%10;
        if(uc<mini)
        {
            mini=uc;
        }
        n=n/10;
    }
    return mini;
}

int cifMinVector(int v[], int n )
{
    int cifmin=cifMinNumar(v[0]);
    for(int i=1;i<n; i++)
    {
        if(cifMinNumar(v[i])<cifmin)
        {
            cifmin=cifMinNumar(v[i]);
        }
    }
    return cifmin;
}
int cifMaxNumar(int n)
{
    int maxi=-1;
    while(n!=0)
    {
        int uc=n%10;
        if(uc>maxi)
        {
            maxi=uc;
        }
        n=n/10;
    }
    return maxi;
}

int cifMaxVector(int v[], int n )
{
    int cifmax=cifMaxNumar(v[0]);
    for(int i =1; i<n; i++)
    {
        if(cifMaxNumar(v[i])>cifmax)
        {
            cifmax=cifMaxNumar(v[i]);
        }
    }
    return cifmax;
}

//functie ce returneaza pozitia maximului in vector
//functie ce returneaza pozitia minimului in vector

int pozMin(int v[], int n )
{
    int p=0;
    for(int i =1; i<n; i++)
    {
        if(v[i]<v[p])
        {
            p=i;
        }
    }
    return p;
}

int pozMax(int v[], int n )
{
    int p=0;
    for(int i =1; i<n; i++)
    {
        if(v[i]>v[p])
        {
            p=i;
        }
    }
    return p;
}


int contorCif(int n , int c)
{
    int nr=0;
    while(n!=0)
    {
        if(n%10==c)
        {
            nr++;
        }
        n=n/10;
    }
    return nr;
}


int frecventaMinimului(int v[], int pmin, int pmax, int mn)
{
    if(pmin>pmax)
    {
        int aux=pmin;
        pmin=pmax;
        pmax=aux;

    }
    int nr=0;
    for(int i=pmin; i<=pmax;i++)
    {
        if(v[i]==mn)
        {
            nr++;
        }
    }
    return nr;
}

bool inCif(int n , int c)
{
    int ok=0;
    while(n!=0)
    {
        int uc=n%10;
        if(uc==c)
        {
            ok=1;
        }
         n=n/10;
    }
    return ok;
}


#endif // FUNCTII_H_INCLUDED
