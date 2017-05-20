#ifndef _EXE_2_H_
#define _EXE_2_H_

#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

class StrBlob
{
public:
	typedef std::vector<std::string > ::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove element
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	//visit element
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	//if data[i] is illegal, this function will throw out_of_range exception.
	void check(size_type i, const std::string &msg) const;
};

#endif
