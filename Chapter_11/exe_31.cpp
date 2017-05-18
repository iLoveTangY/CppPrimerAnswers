#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void removeAuthor(multimap<string, string> &books, const string &author)
{
	auto pos = books.equal_range(author);
	if (pos.first == pos.second)
		cout << author << " Not Found!" << endl;
	else
		books.erase(pos.first, pos.second);
}

void printBooks(multimap<string, string> &books)
{
	cout << "Current books: " << endl;
	for (auto &book : books)
		cout << "\t" << book.first << ": " << book.second << endl;
	cout << endl;
}

int main()
{
	multimap<string, string> books;

	books.insert({ "Barth, John", "Sot-Weed Factor" });
	books.insert({ "Yong.Jin", "TianLongBaBu" });
	books.insert({ "Barth, John", "Lost in paradise" });
	books.insert({ "Yong.Jin", "SheDiaoHero" });

	printBooks(books);
	removeAuthor(books, "Yong.Jin");
	printBooks(books);

	return 0;
}