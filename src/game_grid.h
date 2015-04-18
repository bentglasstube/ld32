#pragma once

#include <boost/shared_ptr.hpp>
#include <list>

#include "grid_piece.h"
#include "candy_block.h"

class Graphics;

class GameGrid {

  public:

    enum Direction { UP, DOWN, LEFT, RIGHT };

    GameGrid();

    void generate(Graphics& graphics);
    int update(Graphics& graphics, unsigned int elapsed);
    void draw(Graphics& graphics, unsigned int x, unsigned int y);

    void move(int dir) { _move = dir; }
    void rotate(int dir) { _rotate = dir; }
    void drop(bool y) { _drop = y; }

  private:

    struct Match {
      Match(unsigned int x, unsigned int y) : x(x), y(y) {}
      unsigned int x;
      unsigned int y;
    };

    boost::shared_ptr<GridPiece> piece(int x, int y);
    unsigned int drop_threshold();
    bool spawn_candy(Graphics& graphics);
    bool collision(boost::shared_ptr<CandyBlock> block);
    void release(int x, int y);
    void commit(boost::shared_ptr<CandyBlock> block);
    int process_matches();
    void remove_piece(int x, int y);

    boost::shared_ptr<GridPiece> pieces[16][8];
    unsigned int move_counter, drop_counter, drop_speed;
    boost::shared_ptr<CandyBlock> active_piece;
    int _move, _rotate;
    bool _drop;
    std::list<boost::shared_ptr<CandyBlock> > falling_pieces;
};
