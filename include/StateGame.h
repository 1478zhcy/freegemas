/**
 * @file stateJuego.h
 *
 * @author José Tomás Tocino García
 * @date 2010
 *
 * Archivo para la clase de juego principal
 *
 * Copyright (C) 2010 José Tomás Tocino García <theom3ga@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef _STATEGAME_H_
#define _STATEGAME_H_

#include <memory>
#include <set>
#include <utility>
using namespace std;

#include "go_font.h"
#include "go_image.h"
#include "go_music.h"
#include "go_sound.h"

#include "BaseButton.h"
#include "Board.h"
#include "State.h"

#include "GameBoard.h"
#include "GameIndicators.h"

class Game;

/**
 * @class StateGame
 *
 * @brief This is the main state of the game.
 *
 * Here is where the game actually takes place.
 *
 * @author José Tomás Tocino García <theom3ga@gmail.com>
 *
 */

class StateGame : public State {
public:
  /// Creates a new StateGame, initializing the loading screen
  StateGame(Game *p);
  ~StateGame();

  virtual void update() = 0;
  void draw();

  void buttonDown(SDL_Keycode button);

  void mouseButtonDown(Uint8 button);
  void mouseButtonUp(Uint8 button);

  void controllerButtonDown(Uint8 button);

  int getScore();

protected:
  friend class GameIndicators;
  friend class GameBoard;

  /// Loads the resources and intializes some variables
  void loadResources();

  /// Resets the game
  void resetGame();

  /// Resets the time
  void resetTime();

  /// Different states of the game
  enum tState { eInitial, eStartLoading, eSteady };

  /// Current state
  tState mState;

  void setState(tState);

  /// Left side of UI
  GameIndicators mGameIndicators;

  /// Right side of the UI
  GameBoard mGameBoard;

  /// Starting time
  double mTimeStart;

private:
  // Increases the score by the given amount
  void increaseScore(int amount);

  /// Shows a hint for a possible match
  void showHint();

  /// Loading screen image
  GoSDL::Image mImgLoadingBanner;

  // Background image
  GoSDL::Image mImgBoard;

  /// Flag that indicates whether the user is clicking
  bool mMousePressed;
};

#endif /* _STATEGAME_H_ */
