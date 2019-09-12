/**
* \file CAquariumTest.cpp
*
* \author Ky Nguyen
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "FishBeta.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			// Empty aquarium
			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			// Add a fish to our aquarium
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);
			
			// Hit test for fish
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");

			// Second fish in our aquarium on top of the first one
			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			// Two fish on top of each other test
			// Hit test on location of the two fish
			// fish1 test
			Assert::IsFalse(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish1 at 100, 200");
			
			// fish2 test
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2,
				L"Testing fish2 at 100, 200");

			// Aquarium with fish
			Assert::IsFalse(aquarium.HitTest(100, 200) == nullptr,
				L"Testing aquarium with fish");

			Assert::IsTrue(aquarium.HitTest(300, 400) == nullptr,
				L"Testing aquarium with fish");
		}
	};
}