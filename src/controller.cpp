
// addPersonu ayarla
// boş cpp person dosyalarını ayarla
// database işlemlerine bak eksik fonksiyonlar
// kişi sildiğimde 
// operator overload? çözülen hataların tüm hatalara oranı? 
// maini ayarla biraz zor olabilir

#include "../header/controller.hpp"
#include "../header/database.hpp"

Controller::Controller(int id, const string& name, const string& user, const string& pass)
        : Person(id, name, user, pass)
{
    Database::insertPerson(*this);
}

Controller::Controller() {}

