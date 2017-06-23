#include <iostream>
#include <cmath> 
#include <map>

using namespace std;

/* Fibonacci with memoization boi */
int Fibonnacci(int n)
{
	static map<int , int> cache = {{0,0},{1,1}};
	auto found = cache.find(n);
	if (found!=cache.end())
	{
		return found->second;
	}

	int result = Fibonnacci(n - 1) + Fibonnacci(n - 2);
	cache[n] = result;
	
	return result;
	//if(num%5 == 0) cout << "Fizz"
}

/* simple prime number checker */
int isPrime(double num)
{
	int isprime = 0;
	for(int i = 2; i <= sqrt(num); i += 2)
	{
		if(i % 2 == 0)
			i++;

		if((int(num)% i) == 0)
		{
			isprime = 1;
			break;
		}
	}
	return isprime;
}

/*-------- FizzBuzzer Function ------------*

	when divisible by 5 -> "Fizz"
	when divisible by 3 -> "Buzz"
	when divisible by 15-> "FizzBuzz"
	when prime 			-> "BuzzFizz"

-------------------------------------------*/
string fizzBuzz(int num)
{
	string s = "";
	
	if(num % 5 == 0)
		s += "Fizz";
	if(num % 3 == 0)
		s += "Buzz";
	if(s == "")
		return to_string(num);
	if(isPrime(num))
	{	
		s += "BuzzFizz";
	}

	return s;
}


int main()
{
	int input;
	cout << "Enter num for FizzBuzz: ";
	cin >> input;
	//cout << endl;


	for (int i = 0;i <= input;i++)
	{
		int fibnum = Fibonnacci(i);
		string s = fizzBuzz(fibnum);
		cout << s << endl;
	}
	return 0;
}