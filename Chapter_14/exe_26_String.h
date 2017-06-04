#ifndef _EXE_26_
#define _EXE_26_

#include <memory>

class String
{
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);

public:
	String() : String("") {}
	String(const char *);
	String(const String&);
	String(String&&) noexcept;
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	~String();

	char& operator[](std::size_t n) { return elements[n]; }
	const char& operator[](std::size_t n) const { return elements[n]; }

	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

private:
	std::pair<char *, char *> alloc_n_copy(const char *, const char *);
	void range_initializer(const char *, const char *);
	void free();

	char *elements;
	char *end;
	std::allocator<char> alloc;
};

#endif