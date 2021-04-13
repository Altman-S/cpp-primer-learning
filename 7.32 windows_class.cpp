#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Screen {
public:
	typedef std::string::size_type pos;
	// default function 
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	// Windows——mgr::clear必须在Screen类之前被声明    友元
	friend class Windows_mgr;
private:
	// initial variable
	pos cursor = 0;
	pos width = 0;
	pos height = 0;
	string contents;
public:
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &move(pos, pos);
    // decided by const     how to display
    Screen &display(std::ostream &os) { do_display(os); return *this; }          // no const
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }  //const
private:
	void do_display(std::ostream &os) const { os << contents; }               // subfunction
};

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}
inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
    return *this;
}


class Windows_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	// 声明
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens{Screen(6, 6, 's')};
};

void Windows_mgr::clear(ScreenIndex i) {
	// s为Screen的引用，想清空屏幕
	Screen &s = screens[i];
	// 将选定的Screen设定成空白
	s.contents = string(s.height * s.width, ' ');
}




int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;
	return 0;
}


