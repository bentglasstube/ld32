#pragma once

#include <map>
#include <SDL2/SDL.h>

#define MAX_AXES 64

class Input {
  public:

    enum Action { NONE, LEFT, RIGHT, UP, DOWN, ACCEPT, BACK, CLOCKWISE, COUNTERCLOCKWISE, FULLSCREEN };

    Input();
    ~Input();

    void clear() { keys_pressed.clear(); }
    void key_down(const SDL_Event& event) { press_key(key_mapping(event.key.keysym.sym)); };
    void key_up(const SDL_Event& event) { release_key(key_mapping(event.key.keysym.sym)); };
    void joy_down(const SDL_Event& event) { press_key(joy_mapping(event.jbutton.button)); };
    void joy_up(const SDL_Event& event) { release_key(joy_mapping(event.jbutton.button)); };
    void joy_axis(const SDL_Event& event);
    void joy_hat(const SDL_Event& event);

    bool key_pressed(Action key) { return keys_pressed[key]; }
    bool key_held(Action key) { return keys_held[key]; }

  private:
    void press_key(const Action key) { keys_pressed[key] = true; keys_held[key] = true; }
    void release_key(const Action key) { keys_held[key] = false; }
    void process_axis(int cur, int prev, Action neg, Action pos);

    Action key_mapping(const SDL_Keycode key);
    Action joy_mapping(const Uint8 button);

    std::map<Action, bool> keys_held;
    std::map<Action, bool> keys_pressed;

    SDL_Joystick* joystick;
    int axis_prev[MAX_AXES], hat_prev_x, hat_prev_y;
};
