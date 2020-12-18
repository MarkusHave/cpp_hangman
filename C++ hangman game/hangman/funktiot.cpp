#include"hirsipuu.h"

int Tarkastus(string arvaus, string oik_sana, string &piil_sana)
{
	int sana = piil_sana.length();
	string kirjain = arvaus.substr(0, 1); //substring kohdasta 0 ja ensimm‰inen merkki

	if (arvaus == oik_sana) //jos arvaa oikean sanan
	{
		return 1;
	}
	else if (arvaus.length() > 1) //jos lenght enemm‰n kuin 1
	{
		return 0;
	}
	else
	{
		if (oik_sana.find(kirjain) != string::npos) //jos lˆyt‰‰ kirjaimen oikeasta sanasta, npos = -1
		{
			for (int i = 0; i < sana; i++)
			{
				if (oik_sana.at(i) == kirjain[0]) //jos arvattu kirjain on == oikean sanan kohdassa i
				{
					piil_sana.at(i) = kirjain[0]; // piilotetun sanan kohta i vaihdetaan arvattun kirjaimeen
				}
			}
			return 2; 
		}
		else
		{
			return 0;
		}
	}
}


void Peli(int max, int arv_nro, string p_sana, string oik_sana)
{
	int t_luku = -1;
	string sanat, text = "";
	while (arv_nro < max)
	{
		string arvaus;
		system("cls");
		cout << "HIRSIPUU" << endl;
		cout << "\nArvauksia j‰ljell‰: " << max - arv_nro << endl;
		cout << "\n\nSana:  " << p_sana << endl;
		cout << "\nArvatut kirjaimet: " << sanat << endl;
		cout << "\n" + text << endl;
		cout << "\nAnna kirjain tai arvaa koko sana: ";
		cin >> arvaus;

		if (sanat.find(arvaus) != string::npos) //etsii sanaa stringin sis‰lt‰
		{
			text = "K‰ytetty kirjain!!";
			arv_nro++;
		}
		else if (sanat.find(arvaus) == string::npos) //jos ei lˆyd‰ sanaa stringin sis‰lt‰
		{
			if (arvaus.length() <= 1) //testaa onko arvaus pidempi kuin 1 merkin
			{
				sanat.append(arvaus + ","); //liitt‰‰ arvatun kirjaimen sanat muuttujaan
			}
			t_luku = Tarkastus(arvaus, oik_sana, p_sana); //tarkastus funktion kutsu
			if (t_luku == 0) //v‰‰r‰ arvaus
			{
				arv_nro++;
				text = "V‰‰r‰ sana tai kirjain!!";
			}
			else if (t_luku == 1) //koko sana arvattu oikein
			{
				Loppu(true, oik_sana); //loppu funktion kutsu
				break;
			}
			else //oikea kirjain arvattu
			{
				text = "Oikea kirjain!!";
			}
		}
		if (oik_sana == p_sana) //kaikki kirjaimet arvattu oikein
		{
			Loppu(true, oik_sana);
			break;

		}
	}
	if (arv_nro == max) //arvausten m‰‰r‰ t‰ysi
	{
		Loppu(false, oik_sana);
	}
}


void Loppu(bool voitto, string sana)
{
	int valinta;
	system("cls");
	if (voitto == true)
	{
		cout << "HIRSIPUU" << endl;
		cout << "\nVoitit pelin!" << endl;
	}
	else
	{
		cout << "HIRSIPUU" << endl;
		cout << "\nH‰visit pelin!" << endl;
	}
	cout << "\n\nOikea sana: " << sana << endl;
	cout << "\n\n1. Pelaa uudestaan \n2. Lopeta" << endl;
	cout << "\nValinta > ";
	cin >> valinta;
	if (valinta == 2)
	{
		exit(0);
	}
}


int Menu()
{
	int valinta = 0;
	while (true)
	{
		system("cls");
		cout << "HIRSIPUU" << endl;
		cout << "\nValitse vaikeustaso" << endl;
		cout << "\n0. Sulje" << endl;
		cout << "1. Helppo  (Kuukausia)" << endl;
		cout << "2. Medium (Euroopan maita)" << endl;
		cout << "3. Omat sanat" << endl;
		cout << "4. Asetukset" << endl;
		cout << "\nValinta (0-4) > ";
		cin >> valinta;
		if (cin.fail()) //testaa jos kirjoittaa muuta kuin numeron
		{
			cout << "\nVirhe!! Anna numero." << endl;
			Sleep(1000);
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			break;
		}
	}
	return valinta;
}


