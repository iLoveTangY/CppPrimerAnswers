#ifndef _EXXE_14_
#define _EXE_14_

#include <string>
#include <iostream>

template<int H, int W> class Screen;

template<int H, int W>
std::ostream& operator<<(std::ostream&, Screen<H, W>&);

template<int H, int W>
std::istream& operator>>(std::istream&, Screen<H, W>&);

template <int H, int W>
class Screen
{
	friend std::ostream& operator<< <H, W>(std::ostream&, Screen<H, W>&);
	friend std::istream& operator>> <H, W>(std::istream&, Screen<H, W>&);
public:
	Screen() : contents(H * W, ' ') {}
	Screen(char c) : contents(H * W, c) {}
	friend class Window_mgr;
	char get() const { return contents[cursor]; }
	inline char get(int, int) const;
	Screen &clear(char = bkground);

private:
	static const char bkground = ' ';

public:
	Screen &move(int r, int c);
	Screen &set(char);
	Screen &set(int, int, char);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:
	void do_display(std::ostream &os) const { os << contents; }
	int cursor = 0;
	std::string contents;
};

template <int H, int W>
std::ostream& operator<<(std::ostream &os, Screen<H, W> &s)
{
	os << s.contents;
	return os;
}

template <int H, int W>
std::istream& operator>>(std::istream &is, Screen<H, W> &s)
{
	std::string t;
	is >> t;
	s.contents = t.substr(0, H*W);
	return is;
}

template <int H, int W>
Screen<H, W> &Screen<H, W>::clear(char c)
{
	contents = std::string(H*W, c);
	return *this;
}

template <int H, int W>
inline
Screen<H, W> &Screen<H, W>::move(int r, int c)
{
	int row = r * W;
	cursor = row + c;
	return *this;
}

template <int H, int W>
char Screen<H, W>::get(int r, int c) const
{
	int row = r * W;
	return contents[row + c];
}

template<int H, int W>
inline
Screen<H, W> &Screen<H, W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<int H, int W>
inline
Screen<H, W> &Screen<H, W>::set(int r, int col, char ch)
{
	contents[r*W + col] = ch;
	return *this;
}



#endif