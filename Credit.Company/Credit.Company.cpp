#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<fstream.h>
#include <stdio.h>
using namespace std;

class company
{
public:
	company()
	{
		insertCapital();
		insertDaysForCredit();
		insertInterest();
		insertMinSumForCredit();
	}

	void insertCapital();
	int insertDaysForCredit();
	float insertInterest();
	int insertMinSumForCredit();
	float computeInterest();
	int computeGivePeriod();
	int computeNotGivePeriod();
	int computeLoop();
	int capital;
	int daysForCredit;
	float interest;
	int minSumForCredit;


};

void company::insertCapital()
{
	cout << "Enter initial capital: ";
	cin >> capital;
}
int company::insertDaysForCredit()
{
	cout << "Enter days for return credit: ";
	cin >> daysForCredit;

	return daysForCredit;
}
float company::insertInterest()
{
	cout << "Enter day interest between 0.5% and 3%: ";
	cin >> interest;

	return interest;
}
int company::insertMinSumForCredit()
{
	cout << "Enter min sum for credit: ";
	cin >> minSumForCredit;

	return minSumForCredit;
}
float company::computeInterest()
{

	return minSumForCredit * (interest / 100)*daysForCredit;
}


int company::computeGivePeriod()
{
	int givePeriod = capital / minSumForCredit;

	return givePeriod;
}
int company::computeNotGivePeriod()
{
	int notGivePeriod = daysForCredit - computeGivePeriod();

	return notGivePeriod;
}
int company::computeLoop()
{
	int loop = 365 / daysForCredit;

	return loop;
}


