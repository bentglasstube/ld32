#include "screen.h"

#include "input.h"

bool Screen::process_input(Input& input) {
  SDL_Event event;

  input.clear();

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        if (event.key.repeat == 0) input.key_down(event);
        break;

      case SDL_KEYUP:
        input.key_up(event);
        break;

      case SDL_JOYBUTTONDOWN:
        input.joy_down(event);
        break;

      case SDL_JOYBUTTONUP:
        input.joy_up(event);
        break;

      case SDL_JOYAXISMOTION:
        input.joy_axis(event);
        break;

      case SDL_JOYHATMOTION:
        input.joy_hat(event);
        break;

      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) lost_focus();
        break;

      case SDL_QUIT:
        return false;
    }
  }

  return true;
}
