#ifndef _ZENITH80_MAIN_HPP_
#define _ZENITH80_MAIN_HPP_

#include "zenith80.hpp"
#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Color;
using sf::Text;
using sf::Font;

#include <string>
using std::string;
#include <vector>
using std::vector;

#include <CPU/Z80.hpp>

#include <defines.hpp>

#include <TGUI/TGUI.hpp>
using tgui::Gui;
using tgui::Canvas;
typedef tgui::ChatBox TermOut;

#include <SFML/System.hpp>
using sf::Clock;

#include <GPU/GR80.hpp>

typedef const char * cstring;

ZENITH_HEADER

typedef enum {
	PNG,binary
}ROM_format;

class Main{
	friend RAMController;
	public:
		Main(int argc,char ** argv);
		~Main();
		static int main(int argc,char** argv);
		void shutdown();
		int run();
		static Main * instance;
		Z80 * cpu;
		GR80 * gpu;
		bool cpm_emu;
		bool phys_cart;
		ROM_format format;
		void putchar(char c);
		void putint(int c);
		void putmsg(string s);
		uint8_t key();
		void resetKeyBuffer();
		void resetClock();
		Font * default_font;
		void setTitle(string s);
		void update();
	private:
		const char *name;
		Clock accuracy_clock;
		Clock precision_clock;
		void initCPU();
		void wait();
		bool waiting;
		vector<uint8_t> key_buffer;
		uint64_t unit;
		uint64_t clock_speed;
		RenderWindow * window;
		Gui * gui;
		TermOut::Ptr termOut;
		Canvas::Ptr canvas;
		Color background;
		void processEvents();
};

bool exists(const char *file_name);
string hex(uint8_t a);
string hex(int a);

ZENITH_FOOTER

#endif
