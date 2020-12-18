#include"hirsipuu.h"

int main()
{
	int sana_nro, valinta, arvaus_nro, MAX_ARVAUS = 5;
	string oik_sana, oma_str;
	
	//sana vectorit
	vector<string> kuukaudet =
	{
		"tammikuu",
		"helmikuu",
		"maaliskuu",
		"huhtikuu",
		"toukokuu",
		"kesakuu",
		"heinakuu",
		"elokuu",
		"syyskuu",
		"lokakuu",
		"marraskuu",
		"joulukuu"
	};
	vector<string> eurooppa =
	{
		"suomi",
		"ruotsi",
		"saksa",
		"ranska",
		"britannia",
		"belgia",
		"italia",
		"kreikka",
		"espanja",
		"portugali",
		"alankomaat",
		"puola",
		"sveitsi",
		"slovakia",
		"itavalta",
		"norja",
		"tanska",
		"viro",
		"latvia",
		"liettua",
		"unkari",
		"jugoslavia"
	};
	vector<string> omat_sanat;

	ifstream read("sanat.txt"); //tuodaan omia sanoja tideostosta ja tallennetaan ne vectoriin
	while (getline(read, oma_str))
	{
		if (oma_str.size() > 0)
		{
			omat_sanat.push_back(oma_str);
		}
	}
	read.close();

	int months = kuukaudet.size();
	int euromaat = eurooppa.size();
	int omat = omat_sanat.size();
	srand(time(NULL)); //alustaa random numerogeneraattorin

	while (true)
	{
		arvaus_nro = 0;
		valinta = Menu();

		switch (valinta)
		{
		case 0:
		{
			exit(0);
		}
		case 1:
		{
			//kuukaudet peli
			sana_nro = rand() % months;
			oik_sana = kuukaudet.at(sana_nro);
			string piilo_sana(oik_sana.length(), '*');
			Peli(MAX_ARVAUS, arvaus_nro, piilo_sana, oik_sana);
			break;
		}
		case 2:
		{
			//euroopanmaat peli
			sana_nro = rand() % euromaat;
			oik_sana = eurooppa.at(sana_nro);
			string piilo_sana(oik_sana.length(), '*');
			Peli(MAX_ARVAUS, arvaus_nro, piilo_sana, oik_sana);
			break;
		}
		case 3:
		{
			//omat sanat peli
			ifstream write("sanat.txt");

			if (write || !omat_sanat.empty())  // testaa onko sanat tiedostoa olemassa tai onko omat sanat vectori tyhjä
			{
				if (omat > 1) // testaa onko sanoja on enemmän kuin yksi
				{
					sana_nro = rand() % omat;
					oik_sana = omat_sanat.at(sana_nro);
				}
				else if (omat == 1)
				{
					oik_sana = omat_sanat.at(0);
				}
				string piilo_sana(oik_sana.length(), '*');
				Peli(MAX_ARVAUS, arvaus_nro, piilo_sana, oik_sana);
			}
			else
			{
				cout << "Sanoja ei ole!!" << endl;
				Sleep(1500);
			}
			break;
		}
		case 4:
		{
			//asetukset
			MAX_ARVAUS = Asetukset(MAX_ARVAUS, kuukaudet, eurooppa, omat_sanat);
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

