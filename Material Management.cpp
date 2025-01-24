#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// D�finition de l'�num�ration Type
enum class Type {
    Serveur,
    Tablette,
    Ordinateur
};

// Classe TypeMateriel
class TypeMateriel {
protected:
    string type;

public:
    TypeMateriel(Type type) {
        switch(type) {
            case Type::Serveur:
                this->type = "Serveur";
                break;
            case Type::Tablette:
                this->type = "Tablette";
                break;
            case Type::Ordinateur:
                this->type = "Ordinateur";
                break;
            default:
                this->type = "Inconnu";
        }
    }
		virtual string getTypeAsString() const {
        return type;
    }
    virtual void afficher() const = 0;
};
// Classe Materiel
class Materiel {
private:
    string nom;
    string reference;
    TypeMateriel* type; 
    bool statut;
    string emplacement;
    int stock; 

public:
    Materiel() {}

    Materiel(string nom, string reference, TypeMateriel* type, bool statut, string emplacement, int stock)
        : nom(nom), reference(reference), type(type), statut(statut), emplacement(emplacement), stock(stock) {}

    string getNom() const { return nom; }
    string getReference() const { return reference; }
    TypeMateriel* getType() const { return type; } 
    bool getStatut() const { return statut; }
    string getEmplacement() const { return emplacement; }
    int getStock() const { return stock; }
	

    void setNom(string nouveauNom) { nom = nouveauNom; }
    void setReference(string nouvelleReference) { reference = nouvelleReference; }
    void setType(TypeMateriel* nouveauType) { type = nouveauType; }
    void setStatut(bool nouveauStatut) { statut = nouveauStatut; }
    void setEmplacement(string nouvelEmplacement) { emplacement = nouvelEmplacement; }
    void setStock(int nouveauStock) { stock = nouveauStock; }

    void afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "R�f�rence: " << reference << endl;
    	type->afficher(); 
        cout << "Statut: " << (statut ? "Disponible" : "Non disponible") << endl;
        cout << "Emplacement: " << emplacement << endl;
        cout << "Stock: " << stock << endl;
    }
};


class Serveur : public TypeMateriel {
public:
Serveur() : TypeMateriel(Type::Serveur) {}

    void afficher() const override {
        cout << "Informations sur le serveur :" << endl;
        cout << "Type: Serveur" << endl;
        cout << "Capacit� de stockage: 1 To" << endl;
        cout << "M�moire RAM: 16 Go" << endl;
    }
};

// Classe Tablette
class Tablette : public TypeMateriel {
public:
    Tablette() : TypeMateriel(Type::Tablette) {}

    void afficher() const override {
        cout << "Informations sur la tablette :" << endl;
        cout << "Type: Tablette" << endl;
        cout << "Taille de l'�cran: 10 pouces" << endl;
        cout << "Syst�me d'exploitation: Android" << endl;
    }
};

// Classe Ordinateur
class Ordinateur : public TypeMateriel {
public:
    Ordinateur() : TypeMateriel(Type::Ordinateur) {}

    void afficher() const override {
        cout << "Informations sur l'ordinateur :" << endl;
        cout << "Type: Ordinateur" << endl;
        cout << "Processeur: Intel Core i7" << endl;
        cout << "Syst�me d'exploitation: Windows 10" << endl;
    }
};

// Classe Utilisateur
class Utilisateur {
private:
    string nom;
    string identifiant;
    string departement;
    vector<string> droitsAcces;

public:
    Utilisateur() : nom(""), identifiant(""), departement(""), droitsAcces({}) {}

    Utilisateur(string nom, string identifiant, string departement, vector<string> droitsAcces)
        : nom(nom), identifiant(identifiant), departement(departement), droitsAcces(droitsAcces) {}

    string getNom() const { return nom; }
    string getIdentifiant() const { return identifiant; }
    string getDepartement() const { return departement; }
    vector<string> getDroitsAcces() const { return droitsAcces; }

    void setNom(string nouveauNom) { nom = nouveauNom; }
    void setIdentifiant(string nouvelIdentifiant) { identifiant = nouvelIdentifiant; }
    void setDepartement(string nouveauDepartement) { departement = nouveauDepartement; }
    void setDroitsAcces(vector<string> nouveauxDroitsAcces) { droitsAcces = nouveauxDroitsAcces; }

