#include "exe_3_TextQuery.h"

#include <algorithm>
#include <cctype>
#include <sstream>

using std::get;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string txt;
	while (getline(is, txt))
	{
		file->push_back(txt);
		int n = file->size() - 1;
		txt.erase(std::remove_if(txt.begin(), txt.end(), ::ispunct), txt.end());
		std::istringstream line(txt);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

query_result TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return std::make_tuple(sought, nodata, file);
	return std::make_tuple(sought, loc->second, file);
}

string make_plural(size_t ctr, string const &word, string const &ending)
{
	return (ctr > 1) ? word + ending : word;
}

ostream& print(ostream &os, const query_result &qr)
{
	os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
		<< make_plural(get<1>(qr)->size(), "time", "s") << std::endl;
	for (auto num : *get<1>(qr))
		os << "\t(line " << num + 1 << ") " << *(get<2>(qr)->begin() + num) << std::endl;

	return os;
}