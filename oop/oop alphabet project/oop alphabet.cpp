// oop alphabet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char temp;
class Alphabet {
	char* letters;
	char* signs;
	int sizeoflet, sizeofsigns;
public:
	Alphabet();
	Alphabet(char*, char*);
	Alphabet(Alphabet&);
	~Alphabet();
	char* getletters();
	char* getsigns();
	int getsizeoflet();
	int getsizeofsigns();
	Alphabet& set_letters(char*);
	Alphabet& set_signs(char*);
	friend ostream& operator<<(ostream&, Alphabet&);
	friend istream& operator>>(istream&, Alphabet&);
	void print_1();
	void print_2();
};

ostream& operator<<(ostream& out, Alphabet& alpha) {
	out << alpha.letters << ", " << alpha.signs << ", " << alpha.sizeoflet << ", " << alpha.sizeofsigns << "\n ";
	return out;
}
istream& operator>>(istream& in, Alphabet& alpha) {
	char* let, * sig;
	let = new char[1000];
	sig = new char[1000];
	in >> let >> sig;
	alpha.letters = new char[strlen(let) + 1];
	strcpy(alpha.letters, let);
	alpha.signs = new char[strlen(sig) + 1];
	strcpy(alpha.signs, sig);
	alpha.sizeoflet = strlen(let);
	alpha.sizeofsigns = strlen(sig);
	return in;
}
Alphabet::Alphabet() {
	letters = new char[10];
	strcpy(letters, "noletters");
	signs = new char[8];
	strcpy(signs, "nosigns");
	sizeoflet = 0;
	sizeofsigns = 0;
	//cout << "default constructor Alphabet" << endl;
};
Alphabet::Alphabet(char* let, char* sig) {
	letters = new char[strlen(let) + 1];
	strcpy(letters, let);
	signs = new char[strlen(sig) + 1];
	strcpy(signs, sig);
	sizeoflet = strlen(let);
	sizeofsigns = strlen(sig);
	for (int k = 0; k < sizeoflet; k++) {
		for (int g = 0; g < sizeoflet - 1; g++) {

			if (letters[g] > letters[g + 1]) {
				temp = letters[g];
				letters[g] = letters[g + 1];
				letters[g + 1] = temp;

			}
		}
	}
	//cout << "constructor Alphabet<par>" << endl;
};
Alphabet::Alphabet(Alphabet& a) {
	if (letters) {
		delete[] letters;
	}
	letters = new char[strlen(a.letters) + 1];
	strcpy(letters, a.letters);
	if (signs) {
		delete[] signs;
	}
	signs = new char[strlen(a.signs) + 1];
	strcpy(signs, a.signs);
	sizeoflet = a.sizeoflet;
	sizeofsigns = a.sizeofsigns;
};
Alphabet::~Alphabet() {
	//cout << "Destructor Alphabet" << endl;
};
char* Alphabet::getletters() {
	return letters;
};
char* Alphabet::getsigns() {
	return signs;
};
int Alphabet::getsizeoflet() {
	return sizeoflet;
};
int Alphabet::getsizeofsigns() {
	return sizeofsigns;
};
Alphabet& Alphabet::set_letters(char* let) {
	delete[] letters;
	letters = new char[strlen(let) + 1];
	strcpy(letters, let);
	sizeoflet = strlen(let);
	return *this;
}
Alphabet& Alphabet::set_signs(char* sig) {
	delete[] signs;
	signs = new char[strlen(sig) + 1];
	strcpy(signs, sig);
	sizeofsigns = strlen(sig);
	return *this;
};
void Alphabet::print_1() {
	cout << letters << ", " << signs << ", " << sizeoflet << ", " << sizeofsigns << "\n ";
}
void Alphabet::print_2() {
	cout << "class Alphabet, " << letters << "\n ";
}
class Phrase {
	char* phras;
	Alphabet alphabet;
public:
	Phrase();
	Phrase(char*, char*, char*);
	Phrase(Phrase&);
	~Phrase();
	char* getphras();
	char* getletters();
	char* getsigns();
	int getsizeoflet();
	int getsizeofsigns();
	Phrase& set_phrase(char*);
	Phrase& set_letters(char*);
	Phrase& set_signs(char*);
	friend ostream& operator<<(ostream&, Phrase&);
	friend istream& operator>>(istream&, Phrase&);
	bool operator==(Phrase&);
	virtual void view();
	void print_1();
	void print_2();
};
void Phrase::view() {
	cout << "Phras: '" << phras << "'";
}
ostream& operator<<(ostream& out, Phrase& phr) {
	out << "'" << phr.phras << "'" << "; " << phr.alphabet;
	return out;
}
istream& operator>>(istream& in, Phrase& phr) {
	char* phra;
	phra = new char[1000];
	in >> phra >> phr.alphabet;
	phr.phras = new char[strlen(phra) + 1];
	strcpy(phr.phras, phra);
	return in;
}
bool Phrase:: operator==(Phrase& a) {
	bool temp, temp1, temp2;
	temp = !strcmp(phras, a.phras);
	temp1 = !strcmp(getletters(), a.getletters());
	temp2 = !strcmp(getsigns(), a.getsigns());
	return temp && temp1 && temp2;
}
Phrase::Phrase() : alphabet(), phras() {
	phras = new char[9];
	strcpy(phras, "nophrase");
	//cout << "default constructor Phrase" << endl;
};


