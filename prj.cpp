#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// ==================== CLASSE DE BASE: PERSONNE ====================
class Personne {
protected:
    int id;
    string nom;
    string email;
    string motDePasse;
    
public:
    // Constructeur
    Personne(int id, string nom, string email, string motDePasse) {
        this->id = id;
        this->nom = nom;
        this->email = email;
        this->motDePasse = motDePasse;
    }
    
    // Getters
    int getId() { return id; }
    string getNom() { return nom; }
    string getEmail() { return email; }
    
    // Setters
    void setNom(string nouveauNom) { nom = nouveauNom; }
    void setEmail(string nouvelEmail) { email = nouvelEmail; }
    
    // Méthode virtuelle pour affichage
    virtual void afficherInfo() {
        cout << "ID: " << id << endl;
        cout << "Nom: " << nom << endl;
        cout << "Email: " << email << endl;
    }
    
    // Destructeur virtuel
    virtual ~Personne() {}
};

// ==================== CLASSE DÉRIVÉE: AUTEUR ====================
class Auteur : public Personne {
private:
    string biographie;
    int nombreArticles;
    
public:
    // Constructeur
    Auteur(int id, string nom, string email, string motDePasse, string bio) 
        : Personne(id, nom, email, motDePasse) {
        this->biographie = bio;
        this->nombreArticles = 0;
    }
    
    // Getters
    string getBiographie() { return biographie; }
    int getNombreArticles() { return nombreArticles; }
    
    // Setters
    void setBiographie(string nouvelleBio) { biographie = nouvelleBio; }
    void incrementerArticles() { nombreArticles++; }
    void decrementerArticles() { 
        if (nombreArticles > 0) nombreArticles--; 
    }
    
    // Redéfinition de la méthode afficherInfo
    void afficherInfo() override {
        cout << "\n=== INFORMATIONS AUTEUR ===" << endl;
        Personne::afficherInfo();
        cout << "Biographie: " << biographie << endl;
        cout << "Nombre d'articles: " << nombreArticles << endl;
    }
};

// ==================== CLASSE DÉRIVÉE: LECTEUR ====================
class Lecteur : public Personne {
private:
    vector<int> articlesLus;
    
public:
    // Constructeur
    Lecteur(int id, string nom, string email, string motDePasse) 
        : Personne(id, nom, email, motDePasse) {}
    
    // Ajouter un article lu
    void ajouterArticleLu(int articleId) {
        articlesLus.push_back(articleId);
    }
    
    // Obtenir le nombre d'articles lus
    int getNombreArticlesLus() {
        return articlesLus.size();
    }
    
    // Redéfinition de la méthode afficherInfo
    void afficherInfo() override {
        cout << "\n=== INFORMATIONS LECTEUR ===" << endl;
        Personne::afficherInfo();
        cout << "Articles lus: " << articlesLus.size() << endl;
    }
};

// ==================== CLASSE DÉRIVÉE: ADMINISTRATEUR ====================
class Administrateur : public Personne {
private:
    string niveauAcces;
    
public:
    // Constructeur
    Administrateur(int id, string nom, string email, string motDePasse) 
        : Personne(id, nom, email, motDePasse) {
        this->niveauAcces = "COMPLET";
    }
    
    // Supprimer un article (simulation)
    void supprimerArticle(int articleId) {
        cout << "Article " << articleId << " supprime par l'administrateur." << endl;
    }
    
    // Modérer un commentaire (simulation)
    void modererCommentaire(int commentaireId, bool approuver) {
        if (approuver) {
            cout << "Commentaire " << commentaireId << " approuve." << endl;
        } else {
            cout << "Commentaire " << commentaireId << " rejete." << endl;
        }
    }
    
    // Redéfinition de la méthode afficherInfo
    void afficherInfo() override {
        cout << "\n=== INFORMATIONS ADMINISTRATEUR ===" << endl;
        Personne::afficherInfo();
        cout << "Niveau d'acces: " << niveauAcces << endl;
    }
};

// ==================== CLASSE: ARTICLE ====================
class Article {
private:
    int id;
    string titre;
    string contenu;
    int auteurId;
    string categorie;
    int nombreVues;
    int nombreLikes;
    time_t datePublication;
    
public:
    // Constructeur
    Article(int id, string titre, string contenu, int auteurId, string categorie) {
        this->id = id;
        this->titre = titre;
        this->contenu = contenu;
        this->auteurId = auteurId;
        this->categorie = categorie;
        this->nombreVues = 0;
        this->nombreLikes = 0;
        this->datePublication = time(0);
    }
    