    //afficher les informations sur l'utilisateur
    void afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "Identifiant: " << identifiant << endl;
        cout << "D�partement: " << departement << endl;
        cout << "Droits d'acc�s: ";
        for (const auto& droit : droitsAcces) {
            cout << droit << " ";
        }
        cout << endl;
    }
    bool aDroitAfficherInventaire() const {
        // vrf si user a le droit r
        for (const auto& droit : droitsAcces) {
            if (droit == "r") {
                return true; 
            }
        }
        return false; 
    }
};

// Classe DemandeMateriel
class DemandeMateriel {
private:
    string identifiantUtilisateur;
    string typeMateriel;
    int priorite;
    string dateDemande;

public:
    DemandeMateriel() : identifiantUtilisateur(""), typeMateriel(""), priorite(0), dateDemande("") {}

    DemandeMateriel(string identifiantUtilisateur, string typeMateriel, int priorite, string dateDemande)
        : identifiantUtilisateur(identifiantUtilisateur), typeMateriel(typeMateriel), priorite(priorite), dateDemande(dateDemande) {}

    string getIdentifiantUtilisateur() const { return identifiantUtilisateur; }
    string getTypeMateriel() const { return typeMateriel; }
    int getPriorite() const { return priorite; }
    string getDateDemande() const { return dateDemande; }

    void setIdentifiantUtilisateur(string nouvelIdentifiant) { identifiantUtilisateur = nouvelIdentifiant; }
    void setTypeMateriel(string nouveauTypeMateriel) { typeMateriel = nouveauTypeMateriel; }
    void setPriorite(int nouvellePriorite) { priorite = nouvellePriorite; }
    void setDateDemande(string nouvelleDateDemande) { dateDemande = nouvelleDateDemande; }

    // afficher les informations sur la demande de mat�riel
    void afficher() const {
        cout << "Identifiant utilisateur: " << identifiantUtilisateur << endl;
        cout << "Type de mat�riel: " << typeMateriel << endl;
        cout << "Priorit�: " << priorite << endl;
        cout << "Date de demande: " << dateDemande << endl;
    }
};

// Classe Reparation
class Reparation {
private:
    string identifiantMateriel;
    string descriptionPanne;
    string dateReparation;
    string historiqueReparations;

public:
    Reparation() : identifiantMateriel(""), descriptionPanne(""), dateReparation(""), historiqueReparations("") {}

    Reparation(string identifiantMateriel, string descriptionPanne, string dateReparation, string historiqueReparations)
        : identifiantMateriel(identifiantMateriel), descriptionPanne(descriptionPanne), dateReparation(dateReparation), historiqueReparations(historiqueReparations) {}

    string getIdentifiantMateriel() const { return identifiantMateriel; }
    string getDescriptionPanne() const { return descriptionPanne; }
    string getDateReparation() const { return dateReparation; }
    string getHistoriqueReparations() const { return historiqueReparations; }

    void setIdentifiantMateriel(string nouvelIdentifiantMateriel) { identifiantMateriel = nouvelIdentifiantMateriel; }
    void setDescriptionPanne(string nouvelleDescriptionPanne) { descriptionPanne = nouvelleDescriptionPanne; }
    void setDateReparation(string nouvelleDateReparation) { dateReparation = nouvelleDateReparation; }
    void setHistoriqueReparations(string nouvelHistoriqueReparations) { historiqueReparations = nouvelHistoriqueReparations; }

    // afficher les informations sur la r�paration
    void afficher() const {
        cout << "Identifiant mat�riel: " << identifiantMateriel << endl;
        cout << "Description de la panne: " << descriptionPanne << endl;
        cout << "Date de r�paration: " << dateReparation << endl;
        cout << "Historique des r�parations: " << historiqueReparations << endl;
    }
};

// Classe Inventaire
class Inventaire {
private:
    vector<Materiel> materiaux;  
    vector<Utilisateur> utilisateurs;  
    vector<DemandeMateriel> demandes; 
    vector<Reparation> reparations;

public:
    // Const par d�faut
    Inventaire() {}

    // ajouter du mat�riel et des utilisateurs � l'inventaire
    void ajouterMateriel(const Materiel& materiel) {
        materiaux.push_back(materiel);
    }

