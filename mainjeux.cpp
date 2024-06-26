#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include"decor.h"
#include"personage.h"

using namespace std;
int random(int );
void affichage_decor(int n,int deb);
const int M =190;
ElementDecor *pt[M];

int main()
{
	system("mode con: cols=128 lines=128");
	int i,type,j,debut;
	int N=10;

	personnage mimu;
	personnage monstre;
	char c;


	debut =0;
	for(i=0;i<M;i++)
	{
		type = random(5);
		if(type==0)
		{
			pt[i] = new Arbre;
		}
		else if(type==1)
		{
			pt[i] = new Maison;
		}
		else if(type==2)
		{
			pt[i] = new Escargot;
		}
		if(type==3)
		{
			pt[i] = new Moulin;
		}
		if(type==4)
		{
			pt[i] = new Batiment;
		}
	}
	while(1)
	{
		system("cls");
		affichage_decor(N, debut);
		
		cout<<endl;
		
		// affichage des personnage 
		for(j=0;j<9;j++)
		{
			mimu.affiche(j+1);
			cout<<"                                   ";
			cout<<"                                   ";
			monstre.affiche(j+1);
			cout<<endl;
		}
		
		c = getch();
		if ( c =='d' && debut+N<M)
		{
			debut++;
		}
		else if( c=='q' && debut>0)
		{
			debut--;
		}
	}

	for (i=0;i<M;i++)
	{
		delete pt[i];
	}
return(0);
}

int random(int a)
{
	int Indice;
	Indice = rand();
	Indice = Indice%a;
	
	return Indice;

}


void affichage_decor(int n,int deb)
{
	int j,i;
	
	for(j=0;j<7;j++)
	{
		for (i=deb;i<deb+n;i++)	
		{
			pt[i]->affiche(j+1);
		}
		cout<<endl;
	}

}