Phrase::Phrase(char* ph, char* let, char* sig) :
	alphabet(let, sig), phras(ph) {
	phras = new char[strlen(ph) + 1];
	strcpy(phras, ph);
	//cout << "constructor Phrase<par>" << endl;
};
Phrase::Phrase(Phrase& a) {
	alphabet = a.alphabet;
	phras = new char[strlen(a.phras) + 1];
	strcpy(phras, a.phras);
}
Phrase::~Phrase() {

	//cout << "destructor Phrase" << endl;
}
char* Phrase::getphras() {
	return phras;
}
char* Phrase::getletters() {
	return alphabet.getletters();
}
char* Phrase::getsigns() {
	return alphabet.getsigns();
}
int Phrase::getsizeoflet() {
	return alphabet.getsizeoflet();
};
int Phrase::getsizeofsigns() {
	return alphabet.getsizeofsigns();
}
Phrase& Phrase::set_phrase(char* phr) {
	if (phras) {
		delete[] phras;
	}
	phras = new char[strlen(phr) + 1];
	strcpy(phras, phr);
	return *this;
}
Phrase& Phrase::set_letters(char* let) {
	alphabet.set_letters(let);
	return *this;
}
Phrase& Phrase::set_signs(char* sig) {
	alphabet.set_signs(sig);
	return *this;
}
void Phrase::print_1() {
	cout << "'" << phras << "'" << "; ";
	alphabet.print_1();
};
void Phrase::print_2() {
	cout << " Phrase" << ", " << phras << endl;
};
class Number : public Phrase {
	int notation;
	int length;
	bool fixedor;
public:
	Number();
	Number(char*, char*, char*, int, int, bool);
	Number(Number&);
	~Number() {/* cout << "destruct.Number" << endl;*/ };
	Number& set_notation(int a) { notation = a; return *this; };
	Number& set_length(int a) { length = a; return *this; };
	Number& set_fixedor(bool a) { fixedor = a; return *this; };
	int  get_notation() { return notation; }
	int  get_lenght() { return length; }
	bool  get_fixedor() { return fixedor; }
	bool operator<(Number&);
	Number operator+(Number&);
	Number(Phrase&);
	operator Phrase();
	void print();
	void view();
};
Number:: operator Phrase() {
	Phrase temp(getphras(), getletters(), getletters());
	return temp;
}
Number::Number(Phrase& a) : Phrase(a.getphras(), a.getletters(), a.getsigns()) {
	notation = 0;
	length = 0;
	fixedor = 0;
}
bool Number::operator<(Number& a) {
	Number temp(*this);
	return (temp.notation * temp.length) < (a.notation * a.length);
}
Number Number:: operator+(Number& a) {
	Number temp(*this);
	temp.notation += a.notation;
	temp.length += a.length;
	char* tempe = new char[1000];
	strcpy(tempe, getletters());
	strcat(tempe, a.getletters());
	temp.set_letters(tempe);
	delete[] tempe;
	char* temper = new char[1000];
	strcpy(temper, getsigns());
	strcat(temper, a.getsigns());
	temp.set_signs(temper);
	delete[] temper;
	temper = new char[1000];
	strcpy(temper, getphras());
	strcat(temper, a.getphras());
	temp.set_phrase(temper);
	delete[] temper;
	return temp;
}
void Number::view() {
	cout << "Phrase: " << "'" << getphras() << "'";
	cout << " Notation: " << get_notation();
}
Number::Number() {
	notation = 0;
	length = 0;
	fixedor = 0;
	//cout << "Defualt constructor Number" << endl;
}
Number::Number(char* ph, char* let, char* sig, int note, int len, bool fix) : Phrase(ph, let, sig) {
	notation = note;
	length = len;
	fixedor = fix;
	//cout << "constructor Number<par>" << endl;
}
Number::Number(Number& a) : Phrase(a.getphras(), a.getletters(), a.getsigns()) {
	notation = a.notation;
	length = a.length;
	fixedor = a.fixedor;
};
void Number::print() {
	cout << "notation:" << notation << "; length:" << length << "; ";
	if (fixedor) { cout << "with fixed dot;"; }
	else { cout << "with floating dot;"; }
	Phrase::print_1();
}
class Sentence : public Phrase {
	int count_let;
	bool ignore;
public:
	Sentence();
	Sentence(char*, char*, char*, bool);
	Sentence(Sentence&);
	~Sentence() {/* cout << "destruct.Sentence" << endl; */ };
	Sentence& set_ignore(int a) { ignore = a; return *this; };
	int  get_count_let() { return count_let; };
	bool  get_ignore() { return ignore; }
	void print();
	void view();
};
Sentence::Sentence() {
	count_let = 0;
	ignore = 0;
	//cout << "Defualt constructor Sentence" << endl;
}
Sentence::Sentence(char* ph, char* let, char* sig, bool ign) : Phrase(ph, let, sig) {
	count_let = getsizeoflet();
	ignore = ign;
	//cout << "constructor Sentence<par>" << endl;
}
Sentence::Sentence(Sentence& a) : Phrase(a.getphras(), a.getletters(), a.getsigns()) {
	count_let = a.count_let;
	ignore = a.ignore;
};
void Sentence::print() {
	cout << "amount:" << count_let << "; ";
	if (ignore) { cout << "with ignore;"; }
	else { cout << "without ignore;"; }
	Phrase::print_1();
}
void Sentence::view() {
	cout << "Phrase: " << "'" << getphras() << "'";
	cout << " Count: " << get_count_let();
}



