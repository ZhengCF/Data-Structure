#include<iostream>

using namespace std;

class Boat;
class  Car
{
	public:
		Car(float j) { weight = j; };
		~ Car();
		friend float totalWeight(Car &acar,Boat &aboat);
	private:
		float weight;
};

 Car::~ Car()
{
}

 class  Boat
{
	public:
		Boat(float i) { weight = i; };
		~ Boat();
		friend float totalWeight(Car &acar, Boat &aboat);
	private:
		float weight;
 };

  Boat::~ Boat()
 {
 }

  float totalWeight(Car &acar, Boat &aboat) {
	  return acar.weight + aboat.weight;
  }

  int main() {
	  Car C(30.5);
	  Boat B(50.8);
	  cout << totalWeight(C, B) << endl;
  }