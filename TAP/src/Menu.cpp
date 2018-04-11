#include <iostream>
#include "Agency.h"
#include "Client.h"
#include<limits.h>
#include "Date.h"

using namespace std;

void Agency::introMenu() {

	int opcao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Bem vindo a nossa agencia de viagens!                    |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+ \n";
	cout << "| 1 - Gestão de Clientes                                   |\n";
	cout << "| 2 - Gestão de Viagens                                    |\n";;
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> opcao;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
	}

	switch (opcao) {

	case 0:
		return;
		break;

	case 1:
		menuCliente();
		cin.get();
		cin.get();
		break;

	case 2:
		menuTrip();
		cin.get();
		cin.get();
		break;
	default:
		cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

	}
}

void Agency::menuCliente() {

	int opcaocliente;
	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com os clientes             |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Adicionar Cliente                                    |\n";
		cout << "| 2 - Apagar Cliente					                    |\n";
		cout << "| 3 - Listagem Clientes					                |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaocliente;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaocliente) {

		case 0:
			return;
			break;

		case 1:
			adicionaCliente();
			cin.get();
			cin.get();
			break;

		case 2:	
			removeCliente();
			cin.get();
			cin.get();
			break;

		case 3:
			listClients();
			 cin.get();
			 cin.get();
			 break;
		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}


void Agency::adicionaCliente() {


	string nomeCliente;
	int telemovel, ID;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu nome?                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeCliente);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu ID?                                         |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> ID;

	for(unsigned int i = 0; i < clientes.size(); i++){

		if(getClientes()[i]->getID() == ID){
			cout << " Cliente já existe!"<<endl;
			introMenu();
		}
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual o seu numero de telemovel?                          |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> telemovel;

	Client * novocliente = new Client(nomeCliente, ID, telemovel);
	addClients(novocliente);

}

void Agency::removeCliente() {

	string clienteremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o cliente a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, clienteremover);

	for (unsigned int i = 0; i < getClientes().size(); i++)
	{
		if (getClientes()[i]->getName() == clienteremover)
			clientes.erase(clientes.begin() + i);

		else{
			cout<<" Cliente não existe!\n";

		}
	}
	cout << endl << "O cliente foi removido com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;
}

void Agency::listClients(){

	cout << "CLIENTS:\n" << getClientes().size() <<endl;

	for(unsigned int i = 0; i < getClientes().size(); i++){

		cout << getClientes().at(i)->getName() << " - " << getClientes().at(i)->getID() << " - " << getClientes().at(i)->getPhoneNumber() <<endl;
	}
}

void Agency::menuTrip(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com a viagem                |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Criar Viagem                                         |\n";
		cout << "| 2 - Apagar Viagem					                    |\n";
		cout << "| 3 - Lista de Destinos					                |\n";
		cout << "| 4 - Lista de Viagens		   			                    |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaotrip;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			adicionaTrip();
			cin.get();
			cin.get();
			break;

		case 2:
			removeTrip();
			cin.get();
			cin.get();
			break;

		case 3:
			destinationsList();
			cin.get();
			cin.get();
			break;

		case 4:
			tripList();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}


void Agency::adicionaTrip() {


	string dataInicio;
	string dataFim;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é a data de inicio da viagem?  (Formato: dd/mm/aa)  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> dataInicio;
	Date *dataInicial = new Date(dataInicio);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual é a data de fim da viagem?  (Formato: dd/mm/aa)     |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> dataFim;
	Date *dataFinal = new Date(dataFim);

	string temp;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique os voos a adicionar (escreva FIM para terminar): |\n";
	cout << "+----------------------------------------------------------+\n";

/*	cin.ignore(INT_MAX, '\n');
		while (temp != "FIM")
		{
			getline(cin, temp);
			if (temp != "FIM") {
				viagem.getFlights().push_back(temp);
			}
			cout << "\n";
		}
		cout << endl << "A viagem foi removida com sucesso" << endl;
		cout << "Pressione Enter para regressar" << endl;
		cin.get();
		return; */

	Trip * novaTrip = new Trip(*dataInicial, *dataFinal);
	addTrips(novaTrip);
}


void Agency::removeTrip() {

	string tripremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a viagem a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, tripremover);

	for (unsigned int i = 0; i < getTrips().size(); i++)
	{
		if (getTrips()[i]->getID() == stoi(tripremover))
			trips.erase(trips.begin() + i);
	}
	cout << endl << "A viagem foi removida com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;

}

void Agency::destinationsList(){

	string assets = "./assets/CitiesNames";
	ifstream in;

	string temp;
	string fich = assets + ".txt";
	const char *nomeFich;
	nomeFich = fich.c_str();

	in.open(nomeFich);

	cout << "\nDESTINATIONS:\n"<<endl;

	while(!in.eof()){

			getline(in,temp);
			cout << " | "<< temp;
		}

	in.close();
}

void Agency::tripList(){

	cout << "TRIPS:\n" << endl;

	for(unsigned int i = 0; i < getTrips().size(); i++){

		cout << trips[i]->getID() << " - " << trips[i]->getDepartureDate().getString() << " ; "  << trips[i]->getArrivalDate().getString() << " - " << trips[i]->getDepartureCity() << " - " << trips[i]->getArrivalCity() << " - " << trips[i]->getHotel() << " - " << trips[i]->getCost() << " ; " << trips[i]->getDistance() << endl;
	}
}
