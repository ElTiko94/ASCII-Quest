#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>


using namespace std;

class personnage
{
public:
	int PV;            // repr�sente les points de vie du personnage
	int PVmax;         // repr�sente les points de vie max du personnage
	int Force;         // repr�sente la force du personnage
	int VIT;           // repr�sente la vitesse du personnage
	int nb_potion;     // repr�sente le nombre de potions du personnage
	char message[100]; // permet d'afficher un message pour chaque action
	char nom[100];     // nom du personnage
	

	personnage();      // par d�faut: force=50, PV=PVMax=100, EXP=0, VIT=50,nb_potion=3
	personnage(int nPV, int nForce, int nEXP, int nVIT, int nb_potion, char * nnom);
	// ~personnage();  // si n�cessaire
	//virtual  char* get_message() const;  // retourne le message
	//virtual  char* get_name() const;     // retourne le nom
	virtual int get_EXP() const;
	virtual int get_Niv() const;
	int get_PV() const;         // retourne les PV
	int get_PVmax() const;      // retourne les PVmax
	int get_VIT() const;         // retourne la vitesse
	int get_Force() const;     // retourne la Force
	int get_nb_potion() const;     // retourne le nbr de potion

	//virtual void set_message(char * newmess); // permet de copier un message dans message
	void donner_coup(personnage &ennemi);  // calcule en comparant la force
	// d’ennemi des points de d ́eg^ats (par exemple degats = 10*Force/ennemi.Force) qui
	// seront retir ́es `a PV d’ennemi. On pourra  ́ecrire un message sp ́ecial dans chaque
	// personnage ("attaque" pour le personnage et "ouille" pour l’ennemi.)
	void prendre_coup(int valeur);  // PV = PV-valeur
	void soin();   // remonte les PV du personnage d’un certain pourcentage des
	// PVmax. D ́ecr ́emente le nombre de potions.
	bool fuite(const personnage &ennemi);  // permet de quitter un combat selon
	// une certaine probabilit ́e en comparant la VIT de l’ennemi. Chance de Reussite =
	// VIT/ennemi.VIT*50%. On ne peut pas avoir plus de 90% de chances de fuir.
	virtual void win(personnage &ennemi); // Lors de la victoire du personnage, cette
	// fonction permet de voler les potions de l’ennemi. La force et la vitesse augmentent
	// d’un certain pourcentage : par exemple, Force=Force+(ennemi.Force/Force)*Force/100;
	// VIT=VIT+ (ennemi.VIT/VIT)*VIT/100 (la force augmente de 3% si l’ennemi  ́etait
	// 3 fois plus fort)
	virtual void affiche(int a) const ;  //affiche l’avatar du personnage, de la m^eme fa ̧con que les d ́ecors.
	virtual void affiche_ennemi(int a) const; // affichage en mode ennemi
	virtual void affiche_Mort(int a) const;
};


// ___________________
//(                   )_
//(__                   )
//   (__________________)


class guerrier :public personnage
{
	public:
	int EXP;
	int Niv;
	guerrier();      // par d�faut: force=50, PV=PVMax=100, EXP=0, VIT=50,nb_potion=3
	//guerrier(int nPV, int nForce, int nEXP, int nVIT, int nb_potion, char * nnom);
	
	int get_EXP() const;
	int get_Niv() const;
	
	/*void affiche(int a);  		//affiche l'avatar du personnage, de la m^eme fa ̧con que les d ́ecors.
	void affiche_ennemi(int a); // affichage en mode ennemi
	void affiche_Mort(int a);*/
	void win(personnage &ennemi, int N);
};


class Serpent :public personnage
{
	public:
	Serpent();      // par d�faut: force=50, PV=PVMax=100, EXP=0, VIT=50,nb_potion=3
	Serpent(int nPV, int nForce, int nEXP, int nVIT, int nb_potion, char * nnom);
	
	  void affiche_ennemi(int a) const;  		//affiche l'avatar du personnage, de la m^eme fa ̧con que les d ́ecors.
	/*void affiche_ennemi(int a); // affichage en mode ennemi
	void affiche_Mort(int a);*/
};


class Robot :public personnage
{
	public:
	Robot();      // par d�faut: force=50, PV=PVMax=100, EXP=0, VIT=50,nb_potion=3
	Robot(int nPV, int nForce, int nEXP, int nVIT, int nb_potion, char * nnom);
	
	  void affiche_ennemi(int a) const;  		//affiche l'avatar du personnage, de la m^eme fa ̧con que les d ́ecors.
	/*void affiche_ennemi(int a); // affichage en mode ennemi
	void affiche_Mort(int a);*/
};

