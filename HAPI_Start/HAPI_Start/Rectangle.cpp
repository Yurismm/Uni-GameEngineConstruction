#include "Rectangle.h"
#include <algorithm> // needed for std::max and std::min functions

using namespace std;

//adjusts this rectangle so that it doesn't extend outside another rectangle
//used for calculating the visible part of an object within a certain area (eg screen or window)
void Rectangle::ClipTo(const Rectangle& other)
{
    // adjust left edge if it's to the left of the other rectangle
    left = std::max(left, other.left);
    // adjust right edge if it's to the right of the other rectangle
    right = std::min(right, other.right);
    // adjust top edge if it's above the other rectangle
    top = std::max(top, other.top);
    // adjust bottom edge if it's below the other rectangle
    bottom = std::min(bottom, other.bottom);
}

// moves the rectangle by a certain amount
// dx and dy are the distances to move the rectangle horizontally and vertically
void Rectangle::Translate(int dx, int dy)
{
    // move left and right edges horizontally
    left += dx;
    right += dx;
    // move top and bottom edges vertically
    top += dy;
    bottom += dy;
}

bool Rectangle::Intersects(const Rectangle& other) const
{
    // indication of the collisions
    // checks each corner 
    return !(left > other.right || right < other.left ||
            top > other.bottom || bottom < other.top);

}