    // Getters
    int getId() { return id; }
    string getTitre() { return titre; }
    string getContenu() { return contenu; }
    int getAuteurId() { return auteurId; }
    string getCategorie() { return categorie; }
    int getNombreVues() { return nombreVues; }
    int getNombreLikes() { return nombreLikes; }
    
    // Setters
    void setTitre(string nouveauTitre) { titre = nouveauTitre; }
    void setContenu(string nouveauContenu) { contenu = nouveauContenu; }
    void setCategorie(string nouvelleCategorie) { categorie = nouvelleCategorie; }
    
    // Incrémenter les vues
    void incrementerVues() { nombreVues++; }
    
    // Ajouter un like
    void ajouterLike() { nombreLikes++; }
    
    // Retirer un like
    void retirerLike() { 
        if (nombreLikes > 0) nombreLikes--; 
    }
    
    // Afficher l'article
    void afficher() {
        cout << "\n=== ARTICLE ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Titre: " << titre << endl;
        cout << "Contenu: " << contenu << endl;
        cout << "Auteur ID: " << auteurId << endl;
        cout << "Categorie: " << categorie << endl;
        cout << "Vues: " << nombreVues << endl;
        cout << "Likes: " << nombreLikes << endl;
    }
};

// ==================== CLASSE: COMMENTAIRE ====================
class Commentaire {
private:
    int id;
    int articleId;
    int utilisateurId;
    string contenu;
    time_t dateCreation;
    
public:
    // Constructeur
    Commentaire(int id, int articleId, int utilisateurId, string contenu) {
        this->id = id;
        this->articleId = articleId;
        this->utilisateurId = utilisateurId;
        this->contenu = contenu;
        this->dateCreation = time(0);
    }
    
    // Getters
    int getId() { return id; }
    int getArticleId() { return articleId; }
    int getUtilisateurId() { return utilisateurId; }
    string getContenu() { return contenu; }
    
    // Setter
    void setContenu(string nouveauContenu) { contenu = nouveauContenu; }
    
    // Afficher le commentaire
    void afficher() {
        cout << "\n--- Commentaire ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Article ID: " << articleId << endl;
        cout << "Utilisateur ID: " << utilisateurId << endl;
        cout << "Contenu: " << contenu << endl;
    }
};

// ==================== CLASSE: NOTIFICATION ====================
class Notification {
private:
    int id;
    int destinataireId;
    string message;
    bool lue;
    time_t dateCreation;
    
public:
    // Constructeur
    Notification(int id, int destinataireId, string message) {
        this->id = id;
        this->destinataireId = destinataireId;
        this->message = message;
        this->lue = false;
        this->dateCreation = time(0);
    }
    
    // Getters
    int getId() { return id; }
    int getDestinataireId() { return destinataireId; }
    string getMessage() { return message; }
    bool estLue() { return lue; }
    
    // Marquer comme lue
    void marquerCommeLue() { lue = true; }
    
    // Afficher la notification
    void afficher() {
        cout << "\n[NOTIFICATION]" << endl;
        cout << "Message: " << message << endl;
        cout << "Statut: " << (lue ? "Lue" : "Non lue") << endl;
    }
};

// ==================== CLASSE: GESTIONNAIRE DE BLOG ====================
class GestionnaireBlog {
private:
    vector<Auteur*> auteurs;
    vector<Lecteur*> lecteurs;
    vector<Administrateur*> administrateurs;
    vector<Article*> articles;
    vector<Commentaire*> commentaires;
    vector<Notification*> notifications;
    
public:
    // Ajouter un auteur
    void ajouterAuteur(Auteur* auteur) {
        auteurs.push_back(auteur);
        cout << "Auteur ajoute avec succes!" << endl;
    }
    
    // Ajouter un lecteur
    void ajouterLecteur(Lecteur* lecteur) {
        lecteurs.push_back(lecteur);
        cout << "Lecteur ajoute avec succes!" << endl;
    }
    
    // Ajouter un administrateur
    void ajouterAdministrateur(Administrateur* admin) {
        administrateurs.push_back(admin);
        cout << "Administrateur ajoute avec succes!" << endl;
    }
    
    // Publier un article
    void publierArticle(Article* article) {
        articles.push_back(article);
        
        // Incrémenter le nombre d'articles de l'auteur
        for (int i = 0; i < auteurs.size(); i++) {
            if (auteurs[i]->getId() == article->getAuteurId()) {
                auteurs[i]->incrementerArticles();
                break;
            }
        }
        
        cout << "Article publie avec succes!" << endl;
    }
    
