/**
* \file FishMagikarp.h
*
* \author Ky Nguyen
*
* Class that implements a Magikarp fish
*/

#pragma once

#include <memory>
#include "Item.h"

/**
* Implements a Magikarp fish
*/
class CFishMagikarp : public CItem
{
public:
	/// Default constuctor (disabled)
	CFishMagikarp() = delete;

	/// Copy constructor (disabled)
	CFishMagikarp(const CFishMagikarp&) = delete;

	CFishMagikarp(CAquarium* aquarium);

	bool HitTest(int x, int y);
	virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
	/// Fish image to use
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

