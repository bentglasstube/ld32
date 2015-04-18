#include "main_screen.h"

#include "input.h"
#include "text.h"

MainScreen::MainScreen(Graphics& graphics) : game_grid(), state(PLAYING) {
  game_grid.generate(graphics);
}

bool MainScreen::process_input(Input& input) {
  if (!Screen::process_input(input)) {
    return false;
  }

  if (input.key_pressed(SDLK_ESCAPE)) {
    return false;
  }

  if (input.key_pressed(SDLK_SPACE) || input.key_pressed(SDLK_RETURN)) {
    if (state == PAUSED) {
      state = PLAYING;
    } else if (state == PLAYING) {
      state = PAUSED;
    }
  }

  if (state == PLAYING) {

    if (input.key_pressed(SDLK_LEFT) || input.key_pressed(SDLK_a)) {
      game_grid.move(-1);
    } else if (input.key_pressed(SDLK_RIGHT) || input.key_pressed(SDLK_d)) {
      game_grid.move(1);
    }

    if (input.key_pressed(SDLK_q)) {
      game_grid.rotate(-1);
    } else if (input.key_pressed(SDLK_UP) || input.key_pressed(SDLK_w) || input.key_pressed(SDLK_e)) {
      game_grid.rotate(1);
    }

    if (input.key_pressed(SDLK_DOWN) || input.key_pressed(SDLK_s)) {
      game_grid.drop(true);
    } else if (input.key_released(SDLK_DOWN) || input.key_released(SDLK_s)) {
      game_grid.drop(false);
    }

  }

  return true;
}

bool MainScreen::update(Graphics& graphics, unsigned int elapsed) {
  if (state == PLAYING) {
    int result = game_grid.update(graphics, elapsed);

    if (result < 0) state = GAME_OVER;
  }

  return true;
}

void MainScreen::draw(Graphics& graphics) {
  game_grid.draw(graphics, 16, 16);
  if (state == PAUSED) {
    Text text(graphics, "PAUSE");
    text.draw(graphics, 60, 136);
  } else if (state == GAME_OVER) {
    Text text(graphics, "GAME OVER");
    text.draw(graphics, 44, 136);
  }
}
