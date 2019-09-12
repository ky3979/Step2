/**
* \file FishBeta.h
*
* \author Ky Nguyen
*
* Class that implements a Beta fish
*/

#pragma once

#include <memory>
#include "Item.h"

/**
* Implements a Beta fish
*/
class CFishBeta : public CItem
{
public:
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;

	CFishBeta(CAquarium* aquarium);

	bool HitTest(int x, int y);
	virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
	/// Fish image to use
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

