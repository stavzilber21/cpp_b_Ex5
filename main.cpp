//
// Created by shaul on 09/05/2022.
//
#include "sources/OrgChart.hpp"
#include "string"
using namespace ariel;
using namespace std;
int main(){
//create object person for this test
class Person {
public:
    string name;
    int age;

    Person(string Name, int Age) : name(Name), age(Age) {}

    bool operator==(Person &p1) {
        return this->name == p1.name;
    }
};
//instantiate People
Person Great_GrandFather("Great_GrandFather", 85);
Person Grandfather("GrandFather", 65);
Person Father("Father", 45);
Person Uncle("Uncle", 43);
Person Aunt("Aunt", 43);
Person Son("Son", 20);
Person Daughter("Daughter", 18);
Person Cousin("Cousin", 15);

OrgChart chart1;
chart1.add_root(Aunt.name);
chart1.add_root(Great_GrandFather.name);
chart1.add_sub(Great_GrandFather.name, Grandfather.name);
chart1.add_sub(Grandfather.name, Father.name);
chart1.add_sub(Grandfather.name, Uncle.name);
chart1.add_sub(Grandfather.name, Aunt.name);
chart1.add_sub(Father.name, Son.name);
chart1.add_sub(Father.name, Daughter.name);
chart1.add_sub(Uncle.name, Cousin.name);



//add another field and check that it works
Person Cousin2("Cousin2", 14);
chart1.add_sub(Aunt.name, Cousin2.name);
    vector<string> lvl_order;
    for (auto person: chart1) {
        lvl_order.push_back(person);
    }
    cout << lvl_order.size();
    for (int i = 0; i < lvl_order.size(); ++i) {
           cout << lvl_order[i];
}
//    lvl_order.at(0), Great_GrandFather.name;
//    lvl_order.at(1), Grandfather.name;
//    lvl_order.at(2), Father.name;
//    lvl_order.at(3), Uncle.name;
//    lvl_order.at(4), Aunt.name;
//    lvl_order.at(5), Son.name;
//    lvl_order.at(6), Daughter.name;
//    lvl_order.at(7), Cousin.name;



}


