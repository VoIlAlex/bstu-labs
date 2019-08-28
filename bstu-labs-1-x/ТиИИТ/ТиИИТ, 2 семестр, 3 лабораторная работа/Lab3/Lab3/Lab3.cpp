#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

const int a = 3, p = 5;

struct client
{
	char login[1024];
	char password[1024];
	int privateNumber;
	int key = -1;
	char keyWith[1024];
};
struct request
{
	char from[1024];
	char to[1024];
	int key;
};
struct message
{
	char from[1024];
	char to[1024];
	char text[1024];
};


int menu();
int login(client*, int);
void menuForAccount(client*, int, int, request*, int*, message*, int*);
void requestsMenu(client*, int, int, request*, int*);
void messagesMenu(client*, int, int, message*, int*);
client* logup(client*, int*, int*, int*, int);
client* biggerArray(client*, int*);
request* biggerArray(request*, int*);
void acceptReq(client*, int, int, request *, int*);
void acceptReq(client*, int, request);
void newRequest(client*, int, int, request*, int*);
void newRequest(client*, int, int, request*, int*, int);


int main()
{
	int MAX_NUM_OF_CLIENTS = 4;

	int * privateNumbers = new int[MAX_NUM_OF_CLIENTS];
	int numOfPrivateNumbers = 0;
	for (int i = 0; i < MAX_NUM_OF_CLIENTS; i++)
		privateNumbers[i] = -1;

	client * arrOfClients = new client[1];
	int sizeOfArrOfClients = 1;
	request * requests = new request;
	int numOfRequests = 0;
	message * messages = new message;
	int numOfMessages = 0;

	/*Admin*/
	strcpy_s(arrOfClients[0].login,"admin");
	strcpy_s(arrOfClients[0].password,"admin");
	arrOfClients[0].privateNumber = 1;
	privateNumbers[numOfPrivateNumbers] = 1;
	numOfPrivateNumbers++;
	/*******/

	while (1)
	{
		int menuInput = menu();
		if (menuInput)
		{
			int idOfClient = login(arrOfClients, sizeOfArrOfClients);
			if (idOfClient == -1)
				continue;
			menuForAccount(arrOfClients, sizeOfArrOfClients, idOfClient, requests, &numOfRequests, messages, &numOfMessages);
		}
		else
			arrOfClients = logup(arrOfClients, &sizeOfArrOfClients, privateNumbers, &numOfPrivateNumbers, MAX_NUM_OF_CLIENTS);
	}

	system("pause");
    return 0;
}

int menu()
{
	system("cls");
	cout << "#Menu# " << endl;
	cout << "1. Sign In" << endl;
	cout << "2. Sign Up" << endl;
	cout << "3. Exit";
	while (1)
	{
		int input = _getch();
		input -= 48;
		if (input == 3)
		{
			system("cls");
			cout << "Good lock!";
			Sleep(1000);
			exit(0);
		}
		else if (input == 1)
		{
			system("cls");
			return 1;
		}
		else if (input == 2)
		{
			system("cls");
			return 0;
		}
	}
}
int login(client* arrOfClients, int sizeOfArrOfClients)
{
	int idOfClientResult;
	while (1)
	{
		system("cls");
		char login[1024], password[1024];
		cout << "#Sign in#" << endl;
		cout << "Login: "; cin >> login;

		int idOfClient = -1;
		for(int i = 0; i < sizeOfArrOfClients; i++)
			if (!strcmp(arrOfClients[i].login, login))
			{
				idOfClient = i;
				break;
			}
		if (idOfClient == -1)
		{
			system("cls");
			cout << "Error! Login does not exist! \nDo you want repeat? (1 - yes, 2 - no)";
			while (1)
			{
				int input = _getch();
				input -= 48;
				if (input == 2)
					return -1;
				if (input == 1)
					break;
			}
			continue;
		}
		cout << "Password: "; cin >> password;
		if (strcmp(arrOfClients[idOfClient].password, password))
		{
			system("cls");
			cout << "Error! Wrong password! \nDo you want repeat? (1 - yes, 2 - no)";
			while (1)
			{
				int input = _getch();
				input -= 48;
				if (input == 2)
					return -1;
				if (input == 1)
					break;
			}
			continue;
		}
		idOfClientResult = idOfClient;
		break;
	}
	system("cls");
	return idOfClientResult;
}