    void ajouterUtilisateur(const Utilisateur& utilisateur) {
        utilisateurs.push_back(utilisateur);
    }

    void ajouterDemande(const DemandeMateriel& demande) {
        demandes.push_back(demande);
    }

    void ajouterReparation(const Reparation& reparation) {
        reparations.push_back(reparation);
    }

    // afficher l'inventaire complet du mat�riel
    void afficherInventaireCompletMateriel() {
        cout << "Inventaire complet du mat�riel informatique :" << endl;
        for (const Materiel& materiel : materiaux) {
            materiel.afficher();
            cout << endl;
        }
    }

    // g�n�rer un rapport d'inventaire par type d'�quipement
    void genererRapportParType(const string& type) {
    cout << "Rapport d'inventaire pour le type : " << type << endl;
    for (const Materiel& materiel : materiaux) {
        if (materiel.getType()->getTypeAsString() == type) {
            materiel.afficher();
            cout << endl;
        }
    }
}


    // M�thode pour g�n�rer un rapport d'inventaire par d�partement
    void genererRapportParDepartement(const string& departement) {
        cout << "Rapport d'inventaire pour le d�partement : " << departement << endl;
        for (const Utilisateur& utilisateur : utilisateurs) {
            if (utilisateur.getDepartement() == departement) {
                utilisateur.afficher();
                cout << endl;
            }
        }
    }

    // g�rer les emplacements
    void assignerEmplacement(string reference, string emplacement) {
        for (Materiel& materiel : materiaux) {
            if (materiel.getReference() == reference) {
                materiel.setEmplacement(emplacement);
                cout << "Emplacement attribu� � l'�quipement : " << materiel.getNom() << endl;
                return;
            }
        }
        cout << "Aucun �quipement trouv� avec la r�f�rence : " << reference << endl;
    }

    void rechercherParEmplacement(const string& emplacement) {
        cout << "Recherche d'�quipements par emplacement : " << emplacement << endl;
        for (const Materiel& materiel : materiaux) {
            if (materiel.getEmplacement() == emplacement) {
                materiel.afficher();
                cout << endl;
            }
        }
    }

    // surveiller les niveaux de stock
    void surveillerStock() {
        cout << "Surveillance des niveaux de stock :" << endl;
        for (const Materiel& materiel : materiaux) {
            if (materiel.getStock() < 10) {
                cout << "Alerte : Stock critique pour l'�quipement " << materiel.getNom() << " (Stock : " << materiel.getStock() << ")" << endl;
            }
        }
    }
    // modifier un mat�riel existant
    void modifierMateriel(const string& reference, const Materiel& materielModifie) {
        for (Materiel& materiel : materiaux) {
            if (materiel.getReference() == reference) {
                materiel.setNom(materielModifie.getNom());
                materiel.setReference(materielModifie.getReference());
                materiel.setType(materielModifie.getType());
                materiel.setStatut(materielModifie.getStatut());
                materiel.setEmplacement(materielModifie.getEmplacement());
                materiel.setStock(materielModifie.getStock());
                cout << "Mat�riel modifi� : " << materiel.getNom() << endl;
                return;
            }
        }
        cout << "Aucun mat�riel trouv� avec la r�f�rence : " << reference << endl;
    }
    // supprimer un mat�riel existant par r�f�rence
    void supprimerMateriel(const string& reference) {
        for (auto it = materiaux.begin(); it != materiaux.end(); ++it) {
            if (it->getReference() == reference) {
                cout << "�quipement supprim� : " << it->getNom() << endl;
                materiaux.erase(it);
                return;
            }
        }
        cout << "Aucun �quipement trouv� avec la r�f�rence : " << reference << endl;
    }
    // rechercher un mat�riel par nom, r�f�rence ou type
    Materiel* rechercherMateriel(const string& nom, const string& reference, const string& type) {
        for (Materiel& materiel : materiaux) {
            if ((materiel.getNom() == nom) || (materiel.getReference() == reference) || (materiel.getType()->getTypeAsString() == type)) {
                return &materiel; 
            }
        }
        return nullptr;  
    }
    // modifier un utilisateur existant
    void modifierUtilisateur(const string& identifiant, const Utilisateur& utilisateurModifie) {
        for (Utilisateur& utilisateur : utilisateurs) {
            if (utilisateur.getIdentifiant() == identifiant) {
                utilisateur.setNom(utilisateurModifie.getNom());
                utilisateur.setIdentifiant(utilisateurModifie.getIdentifiant());
                utilisateur.setDepartement(utilisateurModifie.getDepartement());
                utilisateur.setDroitsAcces(utilisateurModifie.getDroitsAcces());
                cout << "Utilisateur modifi� : " << utilisateur.getNom() << endl;
                return;
            }
        }
        cout << "Aucun utilisateur trouv� avec l'identifiant : " << identifiant << endl;
    }
       // supprimer un utilisateur existant par identifiant
    void supprimerUtilisateur(const string& identifiant) {
        for (auto it = utilisateurs.begin(); it != utilisateurs.end(); ++it) {
            if (it->getIdentifiant() == identifiant) {
                cout << "Utilisateur supprim� : " << it->getNom() << endl;
                utilisateurs.erase(it);
                return;
            }
        }
        cout << "Aucun utilisateur trouv� avec l'identifiant : " << identifiant << endl;
    }
     // rechercher un utilisateuridentifiant 
    Utilisateur* rechercherUtilisateur(const string& identifiant) {
        for (Utilisateur& utilisateur : utilisateurs) {
            if (utilisateur.getIdentifiant() == identifiant) {
                return &utilisateur;  // Retourne un pointeur vers l'utilisateur trouv�
            }
        }
        return nullptr;  
    }
     // afficher la liste compl�te des utilisateurs
    void afficherUtilisateurs() {
        cout << "Liste des utilisateurs :" << endl;
        for (const Utilisateur& utilisateur : utilisateurs) {
            utilisateur.afficher();
            cout << endl;
        }
    }
       // afficher toutes les demandes de mat�riel
    void afficherDemandesMateriel() {
        cout << "Liste des demandes de mat�riel :" << endl;
        for (const DemandeMateriel& demande : demandes) {
            demande.afficher();
            cout << endl;
        }
    }
      // afficher toutes les r�parations
    void afficherReparations() {
        cout << "Liste des r�parations :" << endl;
        for (const Reparation& reparation : reparations) {
            reparation.afficher();
            cout << endl;
        }
    }
    
};