    // Ajouter un commentaire
    void ajouterCommentaire(Commentaire* commentaire) {
        commentaires.push_back(commentaire);
        
        // Créer une notification pour l'auteur de l'article
        for (int i = 0; i < articles.size(); i++) {
            if (articles[i]->getId() == commentaire->getArticleId()) {
                int auteurId = articles[i]->getAuteurId();
                string message = "Nouveau commentaire sur votre article!";
                Notification* notif = new Notification(notifications.size() + 1, auteurId, message);
                notifications.push_back(notif);
                break;
            }
        }
        
        cout << "Commentaire ajoute avec succes!" << endl;
    }
    
    // Rechercher des articles par catégorie
    void rechercherParCategorie(string categorie) {
        cout << "\n=== ARTICLES DE LA CATEGORIE: " << categorie << " ===" << endl;
        bool trouve = false;
        for (int i = 0; i < articles.size(); i++) {
            if (articles[i]->getCategorie() == categorie) {
                articles[i]->afficher();
                trouve = true;
            }
        }
        if (!trouve) {
            cout << "Aucun article trouve dans cette categorie." << endl;
        }
    }
    
    // Afficher tous les auteurs
    void afficherAuteurs() {
        cout << "\n=== LISTE DES AUTEURS ===" << endl;
        for (int i = 0; i < auteurs.size(); i++) {
            auteurs[i]->afficherInfo();
        }
    }
    
    // Afficher tous les articles
    void afficherArticles() {
        cout << "\n=== LISTE DES ARTICLES ===" << endl;
        for (int i = 0; i < articles.size(); i++) {
            articles[i]->afficher();
        }
    }
    
    // Afficher les notifications d'un utilisateur
    void afficherNotifications(int utilisateurId) {
        cout << "\n=== NOTIFICATIONS ===" << endl;
        bool trouve = false;
        for (int i = 0; i < notifications.size(); i++) {
            if (notifications[i]->getDestinataireId() == utilisateurId) {
                notifications[i]->afficher();
                trouve = true;
            }
        }
        if (!trouve) {
            cout << "Aucune notification." << endl;
        }
    }
    
    // Destructeur
    ~GestionnaireBlog() {
        // Libérer la mémoire
        for (int i = 0; i < auteurs.size(); i++) delete auteurs[i];
        for (int i = 0; i < lecteurs.size(); i++) delete lecteurs[i];
        for (int i = 0; i < administrateurs.size(); i++) delete administrateurs[i];
        for (int i = 0; i < articles.size(); i++) delete articles[i];
        for (int i = 0; i < commentaires.size(); i++) delete commentaires[i];
        for (int i = 0; i < notifications.size(); i++) delete notifications[i];
    }
};

// ==================== FONCTION PRINCIPALE ====================
int main() {
    cout << "=== SYSTEME DE BLOG COLLABORATIF ===" << endl;
    
    // Créer le gestionnaire de blog
    GestionnaireBlog blog;
    
    // Créer des auteurs
    Auteur* auteur1 = new Auteur(1, "Taha Bannani", "taha@blog.com", "pass123", "Passione de technologie");
    Auteur* auteur2 = new Auteur(2, "Ihssane Belkadi", "ihssane@blog.com", "pass456", "Experte en design");
    
    blog.ajouterAuteur(auteur1);
    blog.ajouterAuteur(auteur2);
    
    // Créer un lecteur
    Lecteur* lecteur1 = new Lecteur(3, "Nour El Houda", "nour@blog.com", "pass789");
    blog.ajouterLecteur(lecteur1);
    
    // Créer un administrateur
    Administrateur* admin1 = new Administrateur(4, "Khaoula El Mezzi", "khaoula@blog.com", "admin123");
    blog.ajouterAdministrateur(admin1);
    
    // Publier des articles
    Article* article1 = new Article(1, "Introduction a C++", "Le C++ est un langage puissant...", 1, "Programmation");
    Article* article2 = new Article(2, "Design Web Moderne", "Les tendances du design web...", 2, "Design");
    
    blog.publierArticle(article1);
    blog.publierArticle(article2);
    
    // Ajouter des commentaires
    Commentaire* comm1 = new Commentaire(1, 1, 3, "Excellent article!");
    blog.ajouterCommentaire(comm1);
    
    // Afficher les informations
    blog.afficherAuteurs();
    blog.afficherArticles();
    
    // Rechercher par catégorie
    blog.rechercherParCategorie("Programmation");
    
    // Afficher les notifications
    blog.afficherNotifications(1);
    
    // Incrémenter les vues
    article1->incrementerVues();
    article1->ajouterLike();
    
    cout << "\n=== STATISTIQUES ARTICLE 1 ===" << endl;
    cout << "Vues: " << article1->getNombreVues() << endl;
    cout << "Likes: " << article1->getNombreLikes() << endl;
    
    return 0;
}