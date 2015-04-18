#include "input.h"

Input::Input() {}
Input::~Input() {}

void Input::clear() {
  keys_pressed.clear();
  keys_released.clear();
}

void Input::key_down(const SDL_Event& event) {
  fprintf(stderr, "key pressed %u\n", event.key.keysym.sym);
  keys_pressed[event.key.keysym.sym] = true;
  keys_held[event.key.keysym.sym] = true;
}

void Input::key_up(const SDL_Event& event) {
  fprintf(stderr, "key released %u\n", event.key.keysym.sym);
  keys_released[event.key.keysym.sym] = true;
  keys_held[event.key.keysym.sym] = false;
}

bool Input::key_pressed(SDL_Keycode key) {
  return keys_pressed[key];
}

bool Input::key_released(SDL_Keycode key) {
  return keys_released[key];
}

bool Input::key_held(SDL_Keycode key) {
  return keys_held[key];
}

