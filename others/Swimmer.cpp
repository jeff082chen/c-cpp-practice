#include <iostream>
#include <string>

class Swimmer {
public:
    virtual void swim(void) = 0;
    virtual ~Swimmer(void) = default;
};

class Human : public Swimmer {
protected:
    std::string firstName;
    std::string lastName;

public:
    Human(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName) {}

    std::string getFirstName(void) {
        return this->firstName;
    }

    std::string getLastName(void) {
        return this->lastName;
    }

    void swim(void) override {
        std::cout << "人類 " + this->firstName + " " + this->lastName + " 游泳" << std::endl;
    }
};

class Submarine : public Swimmer {
protected:
    std::string nickName;

public:
    Submarine(std::string nickName) : nickName(nickName) {}

    std::string getNickName(void) {
        return this->nickName;
    }

    void swim(void) override {
        std::cout << "潛水艇 " + this->nickName + " 潛行" << std::endl;
    }
};

class Fish : public Swimmer {
protected:
    std::string name;

public:
    Fish(std::string name) : name(name) {}

    std::string getName(void) {
        return this->name;
    }
};

class Anemonefish : public Fish {
public:
    using Fish::Fish;

    void swim(void) override {
        std::cout << "小丑魚 " + this->name + " 游泳" << std::endl;
    }
};

class Shark : public Fish {
public:
    using Fish::Fish;

    void swim(void) override {
        std::cout << "鯊魚 " + this->name + " 游泳" << std::endl;
    }
};

class Piranha : public Fish {
public:
    using Fish::Fish;

    void swim(void) override {
        std::cout << "食人魚 " + this->name + " 游泳" << std::endl;
    }
};

void doSwim(Swimmer &swimmer) {
    swimmer.swim();
}

int main(void) {
    Anemonefish anemonefish("Nemo");
    Shark shark("Zack");
    Human human("Jeff", "Lin");
    Human human2("Nancy", "Chen");
    Submarine submarine("yellow the 1st");

    doSwim(anemonefish);
    doSwim(shark);
    doSwim(human);
    doSwim(human2);
    doSwim(submarine);
    return 0;
}
