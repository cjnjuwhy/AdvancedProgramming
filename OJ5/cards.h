#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Card
{
public:
	Card(string card_id, int account_balance);
	~Card();
	string get_card_id();
	int get_accunt_balance();

protected:
	string card_id;
	int account_balance;

};

class Bank_Card : public Card {
public:
	Bank_Card(string card_id, int account_balance);
	~Bank_Card();
	
	int recharge(int num);
	int consume(int num);
};


class Student_Card : public Card {
public:
	Student_Card(string card_id, int account_balance, Bank_Card* b_card);
	~Student_Card();

	Bank_Card* get_b_card();
	int consume(int num);
	int recharge(Bank_Card* b_card, int num);


	Bank_Card* b_card;
};


class Teacher_Card : public Card {
public:
	Teacher_Card(string card_id, int account_balance, double discount, Bank_Card*
		b_card);
	~Teacher_Card();
	double get_discount();
	vector<Bank_Card* >* get_b_cards();
	int consume(int num);
	int recharge(Bank_Card* b_card, int num);
	
private:
	double discount;
//	Bank_Card* b_card;
	vector<Bank_Card* > b_cards;
};

