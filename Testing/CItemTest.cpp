/**
* \file CItemTest.cpp
*
* \author Ky Nguyen
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Aquarium.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	/**
	* Mock class for testing CItem
	*/
	class CItemMock : public CItem
	{
	public:
		CItemMock(CAquarium* aquarium) : CItem(aquarium) {}

		/**
		* Test this item to see if it has been clicked on.
		*
		* \param x X location on the aquarium to test
		* \param y Y location on the aquarium to test
		* \return true if clicked on
		*/
		virtual bool HitTest(int x, int y) { return false; }

		/**
		* Draw this item.
		*
		* \param graphics Graphics device to draw on
		*/
		virtual void Draw(Gdiplus::Graphics* graphics) {};
	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemConstruct)
		{
			CAquarium aquarium;
			CItemMock item(&aquarium);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CAquarium aquarium;
			CItemMock item(&aquarium);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}
	};
}