#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Carte.h"

int MainMenu();
int FindEmpty(mCarte Carte[]);



void AddCarte(mCarte Carte[]);
void AfficheCarte(mCarte Carte[]);
void SupprCarte(mCarte Carte[]);
void ModifCarte(mCarte Carte[]);


int main()
{
	mCarte Carte[100]; // Création du tableau de Carte
	bool Play = true; // Bool pour savoir si l'application doit s'arretter



	while (Play){ // Boucle d'utilisation de l'appli    si Faux arrette l'appli

		switch (MainMenu()){	//Menu principale

		case 1:	//Ajout d'une carte
			AddCarte(Carte);
			break;

		case 2:	//Suppression d'une carte
			SupprCarte(Carte);
			break;

		case 3:	//Modification d'une carte
			ModifCarte(Carte);
			break;

		case 4:	//Affichage d'une carte
			AfficheCarte(Carte);
			break;

		case 0:	//Fin de l'utilisation de l'appli

			Play = false;
			break;

		default:
			break;			
		}
		

	}



	return 0;
}

int MainMenu(){

	int choice = 0;

system("cls");	//Affichage du menu
	std::cout << "MENU PRINCIPALE\n";
	std::cout << "===============\n\n";
	std::cout << "1/ Ajouter carte identite\n";
	std::cout << "2/ Supprimer carte identite\n";
	std::cout << "3/ Modifier carte identite\n";
	std::cout << "4/ Afficher carte identite\n";
	std::cout << "0/ Quitter\n\n";

	std::cin >> choice;	
	return choice;	//Retourne le choix du menu
}

void AddCarte(mCarte Carte[]){

	mCarte CarteTemp;	//Class temporaire servant de recueil d'information avant d'assigner au tableau
	string Temp;	//Variable permettant la transition par le getline
	char choice;

	int empty = FindEmpty(Carte);	//Recupere un emplacement libre dans le tableau

system("cls");
	std::cout << "Ajout de carte\n";
	std::cout << "===============\n";

	cin.ignore();
	std::cout << "\nNom : ";
	std::getline (std::cin, Temp);
	CarteTemp.setNom(Temp);

	std::cout << "\nPrenom : ";
	std::getline (std::cin, Temp);
	CarteTemp.setPrenom(Temp);

	std::cout << "\nAdresse : ";
	std::getline (std::cin, Temp);
	CarteTemp.setAdresse(Temp);

	std::cout << "\nCode Postal : ";
	std::getline (std::cin, Temp);
	CarteTemp.setCodePostal(Temp);

	std::cout << "\nVille : ";
	std::getline (std::cin, Temp);
	CarteTemp.setVille(Temp);

	std::cout << "\n\nLes informations entre sont elles exacte ? y/n       ";	//Verification des informations par l'utilisateur
	std::cin >> choice;


	switch (choice) {

	case 'y':	//Application des valeurs dans notre tableau de Carte
		
		Carte[empty].setid(empty);

		Carte[empty].setNom(CarteTemp.getNom());

		Carte[empty].setPrenom(CarteTemp.getPrenom());

		Carte[empty].setAdresse(CarteTemp.getAdresse());

		Carte[empty].setCodePostal(CarteTemp.getCodePostal());

		Carte[empty].setVille(CarteTemp.getVille());

		break;

	case 'n':	//Retour a la saisie des données
		AddCarte(Carte);

		break;

	}

}

int FindEmpty(mCarte Carte[]) {

	int i = 1;

	while (Carte[i].getid() != 0) {	//Tant que la variable ID du tableau de classe mCarte est différent de 0 cela incrément i

		i++;


	}

	return i;	//Retourne i
}

void AfficheCarte(mCarte Carte[]) {

	int ID = 0;

	system("cls");
	std::cout << "Affiche Carte\n";
	std::cout << "===============\n";


	std::cout << "Veuillez entrer l'ID de la carte : ";
	std::cin >> ID;

	if (Carte[ID].getid() == 0) {	//Verif si l'ID est valide
		std::cout << "ID invalide\n";


	} else {
		Carte[ID].affiche();	//Affiche les donnée du tableau de la classe mCarte
	}


		
		


	

	system("pause");
}

void SupprCarte(mCarte Carte[]) {

	int ID = 0;

	system("cls");
	std::cout << "Supprimer une carte\n";
	std::cout << "===============\n";


	std::cout << "Veuillez entrer l'ID de la carte : ";
	std::cin >> ID;

	if (Carte[ID].getid() == 0) {	//Verifie si l'ID est valide
		std::cout << "ID invalide\n";

	}
	else {
		Carte[ID].suppr();	//Supprime les données du tableau de classe mCarte

		std::cout << "Carte supprime \n\n ";
	}
		
	

	

	system("pause");
}

void ModifCarte(mCarte Carte[]) {
	int ID = 0;
	int EditChoice = 0;
	string Temp;

	system("cls");
	std::cout << "Modifier une carte\n";
	std::cout << "===============\n";


	std::cout << "Veuillez entrer l'ID de la carte : ";
	std::cin >> ID;

	if (Carte[ID].getid() == 0) {	//Verifie que l'ID est valide
		std::cout << "ID invalide\n";
	} else {
		
		std::cout << "\n\n";
		Carte[ID].affiche();	//Affiche les donnée

		std::cout << "\n\nInfomration a modifier ?\n";
		std::cout << "1/ Nom\n";
		std::cout << "2/ Prenom\n";
		std::cout << "3/ Adresse\n";
		std::cout << "4/ Code Postal\n";
		std::cout << "5/ Ville\n";

		std::cin >> EditChoice;	//Choix de la donnée à modifié

		std::cout << "\n\nEntrez la nouvelle information :\n";

		cin.ignore();
		std::getline(std::cin, Temp);

		switch (EditChoice) {	//Switch pour la modification de la valeur choisis dans le tableau de la classe mCarte

		case 1:
			Carte[ID].setNom(Temp);
			break;

		case 2:
			Carte[ID].setPrenom(Temp);
			break;

		case 3:
			Carte[ID].setAdresse(Temp);
			break;

		case 4:
			Carte[ID].setCodePostal(Temp);
			break;

		case 5:
			Carte[ID].setVille(Temp);
			break;

		}

		std::cout << "\n\nModification effectue\n";

	}


	system("pause");


}