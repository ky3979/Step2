/**
* \file FishStarfish.h
*
* \author Ky Nguyen
*
* Class that implements a Starfish fish
*/

#pragma once

#include <memory>
#include "Item.h"

/**
* Implements a Starfish fish
*/
class CFishStarfish : public CItem
{
public:
	/// Default constructor (disabled)
	CFishStarfish() = delete;

	/// Copy constructor (disabled)
	CFishStarfish(const CFishStarfish&) = delete;

	CFishStarfish(CAquarium* aquarium);

	bool HitTest(int x, int y);
	virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
	/// Fish image to use
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

