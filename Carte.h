#pragma once
#include <iostream>


using namespace std;


class mCarte
{
	//Donn�es membres
	int id;
	string Nom;
	string Prenom;
	string Adresse;
	string CodePostal;
	string Ville;




public:
	mCarte();

	int getid();
	string getNom();
	string getPrenom();
	string getAdresse();
	string getCodePostal();
	string getVille();

	void setid(int id);
	void setNom(string nom);
	void setPrenom(string prenom);
	void setAdresse(string adresse);
	void setCodePostal(string CodePostal);
	void setVille(string ville);

	void affiche(); // Affiche toutes les donn�e de la classe
	void suppr(); // Supprime toute les donn�es de la classe

	~mCarte();
};