int main()
{
	int giveDays, notGiveDays, Loop, lastGiveDays;
	string filenm;
	int choice;
	do
	{
		cout << " Give a name to your file: ";
		cin >> filenm;
		ofstream file;
		file.open(string(filenm + ".dat").c_str());
		if (!file) { cerr << "File couldn't be openend!\n"; return 1; }

		cout << " Plese enter the next data:\n\n";
		company comp1;
		file << "Initial capital " << comp1.capital << " lv. Loan period: " << comp1.daysForCredit << " days Interest: " << comp1.interest
			<< "% Minimum credit: " << comp1.minSumForCredit << " lv" << "\n\n";
		giveDays = comp1.computeGivePeriod();
		notGiveDays = comp1.computeNotGivePeriod();
		Loop = comp1.computeLoop();
		lastGiveDays = 365 % comp1.daysForCredit;
		int leftCapital = comp1.capital%comp1.minSumForCredit;

		int i = 1, numCredit = 0, numDay = 0;
		float iterestToCollect = 0.0, insurance = 0.0, currentCapital = 0.0 + leftCapital;

		if (giveDays <= comp1.daysForCredit)
		{

			while (i <= Loop)
			{

				if (i <= Loop - 1)
				{
					for (int j = 1; j <= giveDays; j++)
					{
						if (i == 1)
						{
							numCredit += 1;
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital " << comp1.capital - (numCredit*comp1.minSumForCredit)
								<< " Interest to collect " << numCredit * comp1.computeInterest() << endl;

							file << " Days " << numDay << " Number of credits: " << numCredit
								<< " Current capital " << comp1.capital - (numCredit*comp1.minSumForCredit)
								<< " lv Interest to collect " << numCredit * comp1.computeInterest() << " lv" << "\n";

							iterestToCollect = numCredit * comp1.computeInterest();
						}

						if (i > 1 && i <= Loop - 1)
						{
							numCredit += 1;
							currentCapital += comp1.computeInterest() - (0.35*comp1.computeInterest());
							insurance += (0.35*comp1.computeInterest());
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital " << currentCapital
								<< " Interest to collect " << iterestToCollect
								<< " Insurance " << insurance << endl;

							file << " Days " << numDay << " Number of credits: " << numCredit
								<< " Current capital " << currentCapital
								<< " lv Interest to collect " << iterestToCollect << " lv"
								<< " Insurance " << insurance << " lv" << "\n";
						}
					}

					for (int k = 1; k <= notGiveDays; k++)
					{
						if (i == 1)
						{
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital: " << leftCapital
								<< " Interest to collect " << numCredit * comp1.computeInterest() << endl;

							file << " Days " << numDay << " Number of cerdits: " << numCredit
								<< " Current capital: " << leftCapital
								<< " lv Interest to collect " << numCredit * comp1.computeInterest() << " lv" << "\n";
						}
						if (i > 1 && i <= Loop - 1)
						{
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital " << currentCapital
								<< " Interest to collect " << iterestToCollect
								<< " Insurance " << insurance << endl;

							file << " Days " << numDay << " Number of cerdits: " << numCredit
								<< " Current capital" << currentCapital
								<< " lv Interest to collect " << iterestToCollect << "lv"
								<< " Insurance " << insurance << " lv" << "\n";
						}
					}
				}
				else
				{
					if (lastGiveDays < giveDays)
					{
						for (int m = 1; m <= lastGiveDays; m++)
						{
							numCredit += 1;
							currentCapital += comp1.computeInterest() - (0.35*comp1.computeInterest());
							insurance += (0.35*comp1.computeInterest());
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital " << currentCapital
								<< " Interest to collect " << iterestToCollect
								<< " Insurance " << insurance << endl;

							file << " Days" << numDay << " Number of cerdits: " << numCredit
								<< " Current capital " << currentCapital
								<< " lv Interest to collect " << iterestToCollect << " lv"
								<< " Insurance " << insurance << " lv" << "\n";
						}
					}
					if (lastGiveDays > giveDays)
					{
						for (int m = 1; m <= giveDays; m++)
						{
							numCredit += 1;
							currentCapital += comp1.computeInterest() - (0.35*comp1.computeInterest());
							insurance += (0.35*comp1.computeInterest());
							numDay += 1;
							cout << numDay << endl;
							cout << " Number of credits: " << numCredit
								<< " Current capital " << currentCapital
								<< " Interest to collect " << iterestToCollect
								<< " Insurance " << insurance << endl;

							file << " Days " << numDay << " Number of cerdits: " << numCredit
								<< " Current capital " << currentCapital
								<< " lv Interest to collect" << iterestToCollect << " lv"
								<< " Current capital " << insurance << " lv" << "\n";
						}
					}
				}
				i++;
			}
			file.close();
		}

		else
		{

			int leftCurrentCapital = comp1.capital - (comp1.daysForCredit*comp1.minSumForCredit);
			if (leftCapital > 0)

				currentCapital += leftCurrentCapital - leftCapital;
			else
				currentCapital += leftCurrentCapital;

			for (int j = 1; j < 365 - comp1.daysForCredit; j++)
			{
				if (numCredit < comp1.daysForCredit)
				{
					numCredit += 1;
					numDay += 1;
					cout << numDay << endl;
					cout << " Number of credits: " << numCredit
						<< " Current capital " << comp1.capital - (numCredit*comp1.minSumForCredit)
						<< " Interest to collect " << numCredit * comp1.computeInterest() << endl;

					file << " Days " << numDay << " Number of credits: " << numCredit
						<< " Current capital" << comp1.capital - (numCredit*comp1.minSumForCredit)
						<< " lv Interest to collect " << numCredit * comp1.computeInterest() << " lv" << "\n";

					iterestToCollect = numCredit * comp1.computeInterest();
				}


				if (numCredit >= comp1.daysForCredit)
				{
					numCredit += 1;
					numDay += 1;

					if (numCredit > 2 * (comp1.daysForCredit))

						currentCapital += 0.65*(comp1.computeInterest() + comp1.computeInterest1());
					else
						currentCapital += (0.65*comp1.computeInterest()) - (0.2*comp1.minSumForCredit);

					if (numCredit > 2 * (comp1.daysForCredit))

						insurance += (0.35*(comp1.computeInterest() + comp1.computeInterest1()));

					else
						insurance += (0.35*comp1.computeInterest());

					if (numCredit > 2 * (comp1.daysForCredit))

						iterestToCollect += 0;
					else

						iterestToCollect += comp1.computeInterest1();

					cout << numDay << endl;
					cout << " Number of credits: " << numCredit
						<< " Current capital " << currentCapital
						<< " Interest to collect " << iterestToCollect
						<< " Insurance " << insurance << endl;

					file << " Days" << numDay << " Number of credits: " << numCredit
						<< " Current capital " << currentCapital
						<< " lv Interest to collect " << iterestToCollect << " lv"
						<< " Insurance " << insurance << " lv" << "\n";

				}

			}
			file.close();
		}
		do
		{

			cout << " To enter new data press 1\n";
			cout << " For exit press 2: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);

	} while (choice != 2);

	return 0;
}
