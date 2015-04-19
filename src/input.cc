#include "input.h"

Input::Input() {}
Input::~Input() {}

void Input::clear() {
  keys_pressed.clear();
  keys_released.clear();
}

void Input::key_down(const SDL_Event& event) {
  keys_pressed[event.key.keysym.sym] = true;
  keys_held[event.key.keysym.sym] = true;
}

void Input::key_up(const SDL_Event& event) {
  keys_released[event.key.keysym.sym] = true;
  keys_held[event.key.keysym.sym] = false;
}

