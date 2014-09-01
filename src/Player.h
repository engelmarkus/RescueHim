#ifndef PLAYER_H
#define PLAYER_H

#include<iosfwd>
#include "Point.h"

namespace RescueHim 
{
    //Represents a Player in the 2d-space
    class Player final
    {
    private:
      Geom::Point position;
    public:  
      Player() = default;
      Player(int x, int y) noexcept;
      Player(Geom::Point p) noexcept;
      
      Player(const Player& p) noexcept = default;
      Player& operator=(const Player& p) noexcept = default;
      
      Player(Player&& p) noexcept = default;
      Player& operator=(Player&& p) noexcept = default;
      
      Geom::Point getPosition() const;
      
      void moveTop();
      void moveDown();
      void moveLeft();
      void moveRight();
    };
    
    std::ostream& operator<<(std::ostream& os, const Player& p);
    
}

#endif