int main() {
    Inventaire inventaireManager;

    while (true) {
        // Menu principal
        cout << "\n--- Menu principal ---" << endl;
        cout << "1. G�rer le mat�riel" << endl;
        cout << "2. G�rer les utilisateurs" << endl;
        cout << "3. G�rer les inventaires" << endl;
        cout << "4. G�rer les emplacements" << endl;
        cout << "5. G�rer les demandes de mat�riel" << endl;
        cout << "6. G�rer les r�parations et maintenances" << endl;
        cout << "7. Surveiller les stocks" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choisissez une option : ";
        
        int choix;
        cin >> choix;

        if (choix == 0) {
            cout << "Fin du programme." << endl;
            break;
        } else if (choix == 1) {
            // Menu pour g�rer le mat�riel
            while (true) {
                cout << "\n--- Menu Mat�riel ---" << endl;
                cout << "1. Ajouter du mat�riel" << endl;
                cout << "2. Modifier du mat�riel" << endl;
                cout << "3. Supprimer du mat�riel" << endl;
                cout << "4. Rechercher du mat�riel" << endl;
                cout << "5. Afficher l'inventaire complet" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixMateriel;
                cin >> choixMateriel;

                if (choixMateriel == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixMateriel == 1) {
                    // Ajouter du mat�riel
                    string nom, reference, type, emplacement;
                    bool statut;
                    int stock;

                    cout << "Entrez le nom du mat�riel : ";
                    cin >> nom;
                    cout << "Entrez la r�f�rence du mat�riel : ";
                    cin >> reference;
                    cout << "Entrez le type du mat�riel : ";
                    cin >> type;
                    cout << "Est-ce que le mat�riel est disponible ? (1 = Oui, 0 = Non) : ";
                    cin >> statut;
                    cout << "Entrez l'emplacement du mat�riel : ";
                    cin >> emplacement;
                    cout << "Entrez le niveau de stock du mat�riel : ";
                    cin >> stock;

                    TypeMateriel* typeMateriel = nullptr; 

if (type == "Ordinateur") {
    typeMateriel = new Ordinateur();
} else if (type == "Serveur") {
    typeMateriel = new Serveur();
} else if (type == "Tablette") {
    typeMateriel = new Tablette();
} else {
    cout << "Type de mat�riel inconnu : " << type << endl;
    return 1; 
}

Materiel nouveauMateriel(nom, reference, typeMateriel, statut, emplacement, stock);

                    inventaireManager.ajouterMateriel(nouveauMateriel);
                } else if (choixMateriel == 2) {
                   // Modifier du mat�riel
string reference;
cout << "Entrez la r�f�rence du mat�riel � modifier : ";
cin >> reference;

string nouveauNom, nouveauType, nouvelEmplacement;
bool nouveauStatut;
int nouveauStock;

cout << "Entrez le nouveau nom : ";
cin >> nouveauNom;
cout << "Entrez le nouveau type : ";
cin >> nouveauType;
cout << "Est-ce que le mat�riel est disponible ? (1 = Oui, 0 = Non) : ";
cin >> nouveauStatut;
cout << "Entrez le nouvel emplacement du mat�riel : ";
cin >> nouvelEmplacement;
cout << "Entrez le nouveau niveau de stock : ";
cin >> nouveauStock;

TypeMateriel* nouveauTypeMateriel = nullptr;

if (nouveauType == "Ordinateur") {
    nouveauTypeMateriel = new Ordinateur();
} else if (nouveauType == "Serveur") {
    nouveauTypeMateriel = new Serveur();
} else if (nouveauType == "Tablette") {
    nouveauTypeMateriel = new Tablette();
} else {
    cout << "Type de mat�riel inconnu : " << nouveauType << endl;
    return 1; 
}

Materiel materielModifie(nouveauNom, reference, nouveauTypeMateriel, nouveauStatut, nouvelEmplacement, nouveauStock);

inventaireManager.modifierMateriel(reference, materielModifie);
                } else if (choixMateriel == 3) {
                    // Supprimer du mat�riel
                    string reference;
                    cout << "Entrez la r�f�rence du mat�riel � supprimer : ";
                    cin >> reference;
                    inventaireManager.supprimerMateriel(reference);
                } else if (choixMateriel == 4) {
                    // Rechercher du mat�riel
                    string nom, reference, type;
                    cout << "Entrez le nom du mat�riel � rechercher (ou laissez vide) : ";
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Entrez la r�f�rence du mat�riel � rechercher (ou laissez vide) : ";
                    getline(cin, reference);
                    cout << "Entrez le type du mat�riel � rechercher (ou laissez vide) : ";
                    getline(cin, type);
                    
                    Materiel* materielTrouve = inventaireManager.rechercherMateriel(nom, reference, type);
                    if (materielTrouve != nullptr) {
                        cout << "\nMat�riel trouv� :" << endl;
                        materielTrouve->afficher();
                    } else {
                        cout << "Aucun mat�riel trouv�." << endl;
                    }
                    
                    
                } else if (choixMateriel == 5) {
                	
    // Menu pour g�rer les demandes de mat�riel
    string identifiant;
    cout << "Entrez l'identifiant de l'utilisateur : ";
    cin >> identifiant;

    // Rechercher l'utilisateur dans la liste des utilisateurs
    Utilisateur* utilisateur = inventaireManager.rechercherUtilisateur(identifiant);

    if (utilisateur != nullptr && utilisateur->aDroitAfficherInventaire()) {
        // Afficher l'inventaire complet
                cout << "Vous avez les autorisations n�cessaires pour afficher l'inventaire." << endl;

        inventaireManager.afficherInventaireCompletMateriel();
    } else {
        // L'utilisateur n'a pas le droit de lire l'inventaire
        cout << "Vous n'avez pas les autorisations n�cessaires pour afficher l'inventaire." << endl;
    }
}

     }}    else if(choix == 2) {
            // Menu pour g�rer les utilisateurs
            while (true) {
                cout << "\n--- Menu Utilisateur ---" << endl;
                cout << "1. Ajouter un utilisateur" << endl;
                cout << "2. Modifier un utilisateur" << endl;
                cout << "3. Supprimer un utilisateur" << endl;
                cout << "4. Rechercher un utilisateur" << endl;
                cout << "5. Afficher la liste des utilisateurs" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";

                int choixUtilisateur;
                cin >> choixUtilisateur;

                if (choixUtilisateur == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixUtilisateur == 1) {
                    // Ajouter un utilisateur
                    string nom, identifiant, departement;
                    vector<string> droitsAcces;

                    cout << "Entrez le nom de l'utilisateur : ";
                    cin >> nom;
                    cout << "Entrez l'identifiant de l'utilisateur : ";
                    cin >> identifiant;
                    cout << "Entrez le d�partement de l'utilisateur : ";
                    cin >> departement;

                    // Demander les droits d'acc�s
                    cout << "Entrez les droits d'acc�s de l'utilisateur (r w x s�par�s par des espaces, - si sans droit(exemple  r - - ), terminez avec 'fin') : ";
                    string droit;
                    while (cin >> droit && droit != "fin") {
                        droitsAcces.push_back(droit);
                    }

                    Utilisateur nouvelUtilisateur(nom, identifiant, departement, droitsAcces);
                    inventaireManager.ajouterUtilisateur(nouvelUtilisateur);
                } else if (choixUtilisateur == 2) {
                    // Modifier un utilisateur
                    string identifiant;
                    cout << "Entrez l'identifiant de l'utilisateur � modifier : ";
                    cin >> identifiant;

                    string nouveauNom, nouveauDepartement;
                    vector<string> nouveauxDroitsAcces;
                    cout << "Entrez le nouveau nom : ";
                    cin >> nouveauNom;
                    cout << "Entrez le nouveau d�partement : ";
                    cin >> nouveauDepartement;

                    cout << "Entrez les nouveaux droits d'acc�s de l'utilisateur (s�par�s par des espaces, terminez avec 'fin') : ";
                    string droit;
                    while (cin >> droit && droit != "fin") {
                        nouveauxDroitsAcces.push_back(droit);
                    }

                    Utilisateur utilisateurModifie(nouveauNom, identifiant, nouveauDepartement, nouveauxDroitsAcces);
                    inventaireManager.modifierUtilisateur(identifiant, utilisateurModifie);
                } else if (choixUtilisateur == 3) {
                    // Supprimer un utilisateur
                    string identifiant;
                    cout << "Entrez l'identifiant de l'utilisateur � supprimer : ";
                    cin >> identifiant;
                    inventaireManager.supprimerUtilisateur(identifiant);
                } else if (choixUtilisateur == 4) {
                    // Rechercher un utilisateur
                    string nom, identifiant, departement;
                    cout << "Entrez le nom de l'utilisateur � rechercher (ou laissez vide) : ";
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Entrez l'identifiant de l'utilisateur � rechercher (ou laissez vide) : ";
                                        cin.ignore();

                    getline(cin, identifiant);
                    cout << "Entrez le d�partement de l'utilisateur � rechercher (ou laissez vide) : ";
                                        cin.ignore();

                    getline(cin, departement);

                    Utilisateur* utilisateurTrouve = inventaireManager.rechercherUtilisateur(identifiant);
                    if (utilisateurTrouve != nullptr) {
                        cout << "\nUtilisateur trouv� :" << endl;
                        utilisateurTrouve->afficher();
                    } else {
                        cout << "Aucun utilisateur trouv�." << endl;
                    }
                } else if (choixUtilisateur == 5) {
                    // Afficher la liste des utilisateurs
                    inventaireManager.afficherUtilisateurs();
                }
            }
        } else if (choix == 3) {
            // Menu pour g�rer les inventaires
            while (true) {
                cout << "\n--- Menu Inventaire ---" << endl;
                cout << "1. Afficher l'inventaire complet du mat�riel" << endl;
                cout << "2. G�n�rer un rapport d'inventaire par type d'�quipement" << endl;
                cout << "3. G�n�rer un rapport d'inventaire par d�partement" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixInventaire;
                cin >> choixInventaire;

                if (choixInventaire == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixInventaire == 1) {
                    // Afficher l'inventaire complet du mat�riel
                    inventaireManager.afficherInventaireCompletMateriel();
                } else if (choixInventaire == 2) {
                    // G�n�rer un rapport d'inventaire par type d'�quipement
                    string type;
                    cout << "Entrez le type d'�quipement pour le rapport d'inventaire : ";
                    cin >> type;
                    inventaireManager.genererRapportParType(type);
                } else if (choixInventaire == 3) {
                    // G�n�rer un rapport d'inventaire par d�partement
                    string departement;
                    cout << "Entrez le d�partement pour le rapport d'inventaire : ";
                    cin >> departement;
                    inventaireManager.genererRapportParDepartement(departement);
                }
            }
        } else if (choix == 4) {
            // Menu pour g�rer les emplacements
            while (true) {
                cout << "\n--- Menu Emplacements ---" << endl;
                cout << "1. Assigner un emplacement � un �quipement" << endl;
                cout << "2. Rechercher un �quipement par emplacement" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixEmplacements;
                cin >> choixEmplacements;

                if (choixEmplacements == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixEmplacements == 1) {
                    // Assigner un emplacement � un �quipement
                    string reference, emplacement;
                    cout << "Entrez la r�f�rence de l'�quipement : ";
                    cin >> reference;
                    cout << "Entrez l'emplacement � assigner : ";
                    cin >> emplacement;
                    inventaireManager.assignerEmplacement(reference, emplacement);
                } else if (choixEmplacements == 2) {
                    // Rechercher un �quipement par emplacement
                    string emplacement;
                    cout << "Entrez l'emplacement pour la recherche : ";
                    cin >> emplacement;
                    inventaireManager.rechercherParEmplacement(emplacement);
                }
            }
        } else if (choix == 5) {
            // Menu pour g�rer les demandes de mat�riel
            while (true) {
                cout << "\n--- Menu Demandes de Mat�riel ---" << endl;
                cout << "1. Enregistrer une nouvelle demande" << endl;
                cout << "2. Afficher toutes les demandes" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";

                int choixDemande;
                cin >> choixDemande;

                if (choixDemande == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixDemande == 1) {
                    // Enregistrer une nouvelle demande
                    string identifiantUtilisateur, typeMateriel, dateDemande;
                    int priorite;

                    cout << "Entrez l'identifiant de l'utilisateur : ";
                    cin >> identifiantUtilisateur;
                    cout << "Entrez le type de mat�riel demand� : ";
                    cin >> typeMateriel;
                    cout << "Entrez la date de la demande (jj-mm-aaaa) : ";
                    cin >> dateDemande;
                    cout << "Entrez la priorit� (1 � 10) : ";
                    cin >> priorite;

                    DemandeMateriel nouvelleDemande(identifiantUtilisateur, typeMateriel, priorite, dateDemande);
                    inventaireManager.ajouterDemande(nouvelleDemande);
                } else if(choixDemande == 2) {
                    // Afficher toutes les demandes
                    inventaireManager.afficherDemandesMateriel();
                }
            }
        } else if(choix == 6) {
            // Menu pour g�rer les r�parations et maintenances
            while (true) {
                cout << "\n--- Menu R�parations et Maintenance ---" << endl;
                cout << "1. Enregistrer une r�paration" << endl;
                cout << "2. Afficher toutes les r�parations" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixReparation;
                cin >> choixReparation;

                if (choixReparation == 0) {
                    // Retour au menu principal
                    break;
                } else if(choixReparation == 1) {
                    // Enregistrer une r�paration
                    string identifiantMateriel, descriptionPanne, dateReparation, historiqueReparations;

                    cout << "Entrez l'identifiant du mat�riel � r�parer : ";
                    cin >> identifiantMateriel;
                    cout << "Entrez la description de la panne : ";
                    cin.ignore();
                    getline(cin, descriptionPanne);
                    cout << "Entrez la date de r�paration (jj-mm-aaaa) : ";
                    cin >> dateReparation;
                    cout << "Entrez l'historique des r�parations (s�par� par des virgules) : ";
                    cin.ignore();
                    getline(cin, historiqueReparations);

                    Reparation nouvelleReparation(identifiantMateriel, descriptionPanne, dateReparation, historiqueReparations);
                    inventaireManager.ajouterReparation(nouvelleReparation);
                } else if(choixReparation == 2) {
                    // Afficher toutes les r�parations
                    inventaireManager.afficherReparations();
                }
            }
        } else if(choix == 7) {
            // Menu pour surveiller les stocks
            inventaireManager.surveillerStock();
        } else {
            // Option invalide
            cout << "Option invalide. Veuillez r�essayer." << endl;
        }
    }

    return 0;
}

