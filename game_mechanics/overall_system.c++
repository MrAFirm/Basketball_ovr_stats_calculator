#include <iostream>
#include <random>
using namespace std;

class	myOverall
{
	public:
		char		decision;
		double		strength;
		double		agility;
		double		height;
		double		speed;
		double		dribbling;
		double		passing;
		double		inside_scoring;
		double		shooting;
		double		rebounding;
		double		dunks_and_layups;
		double		potential;
		double		iq;
		double		total;
		double		PPG;
		double		RPG;
		double		APG;
		double		FG;
		bool		game_loop;
};

double addNoise(double stat, double stddev = 1.5)
{
	random_device rd;
	mt19937 gen(rd());
	normal_distribution<> d(stat, stddev);
	return d(gen);
}

double clamp(double x, double min, double max)
{
	return std::max(min, std::min(x, max));
}

int	main(void)
{
	myOverall	myAttributes;
	
	myAttributes.game_loop = true;
	cout << "Welcome to the player overall counter.\nPlease type in the attribute values when prompted.\n";
	cout << "Y or N?\n";
	cin >> myAttributes.decision;
	while (myAttributes.game_loop)
	{
		if (myAttributes.decision == 'Y')
		{
			cout << "Height?\n";
			cin >> myAttributes.height;
			cout << "Strength?\n";
			cin >> myAttributes.strength;
			cout << "Agility?\n";
			cin >> myAttributes.agility;
			cout << "Speed?\n";
			cin >> myAttributes.speed;
			cout << "Dribbling?\n";
			cin >> myAttributes.dribbling;
			cout << "Passing?\n";
			cin >> myAttributes.passing;
			cout << "Inside Scoring?\n";
			cin >> myAttributes.inside_scoring;
			cout << "Shooting?\n";
			cin >> myAttributes.shooting;
			cout << "Rebounding?\n";
			cin >> myAttributes.rebounding;
			cout << "Dunks and Layups?\n";
			cin >> myAttributes.dunks_and_layups;
			cout << "Ball IQ?\n";
			cin >> myAttributes.iq;
			cout << "Potential?\n";
			cin >> myAttributes.potential;
			myAttributes.total = ((myAttributes.height + myAttributes.strength + myAttributes.agility + myAttributes.speed +
				myAttributes.dribbling + myAttributes.passing + myAttributes.inside_scoring + myAttributes.shooting + myAttributes.rebounding +
				myAttributes.dunks_and_layups + myAttributes.iq + myAttributes.potential) / 12);
				
			cout << "Overall: " << myAttributes.total << "\n";
				
			myAttributes.PPG = addNoise(clamp((0.2 * myAttributes.shooting + 0.2 * myAttributes.inside_scoring + 0.2 * myAttributes.dunks_and_layups + 0.1 * myAttributes.height +
				0.1 * myAttributes.iq + 0.1 * myAttributes.potential + 0.1 * myAttributes.speed) * 0.3, 0.0, 35.0));
				myAttributes.RPG = addNoise(clamp((0.5 * myAttributes.rebounding + 0.2 * myAttributes.height) * 0.15, 0.0, 20.0));
				myAttributes.APG = addNoise(clamp((0.3 * myAttributes.passing + 0.2 * myAttributes.iq + 0.2 * myAttributes.dribbling) * 0.1, 0.0, 15.0));
				myAttributes.FG = clamp((0.1 * myAttributes.inside_scoring + 0.3 * myAttributes.shooting + 0.2 * myAttributes.dunks_and_layups) / 100.0, 0.35, 0.65);
			
			if (myAttributes.total >= 85)
				cout << "This player is a Star.\n";
			else if (myAttributes.total >= 75)
				cout << "This player is a Starter.\n";
			else if (myAttributes.total >= 65)
				cout << "This player is a Bench Player\n";
			else if (myAttributes.total >= 55)
				cout << "This player is a Benchwarmer.\n";
			cout << "Simulated PPG: " << myAttributes.PPG << "\n";
			cout << "Simulated RPG: " << myAttributes.RPG << "\n";
			cout << "Simulated APG: " << myAttributes.APG << "\n";
			cout << "Simulated FG: " << myAttributes.FG * 100 << "%\n";
			cout << "Do you wish to start over?\nY or N\n";
			cin >> myAttributes.decision;
			if (myAttributes.decision == 'N')
			{
				cout << "Have a nice day!\n";
				myAttributes.game_loop = false;
				return (0);
			}
		}
		else if (myAttributes.decision == 'N')
		{
			cout << "Have a nice day!\n";
			myAttributes.game_loop = false;
			return (0);
		}
	}
	return (0);
}