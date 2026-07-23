#ifndef FUNCTII-EXTE1_H_INCLUDED
#define FUNCTII-EXTE1_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;
//problema 1
void afisareVector(int v[], int dim)

{
    for(int i=0; i<dim ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void perecheSuma(int v[],int n,int S,int &pi,int &pj)
{
    pi=-1;
    pj=-1;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
              if(v[i]+v[j]==S)
            {
                pi=i;
                pj=j;
            }
        }
    }
}
//problema 2
int profitMaxim(int v[],int n)
{
    int minim=v[0];
    int profit=0;
    for(int i=1; i<n; i++)
    {
        if(v[i]-minim>profit)
        {
            profit=v[i]-minim;

        }
        if(v[i]<minim)
        {
            minim=v[i];
        }
    }
    return profit;
}

//3
void mutaZerouri(int v[],int n)
{
    int p=0;
    for(int i=0;i<n;i++)
        if(v[i]!=0)
        {
            v[p]=v[i];
            p++;
        }
    while(p<n)
    {
        v[p]=0;
        p++;
    }
}

//4
int maxUnuConsecutiv(int v[],int n)
{
    int nr=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            nr++;
            if(nr>maxi)
            {
                 maxi=nr;
            }
        }else
            nr=0;
    }
    return maxi;
}

//5
int stergereDubluri(int v[], int n )
{
    int k=1;
    for(int i=1; i<n; i++)
    {
        if(v[i]!=v[k-1])
        {
            v[k]=v[i];
            k++;
        }
    }
    return k;

}
//1 2 3 4 5 6 7
// 7 6 5 4 3 2 1
// 5 6 7 4 3 2 1
// 5674123

//6

int elementMajoritar(int v[], int n )
{
    for(int i=0; i<n; i++)
    {
        int nr=0;
        for(int j=0;j<n; j++)
        {
            if(v[i]==v[j])
            {
                nr++;
            }
        }
        if(nr>n/2)
        {
            return v[i];
        }
    }
    return -1;
}



//ex 7
void inversare(int v[], int st, int dr)
{
    while(st<dr)
    {
        int aux=v[st];
        v[st]=v[dr];
        v[dr]=aux;

        st++;
        dr--;
    }
}



void rotesteDreapta(int v[],int n , int k )
{
    k=k%n;
    inversare(v,0,n-1);
    inversare(v,0,k-1);
    inversare(v,k,n-1);
}

//8
void construiestePrefix(int v[],int n, long long p[])
{
    p[0]=0;
    for(int i =0;i<n;i++)
    {
        p[i+1]=p[i]+v[i];
    }
}

long long sumaInterval(long long p[],int st, int dr)
{
    return p[dr+1]-p[st];
}



//9
//0,1,2,3
//1,2,3,4
//n=4
//prefix=1,sufix=1;
//i i<n  rez[i]=prefix;     prefix=prefix*v[i];   i
//0 0<4    rez[0]= 1             prefix=1         1
//1 1<4    rez[1]= 1             prefix=2         2
//2 2<4    rez[2]= 2             prefix=6         3
//3 3<4    rez[3]= 6             prefix=24        4
//4 4<4 F


//i=n-1   i>=0      rez[i]=rez[i]*sufix;       sufix=sufix*v[i];     i--
//i=3     3>=0      rez[3]=6*1=6               sufix=4                2
//i=2     2>=0      rez[2]=2*4=8               sufix=12               1
//i=1     1>=0      rez[1]=1*12=12             sufix=24               0
//i=0     0>=0      rez[0]=24                  sufix=24               -1
//i=-1    -1>=0 F
void produsFaraSine(int v[],int n , long long rez[])
{
    long long prefix=1;
    for(int i=0; i<n; i++)
    {
        rez[i]=prefix;
        prefix=prefix*v[i];
    }
    long long sufix=1;
    for(int i=n-1;i>=0;i--)
    {
        rez[i]=rez[i]*sufix;
        sufix=sufix*v[i];
    }
}
#endif // FUNCTII-EXTE1_H_INCLUDED
