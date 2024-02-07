class	Cat
{
	public:
		class Leg
		{
			//[...]
		};
};

class	Dog
{
	public:
		class Leg
		{
			//[...]
		};
};

int	main()
{
	Cat			somecat;
	Cat::Leg	somecatleg;
}

//one class leg belong to the cat class and the other to the dog class
//hence i can instantiated one or the other