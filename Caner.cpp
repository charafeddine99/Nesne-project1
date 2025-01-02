// Oyuncu sinifi
class Player : public GameObject {
private:
    int attackPower;
    int x, y; // Oyuncunun harita uzerindeki konumu

public:
    Player(const string& name, int health, int attackPower, int startX, int startY)
        : GameObject(name, health), attackPower(attackPower), x(startX), y(startY) {
    }

    void move(char direction, int mapSize) {
        switch (direction) {
        case 'w':
            if (y > 0) y--;
            break;
        case 's':
            if (y < mapSize - 1) y++;
            break;
        case 'a':
            if (x > 0) x--;
            break;
        case 'd':
            if (x < mapSize - 1) x++;
            break;
        default:
            cout << "Gecersiz hareket!" << endl;
        }
        cout << name << " konumuna tasindi: (" << x << ", " << y << ")" << endl;
    }

    void attack(GameObject& target) {
        int damage = attackPower;
        target.takeDamage(damage);
        cout << name << " " << target.getName() << "'ye saldirdi ve " << damage << " hasar verdi!" << endl;
    }

    void heal() {
        int healAmount = 20;
        health += healAmount;
        cout << name << " iyilesti ve " << healAmount << " saglik kazandi. Mevcut saglik: " << health << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};