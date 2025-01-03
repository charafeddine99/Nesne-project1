#include <iostream> // C++'da girdi ve çıktı işlemleri için gerekli kütüphane
#include <vector> // Vektör veri yapısını kullanmak için kütüphane
#include <cstdlib> // Rastgele sayı üretimi için gerekli kütüphane
#include <ctime> // Zaman tabanlı rastgelelik için kütüphane

using namespace std; // Standart isim alanını (std) kullanabilmek için

// Temel sinif: GameObject (Oyun Nesnesi)
class GameObject {
protected:
    string name; // Nesnenin ismi
    int health; // Nesnenin sağlık puanı

public:
    GameObject(const string& name, int health)
        : name(name), health(health) { // Yapıcı fonksiyon: nesnenin ismi ve sağlığı ayarlanıyor
    }

    virtual void displayStatus() const { // Nesnenin durumunu ekrana yazdıran sanal fonksiyon
        cout << name << " - Saglik: " << health << endl;
    }

    bool isAlive() const { // Nesnenin yaşayıp yaşamadığını kontrol eder
        return health > 0;
    }

    void takeDamage(int damage) { // Nesne hasar aldığında sağlık puanını azaltır
        health -= damage;
        if (health < 0) health = 0; // Sağlık negatif olmamalı
    }

    string getName() const { // Nesnenin ismini döndüren fonksiyon
        return name;
    }
};


// Dusman sinifi
class Enemy : public GameObject { // GameObject sınıfından türetilmiş
private:
    int attackPower; // Dusmanın süldürme gücü

public:
    Enemy(const string& name, int health, int attackPower)
        : GameObject(name, health), attackPower(attackPower) { // Yapıcı fonksiyon
    }

    void attack(Player& player) { // Dusmanın oyuncuya saldırdığı fonksiyon
        int damage = attackPower; // Hasar mıktarını belirler
        player.takeDamage(damage); // Oyuncuya hasar uygular
        cout << name << " saldiridi! " << player.getName() << " " << damage << " hasar aldi!" << endl; // Saldırıyı bildirir
    }
};

