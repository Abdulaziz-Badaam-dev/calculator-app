#include <iostream>

using namespace std;

class clsCalculater
{
private:
	float _Result = 0;
	float _LastNumber = 0;
	string _OperationName = "Clear";
	float _PervoiusResult = 0;

	bool _IsZero(float Number)
	{
		return (Number == 0);
	}

public:
	void Clear()
	{
		_Result = 0;
		float _LastNumber = 0;
		string _OperationName = "Clear";
		float _PervoiusResult = 0;
	}

	void Add(float Num)
	{
		_LastNumber = Num;
		_PervoiusResult = _Result;
		_Result += _LastNumber;
		_OperationName = "Adding";
	}

	void Subtract(float Num)
	{
		_LastNumber = Num;
		_PervoiusResult = _Result;
		_Result -= _LastNumber;
		_OperationName = "Substrating";
	}

	void Multiply(float Num)
	{
		_LastNumber = Num;
		_PervoiusResult = _Result;
		_Result *= _LastNumber;
		_OperationName = "Multiplying";
	}

	void Divided(float Num)
	{
		_LastNumber = Num;
		if (_IsZero(Num))
		{
			_LastNumber = 1;
		}
		_PervoiusResult = _Result;
		_Result /= _LastNumber;
		_OperationName = "Dividing";
	}

	void PrintResult()
	{
		cout << "Result ";
		cout << "After " << _OperationName << " " <<
			_LastNumber << " is: " << _Result << "\n";
	}

	void CancelLastOperation()
	{
		_LastNumber = 0;
		cout << "Cancelling Last Operation ";
		_Result = _PervoiusResult;
	}

	float GetFinalResult()
	{
		return _Result;
	}

};


int main()
{
	clsCalculater Calculater;

	Calculater.Add(150);
	Calculater.PrintResult();

	Calculater.Divided(2);
	Calculater.PrintResult();

	Calculater.Divided(2);
	Calculater.PrintResult();

	Calculater.CancelLastOperation();
	Calculater.PrintResult();


	system("pause 0");
	return 0;

}