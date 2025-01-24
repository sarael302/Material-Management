#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Définition de l'énumération Type
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
        cout << "Référence: " << reference << endl;
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
        cout << "Capacité de stockage: 1 To" << endl;
        cout << "Mémoire RAM: 16 Go" << endl;
    }
};

// Classe Tablette
class Tablette : public TypeMateriel {
public:
    Tablette() : TypeMateriel(Type::Tablette) {}

    void afficher() const override {
        cout << "Informations sur la tablette :" << endl;
        cout << "Type: Tablette" << endl;
        cout << "Taille de l'écran: 10 pouces" << endl;
        cout << "Système d'exploitation: Android" << endl;
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
        cout << "Système d'exploitation: Windows 10" << endl;
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
        cout << "Département: " << departement << endl;
        cout << "Droits d'accès: ";
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

    // afficher les informations sur la demande de matériel
    void afficher() const {
        cout << "Identifiant utilisateur: " << identifiantUtilisateur << endl;
        cout << "Type de matériel: " << typeMateriel << endl;
        cout << "Priorité: " << priorite << endl;
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

    // afficher les informations sur la réparation
    void afficher() const {
        cout << "Identifiant matériel: " << identifiantMateriel << endl;
        cout << "Description de la panne: " << descriptionPanne << endl;
        cout << "Date de réparation: " << dateReparation << endl;
        cout << "Historique des réparations: " << historiqueReparations << endl;
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
    // Const par défaut
    Inventaire() {}

    // ajouter du matériel et des utilisateurs à l'inventaire
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

    // afficher l'inventaire complet du matériel
    void afficherInventaireCompletMateriel() {
        cout << "Inventaire complet du matériel informatique :" << endl;
        for (const Materiel& materiel : materiaux) {
            materiel.afficher();
            cout << endl;
        }
    }

    // générer un rapport d'inventaire par type d'équipement
    void genererRapportParType(const string& type) {
    cout << "Rapport d'inventaire pour le type : " << type << endl;
    for (const Materiel& materiel : materiaux) {
        if (materiel.getType()->getTypeAsString() == type) {
            materiel.afficher();
            cout << endl;
        }
    }
}


    // Méthode pour générer un rapport d'inventaire par département
    void genererRapportParDepartement(const string& departement) {
        cout << "Rapport d'inventaire pour le département : " << departement << endl;
        for (const Utilisateur& utilisateur : utilisateurs) {
            if (utilisateur.getDepartement() == departement) {
                utilisateur.afficher();
                cout << endl;
            }
        }
    }

    // gérer les emplacements
    void assignerEmplacement(string reference, string emplacement) {
        for (Materiel& materiel : materiaux) {
            if (materiel.getReference() == reference) {
                materiel.setEmplacement(emplacement);
                cout << "Emplacement attribué à l'équipement : " << materiel.getNom() << endl;
                return;
            }
        }
        cout << "Aucun équipement trouvé avec la référence : " << reference << endl;
    }

    void rechercherParEmplacement(const string& emplacement) {
        cout << "Recherche d'équipements par emplacement : " << emplacement << endl;
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
                cout << "Alerte : Stock critique pour l'équipement " << materiel.getNom() << " (Stock : " << materiel.getStock() << ")" << endl;
            }
        }
    }
    // modifier un matériel existant
    void modifierMateriel(const string& reference, const Materiel& materielModifie) {
        for (Materiel& materiel : materiaux) {
            if (materiel.getReference() == reference) {
                materiel.setNom(materielModifie.getNom());
                materiel.setReference(materielModifie.getReference());
                materiel.setType(materielModifie.getType());
                materiel.setStatut(materielModifie.getStatut());
                materiel.setEmplacement(materielModifie.getEmplacement());
                materiel.setStock(materielModifie.getStock());
                cout << "Matériel modifié : " << materiel.getNom() << endl;
                return;
            }
        }
        cout << "Aucun matériel trouvé avec la référence : " << reference << endl;
    }
    // supprimer un matériel existant par référence
    void supprimerMateriel(const string& reference) {
        for (auto it = materiaux.begin(); it != materiaux.end(); ++it) {
            if (it->getReference() == reference) {
                cout << "Équipement supprimé : " << it->getNom() << endl;
                materiaux.erase(it);
                return;
            }
        }
        cout << "Aucun équipement trouvé avec la référence : " << reference << endl;
    }
    // rechercher un matériel par nom, référence ou type
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
                cout << "Utilisateur modifié : " << utilisateur.getNom() << endl;
                return;
            }
        }
        cout << "Aucun utilisateur trouvé avec l'identifiant : " << identifiant << endl;
    }
       // supprimer un utilisateur existant par identifiant
    void supprimerUtilisateur(const string& identifiant) {
        for (auto it = utilisateurs.begin(); it != utilisateurs.end(); ++it) {
            if (it->getIdentifiant() == identifiant) {
                cout << "Utilisateur supprimé : " << it->getNom() << endl;
                utilisateurs.erase(it);
                return;
            }
        }
        cout << "Aucun utilisateur trouvé avec l'identifiant : " << identifiant << endl;
    }
     // rechercher un utilisateuridentifiant 
    Utilisateur* rechercherUtilisateur(const string& identifiant) {
        for (Utilisateur& utilisateur : utilisateurs) {
            if (utilisateur.getIdentifiant() == identifiant) {
                return &utilisateur;  // Retourne un pointeur vers l'utilisateur trouvé
            }
        }
        return nullptr;  
    }
     // afficher la liste complète des utilisateurs
    void afficherUtilisateurs() {
        cout << "Liste des utilisateurs :" << endl;
        for (const Utilisateur& utilisateur : utilisateurs) {
            utilisateur.afficher();
            cout << endl;
        }
    }
       // afficher toutes les demandes de matériel
    void afficherDemandesMateriel() {
        cout << "Liste des demandes de matériel :" << endl;
        for (const DemandeMateriel& demande : demandes) {
            demande.afficher();
            cout << endl;
        }
    }
      // afficher toutes les réparations
    void afficherReparations() {
        cout << "Liste des réparations :" << endl;
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
        cout << "1. Gérer le matériel" << endl;
        cout << "2. Gérer les utilisateurs" << endl;
        cout << "3. Gérer les inventaires" << endl;
        cout << "4. Gérer les emplacements" << endl;
        cout << "5. Gérer les demandes de matériel" << endl;
        cout << "6. Gérer les réparations et maintenances" << endl;
        cout << "7. Surveiller les stocks" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choisissez une option : ";
        
        int choix;
        cin >> choix;

        if (choix == 0) {
            cout << "Fin du programme." << endl;
            break;
        } else if (choix == 1) {
            // Menu pour gérer le matériel
            while (true) {
                cout << "\n--- Menu Matériel ---" << endl;
                cout << "1. Ajouter du matériel" << endl;
                cout << "2. Modifier du matériel" << endl;
                cout << "3. Supprimer du matériel" << endl;
                cout << "4. Rechercher du matériel" << endl;
                cout << "5. Afficher l'inventaire complet" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixMateriel;
                cin >> choixMateriel;

                if (choixMateriel == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixMateriel == 1) {
                    // Ajouter du matériel
                    string nom, reference, type, emplacement;
                    bool statut;
                    int stock;

                    cout << "Entrez le nom du matériel : ";
                    cin >> nom;
                    cout << "Entrez la référence du matériel : ";
                    cin >> reference;
                    cout << "Entrez le type du matériel : ";
                    cin >> type;
                    cout << "Est-ce que le matériel est disponible ? (1 = Oui, 0 = Non) : ";
                    cin >> statut;
                    cout << "Entrez l'emplacement du matériel : ";
                    cin >> emplacement;
                    cout << "Entrez le niveau de stock du matériel : ";
                    cin >> stock;

                    TypeMateriel* typeMateriel = nullptr; 

if (type == "Ordinateur") {
    typeMateriel = new Ordinateur();
} else if (type == "Serveur") {
    typeMateriel = new Serveur();
} else if (type == "Tablette") {
    typeMateriel = new Tablette();
} else {
    cout << "Type de matériel inconnu : " << type << endl;
    return 1; 
}

Materiel nouveauMateriel(nom, reference, typeMateriel, statut, emplacement, stock);

                    inventaireManager.ajouterMateriel(nouveauMateriel);
                } else if (choixMateriel == 2) {
                   // Modifier du matériel
string reference;
cout << "Entrez la référence du matériel à modifier : ";
cin >> reference;

string nouveauNom, nouveauType, nouvelEmplacement;
bool nouveauStatut;
int nouveauStock;

cout << "Entrez le nouveau nom : ";
cin >> nouveauNom;
cout << "Entrez le nouveau type : ";
cin >> nouveauType;
cout << "Est-ce que le matériel est disponible ? (1 = Oui, 0 = Non) : ";
cin >> nouveauStatut;
cout << "Entrez le nouvel emplacement du matériel : ";
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
    cout << "Type de matériel inconnu : " << nouveauType << endl;
    return 1; 
}

Materiel materielModifie(nouveauNom, reference, nouveauTypeMateriel, nouveauStatut, nouvelEmplacement, nouveauStock);

inventaireManager.modifierMateriel(reference, materielModifie);
                } else if (choixMateriel == 3) {
                    // Supprimer du matériel
                    string reference;
                    cout << "Entrez la référence du matériel à supprimer : ";
                    cin >> reference;
                    inventaireManager.supprimerMateriel(reference);
                } else if (choixMateriel == 4) {
                    // Rechercher du matériel
                    string nom, reference, type;
                    cout << "Entrez le nom du matériel à rechercher (ou laissez vide) : ";
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Entrez la référence du matériel à rechercher (ou laissez vide) : ";
                    getline(cin, reference);
                    cout << "Entrez le type du matériel à rechercher (ou laissez vide) : ";
                    getline(cin, type);
                    
                    Materiel* materielTrouve = inventaireManager.rechercherMateriel(nom, reference, type);
                    if (materielTrouve != nullptr) {
                        cout << "\nMatériel trouvé :" << endl;
                        materielTrouve->afficher();
                    } else {
                        cout << "Aucun matériel trouvé." << endl;
                    }
                    
                    
                } else if (choixMateriel == 5) {
                	
    // Menu pour gérer les demandes de matériel
    string identifiant;
    cout << "Entrez l'identifiant de l'utilisateur : ";
    cin >> identifiant;

    // Rechercher l'utilisateur dans la liste des utilisateurs
    Utilisateur* utilisateur = inventaireManager.rechercherUtilisateur(identifiant);

    if (utilisateur != nullptr && utilisateur->aDroitAfficherInventaire()) {
        // Afficher l'inventaire complet
                cout << "Vous avez les autorisations nécessaires pour afficher l'inventaire." << endl;

        inventaireManager.afficherInventaireCompletMateriel();
    } else {
        // L'utilisateur n'a pas le droit de lire l'inventaire
        cout << "Vous n'avez pas les autorisations nécessaires pour afficher l'inventaire." << endl;
    }
}

     }}    else if(choix == 2) {
            // Menu pour gérer les utilisateurs
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
                    cout << "Entrez le département de l'utilisateur : ";
                    cin >> departement;

                    // Demander les droits d'accès
                    cout << "Entrez les droits d'accès de l'utilisateur (r w x séparés par des espaces, - si sans droit(exemple  r - - ), terminez avec 'fin') : ";
                    string droit;
                    while (cin >> droit && droit != "fin") {
                        droitsAcces.push_back(droit);
                    }

                    Utilisateur nouvelUtilisateur(nom, identifiant, departement, droitsAcces);
                    inventaireManager.ajouterUtilisateur(nouvelUtilisateur);
                } else if (choixUtilisateur == 2) {
                    // Modifier un utilisateur
                    string identifiant;
                    cout << "Entrez l'identifiant de l'utilisateur à modifier : ";
                    cin >> identifiant;

                    string nouveauNom, nouveauDepartement;
                    vector<string> nouveauxDroitsAcces;
                    cout << "Entrez le nouveau nom : ";
                    cin >> nouveauNom;
                    cout << "Entrez le nouveau département : ";
                    cin >> nouveauDepartement;

                    cout << "Entrez les nouveaux droits d'accès de l'utilisateur (séparés par des espaces, terminez avec 'fin') : ";
                    string droit;
                    while (cin >> droit && droit != "fin") {
                        nouveauxDroitsAcces.push_back(droit);
                    }

                    Utilisateur utilisateurModifie(nouveauNom, identifiant, nouveauDepartement, nouveauxDroitsAcces);
                    inventaireManager.modifierUtilisateur(identifiant, utilisateurModifie);
                } else if (choixUtilisateur == 3) {
                    // Supprimer un utilisateur
                    string identifiant;
                    cout << "Entrez l'identifiant de l'utilisateur à supprimer : ";
                    cin >> identifiant;
                    inventaireManager.supprimerUtilisateur(identifiant);
                } else if (choixUtilisateur == 4) {
                    // Rechercher un utilisateur
                    string nom, identifiant, departement;
                    cout << "Entrez le nom de l'utilisateur à rechercher (ou laissez vide) : ";
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Entrez l'identifiant de l'utilisateur à rechercher (ou laissez vide) : ";
                                        cin.ignore();

                    getline(cin, identifiant);
                    cout << "Entrez le département de l'utilisateur à rechercher (ou laissez vide) : ";
                                        cin.ignore();

                    getline(cin, departement);

                    Utilisateur* utilisateurTrouve = inventaireManager.rechercherUtilisateur(identifiant);
                    if (utilisateurTrouve != nullptr) {
                        cout << "\nUtilisateur trouvé :" << endl;
                        utilisateurTrouve->afficher();
                    } else {
                        cout << "Aucun utilisateur trouvé." << endl;
                    }
                } else if (choixUtilisateur == 5) {
                    // Afficher la liste des utilisateurs
                    inventaireManager.afficherUtilisateurs();
                }
            }
        } else if (choix == 3) {
            // Menu pour gérer les inventaires
            while (true) {
                cout << "\n--- Menu Inventaire ---" << endl;
                cout << "1. Afficher l'inventaire complet du matériel" << endl;
                cout << "2. Générer un rapport d'inventaire par type d'équipement" << endl;
                cout << "3. Générer un rapport d'inventaire par département" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixInventaire;
                cin >> choixInventaire;

                if (choixInventaire == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixInventaire == 1) {
                    // Afficher l'inventaire complet du matériel
                    inventaireManager.afficherInventaireCompletMateriel();
                } else if (choixInventaire == 2) {
                    // Générer un rapport d'inventaire par type d'équipement
                    string type;
                    cout << "Entrez le type d'équipement pour le rapport d'inventaire : ";
                    cin >> type;
                    inventaireManager.genererRapportParType(type);
                } else if (choixInventaire == 3) {
                    // Générer un rapport d'inventaire par département
                    string departement;
                    cout << "Entrez le département pour le rapport d'inventaire : ";
                    cin >> departement;
                    inventaireManager.genererRapportParDepartement(departement);
                }
            }
        } else if (choix == 4) {
            // Menu pour gérer les emplacements
            while (true) {
                cout << "\n--- Menu Emplacements ---" << endl;
                cout << "1. Assigner un emplacement à un équipement" << endl;
                cout << "2. Rechercher un équipement par emplacement" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixEmplacements;
                cin >> choixEmplacements;

                if (choixEmplacements == 0) {
                    // Retour au menu principal
                    break;
                } else if (choixEmplacements == 1) {
                    // Assigner un emplacement à un équipement
                    string reference, emplacement;
                    cout << "Entrez la référence de l'équipement : ";
                    cin >> reference;
                    cout << "Entrez l'emplacement à assigner : ";
                    cin >> emplacement;
                    inventaireManager.assignerEmplacement(reference, emplacement);
                } else if (choixEmplacements == 2) {
                    // Rechercher un équipement par emplacement
                    string emplacement;
                    cout << "Entrez l'emplacement pour la recherche : ";
                    cin >> emplacement;
                    inventaireManager.rechercherParEmplacement(emplacement);
                }
            }
        } else if (choix == 5) {
            // Menu pour gérer les demandes de matériel
            while (true) {
                cout << "\n--- Menu Demandes de Matériel ---" << endl;
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
                    cout << "Entrez le type de matériel demandé : ";
                    cin >> typeMateriel;
                    cout << "Entrez la date de la demande (jj-mm-aaaa) : ";
                    cin >> dateDemande;
                    cout << "Entrez la priorité (1 à 10) : ";
                    cin >> priorite;

                    DemandeMateriel nouvelleDemande(identifiantUtilisateur, typeMateriel, priorite, dateDemande);
                    inventaireManager.ajouterDemande(nouvelleDemande);
                } else if(choixDemande == 2) {
                    // Afficher toutes les demandes
                    inventaireManager.afficherDemandesMateriel();
                }
            }
        } else if(choix == 6) {
            // Menu pour gérer les réparations et maintenances
            while (true) {
                cout << "\n--- Menu Réparations et Maintenance ---" << endl;
                cout << "1. Enregistrer une réparation" << endl;
                cout << "2. Afficher toutes les réparations" << endl;
                cout << "0. Retour au menu principal" << endl;
                cout << "Choisissez une option : ";
                
                int choixReparation;
                cin >> choixReparation;

                if (choixReparation == 0) {
                    // Retour au menu principal
                    break;
                } else if(choixReparation == 1) {
                    // Enregistrer une réparation
                    string identifiantMateriel, descriptionPanne, dateReparation, historiqueReparations;

                    cout << "Entrez l'identifiant du matériel à réparer : ";
                    cin >> identifiantMateriel;
                    cout << "Entrez la description de la panne : ";
                    cin.ignore();
                    getline(cin, descriptionPanne);
                    cout << "Entrez la date de réparation (jj-mm-aaaa) : ";
                    cin >> dateReparation;
                    cout << "Entrez l'historique des réparations (séparé par des virgules) : ";
                    cin.ignore();
                    getline(cin, historiqueReparations);

                    Reparation nouvelleReparation(identifiantMateriel, descriptionPanne, dateReparation, historiqueReparations);
                    inventaireManager.ajouterReparation(nouvelleReparation);
                } else if(choixReparation == 2) {
                    // Afficher toutes les réparations
                    inventaireManager.afficherReparations();
                }
            }
        } else if(choix == 7) {
            // Menu pour surveiller les stocks
            inventaireManager.surveillerStock();
        } else {
            // Option invalide
            cout << "Option invalide. Veuillez réessayer." << endl;
        }
    }

    return 0;
}

