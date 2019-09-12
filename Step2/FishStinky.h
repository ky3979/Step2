/**
* \file FishStinky.h
*
* \author Ky Nguyen
*
* Class that implements a Stinky fish
*/

#pragma once

#include <memory>
#include "Item.h"

/**
* Implements a Stinky fish
*/
class CFishStinky : public CItem
{
public:
	/// Default constructor (disabled)
	CFishStinky() = delete;

	/// Copy constructor (disabled)
	CFishStinky(const CFishStinky&) = delete;

	CFishStinky(CAquarium* aquarium);

	bool HitTest(int x, int y);
	void SetLocation(double x, double y);
	virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
	/// Fish image to use
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

