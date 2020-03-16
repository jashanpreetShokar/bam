#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace sf; using namespace std;
class arrow
{
private:
	// items

public:
	Texture nothit_arrow;
	Texture hit_arrow;
	RectangleShape larrow; // <-
	RectangleShape uarrow; // ^
	RectangleShape darrow; // v
	RectangleShape rarrow; // -> 
	vector<RectangleShape> vec_arrow;
	Rect<float> left_arrow_size;
	Rect<float> up_arrow_size;
	Rect<float> down_arrow_size;
	Rect<float> right_arrow_size;

	// functions
	arrow();
	void draw(RenderWindow& window);



};


class leftArrow
{

public:
	leftArrow();
	void draw(RenderWindow& window);
	void move(float y);
	RectangleShape getLeft() { return larrow; };
private:
	Texture nothit_arrow;
	RectangleShape larrow;
	Rect<float> left_arrow_size;
	

};



class upArrow
{

public:
	upArrow();
	void draw(RenderWindow& window);
	void move(float y);
	RectangleShape getUp() { return uarrow; };
private:
	Texture nothit_arrow;
	RectangleShape uarrow;
	Rect<float> up_arrow_size;


};


class downArrow
{

public:
	downArrow();
	void draw(RenderWindow& window);
	void move(float y);
	RectangleShape getDown() { return darrow; };
private:
	Texture nothit_arrow;
	RectangleShape darrow;
	Rect<float> down_arrow_size;


};

class rightArrow
{

public:
	rightArrow();
	void draw(RenderWindow& window);
	void move(float y);
	RectangleShape getRight() { return rarrow; };
private:
	Texture nothit_arrow;
	RectangleShape rarrow;
 


};
