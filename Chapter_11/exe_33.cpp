#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

void wordTransform(ifstream &map_file, ifstream &input);
map<string, string> buildMap(ifstream &map_file);
const string & transform(const string &s, const map<string, string> &m);

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " <map file> <input file>" << endl;
		exit(-1);
	}
	ifstream map_file(argv[1]), input(argv[2]);
	if (!map_file || !input)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}

	wordTransform(map_file, input);

	return 0;
}

void wordTransform(ifstream &map_file, ifstream &input)
{
	auto transMap = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstWord = true;
		while (stream >> word)
		{
			if (firstWord)
				firstWord = false;
			else
				cout << " ";
			cout << transform(word, transMap);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> transMap;
	string key, value;

	while (map_file >> key  && getline(map_file, value))
	{
		if (value.size() > 1)
			transMap[key] = value.substr(1);
		else
			throw runtime_error("No rule for " + key);
	}

	return transMap;
}

const string & transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}