#include <iostream>

// class declaration
class Gaussian
{
	private:
		float mu, sigma2;

	public:

		// constructor functions
		Gaussian ();
		Gaussian (float, float);

		// change value of average and standard deviation
		void setMu(float);
		void setSigma2(float);

		// output value of average and standard deviation
		float getMu();
		float getSigma2();

		// functions to evaluate
		float evaluate (float);
		Gaussian mul (Gaussian);
		Gaussian add (Gaussian);
};

int main ()
{

	Gaussian mygaussian(30.0,100.0);
	Gaussian othergaussian(10.0,25.0);

	std::cout << "average " << mygaussian.getMu() << std::endl;
	std::cout << "evaluation " << mygaussian.evaluate(15.0) << std::endl;

	std::cout << "mul results variance " << mygaussian.mul(othergaussian).getSigma2() << std::endl;
	std::cout << "mul results average " << mygaussian.mul(othergaussian).getMu() << std::endl;

	std::cout << "add results variance " << mygaussian.add(othergaussian).getSigma2() << std::endl;
	std::cout << "add results average " << mygaussian.add(othergaussian).getMu() << std::endl;

	return 0;
}


#include <iostream>

using namespace std;

// class declaration
class Gaussian
{
	private:
		float mu, sigma2;

	public:

		// constructor functions
		Gaussian ();
		Gaussian (float, float);

		// changes value of average and standard deviation
		void setMu(float);
		void setSigma2(float);

		// outputs value of average and standard deviation
		float getMu();
		float getSigma2();

		// class methods
		float evaluate (float);
		Gaussian mul (Gaussian);
		Gaussian add (Gaussian);
};

int main ()
{
 /*
TODO: Instantiate a Gaussian object called gaussianone.The object
should have mean = 40.0 and variance (aka sigma2) = 225.0
*/
Gaussian gaus1(40.0,225.0);
/*
TODO: Instantiate another Gaussian object called gaussiantwo.
The object should have mean = 35.6 and variance = 12.25
*/
Gaussian gaus2(35.6,12.25);
/*
TODO:
Output to the terminal the following (hint: use the std namespace with cout or
use std::cout):
- the probability density function value for gaussianone when x = 10.5
- the probability density function value for gaussianone when x = 55.4
- the probability density function value for gaussiantwo when x = 35.6
- the probability density function value for gaussiantwo when x = 29.4
*/
 cout<<gaus1.evaluate(10.5)<<endl;
 cout<<gaus1.evaluate(55.4)<<endl;
 cout<<gaus1.evaluate(35.6)<<endl;
 cout<<gaus1.evaluate(29.4)<<endl;
/*
TODO:
- Change the mean value of gaussianone to mean = 45
- Change the variance of gaussiantwo to variance = 15.4
- Output the mean of gaussianone to the terminal
- Output the variance of gaussiantwo to the terminal
*/
 gaus1.setMu(45.0);
 gaus2.setSigma2(15.4);
 cout<<gaus1.getMu()<<endl;
 cout<<gaus2.getSigma2()<<endl;
/*
TODO:
- Multiply gaussian one and gaussian two. Store the resulting gaussian
in a variable called gaussianthree
- Output the mean and variance of gaussianthree to the terminal
- Add gaussian one and gaussian two. Store the resulting gaussian in a
variable called gaussianfour
- Output the mean and variance of gaussianfour to the terminal
*/
Gaussian gaus3 = gaus1.mul(gaus2);
Gaussian gaus4 = gaus1.add(gaus2);
  cout<<gaus3.getMu()<<", "<<gaus3.getSigma2()<<endl;
  cout<<gaus4.getMu()<<", "<<gaus4.getSigma2()<<endl;





}
