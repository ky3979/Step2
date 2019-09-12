/**
* \file Item.cpp
*
* \author Ky Nguyen
*/

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

/// Maximum allowed X value
const double MaxX = 950;

/// Minimum allowed X value
const double MinX = 100;

/// Maximum allowed Y value
const double MaxY = 750;

/// Minimum allowed Y value
const double MinY = 50;

/// Minimum distance from a nudging fish
const double MinDistance = 200;

/**
* Constructor
*
* \param aquarium The aquarium this item is a member of
*/
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}

/**
* Destructor
*/
CItem::~CItem()
{
}

/**
* Moves this item away from this location.
*
* That location belongs to a stinky fish,
* so we move the fish away from it.
*
* \param stinkyX X location to move away from
* \param stinkyY Y location to move away from
*/
void CItem::Nudge(double stinkyX, double stinkyY)
{
	// fishX, fishY is the position of a fish
	double fishX = GetX();
	double fishY = GetY();

	// Create a vector in the direction we are from the nudger
	double dx = fishX - stinkyX;
	double dy = fishY - stinkyY;

	// Determine how far away we are
	double distance = sqrt(dx * dx + dy * dy);
	if (distance > 0 && distance < MinDistance)
	{
		// Distance is less than our minimum
		dx *= MinDistance / distance;
		dy *= MinDistance / distance;

		// New position for the fish
		fishX = stinkyX + dx;
		fishY = stinkyY + dy;

		// Check if the fish is in bound
		if ((fishX > MinX && fishX < MaxX) && (fishY > MinY && fishY < MaxY))
		{
			CItem::SetLocation(fishX, fishY);
		}
	}
}
