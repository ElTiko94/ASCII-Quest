class ElementDecor
{
	public:

	virtual void affiche(int a) const =0;
	virtual int get_largeur() const = 0;
};

// classe derivee
class  Maison : public ElementDecor
{
	public:
	int largeur;
	
	Maison();
	void affiche(int a) const;
	int get_largeur() const;
};

class  Arbre : public ElementDecor
{
	public:
	int largeur;
	
	Arbre();
	void affiche(int a) const;
	int get_largeur() const;
};

class Escargot : public ElementDecor
{
	public:
	int largeur;
	
	Escargot();
	void affiche(int a) const;
	int get_largeur() const;
};


class Moulin : public ElementDecor
{
	public:
	int largeur;

	Moulin();
	int get_largeur() const;
	void affiche(int a) const;
};


class Batiment : public ElementDecor
{
	public:
	int largeur;
	
	Batiment();
	int get_largeur() const;
	void affiche(int a) const;
};
