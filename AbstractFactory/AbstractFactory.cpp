// AbstractFactory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Harbirove  abstract  {
public:
    virtual void Animal() = 0;
    virtual int GetWeight() = 0;
    virtual void EatGrass() = 0;
    virtual bool IsAlive() = 0;
    virtual void aliveNow(bool al) = 0;
};

class Carnivore abstract {
public:
    virtual void Animal() = 0;
    virtual void Eat(Harbirove* herbivore) = 0;

    
};
class Continent  abstract {
public:
    virtual Harbirove* GetHarbiroveContinent() abstract;
    virtual Carnivore* GetCarnivoreContinent() abstract;
};
class Wolf : public Carnivore {
    int power = 50;
public:
    void Animal()  override {
        cout << "Wolf " << "Power = " << power << endl;
     }
    void Eat(Harbirove* harbivore) override  {
        
        
        if (power > harbivore->GetWeight() ) {
            power += 10;
            harbivore->aliveNow(false);
        }
        else {
            power -= 10;
        }
    }
};
class Tiger : public Carnivore {
    int power = 80;


public:
    void Animal() override {
        cout << "Tiger " << "Power = " << power << endl;
    }
    void Eat(Harbirove* harbivore) override {
       

        if (power > harbivore->GetWeight()) {
            power += 10;
            harbivore->aliveNow(false);
        }
        else {
            power -= 10;
        }
    }
};
class Lion : public Carnivore {
    int power = 90;
    
   
public:
    void Animal() override {
        cout << "Lion " << "Power = " << power << endl;
    }
    void Eat(Harbirove* harbivore) override {
       

        if (power > harbivore->GetWeight()) {
            power += 10;
            harbivore->aliveNow(false);
        }
        else {
            power -= 10;
        }
    }
};
class Elk : public Harbirove {
    int weight = 70;
    bool isAlive = true;
public:
    int GetWeight() override {
        return weight;
    }
    void Animal() override {
        cout << "Elk " << "Weight = " << weight << endl;
    }

    void EatGrass() override {
        cout << "Elk eats " << weight + 10 << endl;
    }
    void aliveNow(bool al) override {
        al = isAlive;
    }
    bool IsAlive() override {
        return this->isAlive;
    }
};
class Bison : public Harbirove {
    int weight = 100;
    bool isAlive = true;
public:
    int GetWeight() override {
        return weight;
    }
    void Animal() override {
        cout << "Bison " << "Weight = " << weight << endl;
    }
    
    void EatGrass() override {
        cout << "Bison eats " << weight + 10 << endl;
    }
    void aliveNow(bool al) override {
        al = isAlive;
    }
    bool IsAlive() override {
        return this->isAlive;
    }
};
class Wildebeest : public Harbirove {
    int weight = 20;
    bool isAlive = true;
public:
    int GetWeight() override {
        return weight;
    }
    void Animal() override {
        cout << "Wildebeest " << "Weight = " << weight << endl;
    }
    void EatGrass() override {
        cout << "Wildebeest eats " << weight + 10 << endl;
    }
    bool IsAlive() override {
        return this->isAlive;
    }
    void aliveNow(bool al) override {
        al = isAlive;
    }
};
class Africa : public Continent {
public:
    Harbirove* GetHarbiroveContinent() {
        return new  Wildebeest();
    }
    Carnivore* GetCarnivoreContinent() {
        return new Lion();
    }
};

class America : public Continent {
public:
    Harbirove* GetHarbiroveContinent() {
        return new  Bison();
    }
    Carnivore* GetCarnivoreContinent() {
        return new Wolf();
    }
};
class Eurasia : public Continent {
    Harbirove* GetHarbiroveContinent() {
        return new Elk();
    }
    Carnivore* GetCarnivoreContinent() {
        return new Tiger();
    }
};

class AnimalWorld {
    Harbirove* har;
    Carnivore* carn;
public:
    AnimalWorld(Harbirove* h, Carnivore* c ) {
        har = h;
        carn = c;
       
    }
    void Harb() {
        if (har->IsAlive()) {
            cout << "Harbirove eats now " << endl;
            har->EatGrass();
            har->Animal();
        }
    }
    void Carn() {
        if (har->IsAlive()) {
            cout << "Carnivore eats now " << endl;
            carn->Eat(har);
        }
    }
};
void Print(Continent* cont, const string name) {
    cout << name << ":" << endl;
    AnimalWorld world(cont->GetHarbiroveContinent(), cont->GetCarnivoreContinent());
    world.Harb();
    world.Carn();
}

int main()
{
    Print(new Africa(), "Africa");
    Print(new America(), "America");
    Print(new Eurasia(), "Eurasia");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
