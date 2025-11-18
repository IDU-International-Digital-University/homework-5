#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class GameCharacter {
    protected:
        int health;
        int level;
        int position;

    public:
        GameCharacter(int h, int l, int p)
            : health(h), level(l), position(p) {}

        virtual ~GameCharacter() = default;

        bool isAlive() const { return health > 0; }

        virtual void attack(GameCharacter& target) = 0;
        virtual void defend(int damage) = 0;
        virtual void useSpecialAbility(GameCharacter& target) = 0;

        void showStatus() const {
            cout << "HP: " << health << " | Level: " << level
                << " | Pos: " << position << endl;
        }
};

class Warrior : public GameCharacter {
    public:
        Warrior(int level)
            : GameCharacter(150, level, 0) {}

        void attack(GameCharacter& target) override {
            int dmg = 20 + level * 3;
            cout << "Warrior attacks with sword! Damage: " << dmg << endl;
            target.defend(dmg);
        }

        void defend(int damage) override {
            int reduced = damage - 10;
            if (reduced < 0) reduced = 0;
            health -= reduced;
            cout << "Warrior blocks attack! Damage taken: " << reduced << endl;
        }

        void useSpecialAbility(GameCharacter& target) override {
            int dmg = 40 + level * 4;
            cout << "Warrior uses BERSERK! Massive damage: " << dmg << endl;
            target.defend(dmg);
        }
};

class Mage : public GameCharacter {
    public:
        Mage(int level)
            : GameCharacter(90, level, 0) {}

        void attack(GameCharacter& target) override {
            int dmg = 25 + level * 4;
            cout << "Mage casts Fireball! Damage: " << dmg << endl;
            target.defend(dmg);
        }

        void defend(int damage) override {
            int taken = damage + 5; // very weak armor
            health -= taken;
            cout << "Mage is hit! Damage taken: " << taken << endl;
        }

        void useSpecialAbility(GameCharacter& target) override {
            int dmg = 50 + level * 5;
            cout << "Mage uses LIGHTNING STORM! Damage: " << dmg << endl;
            target.defend(dmg);
        }
};

class Archer : public GameCharacter {
    public:
        Archer(int level)
            : GameCharacter(120, level, 0) {}

        void attack(GameCharacter& target) override {
            int dmg = 18 + level * 3;
            cout << "Archer shoots an arrow! Damage: " << dmg << endl;
            target.defend(dmg);
        }

        void defend(int damage) override {
            int reduced = damage - 5;
            if (reduced < 0) reduced = 0;
            health -= reduced;
            cout << "Archer evades partially! Damage taken: " << reduced << endl;
        }

        void useSpecialAbility(GameCharacter& target) override {
            int dmg = 35 + level * 4;
            cout << "Archer uses MULTI-SHOT! Damage: " << dmg << endl;
            target.defend(dmg);
        }
};

void battle(GameCharacter& a, GameCharacter& b) {
    cout << "\n===== BATTLE START =====\n";

    int round = 1;
    while (a.isAlive() && b.isAlive()) {
        cout << "\n--- Round " << round++ << " ---\n";

        a.attack(b);
        if (!b.isAlive()) break;

        b.attack(a);
        if (!a.isAlive()) break;

        if (round % 3 == 0) {
            cout << "\nSpecial Abilities Triggered!\n";
            a.useSpecialAbility(b);
            b.useSpecialAbility(a);
        }

        cout << "\nA status: ";
        a.showStatus();
        cout << "B status: ";
        b.showStatus();
    }

    cout << "\n===== BATTLE END =====\n";

    if (a.isAlive())
        cout << "Winner: Character A\n";
    else
        cout << "Winner: Character B\n";
}

int main() {
    Warrior w(3);
    Mage m(3);

    battle(w, m);

    cout << "\nAnother battle:\n";
    Archer a(2);
    Warrior w2(2);

    battle(a, w2);

    return 0;
}
