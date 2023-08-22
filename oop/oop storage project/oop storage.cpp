// op storage.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

using namespace std;

enum Delivery {
    agent,
    provider,
    own_way,
};

class Vegetables {
private:
    string country_name, name;
    int season;
public:
    Vegetables() {
        country_name = "none";
        name = "none";
        season = 0;
    }
    Vegetables(Vegetables& a) {
        country_name = a.country_name;
        name = a.name;
        season = a.season;
    }
    Vegetables(int getseason, string getcountryname, string getname) {
        country_name = getcountryname;
        name = getname;
        season = getseason;
    }
    ~Vegetables() {

    }
    string get_country_name() {
        return country_name;
    }
    void set_country_name(string acountry_name) {
        country_name = acountry_name;
    }
    string get_name() {
        return name;
    }
    void set_name(string aname) {
        name = aname;
    }
    int get_season() {
        return  season;
    }
    void set_season(int aseason) {
        season = aseason;
    }
    Vegetables& operator = (const Vegetables& Vegetables_right) {
        country_name = Vegetables_right.country_name;
        name = Vegetables_right.name;
        season = Vegetables_right.season;
        return *this;
    }
    void print_vegetables() {
        cout << "NAME: " << name << "\nCOUNTRY: " << country_name << "\nSEASON: " << season << endl;
    }

};

class Date {
private:
    int day, mouth, year;
public:
    Date() {
        day = 00;
        mouth = 00;
        year = 00;
    }
    Date(int aday, int amouth, int ayear) {
        day = aday;
        mouth = amouth;
        year = ayear;
    }
    Date(Date& a) {
        day = a.day;
        mouth = a.mouth;
        year = a.year;
    }
    ~Date() {

    };
    void Set_year(int year_2) {
        year = year_2;
    }
    void Set_day(int day_2) {
        day = day_2;
    }
    void Set_mouth(int mouth_2) {
        mouth = mouth_2;
    }
    int get_day() {
        return day;
    }
    int get_mouth() {
        return mouth;
    }
    int get_year() {
        return year;
    }
    void print_date() {
        cout << day << "." << mouth << "." << year << endl;
    }
};

class consignment {
private:
    Vegetables some_vegetables;
    Delivery some_delivery;
    int goods_count, prise, transport_prise;
    Date arriving_date;
public:

    consignment() {
        some_delivery = own_way;
        goods_count = 0;
        prise = 0;
        transport_prise = 0;
    }
    consignment(Delivery asome_delivery, Vegetables asome_vegetables, int agoods_count, int  aprise, int  atransport_prise, Date aarriving_date) {
        some_delivery = asome_delivery;
        some_vegetables = asome_vegetables;
        goods_count = agoods_count;
        prise = aprise;
        transport_prise = atransport_prise;
        arriving_date = aarriving_date;
    }
    consignment(consignment& a) {
        some_delivery = a.some_delivery;
        some_vegetables = a.some_vegetables;
        goods_count = a.goods_count;
        prise = a.prise;
        transport_prise = a.transport_prise;
        arriving_date = a.arriving_date;
    }

    consignment& operator = (const consignment& consignment_right) {
        some_vegetables = consignment_right.some_vegetables;
        some_delivery = consignment_right.some_delivery;
        goods_count = consignment_right.goods_count;
        prise = consignment_right.prise;
        transport_prise = consignment_right.transport_prise;
        arriving_date = consignment_right.arriving_date;
        return *this;
    }

    int get_goods_count() {
        return goods_count;
    }
    int get_prise() {
        return prise;
    }
    int get_transport_prise() {
        return transport_prise;
    }
    void set_prise(int aprise) {
        prise = aprise;
    }
    void set_goods_count(int agoods_count) {
        goods_count = agoods_count;
    }
    void set_transport_prise(int aprise) {
        transport_prise = aprise;
    }
    void set_date(int aday, int  amouth, int ayear) {
        arriving_date.Set_day(aday);
        arriving_date.Set_mouth(amouth);
        arriving_date.Set_year(ayear);
    }
    void set_date(Date aarriving_date) {
        arriving_date = aarriving_date;
    }
    void set_delivery(Delivery adelv) {
        some_delivery = adelv;
    }
    void set_vegetables(Vegetables asome_vegetables) {
        some_vegetables = asome_vegetables;
    }
    void print_consignment() {
        some_vegetables.print_vegetables();
        arriving_date.print_date();
        cout << "NUMBER OF GOODS:" << goods_count << "\nPRISE:" << prise << "$\nTRANSPORT PRISE:" << transport_prise << "$" << endl;

    };



};

