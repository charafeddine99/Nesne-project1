// Oyuncu sinifi
class Player : public GameObject { // GameObject sınıfından türetilmiş
private:
    int attackPower; // Oyuncunun süldürme gücü
    int x, y; // Oyuncunun harita üzerindeki konumu

public:
    Player(const string& name, int health, int attackPower, int startX, int startY)
        : GameObject(name, health), attackPower(attackPower), x(startX), y(startY) { // Yapıcı fonksiyon
    }

    void move(char direction, int mapSize) { // Oyuncuyu belirtilen yönde hareket ettiren fonksiyon
        switch (direction) {
        case 'w':
            if (y > 0) y--; // Yukarı hareket
            break;
        case 's':
            if (y < mapSize - 1) y++; // Aşağı hareket
            break;
        case 'a':
            if (x > 0) x--; // Sola hareket
            break;
        case 'd':
            if (x < mapSize - 1) x++; // Sağa hareket
            break;
        default:
            cout << "Gecersiz hareket!" << endl; // Hatalı girdi durumu
        }
        cout << name << " konumuna tasindi: (" << x << ", " << y << ")" << endl; // Yeni konumu gösterir
    }

    void attack(GameObject& target) { // Oyuncunun hedefe saldırdığı fonksiyon
        int damage = attackPower; // Hasar mıktarını belirler
        target.takeDamage(damage); // Hedefe hasar uygular
        cout << name << " " << target.getName() << "'ye saldirdi ve " << damage << " hasar verdi!" << endl; // Saldırıyı bildirir
    }

    void heal() { // Oyuncuyu iyileştiren fonksiyon
        int healAmount = 20; // İyileşme miktarı
        health += healAmount; // Sağlığı arttır
        cout << name << " iyilesti ve " << healAmount << " saglik kazandi. Mevcut saglik: " << health << endl; // Durumu bildirir
    }

    int getX() const { return x; } // Oyuncunun x koordinatını döndürür
    int getY() const { return y; } // Oyuncunun y koordinatını döndürür
};

// Harita sinifi
class Map {
private:
    vector<vector<char>> grid; // Harita için 2D karakter matrisi
    int size; // Harita boyutu
    pair<int, int> treasurePosition; // Hazine konumu

public:
    Map(int size) : size(size) { // Yapıcı fonksiyon, harita boyutunu ayarlar
        grid = vector<vector<char>>(size, vector<char>(size, '.')); // Harita nokta (‘.’) ile doldurulur
        placeTreasure(); // Hazineyi yerleştirir
    }

    void placeTreasure() { // Hazineyi haritada rastgele bir yere yerleştirir
        treasurePosition.first = rand() % size; // Rastgele x koordinatı
        treasurePosition.second = rand() % size; // Rastgele y koordinatı
        grid[treasurePosition.first][treasurePosition.second] = 'T'; // Hazineyi ‘T’ ile işaretler
    }

    bool isTreasure(int x, int y) { // Oyuncunun koordinatlarında hazine olup olmadığını kontrol eder
        return x == treasurePosition.first && y == treasurePosition.second;
    }

    void display(Player& player) { // Haritayı ekrana yazdırır
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == player.getY() && j == player.getX()) {
                    cout << 'P' << " "; // Oyuncuyu ‘P’ ile gösterir
                }
                else if (i == treasurePosition.first && j == treasurePosition.second) {
                    cout << 'T' << " "; // Hazineyi ‘T’ ile gösterir
                }
                else {
                    cout << grid[i][j] << " "; // Boş alanı nokta ile gösterir
                }
            }
            cout << endl;
        }
    }
};
