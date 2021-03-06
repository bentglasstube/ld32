#pragma once

#include <boost/scoped_ptr.hpp>

#include "menu.h"
#include "backdrop.h"
#include "screen.h"

class TitleScreen : public Screen {

  public:

    void init(Graphics& graphics);
    bool update(Input& input, Audio& audio, Graphics& graphics, int elapsed);
    void draw(Graphics& graphics);
    Screen* next_screen();
    std::string get_music_track() { return "dario"; }

  private:

    int choice;
    boost::scoped_ptr<Backdrop> backdrop;
    boost::scoped_ptr<Menu> menu;

};
