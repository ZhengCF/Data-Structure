#include"iostream"

using namespace std;

class Book
{
public:
	Book();
	Book(char *name, int No, char *author);
	//~Book();
	void setna(char *name);
	void setn(int no);
	void seta(char *name);
	char * getna();
	int getn();
	char * geta();
private:
	char *name;
	int No;
	char *author;
};

Book::Book()
{
}

Book::Book(char *name, int No, char *author)
{
	this->name = name;
	this->No = No;
	this->author = author;
}

void Book::setna(char * name)
{
	this->name = name;
}

void Book::setn(int no)
{
	this->No = no;
}

void Book::seta(char * name)
{
	this->author = name;
}

char * Book::getna()
{
	return name;
}

int Book::getn()
{
	return No;
}

char * Book::geta()
{
	return author;
}


class Card
{
public:
	Card(){}
	Card(int c);
	~Card();
	void  Add(Book book) { this->book[booknum++] = book; 
	}
	void  sub(Book book);
	void  getImformation();
private:
	int No;
	int booknum = 0;
	Book book[3];
};

Card::Card(int c)
{
	No = c;
}

Card::~Card()
{
}

void Card::sub(Book book)
{
}

void Card::getImformation()
{
	int i;
	cout << No << endl;
	for(i=0;i<booknum;i++)
		cout << book[i].getn() <<"  "<< book[i].getna() << "  " << book[i].geta() << endl;
}

class Reader
{
public:
	Reader();
	Reader(char *name, Card card);
	void Bbook(Book book);
	char *getname() { return name; }
	Card getcard() { return card; }
	~Reader();
private:
	char *name;
	Card card;
};

Reader::Reader()
{
}

Reader::Reader(char *name1, Card card1) {
	card = card1;
	name = name1;
}
void Reader::Bbook(Book book) {
	card.Add(book);
}
Reader::~Reader()
{
}

int main() {
	char name[] = "C++";
	char author[] = "rain";
	char na[] = "ÕÅÈý";
	Card card(123221);
	Book book1(name, 1, author);
	Reader R(na,card);
	cout << R.getname()<< endl;
	R.Bbook(book1);
	R.Bbook(book1);
	R.Bbook(book1);
	R.getcard().getImformation();
}