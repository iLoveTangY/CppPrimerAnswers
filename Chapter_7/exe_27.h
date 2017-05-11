#ifndef EXE_27
#define EXE_27

#include <string>
#include <iostream>

class Screen
{
public:
    using pos = std::string::size_type;

    //构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
        contents(ht * wd, c) { }
    Screen(pos ht, pos wd) : height(ht), width(wd),
        contents(ht * wd, ' ') { }

    //成员函数
    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char c);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    //基于const的重载
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline
Screen& Screen::set(pos r, pos col, char c)
{
    contents[r*width + col] = c;
    return *this;
}
#endif // EXE_27