int Asetukset(int maksimi, vector<string> &kuut, vector<string> &eu_maat, vector<string> &omat)
{
	int valinta = -1;
	while (valinta != 0)
	{
		system("cls");
		cout << "HIRSIPUU" << endl;
		cout << "\nAsetukset" << endl;
		cout << "\n0. Takaisin" << endl;
		cout << "1. Muuta arvausten m‰‰r‰‰. Asetettu m‰‰r‰: " << maksimi << endl;
		cout << "2. Tulosta kaikki sanat" << endl;
		cout << "3. Poista sana" << endl;
		cout << "4. Lis‰‰ omia sanoja" << endl;
		cout << "5. Tallenna omat sanat" << endl;
		cout << "6. Poista kaikki omat sanat" << endl;
		cout << "\nValinta: ";
		cin >> valinta;
		switch (valinta)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			ArvMaara(maksimi); //arvausten m‰‰r‰n muuttaminen
			break;
		}
		case 2:
		{
			TulostaFunk(kuut, eu_maat, omat); //tulostetaan kaikki sanat
			break;
		}
		case 3:
		{
			PoistaFunk(kuut, eu_maat, omat); //poista sana
			break;
		}
		case 4:
		{
			UusiSana(omat); //lis‰‰ uusi sana
			break;
		}
		case 5: //tallennus
		{
			if (omat.empty())
			{
				cout << "\nEi lis‰ttyj‰ sanoja!" << endl;
				Sleep(1500);
			}
			else
			{
				cout << "\nTallenetaan... " << endl;
				Sleep(500);
				Save(omat);
				cout << "Tallennettu! " << endl;
				Sleep(1500);
			}
			break;
		}
		case 6:
		{
			//poista kaikki omat sanat
			if (remove("sanat.txt") != 0)
			{
				cout << "\nVirhe tiedostoa ei ole!";
				Sleep(1500);
			}
			else
			{
				omat.clear();
				cout << "\nKaikki omat sanat poistettu!";
				Sleep(1500);
			}
		}
		default:
		{
			break;
		}
		}
	}
	return maksimi;
}


void Tulosta(vector<string> &vect) //tulostus 
{
	for (vector<string>::iterator i = vect.begin(); i != vect.end(); i++) //iteraattori i k‰y vektorin l‰pi ja tallentaa sanan i muuttujuaan
	{
		cout << *i << endl;
		Sleep(25);
	}
}


bool Poista(string delsana, vector<string> &vect_del) //poisto
{
	vector<string>::iterator itr_del = find(vect_del.begin(), vect_del.end(), delsana); //etsii halutun sanan
	if (itr_del != vect_del.end())
	{
		vect_del.erase(itr_del);	//poistaa itr_del tallenetun sanan
		return true;				// sana poistettu palauttaa truen
	}
	else				
	{
		return false;	//jos sanaa ei ole palauttaa falsen
	}
}


void PoistaFunk(vector<string> &kuut, vector<string> &eu_maat, vector<string> &omat)
{
	while (true)
	{
		string del;
		system("cls");
		cout << "HIRSIPUU" << endl;
		cout << "\nAsetukset > Poista sana \n\nKirjoita exit jos haluat poistua" << endl;
		cout << "\nAnna poistettava sana: ";
		cin >> del;
		if (del == "exit")
		{
			break;
		}
		if (Poista(del, kuut) || Poista(del, eu_maat) || Poista(del, omat)) //jos jokin n‰ista palauttaa truen
		{
			cout << "\n>> " << del << " poistettu" << endl;
			Save(omat);			// p‰ivitt‰‰ omat sanat tiedoston
			Sleep(1500);
			break;
		}
		else
		{
			cout << "\nSanaa ei ole. Syît‰ uusi." << endl;
			Sleep(1500);
		}
	}
}


void TulostaFunk(vector<string> &kuut, vector<string> &eu, vector<string> &omat) //tulosta kaikki
{
	system("cls");
	cout << "\nKuukaudet: " << endl;
	Tulosta(kuut);
	cout << "\nEuroopan maita: " << endl;
	Tulosta(eu);
	cout << "\nOmat sanat: " << endl;
	Tulosta(omat);
	cout << "\n\n";
	system("pause");
}


void ArvMaara(int max) //arvaus m‰‰r‰n muuttamis funktio
{
	system("cls");
	cout << "HIRSIPUU" << endl;
	cout << "\nAsetukset > Arvausten m‰‰r‰:" << max << endl;
	cout << "Anna uusi arvo: ";
	cin >> max;
	cout << "Uusi arvo annettu: " << max << "\n\n\n";
	system("pause");
}


void UusiSana(vector<string> &oma) 
{
	string uusi;
	while (true)
	{
		system("cls");
		cout << "HIRSIPUU" << endl;
		cout << "\nAsetukset > Lis‰‰ sanoja \n\nKirjoita exit jos haluat poistua" << endl;
		cout << "\nKirjoita uusi sana: ";
		cin >> uusi;
		if (uusi == "exit")
		{
			break;
		}
		if (find(oma.begin(), oma.end(), uusi) != oma.end()) //etsii vectorista jo lis‰tty‰ sanaa
		{
			cout << "\nSana on jo lis‰tty! Syît‰ uusi.\n\n";
			system("pause");
		}
		else
		{
			oma.push_back(uusi);
			cout << "\n\nLis‰ttiin sana: " << uusi << "\n\n";
			system("pause");
			break;
		}
	}
}


void Save(vector<string> &s_omat) //tallenus funktio
{
	ofstream write("sanat.txt");
	for (string &sana : s_omat)
	{
		write << sana << "\n";
	}
	write.close();
}


