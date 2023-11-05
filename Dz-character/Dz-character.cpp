#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
class Items {
public:
   Items(std::string new_name) :name(new_name){}
   std::string Get_Name() {
       return this->name;
   }



private:
    std::string name;
    int size;
    char purpose;
};



class Helmet : public Items {
public:
    Helmet(std::string new_name): Items(new_name){}

};

class Boots : public Items {
public:
    Boots(std::string new_name):Items(new_name){}
};

class Hauberk:public Items {
public:
    Hauberk(std::string new_name) :Items(new_name) {}
};

class Character {
public:
    Character(int up_health, char ch_gender, int new_age, int new_height):
        health(up_health),gender(ch_gender), age(new_age), height(new_height){}

    void Set_health(int new_health) {
        this->health = new_health;
    }

    void Move() {
        std::cout << "Топ топ топ" << "\n";
    }


    void Add_Bag_Item(Items *obj) {
        if (Bag.size() == 2) {
            std::cout << "Рюкзак заполнен"<<"\n";
        }
        else Bag.push_back(obj);
    }

    void Equim_item_helmet(Helmet *obj) {
        std::cout << "Шлем надет"<<"\n";
        equipment_slots[obj] = obj->Get_Name();

    }
    void Equim_item_Boots(Boots* obj) {
        std::cout << "сапоги надеты"<<"\n";
        equipment_slots[obj] = obj->Get_Name();
    }
    void Equim_item_Hauberk(Hauberk* obj) {
        equipment_slots[obj] = obj->Get_Name();
    }

    void show_slots() {
        std::cout << "сейчас в слотах снаряжения: " << "\n";
        for (const auto& element : this->equipment_slots)
            std::cout << element.first << "\t" << element.second << std::endl;
    }
    void show_bag() {
        std::cout << "сейчас в рюкзаке" << "\n";
        for (auto& el : this->Bag) {
            std::cout << el->Get_Name() << "\n";
        }
    }
    

private:
    int health;
    char gender;
    int age;
    int height;
    std::vector<Items*> Bag;
    std::map<Items*, std::string> equipment_slots;
    

};







int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout << "Hello World!\n";
    int health = 100;
    Boots Scorohods("Сапоги скороходы");
    Hauberk Iron_armor("Железная броня");
    Helmet Iron_helmet("Железный шлем");
    Items sword("катана");
    Character Peter(health, 'm', 20, 180);
    Peter.Equim_item_Boots(&Scorohods);
    Peter.Equim_item_Hauberk(&Iron_armor); 
    Peter.Equim_item_helmet(&Iron_helmet);
    Peter.Add_Bag_Item(&sword);
    Peter.show_bag();
    Peter.show_slots();

}

