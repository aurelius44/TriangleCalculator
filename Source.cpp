/*
Name: Mark Middleton
Date: 6/21/22
Program Name: Triangle Calculator
Program Description:
A calculator that, when the user inputs three pieces of 
information (including the length of one side), will
calculate the two remaining lengths and remaing angles.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int sides, angles;
	double sideLength1, sideLength2, sideLength3, // While angles is a int, it is a single integer input. Whereas, the
		angleA, angleB, angleC, area, perimeter,  // single angles may be fractional.
		aRads, bRads, cRads, pi;  
	string userName, units, triangleShape, triangleType;                      
	char yesNo, Y, y; // Using both Y and y ensures the user will not encounter error if using one or the other.

	cout << "Hello, user! What is you name?\n";
	getline(cin, userName);
	cout << "\nGreat! Thank you, " << userName << "! And thank you for using Triangle Calculator!\n\n"
		<< "What units will you be working with today? ";
	getline(cin, units);
	cout << "\nThank you! We will use " << units << " for our triangle today.\n\n";

	cout << "To calcualate the contents of your triangle, we will need to know at least three measurements.\n\n"
		<< "Do you have three measurements, including the length of at least one side (Y or N)? ";
	cin >> yesNo;

	pi = 3.141592626535897932;

	if (yesNo == 'Y' || yesNo == 'y') // User must enter at least 1 side measurement to complete the mathematics
	{
		cout << "Excellent! How many sides do you have? ";
			cin >> sides;

			if (sides == 1)
			{
				cout << "\nInput length of Side 1: ";
				cin >> sideLength1;

				cout << "\nHow many angles do you have? ";
				cin >> angles;

					if (angles == 1) // If there is only one side, there must be two angles to solve.
					{                // Therefore, the program instruct user to restart.
						cout << "\nYou must have at least two angles to calculate the triangle.\n"
							<< "Please recheck your triangle and restart the program.\n\n";
					}
					else if (angles == 2)
					{
						cout << "\nAngle A (in degrees): ";
						cin >> angleA;
						aRads = angleA * (pi / 180); // Converting angle to radians: rads = deg * (pi/180)
						cout << "Angle B (in degrees): ";
						cin >> angleB;
						bRads = angleB * (pi / 180);

						angleC = 180 - (angleA + angleB); //The sum of a triangles angles must equal 180.
						cRads = angleC * (pi / 180);

						sideLength2 = sin(bRads) * (sideLength1 / sin(aRads)); // This and the line below use the Law of Sines
						sideLength3 = sin(cRads) * (sideLength1 / sin(aRads)); // to solve for the respective side length.
						perimeter = sideLength1 + sideLength2 + sideLength3;
						area = (pow(sideLength1, 2.0) * sin(bRads) * sin(cRads)) / (2 * sin(bRads * cRads)); // Area formula for a A-A-S triangle.

						if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
						{
							triangleShape = "equilateral";
						}
						else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
						{
							triangleShape = "isosceles";
						}
						else
						{
							triangleShape = "scalene";
						}

						if (angleA == 90 || angleB == 90 || angleC == 90)
						{
							triangleType = "right";
						}
						else if (angleA > 90 || angleB > 90 || angleC > 90)
						{
							triangleType = "obtuse";
						}
						else
						{
							triangleType = "acute";
						}

						cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
							<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed
							<<  sideLength1 << " " << units << endl;
						cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl
							<< "Side 3: " << showpoint << setprecision(2) << fixed << sideLength3 << " " << units << endl << endl
							<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
						cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed
							<< angleC << endl << endl << "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter 
							<< " " << units << " and the area is " << showpoint << setprecision(2) << fixed << area << " " << units
							<< " squared." << endl;
					}
					else if (angles == 3)
					{
						cout << "\nAngle A (in degrees): ";
						cin >> angleA;
						aRads = angleA * (pi / 180);
						cout << "\nAngle B (in degrees): ";
						cin >> angleB;
						bRads = angleB * (pi / 180);
						cout << "\nAngle C (in degrees): ";
						cin >> angleC;
						cRads = angleC * (pi / 180);

						sideLength2 = sin(bRads) * (sideLength1 / sin(aRads));
						sideLength3 = sin(cRads) * (sideLength1 / sin(aRads));
						perimeter = sideLength1 + sideLength2 + sideLength3;
						area = (pow(sideLength1, 2.0) * sin(bRads) * sin(cRads)) / (2 * sin(bRads * cRads));

						if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
						{
							triangleShape = "equilateral";
						}
						else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
						{
							triangleShape = "isosceles";
						}
						else
						{
							triangleShape = "scalene";
						}

						if (angleA == 90 || angleB == 90 || angleC == 90)
						{
							triangleShape = "right";
						}
						else if (angleA > 90 || angleB > 90 || angleC > 90)
						{
							triangleType = "obtuse";
						}
						else
						{
							triangleType = "acute";
						}

						cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
							<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
						cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: "
							<< showpoint << setprecision(2) << fixed << sideLength3 << " " << units << endl << endl
							<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
						cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed
							<< angleC << endl << endl << "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter 
							<< " " << units << " and the area is " << showpoint << setprecision(2) << fixed << area << " " << units
							<< " squared." << endl;
					}
					else
						cout << "\nYou must have at least 2 angles to calculate the triangle.\n\n";
			}
			else if (sides == 2)
			{
				cout << "\nInput length of Side 1: ";
				cin >> sideLength1;
				cout << "\nInput length of Side 2: ";
				cin >> sideLength2;

				cout << "\nHow many angles do you have? ";
				cin >> angles;

					if (angles == 1)
					{
						cout << "\nAngle A (in degrees): ";
						cin >> angleA;
						aRads = angleA * (pi / 180);

						bRads = asin((sideLength1 * sin(aRads)) / sideLength2);
						angleB = bRads * (180 / pi);
						angleC = 180 - (angleA + angleB);
						cRads = angleC * (pi / 180);

						sideLength3 = sin(cRads) * (sideLength1 / sin(aRads));
						perimeter = sideLength1 + sideLength2 + sideLength3;
						area = 0.5 * (sideLength2 * sideLength3) * sin(aRads);

						if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
						{
							triangleShape = "equilateral";
						}
						else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
						{
							triangleShape = "isosceles";
						}
						else
						{
							triangleShape = "scalene";
						}

						if (angleA == 90 || angleB == 90 || angleC == 90)
						{
							triangleShape = "right";
						}
						else if (angleA > 90 || angleB > 90 || angleC > 90)
						{
							triangleType = "obtuse";
						}
						else
						{
							triangleType = "acute";
						}

						cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
							<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
						cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: "
							<< showpoint << setprecision(2) << fixed << sideLength3 << " " << units << endl << endl
							<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
						cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed 
							<< angleC << endl << endl << "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter 
							<< " " << units << " and the area is " << showpoint << setprecision(2) << fixed << area << " " << units
							<< " squared." << endl;
					}

					else if (angles == 2)
					{
						cout << "\nAngle A (in degrees): ";
						cin >> angleA;
						aRads = angleA * (pi / 180);
						cout << "Angle B (in degrees): ";
						cin >> angleB;
						bRads = angleB * (pi / 180);

						angleC = 180 - (angleA + angleB);
						cRads = angleC * (pi / 180);

						sideLength3 = sin(cRads) * (sideLength1 / sin(aRads));
						perimeter = sideLength1 + sideLength2 + sideLength3;
						area = 0.5 * (sideLength2 * sideLength3) * sin(aRads);

						if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
						{
							triangleShape = "equilateral";
						}
						else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
						{
							triangleShape = "isosceles";
						}
						else
						{
							triangleShape = "scalene";
						}

						if (angleA == 90 || angleB == 90 || angleC == 90)
						{
							triangleShape = "right";
						}
						else if (angleA > 90 || angleB > 90 || angleC > 90)
						{
							triangleType = "obtuse";
						}
						else
						{
							triangleType = "acute";
						}

						cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
							<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
						cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: " << showpoint << setprecision(2) << fixed
							<< sideLength3 << " " << units << endl << endl
							<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
						cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed << angleC << endl << endl
							<< "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " " << units << " and the area is "
							<< showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
					}
					else if (angles == 3)
					{
						cout << "\nAngle A (in degrees): ";
						cin >> angleA;
						aRads = angleA * (pi / 180);
						cout << "\nAngle B (in degrees): ";
						cin >> angleB;
						bRads = angleB * (pi / 180);
						cout << "\nAngle C (in degrees): ";
						cin >> angleC;
						cRads = angleC * (pi / 180);

						sideLength3 = sin(cRads) * (sideLength1 / sin(aRads));
						perimeter = sideLength1 + sideLength2 + sideLength3;
						area = 0.5 * (sideLength2 * sideLength3) * sin(aRads);

						if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
						{
							triangleShape = "equilateral";
						}
						else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
						{
							triangleShape = "isosceles";
						}
						else
						{
							triangleShape = "scalene";
						}

						if (angleA == 90 || angleB == 90 || angleC == 90)
						{
							triangleShape = "right";
						}
						else if (angleA > 90 || angleB > 90 || angleC > 90)
						{
							triangleType = "obtuse";
						}
						else
						{
							triangleType = "acute";
						}

						cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
							<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
						cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: "
							<< showpoint << setprecision(2) << fixed << sideLength3 << " " << units << endl << endl
							<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
						cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed
							<< angleC << endl << endl << "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " "
							<< units << " and the area is " << showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
					}
					else
						cout << "You must have at least one angle to solve this triangle.\n"
							<< "Please doublecheck you triangle and restart this program.\n\n";
			}
			else if (sides == 3)
			{
				cout << "\nInput length of Side 1: ";
				cin >> sideLength1;
				cout << "\nInput length of Side 2: ";
				cin >> sideLength2;
				cout << "\nInput length of Side 3: ";
				cin >> sideLength3;

					if (sideLength3 > (sideLength1 + sideLength2)) //Side 3 must be more than the sum of 1 and 2.
					{
						cout << "\nThe sum of two sides must be greater than the third.";

						return 0;
					}

				cout << "\nHow many angles do you have? ";
				cin >> angles;

				if (angles == 0)
				{
					aRads = acos((pow(sideLength2, 2.0) + pow(sideLength3, 2.0) - pow(sideLength1, 2.0)) / (2 * sideLength2 * sideLength3));
					angleA = aRads * (180 / pi);
					bRads = acos((pow(sideLength1, 2.0) + pow(sideLength3, 2.0) - pow(sideLength2, 2.0)) / (2 * sideLength1 * sideLength3));
					angleB = bRads * (180 / pi);
					cRads = acos((pow(sideLength1, 2.0) + pow(sideLength2, 2.0) - pow(sideLength3, 2.0)) / (2 * sideLength1 * sideLength2));
					angleC = cRads * (180 / pi);

					perimeter = sideLength1 + sideLength2 + sideLength3;
					area = ((sideLength1 * sideLength2) * sin(cRads)) / 2;
					
					if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
					{
						triangleShape = "equilateral";
					}
					else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
					{
						triangleShape = "isosceles";
					}
					else
					{
						triangleShape = "scalene";
					}

					if (angleA == 90 || angleB == 90 || angleC == 90)
					{
						triangleShape = "right";
					}
					else if (angleA > 90 || angleB > 90 || angleC > 90)
					{
						triangleType = "obtuse";
					}
					else
					{
						triangleType = "acute";
					}

					cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
						<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
					cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: " << showpoint << setprecision(2) << fixed
						<< sideLength3 << " " << units << endl << endl
						<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
					cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed << angleC << endl << endl
						<< "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " " << units << " and the area is "
						<< showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
				}
				else if (angles == 1)
				{
					cout << "\nAngle A (in degrees): ";
					cin >> angleA;
					aRads = angleA * (pi / 180);

					bRads = asin((sideLength1 * sin(aRads)) / sideLength2);
					angleB = bRads * (180 / pi);
					angleC = 180 - (angleA + angleB);
					cRads = angleC * (pi / 180);

					perimeter = sideLength1 + sideLength2 + sideLength3;
					area = ((sideLength1 * sideLength2) * sin(cRads)) / 2;

					if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
					{
						triangleShape = "equilateral";
					}
					else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
					{
						triangleShape = "isosceles";
					}
					else
					{
						triangleShape = "scalene";
					}

					if (angleA == 90 || angleB == 90 || angleC == 90)
					{
						triangleShape = "right";
					}
					else if (angleA > 90 || angleB > 90 || angleC > 90)
					{
						triangleType = "obtuse";
					}
					else
					{
						triangleType = "acute";
					}

					cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
						<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
					cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: " << showpoint << setprecision(2) << fixed
						<< sideLength3 << " " << units << endl << endl
						<< "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
					cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed
						<< angleC << endl << endl << "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " "
						<< units << " and the area is " << showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
				}
				else if (angles == 2)
				{
					cout << "\nAngle A (in degrees): ";
					cin >> angleA;
					aRads = angleA * (pi / 180);
					cout << "\nAngle B (in degrees): ";
					cin >> angleB;
					bRads = angleB * (pi / 180);

					angleC = 180 - (angleA + angleB);
					cRads = angleC * (pi / 180);

					perimeter = sideLength1 + sideLength2 + sideLength3;
					area = ((sideLength1 * sideLength2) * sin(cRads)) / 2;

					if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
					{
						triangleShape = "equilateral";
					}
					else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
					{
						triangleShape = "isosceles";
					}
					else
					{
						triangleShape = "scalene";
					}

					if (angleA == 90 || angleB == 90 || angleC == 90)
					{
						triangleShape = "right";
					}
					else if (angleA > 90 || angleB > 90 || angleC > 90)
					{
						triangleType = "obtuse";
					}
					else
					{
						triangleType = "acute";
					}

					cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
						<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
					cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: " << showpoint << setprecision(2)
						<< fixed << sideLength3 << " " << units << endl << endl << "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2)
						<< fixed << angleA << endl;
					cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed << angleC << endl << endl
						<< "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " " << units << " and the area is "
						<< showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
				}
				else
				{
				cout << "\nAngle A (in degrees): ";
				cin >> angleA;
				aRads = angleA * (pi / 180);
				cout << "\nAngle B (in degrees): ";
				cin >> angleB;
				bRads = angleB * (pi / 180);
				cout << "\nAngle C (in degrees): ";
				cin >> angleC;
				cRads = angleC * (pi / 180);

				perimeter = sideLength1 + sideLength2 + sideLength3;
				area = ((sideLength1 * sideLength2) * sin(cRads)) / 2;

				if (sideLength1 == sideLength2 && sideLength2 == sideLength3)
				{
					triangleShape = "equilateral";
				}
				else if (sideLength1 == sideLength2 || sideLength1 == sideLength3 || sideLength2 == sideLength3)
				{
					triangleShape = "isosceles";
				}
				else
				{
					triangleShape = "scalene";
				}

				if (angleA == 90 || angleB == 90 || angleC == 90)
				{
					triangleShape = "right";
				}
				else if (angleA > 90 || angleB > 90 || angleC > 90)
				{
					triangleType = "obtuse";
				}
				else
				{
					triangleType = "acute";
				}

				cout << "\n\nYour triangle is a(n) " << triangleShape << " and " << triangleType << " triangle.\n"
					<< "\nThe length of the sides are as follows:\n" << "Side 1: " << showpoint << setprecision(2) << fixed << sideLength1 << " " << units << endl;
				cout << "Side 2: " << showpoint << setprecision(2) << fixed << sideLength2 << " " << units << endl << "Side 3: " << showpoint << setprecision(2) << fixed
					<< sideLength3 << " " << units << endl << endl << "The angles are as follows:\n" << "Angle A: " << showpoint << setprecision(2) << fixed << angleA << endl;
				cout << "Angle B: " << showpoint << setprecision(2) << fixed << angleB << "\nAngle C: " << showpoint << setprecision(2) << fixed << angleC << endl << endl
					<< "The perimeter of your triangle is " << showpoint << setprecision(2) << fixed << perimeter << " " << units << " and the area is "
					<< showpoint << setprecision(2) << fixed << area << " " << units << " squared." << endl;
				}
			}
			else
			{
				cout << "\nYou must have at least one side or less than three.\n"
					<< "Please, doublecheck you triangle and restart this program.\n\n";
			}
	}
	else
	{
		cout << "\nYou will need three measurements, including the length of one side.\n"
			<< "Please, doublecheck you triangle and restart this program.\n\n";

		return 0;
	}
	cout << "Thank you, " << userName << ", for using Triangle Calculator!\n\n";

	return 0;
}