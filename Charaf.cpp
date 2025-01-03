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


// Ana oyun dongusu
int main() {
    srand(time(0)); // Rastgelelik için zamanı kullan

    cout << "Hazine Avcisi Oyununa Hosgeldiniz!" << endl; // Oyuna karşılama mesajı
    int mapSize = 5; // Harita boyutunu belirle
    Map map(mapSize); // Haritayı oluştur

    Player player("Oyuncu", 100, 25, 0, 0); // Oyuncu oluştur
    Enemy enemy("Dusman", 50, 15); // Dusman oluştur

    while (player.isAlive()) { // Oyuncu yaşadıkça oyun devam eder
        cout << "\nHarita:" << endl;
        map.display(player); // Haritayı göster

        cout << "\nHareket (w: yukari, s: asagi, a: sola, d: saga): "; // Hareket seçenekleri
        char moveDirection;
        cin >> moveDirection; // Oyuncunun hareket yönü

        player.move(moveDirection, mapSize); // Oyuncuyu hareket ettir

        if (map.isTreasure(player.getX(), player.getY())) { // Oyuncu hazinenin konumundaysa
            cout << "Tebrikler! Hazinenizi buldunuz!" << endl; // Kazandı bildirimi
            break;
        }

        if (rand() % 3 == 0) { // Yuzde 33 olasilikla bir dusman cikar
            cout << "\nBir dusman belirdi!" << endl;
            battle(player, enemy); // Savaş başlat

            if (enemy.isAlive()) { // Dusman yaşıyorsa yeni bir dusman yaratılır
                enemy = Enemy("Dusman", 50, 15);
            }
        }

        if (!player.isAlive()) { // Oyuncu öldüyse oyun biter
            cout << "Oyun Bitti! Kaybettiniz. Tekrar deneyin!" << endl;
            break;
        }
    }

    return 0; // Programın başarıyla sona erdiğini bildirir
}