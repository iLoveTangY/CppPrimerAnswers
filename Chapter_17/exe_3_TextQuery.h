#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::vector;
using std::tuple;
using std::shared_ptr;
using std::set;
using std::map;
using std::ifstream;
using std::ostream;

using line_no = vector<string>::size_type;
using query_result = tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>>;

class TextQuery
{
public:
	TextQuery(ifstream&);
	query_result query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

ostream& print(ostream&, const query_result&);