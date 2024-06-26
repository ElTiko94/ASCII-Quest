#include"decor.h"
#include<iostream>

using namespace std;



	
void Maison :: affiche(int a) const
{
	if(a<5 && a >0)
	{cout<<"     ";}
	if(a==5)
	{cout<<"/===\\";}
	else if(a==6)
	{cout<<"|   |";}
	else if(a==7)
	{cout<<"|___|";}
}


	
void Arbre :: affiche(int a) const
{
	if(a<5 && a >0)
	{cout<<"    ";}
	if(a==5)
	{cout<<" /\\ ";}
	else if(a==6)
	{cout<<" /\\ ";}
	else if(a==7)
	{cout<<"_/\\_";}
}




	
void Escargot :: affiche(int a) const
{
	if(a<7 && a >0)
	{cout<<"    ";}
	else if(a==7)
	{cout<<"_Y@_";}
}


void Moulin :: affiche(int a) const
{
	if(a==1)
	{cout<<"\\\\   //";}
	else if(a==2)
	{cout<<" \\\\ // ";}
	else if(a==3)
	{cout<<"  (0)  ";}
	else if(a==4)
	{cout<<" //#\\\\ ";}
	else if(a==5)
	{cout<<"//###\\\\";}
	else if(a==6)
	{cout<<" ##### ";}
	else if(a==7)
	{cout<<"_#####_";}
}


void Batiment :: affiche(int a) const
{
    if(a<3 && a >0)
	{cout<<"                   ";}
	else if(a==3)
	{cout<<"     __.---.__     ";}
	else if(a==4)
	{cout<<"  __/__\\_O_/__\\__  ";}
	else if(a==5)
	{cout<<" /__\\_________/__\\ ";}
	else if(a==6)
	{cout<<" |==|   ___   |==| ";}
	else if(a==7)
	{cout<<"_|==|___| |___|==|_";}
}

int Batiment :: get_largeur() const
{
    return(largeur);
}

int Moulin :: get_largeur() const
{
    return(largeur);
}

int Maison :: get_largeur() const
{
    return(largeur);
}

int Arbre :: get_largeur() const
{
    return(largeur);
}

int Escargot :: get_largeur() const
{
    return(largeur);
}
