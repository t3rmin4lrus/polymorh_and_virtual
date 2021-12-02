#include <iostream>

//Задание 1:

class Figure
{
public:
	virtual double area() = 0;
};

class Parallelogram : Figure
{
protected:
	double a, h;

public:
	Parallelogram(double aA, double hH) : a(aA), h(hH) {};

	double area() override
	{
		return(a * h);
	}
};

class Circle : Figure
{
private:
	double r;
public:
	Circle(double rR) : r(rR) {};

	double area() override
	{
		return(3.14 * r * r / 2);
	}
};

class Rectangle : Parallelogram
{
public:
	Rectangle(double aA, double hH) : Parallelogram(aA, hH) {};

	double area() override
	{
		return(a * h);
	}
};

class Square : Parallelogram
{
public:
	Square(double aA) : Parallelogram(aA, aA) {};

	double area() override
	{
		return(a * a);
	}
};

class Rhombus : Parallelogram
{
public:
	Rhombus(double aA, double hH) : Parallelogram(aA, hH) {};

	double area() override
	{
		return(a * h);
	}

};

//Задание 2:

class Car
{
protected:

	std::string companyCar,modelCar;

public:

	Car() {}
	Car(std::string enterCompanyCar, std::string enterModelCar) 
		: companyCar(enterCompanyCar), modelCar(enterModelCar)

	{
		std::cout << "\nCar Constructor";
	}

	virtual ~Car()
		{
			std::cout << "\nCar Destructor";
		}

};

class PassengerCar : virtual public Car
{
public:

	PassengerCar(){}
	PassengerCar(std::string enterCompanyCar, std::string enterModelCar)
		: Car(enterCompanyCar, enterModelCar)
	{
		std::cout << "\nPassenger car constructor";
		std::cout << "\n" << companyCar << " " << modelCar;
	}
	
	std::string getModel()
	{
		return modelCar;
	}
	
	~PassengerCar()
	{
		std::cout << "\nPassenger car Destructor";
	}
};

class Bus : virtual public Car
{
public:
	Bus() {}
	Bus(std::string enterCompanyCar, std::string enterModelCar)
		: Car(enterCompanyCar, enterModelCar)
	{
		std::cout << "\nBus constructor";
		std::cout << "\n" << companyCar << modelCar;
	}
	~Bus()
	{
		std::cout << "\nBus destructor";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:

	Minivan(std::string enterCompanyCar, std::string enterModelCar)
		: Car(enterCompanyCar, enterModelCar)

	{
		std::cout << "\nMinivan constructor";
		std::cout << "\n" << companyCar << modelCar;
	}
	~Minivan()
	{
		std::cout << "\nMinivan destructor";
	}
};

//Задание 3:

class Fraction
{
private:

	double numerator, denominator;

public:

	Fraction(double enterNumerator, double enterDenominator)
		: numerator(enterNumerator), denominator(enterDenominator)
	{
		if (denominator == 0) denominator == 0.00000001;
	}
	friend Fraction operator+(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1, const Fraction& d2);
	friend Fraction operator*(const Fraction& d1, const Fraction& d2);
	friend Fraction operator/(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

	void setDenominator(double inputDenominator)
	{
		if (inputDenominator == 0) inputDenominator = 0.00000001;
		denominator = inputDenominator;
	}

	void setNumerator(double inputNumerator)
	{
		numerator = inputNumerator;
	}

	double getNumerator()
	{
		return numerator;
	}

	double getDenominator()
	{
		return denominator;
	}
};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
	return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
	else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
	if (d1 == d2) return false;
	else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
	if (!(d1 > d2)) return true;
	else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
	if (!(d1 < d2)) return true;
	else return false;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}

//Задание 4

class Card
{
public:
enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

Card(rank r = ACE, suit s = SPADES, bool ifu = true);

int GetValue() const;

void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
		return value;
	}
}

void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

int main()
{
	double parallelorgamHeight(3), parallelogramBase(5.1);
	Parallelogram parallelogram(parallelogramBase, parallelorgamHeight);
	std::cout << parallelogram.area() << "\n";

	double circleRadius(2.8);
	Circle circle(circleRadius);
	std::cout << circle.area() << "\n";

	double squareBase(5);
	Square square(squareBase);
	std::cout << square.area() << "\n";

	double rectangleBase(3), rectangleHeight(3);
	Rectangle rectangle(rectangleBase, rectangleHeight);
	std::cout << rectangle.area() << "\n";

	double rhombusBase(2), rhombusHeight(5);
	Rhombus rhombus(rhombusBase, rhombusHeight);
	std::cout << rhombus.area() << "\n";

	Car* car = new Car("Ford", "Fusion");
	std::cout << "\n=";
	PassengerCar* passengerCar = new PassengerCar("Lifan", "Smily");
	std::cout << "\n=";
	Bus* bus = new Bus("UAZ", "2206");
	std::cout << "\n=";
	Minivan* minivan = new Minivan("Toyota", "Alphard");
	std::cout << "\n=";
	delete minivan;
	std::cout << "\n=";
	delete bus;
	std::cout << "\n=";
	delete passengerCar;
	std::cout << "\n=";
	delete car;

	Fraction d1(3, 2);
	Fraction d2(8, 3);
	std::cout << "\n\n" << (d1 + d2);
	std::cout << "\n\n" << (d1 - d2);
	std::cout << "\n\n" << (d1 * d2);
	std::cout << "\n\n" << (d1 / d2);
	std::cout << "\n\n" << (-d1) << "\n";

	if (d1 == d2) std::cout << "\nFraction 1 == Fraction 2";
	if (d1 != d2) std::cout << "\nFraction 1 != Fraction 2";
	if (d1 > d2) std::cout << "\nFraction 1 > Fraction 2";
	if (d1 <= d2) std::cout << "\nFraction 1 <= Fraction 2";
	if (d1 < d2) std::cout << "\nFraction 1 < Fraction 2";
	if (d1 >= d2) std::cout << "\nFraction 1 >= Fraction 2";
}