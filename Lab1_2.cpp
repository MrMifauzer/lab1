#include <iostream>
#include <string>

class Entity {
protected:
    std::string name; // ���������� ����: ���
    int health;      // ���������� ����: ��������

public:
    // ����������� �������� ������
    Entity(const std::string& n, int h) : name(n), health(h) {}

    // ����� ��� ������ ����������
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health << std::endl;
    }

    virtual ~Entity() {}
};

class Player : public Entity {
private:
    int experience; // ��������� ����: ����

public:
    // ����������� ������������ ������
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {
    }

    // ��������������� ������ displayInfo
    void displayInfo() const override {
        Entity::displayInfo(); // ����� ������ �������� ������
        std::cout << "Experience: " << experience << std::endl;
    }
};

class Enemy : public Entity {
private:
    std::string type; // ��������� ����: ��� �����

public:
    // ����������� ������������ ������
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {
    }

    // ��������������� ������ displayInfo
    void displayInfo() const override {
        Entity::displayInfo(); // ����� ������ �������� ������
        std::cout << "Type: " << type << std::endl;
    }
};
// ����� Boss, ������� ��������� �� Enemy
class boss : public Enemy {
private:
    std::string spetialAbility; // �������� ����������� �����������

public:
    boss(const std::string& n, int h, const std::string& t, const std::string& sa)  //��������������� ������������
        : Enemy(n, h, t), spetialAbility(sa) {} 
    void displayInfo() const {  //��������������� ������ ����������
        Enemy::displayInfo();
        std::cout << "Spetial Ability: " << spetialAbility << std::endl; 
    }
};

int main() {
    // ������� ������� ������ � �����
    Player hero("Hero", 100, 0);
    Enemy monster("Small Goblin", 30, "Goblin");

    // ������� ���������� � ����������
    hero.displayInfo();
    monster.displayInfo();

    boss monsterBoss("Goblin Shaman", 75, "Goblin", "It inflicts additional damage to living beings");
    monsterBoss.displayInfo();
    return 0;
}
