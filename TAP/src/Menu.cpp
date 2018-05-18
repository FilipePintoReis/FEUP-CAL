#include <iostream>
#include "graphviewer.h"
#include <cstdio>
#include <fstream>
#include <sstream>
#include "Agency.h"
#include "Client.h"
#include <limits.h>
#include "Date.h"

GraphViewer *gv;

using namespace std;

void Agency::introMenu() {

	int opcao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Bem vindo a nossa agencia de viagens!                    |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Gestao de Clientes                                   |\n";
	cout << "| 2 - Gestao de Viagens                                    |\n";
	cout << "| 3 - Abrir o Mapa                                         |\n";
	cout << "| 4 - Guardar Ficheiros                                    |\n";
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

	case 3:
		map();
		cin.get();
		cin.get();
		break;

	case 4:
		menuSave();
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
		cout << "| 4 - Menu Principal  					                    |\n";
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

		case 4:
			introMenu();
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
			cout << " Cliente ja existe!"<<endl;
			introMenu();
		}
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual o seu numero de telemovel?                          |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> telemovel;

	Client * novocliente = new Client(nomeCliente, ID, telemovel);
	addClients(novocliente);

	cout << "Cliente adicionado com sucesso! \n";
	menuCliente();

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

		else {
			cout << " Cliente nao existe!\n";

		}
	}
	cout << endl << "O cliente foi removido com sucesso" << endl;
	menuCliente();
}

void Agency::listClients(){

	cout << "CLIENTS:\n" <<endl;

	for(unsigned int i = 0; i < getClientes().size(); i++){

		cout << getClientes().at(i)->getName() << " - " << getClientes().at(i)->getID() << " - " << getClientes().at(i)->getPhoneNumber() <<endl;
	}

	cout << "Pressione ENTER para regressar" << endl;
	cin.get();
	return;
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
		cout << "| 4 - Escolher uma origem e um destino diretamente         |\n";
		cout << "| 5 - Escolher conjunto de locais a visitar                |\n";
		cout << "|     a partir de onde me encontro                         |\n";
		cout << "| 6 - Menu Principal                                       |\n";
		cout << "+----------------------------------------------------------+\n";
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

		cin.ignore(INT_MAX, '\n');

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
			menuViagem();
			cin.get();
			cin.get();
			break;


		case 5:
			destinosCidade();
			cin.get();
			cin.get();
			break;

		case 6:
			introMenu();
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
	cout << "| Qual e a data de inicio da viagem?  (Formato: dd/mm/aa)  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> dataInicio;
	Date *dataInicial = new Date(dataInicio);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a data de fim da viagem?  (Formato: dd/mm/aa)     |\n";
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

	cout << "Viagem adicionada com sucesso!\n";
}

