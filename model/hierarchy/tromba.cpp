#include "tromba.h"

Tromba::Tromba(Strumento::Tune _tune, double _price, const std::string& _brand, int _material, bool _used, const std::string& _desc, unsigned int _quantity):
     Strumento(_price,_brand,_used,_desc,_quantity),
     Fiato(_material,_tune,brass_mouthpiece){}

Strumento* Tromba::clone() const {
     return new Tromba(*this);
}

std::string Tromba::className() const {
	return "Tromba";
}

void Tromba::loadData(const QJsonObject& obj){
	Fiato::loadData(obj);
}

void Tromba::saveData(QJsonObject& obj) const {
	Fiato::saveData(obj);
}

bool Tromba::operator==(const Tromba& other) const {
     return Fiato::operator==(other);
}

bool Tromba::operator!=(const Tromba& other) const {
     return !(*this == other);
}
