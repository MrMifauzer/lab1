#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Entity(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
    }


    virtual void attackEnemy(Entity& target) {
        int damage = attack - target.defense;
        if (damage > 0) {
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

  
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    virtual void heal(Entity& target ,int point) { //��� ������� ���� ��������� ����
        target.setHp(point);
        std::cout << name << " restores " << point << " heals " << target.getName() << std::endl;
    }
    //������ �������
    int getDef()
    {
        return(defense);
    }

    int getAtk()
    {
        return(attack);
    }

    int getHp()
    {
        return(health);
    }
    void setHp(int point)
    {
        health += point;
    }
    std::string getName() 
    { 
        return(name);
    }
    
    virtual ~Entity() {}
};
class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {
    }

    // ��������������� ������ attack
    void attackEnemy(Entity& target) override {
        int damage = attack - target.getDef();
        if (damage > 0) {
            // ���� �� ����������� ���� (20%)
            if (rand() % 100 < 20) {
                damage *= 2;
                std::cout << "Critical hit! ";
            }
            target.setHp(-damage);
            std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }


    void displayInfo() const override {
        std::cout << "Character: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
    void heal(Entity& target, int point) override { // ��������������� ���������
        target.setHp(point*2); // ����� ������� � 2 ���� �����
        std::cout<< "Holy " << name << " restores " << point*2 << " heals " << target.getName() << std::endl;
    }
};

class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {
    }


    void attackEnemy(Entity& target) override {
        int damage = attack - target.getDef();
        if (damage > 0) {
            // ���� �� �������� ����� (30%)
            if (rand() % 100 < 30) {
                damage += 5; // �������������� ���� �� ���
                std::cout << "Poisonous attack! ";
            }
            target.setHp(-damage);
            std::cout << name << " attacks " << target.getName()<< " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }

    // ��������������� ������ displayInfo
    void displayInfo() const override {
        std::cout << "Monster: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

//����� Boss
class Boss : public Monster {
public:
    Boss(const std::string& n, int h, int a, int d)
        : Monster(n, h, a, d) {
    }
    void attackEnemy(Entity& target) override {
        int damage = attack - target.getDef() / 2; //����� ��������� �����, ��� ������� ����������
        if (damage > 0) {
            // ���� �� ����������� (90% ��� �����������)
            if (rand() % 100 < 90) {
                damage = target.getHp(); //���� ����� ������� ����
                std::cout << "BREEDING! ";
            }
            target.setHp(-damage);// � ���� ���� �� ����������� ������
            std::cout << name << " bites " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " bites " << target.getName() << ", but it has no effect!\n";
        }
    }
    void displayInfo() const override {
        std::cout << "Monster: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense 
            << "\n Special ability: 90% chance to incinerate the enemy." << std::endl;
    }
};


int main() {
    srand(static_cast<unsigned>(time(0)));

  
    Character hero("Hero", 100, 20, 10);
    Monster goblin("Goblin", 50, 15, 5);
    Boss dragon("Dragon", 150, 25, 20); //  ������ ������������������ � �����

 
    Entity* entities[] = { &hero, &goblin, &dragon };

    for (auto& entity : entities) {
        entity->displayInfo(); 
    }

  
    hero.attackEnemy(dragon);
    goblin.attackEnemy(hero);
    hero.heal(hero, 10);
    for (auto& entity : entities) {
        entity->displayInfo();
    }
    dragon.attackEnemy(hero);

    return 0;
}
