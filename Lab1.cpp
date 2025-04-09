#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // ��������� ����: ��� ���������
    int health;        // ��������� ����: ������� ��������
    int attack;        // ��������� ����: ������� �����
    int defense;       // ��������� ����: ������� ������

    int maxHealth;      // ��������� ����: ������ ����� �������� (������������ � heal)

public:
    // ����������� ��� ������������� ������
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), maxHealth(h), attack(a), defense(d) {
    }

    // ����� ��� ��������� ������ ��������
    int getHealth() const {
        return health;
    }

    // ����� ��� ������ ���������� � ���������
    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    // ����� ��� ����� ������� ���������
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    // ����� ��� �������������� ��������
    void heal(int point) {
        health += point;
        if (health > maxHealth) {
            health = maxHealth;
            std::cout << name << " is restored to the limit of " << health << "health!" << std::endl;
        }
        else {
            std::cout << name << " is restored to " << point << " health!" << std::endl;
        }
    }

    // ����� ��� �������������� �����
    void takeDamege(int point) {
        health -= point;
        if (health <= 0) {
            std::cout << name << " receives deadly damage, but survives!" << std::endl;
            health = 1;
        }
        else {
            std::cout << name << " receives " << point << " damage!"<<std::endl;
        }
    }
};

int main() {
    // ������� ������� ����������
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    // ������� ���������� � ����������
    hero.displayInfo();
    monster.displayInfo();

    // ����� ������� �������
    hero.attackEnemy(monster);
    monster.displayInfo();

    // ������ �����������������
    monster.heal(10);
    monster.displayInfo();

    //����� �����������
    hero.takeDamege(999);
    hero.displayInfo();
    return 0;
}
