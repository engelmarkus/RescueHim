#include "Player.h"
#include "Point.h"
#include <iostream>

namespace RescueHim 
{
  /** 
   * @brief Creates a new Player instance.
   * @param x The x-value of the position
   * @param y The y-value of the position
   */
  Player::Player(int x, int y) noexcept : position{Geom::Point(x, y)} {}
  /** 
   * @brief Creates a new Player instance from a point.
   * @param p Point to initialize the Player's position
   */
  Player::Player(Geom::Point p) noexcept : position{p} {}
  
  /**
   * @brief Returns the Player's current position
   * @param none
   */
  Geom::Point Player::getPosition() const
  {
      return this->position;
  }
  /**
   * @brief prints the Player to ostream
   * @param os 	ostream to print Player to
   * @param p 	The Player you want to write to the ostream
   */
  std::ostream& operator<<(std::ostream& os, const Player& p)
  {
      os << "Player's position: " << p.getPosition();
      return os;
  }
}