class Text {
	char* title;
	Phrase* arr;
	int size;
public:
	Text();
	Text(int, char*);
	Text(Text&);
	~Text() {
		delete[] title;
		delete[] arr;
		/* cout << "destruct.Text" << endl; */
	};
	Text& set_size(int a) { size = a; return *this; };
	Text& set_title(char*);
	int  get_size() { return size; };
	char* get_title() { return title; }
	Phrase& operator[](int);
	void print();
};
void Text::print() {
	cout << "Title: " << title << " || ";
	if (size == 1) {
		cout << arr[0] << ";\n";
		return;
	}
	int i = 0;
	for (; i < size; i++) {
		cout << arr[i];
	}
}
Phrase& Text::operator[](int i) {
	return arr[i];
}
Text::Text() {
	size = 1;
	arr = new Phrase[size];
	title = new char[10];
	strcpy(title, "notitle");
	//cout << "Defualt constructor Text" << endl;
}
Text::Text(int a, char* tit) {
	size = a;
	arr = new Phrase[size];
	title = new char[strlen(tit) + 1];
	strcpy(title, tit);
	//cout << "Defualt constructor Text" << endl;
}
Text::Text(Text& a) {
	size = a.size;
	if (arr) {
		delete[] arr;
	}
	if (title) {
		delete[] title;
	}
	arr = new Phrase[a.size];
	for (int i = 0; i < a.size; i++) {
		arr[i] = a.arr[i];
	}
	title = new char[strlen(a.title) + 1];
	strcpy(title, a.title);
	//cout << "Defualt constructor Text" << endl;
}
Text& Text::set_title(char* tit) {
	delete[] title;
	title = new char[strlen(tit) + 1];
	strcpy(title, tit);
	return *this;
};

int main()
{
	int nota, len, fixedor, count, ign;
	char phras3[100], let3[100], sig3[100];
	int nota1, len1, fixedor1, count1, ign1;
	char phras[100], let[100], sig[100], phr[100];
	char phras1[100], phras2[100], let1[100], sig1[100], title[100];
	char let2[100], sig2[100];
	cout << "Enter phras, letters, signs title:" << endl;
	scanf_s("%s", phras);
	scanf_s(" %s %s %s", let, sig, title);
	cout << "Enter phras, letters, signs:" << endl;
	scanf_s("%s", phras3);
	scanf_s(" %s %s", let3, sig3);
	Phrase a(phras, let, sig), b(phras3, let3, sig3);
	Text c(3, title);
	c[1] = a;
	c.print();
	cout << "Enter phras, letters, signs, notation, lenght, fixedoe(1/0):" << endl;
	scanf_s("%s", phras1);
	scanf_s(" %s %s %d %d %d", let1, sig1, &nota1, &len1, &fixedor1);
	Number k(phras1, let1, sig1, nota1, len1, fixedor1);
	k.print();
	a.print_1();
	a = k;
	k = b;
	a.print_1();
	k.print();
	cout << "Enter phras, letters, signs, ignor(1/0):" << endl;
	scanf_s("%s", phras2);
	scanf_s(" %s %s %d", let2, sig2, &ign);
	Phrase* arr[3];
	arr[0] = &b;
	arr[1] = new Sentence(phras2, let2, sig2, ign);
	arr[2] = &k;
	for (int i = 0; i < 3; i++) {
		arr[i]->view();
		cout << endl;
	}

	return 0;
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
