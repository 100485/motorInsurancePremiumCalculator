#include <iostream>
#include <cstdlib>
using namespace std;

double getBase (double carValue, double& premium);
double accidentAdjust (double accidents, double& premium);
double getRiskSurcharge (double& premium, char riskSurcharge);
double excessProtector (double excessP, double& carValue, double& premium);
double leviesCharged(double pLevies, double cLevies, double& premium);

int main()
{
	double carValue, premium=0, pLevies, cLevies;
	double accidents, excessP;
	char riskSurcharge, excessProtection;
	
	cout << endl << endl << "GoldOak Insurance Agency" << endl;
	cout << "Automotive Policy Annual Premium Calculator" << endl << endl;
	
	cout << "Enter the value of the vehicle to be insured:  KShs ";
	cin >> carValue;
	if (carValue<0)
	{
		cout<<"You have entered an invalid number. The program will now terminate." <<endl;
		exit(1);   
	}
	else getBase(carValue, premium);



	cout << "How many accidents has the policyholder caused in the last three years? ";
	cin >> accidents;

	if (accidents<0)
	{
		cout<<"You have entered an invalid number. The program will now terminate." <<endl;
		exit(1);   
	}
	else accidentAdjust(accidents, premium);

	if(accidents <= 3)
	cout << "You qualify for Excess Protection." << endl;	
	cout << "Do you require Excess Protection. Y/N: ";
	cin >> excessProtection;

	
	cout << "Enter the geographical risk factor a is low, e is high (Class a - e): ";
	cin >> riskSurcharge;
	
	getRiskSurcharge(premium, riskSurcharge);

	// If Client is taking Excess Protection, Calculate Excess Protection + Premium
	if(excessProtection == 'Y' || excessProtection == 'y'){
		excessProtector (excessP, carValue, premium);
	}
	
	// Add Levies charged for the services
	leviesCharged(pLevies, cLevies, premium);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "The premium for this policyholder will be: KShs " << premium << endl << endl;

	// cout << "Excess Protection: " << excessP << endl;

	// cout << "Levies Charged: " << pLevies << endl;

	// cout << "Stamp Duty: " << cLevies << endl;
	
	cout << "Insure to be Sure" << endl << endl << endl << endl;
	
	return 0;
}

// Comment
double getBase(double carValue, double& premium)
{
	if(carValue>= 500000 && carValue<=1499999)
	premium = carValue*0.06;
	if(carValue>= 1500000 && carValue<=2499999)
	premium = carValue*0.05;
	if(carValue>= 2500000 && carValue<=3499999)
	premium = carValue*0.04;
	if(carValue>= 3500000 && carValue<=4999999)
	premium = carValue*0.035;
	if(carValue > 5000000)
	premium = carValue*0.03;
	if(carValue < 500000){
		cout << "Vehicle Value is below Insurable Value" << endl;
		exit(1);
	}

	return premium;
}

// Comment
double accidentAdjust(double accidents, double& premium)
{
	if (accidents == 0)
		premium=premium - (premium*0.05);
	if (accidents>=1 && accidents<=3)
		premium=premium*(accidents*.025)+premium;
	if (accidents>3 && accidents<=6)
		premium=premium*(accidents*.05)+premium;
	if (accidents>6)
	{
		cout<<"We will not be able to insure your vehicle."<<endl;
		exit(1);   
	}
	
	return premium;
}

// comment
double getRiskSurcharge(double& premium, char riskSurcharge)
{
	switch (riskSurcharge) 
	{
	case 'A':
	case 'a':
		premium=premium+2000;
		break;
	case 'B':
	case 'b':
		premium=premium+3000;
		break;
	case 'C':
	case 'c':
		premium=premium+5000;
		break;
	case 'D':
	case 'd':
		premium=premium+10000;
		break;
	case 'E':
	case 'e':
		premium=premium+25000;
		break;
	default:
		cout<<"You have entered an invalid number. The program will now terminate."<<endl;
		exit(1);
	}

		return premium;
}

// Comment
double excessProtector(double excessP, double& carValue, double& premium)
{
	excessP = carValue * 0.0025;

	if (excessP <= 5000){
		excessP = 5000;
	}

	premium = premium + excessP;
	
	return premium;
}


// Comment
double leviesCharged(double pLevies, double cLevies, double& premium)
{
	pLevies = premium * 0.0045;

	cLevies = 40;

	premium = premium + cLevies + pLevies;
	
	return premium;
}
