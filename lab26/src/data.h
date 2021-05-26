/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 17-march-2021
 * @version 1.0
 */
#pragma once
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

//long fileSize(FILE * file);


enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};
//static char material[3][20] = {"Brazilian Tree", "Pernambuco", "Fiberglass"};

class Bow {
public:
    int weight;
    enum Material material;

    Bow(): weight(0), material(){

    }
    Bow(int w, Material m): weight(w), material(m){

    }
    Bow(const Bow& copy ): weight(copy.weight), material(copy.material){

    }
    int getWeight() const{
        return weight;
    }
    Material getMat() const{
        return material;
    }
    virtual ~Bow(){

    }


    void setMat(Material material){
        Bow::material = material;
    }
    void setWeight(int weight) {
        Bow::weight = weight;
    }

    //void print() const;
    friend std::istream& operator>> (std::istream &input, Bow& bow);
    void readFromFileBow(std::ifstream &f);
    //void writeInFileBow(std::ofstream &f);
    Bow& getBowFromString();

};

/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
class Instrument {
protected:
    string type;
    string firm;
    int year;
    float size;
    Bow bow;
public:
Instrument(): type(), firm(), year(0), size(0), bow(0, BT){

}
Instrument (const string& t, const string& f, const int year, const float size, const Bow& bow ): type(t), firm(f), year(year), size(size), bow(bow){
    type = t;
    firm = f;
}

Instrument(const Instrument& copy): type(copy.type), firm(copy.firm), year(copy.year), size(copy.size), bow(copy.bow){
    type = copy.type;
    firm = copy.firm;
}
    void printTheOldestInstrument(std::string& name);
    Instrument& getInstrumentFromString(std::string& str);
    std::string& getFirm();
    int getYear() const;
    std::string& getType();
    float getSize() const;

    void setType(string& t){
        Instrument::type = t;
    }
    void setYear(int y) {
        Instrument::year = y;
    }
    void setSize(float s){
        Instrument::size = s;
    }
    void setBow(Bow& bow1) {
        Instrument::bow = bow1;
    }


    friend std::ostream& operator<<(std::ostream& out, const Instrument &instrument) {   // no way to override operators
        out << instrument.getInfo();
        return out;
    }
    virtual string getInfo() const;

    //void print() const;
    void readElementFromFile(std::ifstream &f);
    void writeInFileInstr(std::ofstream &f) const;

    bool operator == (const std::string& name) const {
        return this->firm == name;
    }
    bool operator == (const Instrument& other) const {
        return this->firm == other.firm && this->type == other.type && this->size == other.size && this->bow.getWeight() == other.bow.getWeight();

    }
    bool operator != (const Instrument& other) const {
        return !(this->firm == other.firm);
    }
    friend std::istream& operator>> (std::istream &input, Instrument& instrument);
    friend std::ostream& operator<< (std::ostream &output, const Instrument& instrument);

    virtual ~Instrument() = default;

};
enum ViolinType {SOLO = 1, ORCHESTRAL = 2, UNIVERSAL = 3};

class Violin: public Instrument {
protected:
    bool hasBridge;
    bool hasChinRest;
    enum ViolinType violinType;
public:
    //Violin(Instrument instrument, bool hasBridge, bool hasChinRest, ViolinType type) {

    //}
    Violin() : Instrument(), hasBridge(), hasChinRest(), violinType() {

    }
    Violin( Instrument(string& type, string &firm, const int year, const float size, Bow &bow), bool hasBridge,
            bool hasChinRest, ViolinType violinType) : Instrument(type, firm, year, size, bow), hasBridge(hasBridge),
                                                      hasChinRest(hasChinRest), violinType(violinType) {

    }
    Violin(string &t, string &f, const int year, const float size, Bow &bow, const Violin& copyV): Instrument(t, f, year, size, bow), hasBridge(copyV.hasBridge), hasChinRest(copyV.hasChinRest), violinType(copyV.violinType){

    }

    ~Violin() override = default;     // + TODO copy ctor; Inherited dtoc can be declared without ‘virtual’ keyword


    ViolinType getVType() const {
        return violinType;
    }

    void setViolinType(ViolinType vType) {
        Violin::violinType = vType;
    }

    bool getHasBridge() {
        return hasBridge;
    }

    void setHasBridge(bool Bridge) {
        Violin::hasBridge = Bridge;
    }

    bool getHasChinRest() {
        return hasChinRest;
    }

    void setHasChinRest(bool ChinRest) {
        Violin::hasChinRest = ChinRest;
    }

    string getInfo() const ;

    //Violin(Instrument instrument, bool b, bool b1, ViolinType type);
};
class Contrabass: Instrument {
protected:
    bool hasExtraString;
    int endpinLength;
public:
    Contrabass(): hasExtraString(false), endpinLength(0){

    }
};


