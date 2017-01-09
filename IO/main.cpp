#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



int main(int argc, char ** argv)
{
	cout << argv[1];
	fstream file;
	file.open(argv[1], std::ios::in | std::ios::out);

	string check_cite;
	char character;

	string word;

	
	vector<string> cite_list;
	while (!file.eof())
	{

		file >> character;
		if (character == '~')
		{
			file >> character;
			if (character == '\\')
			{
				for (int i = 0; i < 4; i++)
				{
					file >> character;
					check_cite += character;
				}

				if (check_cite.compare("cite")==0)
				{
					file >> character;

					do
					{
						file >> character;
						if (character != '}')word += character;

					} while (character != '}');

					istringstream iss(word);
					string token;
					while (getline(iss, token, ','))
					{
						cite_list.push_back(token);
					}
					

					word.clear();
					check_cite.clear();
				}
				check_cite.clear();
			}
		}

	}


	file.close();



	return 0;
}