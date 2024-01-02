#pragma once


class Rectangle
{

public:
	//coords for rectangle
	int left{ 0 }, right{ 0 }, top{ 0 }, bottom{ 0 };

	// sets position and size of rectangle
	Rectangle() = default;
	Rectangle(int l, int t, int r, int b) 
	: left(l), top(t), right(r), bottom(b) {};

	// calc width and height of rectangle
	int Width() const { return right - left; }
	int Height() const { return bottom - top; }

	// rectange functions 
	void ClipTo(const Rectangle& other);
	void Translate(int dx, int dy);

	bool InterSects(const Rectangle& other) {

	};
};