void Agency::removeTrip() {
	tripList();

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

void Agency::escolheGeral() {
	string temp;

	cout << "+-------------------------------------------------------------+\n";
	cout << "| Indique os destinos a adicionar (escreva FIM para terminar):|\n";
	cout << "+-------------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	while (temp != "FIM")
	{
		getline(cin, temp);
		if (temp != "FIM") {
			//meter aqui os coisos para criar trip com muitos
		}
		cout << "\n";
	}


}

void Agency::menuViagem(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Qual a sua prioridade?                                   |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Tempo                                                |\n";
		cout << "| 2 - Custo         					                    |\n";
		cout << "| 3 - Andar p/ trás         					            |\n";
		cout << "| 4 - Menu Principal                                       |\n";
		cout << "+----------------------------------------------------------+\n";
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

		cin.ignore(INT_MAX, '\n');

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			calculatePathAcorddingToDistance();
			escolheDireto();
			cin.get();
			cin.get();
			break;

		case 2:
			calculatePathAcorddingToCost();
			escolheDireto();
			cin.get();
			cin.get();
			break;

		case 3:
			menuTrip();
			cin.get();
			cin.get();
			break;

		case 4:
			introMenu();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::destinosCidade(){

	string origem;

	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique onde se encontra                                |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, origem);

	for(unsigned int i = 0; i < vec.size(); i++){

		if(origem == vec[i]->getName()){

			gv = new GraphViewer(1360,625, false);
			gv->setBackground("worldmap.jpg");
			gv->defineVertexColor("black");
			gv->defineEdgeColor("red");
			gv->defineEdgeCurved(true);
			gv->createWindow(750,450);

			for(unsigned int i = 0; i < vec.size(); i++){

				gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
				gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
				gv->setVertexColor(vec[i]->getID(), "grey");
				gv->setVertexSize(vec[i]->getID(), 3);
			}

			gv->addEdge(0, vec[i]->getID(), vec[i]->getIDDestinies(0), EdgeType::DIRECTED);
			gv->addEdge(1, vec[i]->getID(), vec[i]->getIDDestinies(1), EdgeType::DIRECTED);
			gv->addEdge(2, vec[i]->getID(), vec[i]->getIDDestinies(2), EdgeType::DIRECTED);

		}
	}

		gv->rearrange();

}



void Agency::escolheDireto() {

	string origem;
	string destino;
	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique a origem da sua viagem:                         |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, origem);


	Vertex<City>* originVertex;
	if ((originVertex = getGraph().findVertexName(origem)) == NULL){//VERIFICAR SE EXISTE
		cout << " Origem nao existe!\n";
		return;
	}


	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique o destino que quer visitar:                      |\n";
	cout << "+----------------------------------------------------------+\n";

	getline(cin, destino);


	Vertex<City>* destVertex;
	if ((destVertex = getGraph().findVertexName(destino)) == NULL){//VERIFICAR SE EXISTE
		cout << " Destino nao existe!\n";
		return;
	}

	graph.dijkstraShortestPath(originVertex->getInfo());
	cout << "Distance : " << destVertex->getDist() << "\n";
	auto path = graph.getPath(originVertex->getInfo(), destVertex->getInfo());

	for(City city: path){
		cout << city.getName() <<"\n";
	}

	gv = new GraphViewer(1360,625, false);
	gv->setBackground("worldmap.jpg");
	gv->defineVertexColor("black");
	gv->defineEdgeColor("red");
	gv->defineEdgeCurved(true);
	gv->createWindow(750,450);

	for(unsigned int i = 0; i < vec.size(); i++){

		gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
		gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
		gv->setVertexColor(vec[i]->getID(), "grey");
		gv->setVertexSize(vec[i]->getID(), 3);
	}

	int id = 0;

	for(unsigned int i = 0; i < path.size() - 1; i++){
		gv->addEdge(id, path[i].getID(), path[i+1].getID(), EdgeType::DIRECTED);
		id++;
	}

	gv->rearrange();
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

void Agency::menuSave(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha que ficheiros pretende guardar                   |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Guardar Cliente                                      |\n";
		cout << "| 2 - Guardar Viagens					                    |\n";
		cout << "| 3 - Menu Principal					                    |\n";
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
			readToClientFile();
			cin.get();
			cin.get();
			break;

		case 2:
			readToTripsFile();
			cin.get();
			cin.get();
			break;

		case 3:
			readToTripsFile();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::map(){

	gv = new GraphViewer(1360,625, false);
	gv->setBackground("worldmap.jpg");
	gv->defineVertexColor(GRAY);
	gv->defineEdgeColor(GRAY);
	gv->defineEdgeCurved(true);
	gv->createWindow(750,450);

	for(unsigned int i = 0; i < vec.size(); i++){
		cout << i << "\n";
		gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
		gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
		gv->setVertexColor(vec[i]->getID(), GRAY);
		gv->setVertexSize(vec[i]->getID(), 3);
	}

	int id = 0;

	for(unsigned int i = 0; i < vec.size(); i++){

		if(vec[i]->getID() != 0){

			for(unsigned int j = 0; j < 3; j++){
				gv->addEdge(id, vec.at(i)->getID(), vec.at(i)->getIDDestinies(j), EdgeType::UNDIRECTED);
				id++;
			}
		}
	}

	gv->rearrange();

}
