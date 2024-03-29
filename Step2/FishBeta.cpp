/**
* \file FishBeta.cpp
*
* \author Ky Nguyen
*/

#include "pch.h"
#include <string>
#include "FishBeta.h"

using namespace Gdiplus;
using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
* Constructor
*
* \param aquarium Aquarium this fish is a member of
*/
CFishBeta::CFishBeta(CAquarium *aquarium) : CItem(aquarium) 
{
	// Load image from disk
	mFishImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishBetaImageName.c_str()));
	
	// Error check
	if (mFishImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open");
		msg += FishBetaImageName;
		AfxMessageBox(msg.c_str());
	}
}

/**
* Test to see if we hit this object with a mouse.
*
* \param x X postion to test
* \param y Y position to test
* \return true if hit
*/
bool CFishBeta::HitTest(int x, int y)
{
	double width = mFishImage->GetWidth();
	double height = mFishImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + width / 2;
	double testY = y - GetY() + height / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= width || testY >= height)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mFishImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mFishImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else 
	{
		return true;
	}
}

/**
* Draw this item
*
* \param graphics Graphics device to draw on
*/
void CFishBeta::Draw(Gdiplus::Graphics *graphics)
{
	double width = mFishImage->GetWidth();
	double height = mFishImage->GetHeight();
	graphics->DrawImage(mFishImage.get(),
		float(GetX() - width / 2), float(GetY() - height / 2),
		(float)mFishImage->GetWidth(), (float)mFishImage->GetHeight());
}