class Storage {
private:
    int storage_number, storage_prise, Delivvered_cons_number = 0;
    consignment* Delivvered_cons;
public:
    Storage() {
        Delivvered_cons = new consignment;
        storage_number = 0;
        storage_prise = 0;
        Delivvered_cons_number = 1;
    }
    Storage(int astorage_number, int astorage_prise) {
        Delivvered_cons = new consignment[1];
        storage_number = astorage_number;
        storage_prise = astorage_prise;
        Delivvered_cons_number++;

    }
    Storage(int aDelivvered_cons_number, int astorage_number, int astorage_prise, consignment aDelivvered_cons) {
        Delivvered_cons = new consignment[aDelivvered_cons_number];
        // Delivvered_cons = new consignment;
        Delivvered_cons[0] = aDelivvered_cons;
        storage_number = astorage_number;
        storage_prise = astorage_prise;
        Delivvered_cons_number = 1;

    }
    Storage(Storage& a) {

        Delivvered_cons_number = a.Delivvered_cons_number;
        storage_prise = a.storage_prise;
        storage_number = a.storage_number;

        Delivvered_cons = new consignment[Delivvered_cons_number];
        for (int i = 0; i < Delivvered_cons_number; i++) {
            Delivvered_cons[i] = a.Delivvered_cons[i];
        }
    }


    int get_storage_number() {
        return storage_number;
    }
    int get_storage_price() {
        return storage_prise;
    }
    int get_Delivvered_cons_number() {
        return Delivvered_cons_number;
    }

    void add_consignment(consignment temp_cons) {
        consignment* temp_Delivvered_cons = new consignment[Delivvered_cons_number];
        for (int i = 0; i < Delivvered_cons_number; i++) {
            temp_Delivvered_cons[i] = Delivvered_cons[i];
        }
        // delete Delivvered_cons;
        Delivvered_cons_number++;
        Delivvered_cons = new consignment[Delivvered_cons_number];

        for (int i = 0; i < Delivvered_cons_number - 1; i++) {
            Delivvered_cons[i] = temp_Delivvered_cons[i];
        }
        Delivvered_cons[Delivvered_cons_number - 1] = temp_cons;

    }
    void delete_consigment(int Del_cons_number) {
        Delivvered_cons_number--;
        consignment* temp_Delivvered_cons = new consignment[Delivvered_cons_number];
        for (int i = 0; i < Delivvered_cons_number; i++) {
            if (i == Del_cons_number) {
                continue;
            }
            temp_Delivvered_cons[i] = Delivvered_cons[i];
        }
        for (int i = 0; i < Delivvered_cons_number; i++) {
            Delivvered_cons[i] = temp_Delivvered_cons[i];
        }

        // Delivvered_cons[Del_cons_number]
    }
    void print_long() {
        cout << "STORAGE #" << storage_number << "\nRENT PRISE:" << storage_prise << "$\n" << "NUMBER OF CONSIGNMENT:" << Delivvered_cons_number << endl;
        for (int i = 0; i < Delivvered_cons_number; i++) {
            Delivvered_cons[i].print_consignment();
            cout << endl;
        }
        cout << Delivvered_cons_number << endl;
    }
    void print_short() {
        cout << "STORAGE #" << storage_number << "$\n" << "NUMBER OF CONSIGNMENT:" << Delivvered_cons_number << endl;
        int Psum = 0;
        for (int i = 0; i < Delivvered_cons_number; i++) {
            Psum += Delivvered_cons[i].get_prise() * Delivvered_cons[i].get_goods_count();

        }
        cout << "PRISE: " << Psum << "$\n";
        cout << endl;
    }





};



int main() {
    cout << "Enter date of consigment(day, mouth and year:" << endl;
    int i, j, k;
    string temp_1, temp_2;
    cin >> i >> j >> k;
    Date exp_date(i, j, k);
    cout << "Enter info about vegetables(country, vegetables, season:" << endl;
    cin >> temp_1 >> temp_2 >> i;
    Vegetables veg_1, veg_2(i, temp_1, temp_2), veg_3 = veg_2;
    cout << "Enter info about consigment(goods number, prise, delivery prise):" << endl;
    cin >> i >> j >> k;
    consignment cons_1, cons_2(agent, veg_2, i, j, k, exp_date), cons_3 = cons_2;
    //veg_2.print_vegetables();
    //veg_3.print_vegetables();
    //cons_1.print_consignment();
   // cons_2.print_consignment();
  //  cons_3.print_consignment();
    cout << "Enter info about Storage(Storage number, rent prise,):" << endl;
    cin >> i >> j;
    Storage A, B(2, i, j, cons_2), C = B;
    // A.print_long();
    // B.print_long();
    A.print_long();
    cout << endl << endl;
    B.print_long();
    cout << endl << endl;
    C.print_long();
    cout << "Enter info about vegetables2(country, vegetables, season:" << endl;
    cin >> temp_1 >> temp_2 >> i;
    Vegetables veg_4(i, temp_1, temp_2);
    consignment  cons_4(provider, veg_4, i, j, k, exp_date);
    B.add_consignment(cons_4);
    cout << endl << endl;
    B.print_long();
    B.add_consignment(cons_4);
    B.add_consignment(cons_1);
    B.print_long();
    B.delete_consigment(2);
    B.print_long();
    B.print_short();


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
