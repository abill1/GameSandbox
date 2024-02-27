
#include "Game/Game.h"

namespace ABFramework {
	class Animal
	{
	public:
		virtual ~Animal() {};
	};

	typedef std::function<void(Animal*)> t_AnimalFunctions;


	class Dog : public Animal
	{
	public:
		void Test() { printf("Test Function from dog\n"); }
	};


	class Cat : public Animal
	{
	public:
		Cat() : Woah(new int) {};
		virtual ~Cat() { delete Woah; }
		void Test() { printf("Test Function from cat\n"); }
		int* Woah;
	};

}



int main()
{

	ABFramework::MemoryTracker::Init();

	ABFramework::ManagedObjects<ABFramework::Animal> mAnimals;
	if(mAnimals.Add("Spot", new ABFramework::Dog()) != 0)
		printf("Added Dog Spot\n");
	if (mAnimals.GetObject("Spot") != nullptr)
		printf("Found Spot\n");
	if (mAnimals.GetObject(ABFramework::String("Spot").GetHash()) != nullptr)
		printf("Found Spot\n");

	if (mAnimals.Add<ABFramework::Cat>("Pip") != 0)
		printf("Added Cat Pip\n");

	((ABFramework::Cat*)mAnimals.GetObject("Pip"))->Test();

	if (mAnimals.GetObject("Pip") != nullptr)
		printf("Found Pip\n");
	if (mAnimals.GetObject(ABFramework::String("Pip").GetHash()) != nullptr)
		printf("Found Pip\n");


    ABFramework::Code retCode = ABFramework::Code::SUCCESS;
	ABFramework::Game game("Hello World", 1200, 900);
	retCode = game.Run();



	return (int)retCode;
}

