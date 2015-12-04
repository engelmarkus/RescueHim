#include "Player.h"
#include "Point.h"
#include <iostream>

namespace RescueHim {
    /**
     * @brief Creates a new Player instance.
     * @param x The x-value of the position
     * @param y The y-value of the position
     */
    Player::Player(int x, int y) noexcept
        : position{Geom::Point(x, y)}
    {
    }

    /**
     * @brief Creates a new Player instance from a point.
     * @param p Point to initialize the Player's position
     */
    Player::Player(Geom::Point p) noexcept
        : position{p}
    {
    }

    /**
     * @brief Returns the Player's current position
     * @param none
     */
    Geom::Point Player::getPosition() const {
        return this->position;
    }

    /**
     * @brief Player moves one step to the top
     * @param none
     */
    void Player::moveTop() {
        this->position.y++;
    }

    /**
     * @brief Player moves one step down
     * @param none
     */
    void Player::moveDown() {
        this->position.y--;
    }

    /**
     * @brief Player moves one step to the left
     * @param none
     */
    void Player::moveLeft() {
        this->position.x--;
    }

    /**
     * @brief Player moves one step to the right
     * @param none
     */
    void Player::moveRight() {
        this->position.x++;
    }

    /**
     * @brief prints the Player to ostream
     * @param os 	ostream to print Player to
     * @param p 	The Player you want to write to the ostream
     */
    std::ostream& operator<<(std::ostream& os, Player const& p) {
        os << "Player's position: " << p.getPosition();
        return os;
    }
}
