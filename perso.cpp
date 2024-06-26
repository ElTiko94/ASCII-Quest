#include<string.h>
#include"perso.h"
#include<iostream>


using namespace std;

personnage::personnage()
{
	int i;
	PV = 100;            // repr ́esente les points de vie du personnage
	PVmax = 100;         // repr ́esente les points de vie max du personnage
	Force = 50;         // repr ́esente la force du personnage
	VIT = 50;           // repr ́esente la vitesse du personnage
	nb_potion = 3;     // repr ́esente le nombre de potions du personnage
	
	strcpy(message, "bonjour");
	
	strcpy(nom, "Tiko");
}


	personnage::personnage(int nPV, int nForce, int nEXP, int nVIT, int nnb_potion, char * nnom)
	{
		int i;
		PV = nPV;            // repr ́esente les points de vie du personnage
		PVmax = nPV;         // repr ́esente les points de vie max du personnage
		Force = nForce;         // repr ́esente la force du personnage
		VIT = nVIT;           // repr ́esente la vitesse du personnage
		nb_potion = nnb_potion;     // repr ́esente le nombre de potions du personnage

		strcpy(nom, nnom);

		strcpy(message, "bonjour");

	}

	// ~personnage();  // si n ́ecessaire
	//char* personnage::get_message() const
	//{
	//	return(&message);
	//}

	//virtual  char*  personnage::get_name() const
	//{
	//	return(&nom[0]);
	//}


	int  personnage::get_PV() const
	{
		return(PV);
	}

	int  personnage::get_PVmax() const
	{
		return(PVmax);
	}

	int  personnage::get_VIT() const
	{
		return(VIT);
	}

	int personnage::get_Force() const
	{
		return(Force);
	}

	//virtual void personnage::set_message(char * newmess)
	//{
	//	int i;
	//}
	// ___________________
	//(                   )_
	//(__                   )
	//   (__________________)

	//virtual void donner_coup(personnage &ennemi);  // calcule en comparant la force
	// d’ennemi des points de d ́eg^ats (par exemple degats = 10*Force/ennemi.Force) qui
	// seront retir ́es `a PV d’ennemi. On pourra  ́ecrire un message sp ́ecial dans chaque
	// personnage ("attaque" pour le personnage et "ouille" pour l’ennemi.)
	void personnage:: prendre_coup(int valeur)  // PV = PV-valeur
	{
		PV = PV-valeur;
	}
	void personnage::soin()   // remonte les PV du personnage d’un certain pourcentage des
	// PVmax. D ́ecr ́emente le nombre de potions.
	{
		int valsoin;
		valsoin = 15*PVmax/100;
		PV = PV+valsoin;
		nb_potion--;
	}
	//virtual bool fuite(const personnage &ennemi);  // permet de quitter un combat selon
	// une certaine probabilit ́e en comparant la VIT de l’ennemi. Chance de Reussite =
	// VIT/ennemi.VIT*50%. On ne peut pas avoir plus de 90% de chances de fuir.
	//virtual void win(personnage &ennemi); // Lors de la victoire du personnage, cette
	// fonction permet de voler les potions de l’ennemi. La force et la vitesse augmentent
	// d’un certain pourcentage : par exemple, Force=Force+(ennemi.Force/Force)*Force/100;
	// VIT=VIT+ (ennemi.VIT/VIT)*VIT/100 (la force augmente de 3% si l’ennemi  ́etait
	// 3 fois plus fort)
void affiche(int a)  //affiche l’avatar du personnage, de la m^eme fa ̧con que les d ́ecors.
{
	if(a==1)
	{cout<<"           .";}
	else if(a==2)
	{cout<<"          / \\";}
	else if(a==3)
	{cout<<"          |.|";}
	else if(a==3)
	{cout<<"     _    |:|";}
	else if(a==4)
	{cout<<"   _(_)_`--8--'";}
	else if(a==5)
	{cout<<"  /\\   /\\  8";}
	else if(a==6)
	{cout<<" 0  \\_/  \\ O";}
	else if(a==7)
	{cout<<"    / \\";}
	else if(a==8)
	{cout<<"  _/   \\_";}
	
}