void menuForAccount(client* arrOfClients, int sizeOfArrOfClients, int id, request* requests, int* numOfRequests, message* messages, int* numOfMessages)
{
	while (1)
	{
		system("cls");
		cout << "1. Requests" << endl;
		cout << "2. Messages" << endl;
		cout << "3. Log out" << endl;
		while (1)
		{
			int input = _getch();
			input -= 48;
			if (input == 1)
			{
				requestsMenu(arrOfClients, sizeOfArrOfClients, id, requests, numOfRequests);
				break;
			}
			else if (input == 2)
			{
				messagesMenu(arrOfClients, sizeOfArrOfClients, id, messages, numOfMessages);
				break;
			}
			if (input == 3)
			{
				system("cls");
				cout << "Do you want to disconnect?(1 - yes, 2 - no)";
				while (1)
				{
					input = _getch();
					input -= 48;
					if (input == 1)
						return;
					else if (input == 2)
						break;
				}
				break;
			}
		}
	}
}
void requestsMenu(client* arrOfClients, int sizeOfArrOfClients, int id, request* requests, int* numOfRequests)
{
	while (1)
	{
		system("cls");
		for (int i = 0; i < *numOfRequests; i++)
		{
			cout << "Request #" << i + 1 << endl;
			cout << "From: " << requests[i].from << endl;
			cout << "To: " << requests[i].to << endl << endl;
		}
		cout << "1. To accept request" << endl;
		cout << "2. New request" << endl;
		while (1)
		{
			int input = _getch();
			if (input == 27)
				return;
			input -= 48;
			if (input == 1)
			{
				acceptReq(arrOfClients,sizeOfArrOfClients, id, requests, numOfRequests);
				break;
			}
			else if (input == 2)
			{
				newRequest(arrOfClients, sizeOfArrOfClients, id, requests, numOfRequests);
				break;
			}
		}
	}
}
void messagesMenu(client* arrOfClients, int sizeOfArrOfClients, int id, message* messages, int* numOfMessages)
{
	system("cls");
	/*if (arrOfClients[id].key = -1)
	{
		cout << "You don't have a key. Connect with someone.";
		return;
	}

	int numOfMess = *numOfMessages;
	int *idMessageVector = new int[numOfMess];
	for (int i = 0; i < numOfMess; i++)
		idMessageVector[i] = -1;

	for (int i = 0; i < numOfMess; i++)
		for (int j = 0; j < sizeOfArrOfClients; j++)
			if (!strcmp(arrOfClients[j].login, messages[i].from))
			{
				idMessageVector[i] = j;
				break;
			}
		*/
}

client* logup(client* arrOfClients, int* sizeOfArrOfClient, int * privateNumbers, int * numOfPrivateNumbers, int MAX_NUM_OF_CLIENTS)
{
	system("cls");
	if (*numOfPrivateNumbers == MAX_NUM_OF_CLIENTS)
	{
		cout << "Max clients!"; Sleep(1000); system("cls"); return arrOfClients;
	}
	while (1)
	{
		system("cls");
		char login[1024], password[1024], passwordRepeat[1024];
		cout << "#Log up#" << endl;
		cout << "Login:"; cin >> login;
		bool con = false;
		for (int i = 0; i < *sizeOfArrOfClient; i++)
			if (!strcmp(login, arrOfClients[i].login))
			{
				system("cls");
				cout << "Error! Login already in use! \nDo you want repeat? (1 - yes, 2 - no)";
				while (1)
				{
					int input = _getch();
					input -= 48;
					if (input == 2)
						return arrOfClients;
					if (input == 1)
						break;
				}
				con = true;
			}
		if (con) continue;

		cout << "Password: "; cin >> password;
		cout << "Repeating password: "; cin >> passwordRepeat;
		if(strcmp(password, passwordRepeat))
		{
			system("cls");
			cout << "Error! Password repeating is wrong! \nDo you want repeat? (1 - yes, 2 - no)";
			while (1)
			{
				int input = _getch();
				input -= 48;
				if (input == 2)
					return arrOfClients;
				if (input == 1)
					break;
			}
			continue;
		}

		arrOfClients = biggerArray(arrOfClients, sizeOfArrOfClient);
		int id = *sizeOfArrOfClient - 1;
		strcpy_s(arrOfClients[id].login, login);
		strcpy_s(arrOfClients[id].password, password);
		
		int privateNumber;
		while (1) 
		{
			privateNumber = rand() % MAX_NUM_OF_CLIENTS + 1;
			for (int i = 0; i < *numOfPrivateNumbers; i++)
				if (privateNumbers[i] == privateNumber)
					continue;
			break;
		}
		arrOfClients[id].privateNumber = privateNumber;
		int numOfPrNum = *numOfPrivateNumbers;
		privateNumbers[numOfPrNum] = privateNumber;
		(*numOfPrivateNumbers)++;

		return arrOfClients;
	}
}
client* biggerArray(client* arrayOfStruct, int* sizeOfArrayOfStruct)
{
	client * arrayOfStructResult;
	(*sizeOfArrayOfStruct)++;
	system("cls");
	int  sizeOfResultArray = *sizeOfArrayOfStruct;
	arrayOfStructResult = new client[sizeOfResultArray];
	for (int i = 0; i < (sizeOfResultArray - 1); i++)
		arrayOfStructResult[i] = arrayOfStruct[i];
	return arrayOfStructResult;
}

