#include <iostream>
#include<vector>
using namespace std;

class Etudiant{
string nom;
int matricule;
float ntmoy;
public:
    friend class Cours;
    friend class Professeur;
    Etudiant(){
    nom = " ";
    matricule = 0;
    ntmoy = 0;
    }

    Etudiant(string nom , int matricule , float ntmoy){
    this->nom = nom;
    this->matricule = matricule ;
    this->ntmoy = ntmoy;
    }

    void afficherinfoEtudiant(){
    cout<<nom<<endl;
    cout<<matricule<<endl;
    cout<<ntmoy<<endl;
    }
    void modifier_nt(float note){
    ntmoy = note;
    }
};

class Professeur{
string nom;
int matricule;
string specialite;
public:
    friend class Cours;
    Professeur(){
    nom = " ";
    matricule = 0;
    specialite = " ";
    }
    Professeur(string nom , int matricule , string specialite){
    this->nom = nom;
    this->matricule = matricule ;
    this->specialite = specialite;
    }
    void afficherinfoProfesseur(){
    cout<<nom<<endl;
    cout<<matricule<<endl;
    cout<<specialite<<endl;
    }
    void attribuer_nt(Etudiant& e ,float note){
    e.ntmoy = note;
    }
};

class Cours{
string nomCours;
Professeur p;
vector<Etudiant> tab;
public:
    void ajouter_etd(Etudiant e){
    tab.push_back(e);
    }

    void afficherinfoCours(){
    cout<<nomCours<<endl;
    cout<<p.matricule<<endl;
    cout<<p.nom<<endl;
    cout<<p.specialite<<endl;
    for(int i=0 ; i<tab.size() ; i++){
        cout<<tab[i].matricule<<endl;
        cout<<tab[i].ntmoy<<endl;
        cout<<tab[i].nom<<endl;
    }
    }

    float moyennecours(){
    float s=0;
    for(int i=0 ; i<tab.size() ; i++){
    s += tab[i].ntmoy;
    }
    return s/tab.size();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
