
#include <iostream>
using namespace std;

float calculate_series_resistors(string s);
float calculate_parallel_resistors(string s);
bool is_valid_connection(string s);

int main ()

{
	string s;
	getline(cin, s);

	if (is_valid_connection(s))
	{
		cout<<"Incorrect Input"<<endl;
		return 0;
	}

	if (s[0] == 'S' || s[0] == 's')
	{
		cout<<"The total resistance = "<<calculate_series_resistors(s)<<endl;
	}

	else if (s[0] == 'P' || s[0] == 'p')
	{
		cout<<"The total resistance = "<<calculate_parallel_resistors(s)<<endl;
	}

	return 0;

}

float calculate_series_resistors(string s)
{
	string r[] = {"", "", ""};
	int n = 0, i = 2;
	while (s[i] != 'e')
	{
		if (s[i] != ' ')
		{
			r[n] += s[i];
			while (s[i+1] != ' ')
			{
				i++;
				r[n] += s[i];

			}
			n++;
		}
		i++;
	}

	float sum = 0;

	for (int j = 0; j < n; j++)
	{
		sum+=stof(r[j]);
	}

	return sum;
}

float calculate_parallel_resistors(string s)
{
	string r[] = {"", "", ""};
	int n = 0, i = 2;
	while (s[i] != 'e')
	{
		if (s[i] != ' ')
		{
			r[n] += s[i];
			while (s[i+1] != ' ')
			{
				i++;
				r[n] += s[i];

			}
			n++;
		}
		i++;
	}

	float sum = 0;

	for (int j = 0; j < n; j++)
	{
		sum+= 1/stof(r[j]);
	}

	return 1/sum;
}

bool is_valid_connection(string s)
{
	int i = 2, n = 0;
	while (s[i] != 'e')
	{
		if (s[i] == ' ') n++;
		i++;
	}

	if ((s[0] == 'S' || s[0] == 's') && n < 1) return 1 ;
	else if ((s[0] == 'P' || s[0] == 'p') && n < 2) return 1;

	return 0;
}