request* biggerArray(request* arrayOfStruct, int* sizeOfArrayOfStruct)
{
	request* arrayOfStructResult;
	(*sizeOfArrayOfStruct)++;
	system("cls");
	int  sizeOfResultArray = *sizeOfArrayOfStruct;
	arrayOfStructResult = new request[sizeOfResultArray];
	for (int i = 0; i < (sizeOfResultArray - 1); i++)
		arrayOfStructResult[i] = arrayOfStruct[i];
	return arrayOfStructResult;
}

void acceptReq(client* arrOfClients, int sizeOfArrOfClients, int id, request * req, int * numOfRequests)
{
	system("cls");
	while (1)
	{
		cout << "Number of request";
		int input;
		while (1)
		{
			input = _getch();
			if (input == 27)
				return;
			input -= 48;
			if (input > 0 && input < *numOfRequests)
				break;
		}
		if (!strcmp(req[input].to, arrOfClients[id].login))
		{
			system("cls");
			cout << "Error!";
			Sleep(1000);
			break;
		}
		int idOfFrom = -1;
		for(int i = 0; i < sizeOfArrOfClients; i++)
			if (!strcmp(req[input].from, arrOfClients[i].login))
			{
				idOfFrom = i;
				break;
			}
		if (idOfFrom == -1)
		{
			system("cls");
			cout << "Error! Login does not exist! \nDo you want repeat? (1 - yes, 2 - no)";
			while (1)
			{
				int input = _getch();
				input -= 48;
				if (input == 2)
					return;
				if (input == 1)
					break;
			}
			continue;
		}
		arrOfClients[id].key = (int)pow((double)req[input].key, (double)arrOfClients[id].privateNumber) % p;
		strcpy_s(arrOfClients[id].keyWith, req[input].from);
		newRequest(arrOfClients, sizeOfArrOfClients, id, req, numOfRequests, idOfFrom);
		acceptReq(arrOfClients, idOfFrom, req[(*numOfRequests-1)]);
		break;
	}
	system("cls");
}
void acceptReq(client* cl, int id,request req)
{

	cl[id].key = (int)pow((double)req.key, (double)cl[id].privateNumber) % p;
	strcpy_s(cl[id].keyWith, req.from);
}

void newRequest(client* arrOfClients, int sizeOfArrOfClients, int id, request* requests, int* numOfRequests)
{
	while (1)
	{
		system("cls");
		requests = biggerArray(requests, numOfRequests);
		int nOfR = *numOfRequests - 1;
		strcpy_s(requests[nOfR].from,arrOfClients[id].login);
		requests[nOfR].key = (int)pow((double)a, (double)arrOfClients[id].privateNumber);
		cout << "To: " << endl;
		for (int i = 0; i < sizeOfArrOfClients; i++)
		{
			cout << i + 1 << ". " << arrOfClients[i].login << endl;
		}
		int input;
		while (1)
		{
			input = _getch();
			if (input == 27)
				return;
			input -= 48;
			if (input > 0 && input <= sizeOfArrOfClients)
				break;
		}
		
		strcpy_s(requests[nOfR].to, arrOfClients[input - 1].login);
		break;
	}
	system("cls");
}
void newRequest(client* arrOfClients, int sizeOfArrOfClients, int id, request* requests, int* numOfRequests, int toId)
{
	requests = biggerArray(requests, numOfRequests);
	int nOfR = *numOfRequests - 1;
	strcpy_s(requests[nOfR].from, arrOfClients[id].login);
	requests[nOfR].key = (int)pow((double)a, (double)arrOfClients[id].privateNumber);
	strcpy_s(requests[nOfR].to, arrOfClients[toId].login);
}