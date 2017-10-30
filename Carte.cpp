#include "Carte.h"


mCarte::mCarte()
{
	setid(0);
}

int mCarte::getid()
{
	return id;
}

string mCarte::getNom()
{
	return Nom;
}

string mCarte::getPrenom()
{
	return Prenom;
}

string mCarte::getAdresse()
{
	return Adresse;
}

string mCarte::getCodePostal()
{
	return CodePostal;
}

string mCarte::getVille()
{
	return Ville;
}

void mCarte::setid(int id)
{
	this->id = id;

}

void mCarte::setNom(string nom)
{
	this->Nom = nom;
}

void mCarte::setPrenom(string prenom)
{
	this->Prenom = prenom;
}

void mCarte::setAdresse(string adresse)
{
	this->Adresse = adresse;
}

void mCarte::setCodePostal(string CodePostal)
{
	this->CodePostal = CodePostal;
}

void mCarte::setVille(string ville)
{
	this->Ville = ville;
}

void mCarte::affiche() // Affiche toute les données de la classe
{
	cout << "Id : " << getid() << endl;
	cout << "Nom : " << getNom() << endl;
	cout << "Prenom : " << getPrenom() << endl;
	cout << "Adresse : " << getAdresse() << endl;
	cout << "Code postal : " << getCodePostal() << endl;
	cout << "Ville : " << getVille() << endl;
}

void mCarte::suppr()  // Supprime toute les données de la classe
{
	setid(0);
	setNom("");
	setPrenom("");
	setAdresse("");
	setCodePostal("");
	setVille("");

}

mCarte::~mCarte()
{

}