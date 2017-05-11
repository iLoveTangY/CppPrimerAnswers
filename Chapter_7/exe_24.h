#ifndef EXE_24
#define EXE_24

class Screen
{
public:
    using pos = std::string::size_type;

    //构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
    contents(ht * wd, c) { }
    //本题新增的构造函数
    Screen(pos ht, pos wd) : height(ht), width(wd),
    contents(ht * wd, ' ') { }

    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

private:
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
#endif // EXE_24

