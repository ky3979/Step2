/**
* \file Aquarium.cpp
*
* \author Ky Nguyen
*/

#include "pch.h"
#include <string>
#include <algorithm>
#include "Aquarium.h"
#include "FishStinky.h"
#include "leak.h"

using namespace Gdiplus;
using namespace std;

/// Image to use for the background
const wstring BackgroundImageName = L"images/background1.png";

/**
* Constructor
*/
CAquarium::CAquarium()
{
	// Load image from disk
	mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(BackgroundImageName.c_str()));
	
	// Error check
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
}

/**
* Destructor
*/
CAquarium::~CAquarium()
{
	mItems.clear();
}

/**
* Add an item to the aquarium.
*
* \param item New item to add
*/
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/**
* Draw the aquarium.
*
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 61, 0));
	graphics->DrawString(L"Under the sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/** 
* Test an x,y click location to see if it clicked
* on some item in the aquarium.
*
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
* Move an item to the end of the list.
*
* The item is removed from the list then
* inserted at the end of the list.
*
* \param item Item to move
*/
void CAquarium::MoveItemToFront(std::shared_ptr<CItem> item)
{
	auto loc = find(mItems.begin(), mItems.end(), item);

	if (loc != mItems.end())
	{
		mItems.erase(loc);
		mItems.push_back(item);
	}
}

/**
* Tells the aquarium that the stinky fish has moved.
*
* The stinky fish has moved from this location.
*
* \param x X location of the stinky fish
* \param y Y location of the stinky fish
*/
void CAquarium::StinkyFishMoved(double x, double y)
{
	// Loops through the list to move the items 
	// away from this position.
	for (auto item : mItems)
	{
		item->Nudge(x, y);
	}
}
