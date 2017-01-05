#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



int main(int argc, char ** argv)
{
	cout << argv[1];
	fstream plik;
	plik.open(argv[1], std::ios::in | std::ios::out);

	string sprawdz_cite;
	char znak;

	string slowo;

	
	vector<string> lista;
	while (!plik.eof())
	{

		plik >> znak;
		if (znak == '~')
		{
			plik >> znak;
			if (znak == '\\')
			{
				for (int i = 0; i < 4; i++)
				{
					plik >> znak;
					sprawdz_cite += znak;
				}

				if (sprawdz_cite.compare("cite")==0)
				{
					plik >> znak;

					do
					{
						plik >> znak;
						if (znak != '}')slowo += znak;

					} while (znak != '}');

					istringstream iss(slowo);
					string token;
					while (getline(iss, token, ','))
					{
						lista.push_back(token);
					}
					

					slowo.clear();
					sprawdz_cite.clear();
				}
				sprawdz_cite.clear();
			}
		}

	}


	plik.close();



	return 0;
}