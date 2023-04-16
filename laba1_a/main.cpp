#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Åñòü áèáëèîòåêà, â êîòîðîé õðàíÿòñÿ äâà âèäà êíèã – õóäîæåñòâåííûå è
//òåõíè÷åñêèå.
//Íàäî ñîçäàòü ïðîãðàììó, â êîòîðîé :
//À) íàïîëíèòü áèáëèîòåêó íåñêîëüêèìè ðàçíûìè êíèãàìè(Ïðèìå÷àíèå1: ó
//ïîëüçîâàòåëüñêîãî êîíñòðóêòîðà êëàññà äîëæíî áûòü 3 ïàðàìåòðà – äëÿ óêàçàíèÿ
//èìåíè àâòîðà, íàçâàíèÿ êíèãè è òèïà, õóäîæåñòâåííàÿ èëè òåõíè÷åñêàÿ)
//(Ïðèìå÷àíèå2: â áèáëèîòåêå íå äîëæíî áûòü êíèã áåçûìÿííûõ è áåç íàçâàíèÿ);
//Á) Â îòäåëüíîé ïðîöåäóðå âûâåñòè íà êîíñîëü, èñïîëüçóÿ îïåðàòîð switch,
//êîëè÷åñòâî õóäîæåñòâåííîé ëèòåðàòóðû è òåõíè÷åñêîé;
//Â) Â äîïîëíèòåëüíîé ïðîöåäóðå âûâåñòè íà êîíñîëü òå æå äàííûå, íå ïðèìåíÿÿ
//îïåðàòîð switch.
//Ïðîãðàììà äîëæíà ôóíêöèîíèðîâàòü êîððåêòíî(ñëåäèòü çà íåäîïóùåíèåì
//	óòå÷êè ïàìÿòè).

enum class Type_book {
	tech,
	art
};

class book {
private:
	string name_author, name_book;
	Type_book type_book;
public:
	book(const string& name_author_pub, const string& name_book_pub, Type_book type_book_pub) {
		name_author = name_author_pub;
		name_book = name_book_pub;
		type_book = type_book_pub;
	}
	void print() const {
		switch (type_book)
		{
		case Type_book::art:
			cout << name_author << '\t' << name_book << '\t' << "Õóäîæåñòâåííàÿ" << endl;
			break;
		case Type_book::tech:
			cout << name_author << '\t' << name_book << '\t' << "Òåõíè÷åñêàÿ" << endl;
			break;
		}
	}
	Type_book get_type() const {
		return type_book;
	}

};

class library {
private:
	vector <book*> bibliothek;
	Type_book getTypeFromString(const string& str) {
		if (str == "Õóäîæåñòâåííàÿ")
		{
			return Type_book::art;
		}
		if (str == "Òåõíè÷åñêàÿ")
		{
			return Type_book::tech;
		}
	}
public:
	void add_book(const string& name_author, const string& name_book, const string& type_book) {
		if (!name_author.empty() && !name_book.empty() && (type_book == "Òåõíè÷åñêàÿ" || type_book == "Õóäîæåñòâåííàÿ")) {
			bibliothek.emplace_back(new book(name_author, name_book, this->getTypeFromString(type_book)));
		}
		else {
			cout << "Ââåäèòå êîððåêòíûå äàííûå" << endl;
		}
	}
	void print_all() const {
		for (book* element : bibliothek) {
			element->print();
		}
	}
	void count_type_book() const {
		int count_technikal_book = 0;
		int count_art_book = 0;
		for (book* element : bibliothek) {
			switch (element->get_type())
			{
			case Type_book::tech:
				count_technikal_book++;
				break;
			case Type_book::art:
				count_art_book++;
			}
		}
		cout << "Êîë-âî òåõíè÷åñêîé ëèòåðàòóðû - " << count_technikal_book << " êíèã\t" << "Êîë-âî õóäîæåñòâåííîé ëèòåðàòóðû - " << count_art_book << " êíèã" << endl;
	}
	void count_type_book2() const {
		int count_technikal_book = 0;
		int count_art_book = 0;
		for (book* element : bibliothek) {
			if (element->get_type() == Type_book::tech) {
				count_technikal_book++;
				continue;
			}
			if (element->get_type() == Type_book::art) {
				count_art_book++;
			}
		}
		cout << "Êîë-âî òåõíè÷åñêîé ëèòåðàòóðû - " << count_technikal_book << " êíèã\t" << "Êîë-âî õóäîæåñòâåííîé ëèòåðàòóðû - " << count_art_book << " êíèã" << endl;
	}
	~library() {
		for (book* element : bibliothek) {
			delete element;
		}
	}

};


int main() {
	setlocale(LC_ALL, "Rus");
	library bibliothek;
	bibliothek.add_book("Ëåâ Òîëñòîé", "Âîéíà è Ìèð", "Õóäîæåñòâåííàÿ");
	bibliothek.add_book("Ëåâ Òîëñòîé", "Âîéíà è Ìèð", "Õóäîæåñòâåííàÿ");
	bibliothek.print_all();
	bibliothek.count_type_book();
	bibliothek.count_type_book2();
	return 0;
}