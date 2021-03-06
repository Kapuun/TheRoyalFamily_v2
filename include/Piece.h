#pragma once

#include <tuple>
#include <iostream>

namespace TheRoyalFamily_v2
{


class TPiece
{

public:

	using PiecePos = std::tuple<char, int>;
	enum Color { white, black };

private:

	const Color		fColor;
	PiecePos		fPos; 
	const char		fCode{};

public:

	TPiece(char file, int rank, Color color, char code) : fPos{ std::make_tuple(file, rank) }, fColor{ color }, fCode{ code } {}
	virtual ~TPiece() = default;

public:

	PiecePos GetPos(void) { return fPos; }

public:

	virtual bool Move( PiecePos& curr_pos, PiecePos& target_pos ) = 0;

};


std::ostream& operator<< (std::ostream& o, const TPiece& p);



}