#ifndef _EXE_42_
#define _EXE_42_
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include "exe_39_40.h"

class QueryResult;

class TextQuery
{
public:
	using line_no = size_t;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<StrVec> file;  //input file
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);

public:
	using line_it = std::set<TextQuery::line_no>::const_iterator;
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
		std::shared_ptr<StrVec> f) : sought(s), lines(p), file(f) { }
	std::shared_ptr<StrVec> get_file() { return file; }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }

private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<StrVec> file;
};

#endif