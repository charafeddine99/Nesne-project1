#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Temel sinif: GameObject (Oyun Nesnesi)
class GameObject {
protected:
    string name;
    int health;

public:
    GameObject(const string& name, int health)
        : name(name), health(health) {
    }

    virtual void displayStatus() const {
        cout << name << " - Saglik: " << health << endl;
    }

    bool isAlive() const {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    string getName() const {
        return name;
    }
};