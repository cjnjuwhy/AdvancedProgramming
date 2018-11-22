#include "cards.h"


Card::Card(string card_id, int account_balance)
{
	this->card_id = card_id;
	this->account_balance = account_balance;
}

Card::~Card()
{
}

string Card::get_card_id()
{
	return card_id;
}

int Card::get_accunt_balance()
{
	return account_balance;
}

Bank_Card::Bank_Card(string card_id, int account_balance)
	:Card(card_id, account_balance)
{
}

Bank_Card::~Bank_Card()
{
}

int Bank_Card::recharge(int num)
{
	Card::account_balance += num;
	return 0;
}

int Bank_Card::consume(int num)
{
	if (get_accunt_balance() < num)return -1;
	Card::account_balance -= num;
	return 0;
}

Student_Card::Student_Card(string card_id, int account_balance, Bank_Card * b_card)
	:Card(card_id, account_balance)
{
	this->b_card = b_card;
}

Student_Card::~Student_Card()
{
}

Bank_Card * Student_Card::get_b_card()
{
	return b_card;
}

int Student_Card::consume(int num)
{
	if (get_accunt_balance() < num)return -1;
	Card::account_balance -= num;
	return 0;
}

int Student_Card::recharge(Bank_Card * b_card, int num)
{
	if (this->b_card == b_card) {
		if (!this->b_card->consume(num)) {
			Card::account_balance += num;
			return 0;
		}
	}
	return -1;
}

Teacher_Card::Teacher_Card(string card_id, int account_balance, double discount, Bank_Card*
	b_card)
	:Card(card_id, account_balance)
{
	this->discount = discount;
//	this->b_card = b_card;
	this->b_cards.push_back(b_card);
}

Teacher_Card::~Teacher_Card()
{
}

double Teacher_Card::get_discount()
{
	return discount;
}

vector<Bank_Card*>* Teacher_Card::get_b_cards()
{
	return &b_cards;
}

int Teacher_Card::consume(int num)
{
	int cos = (int)(discount*num);
	if (get_accunt_balance() < cos)return -1;
	Card::account_balance -= cos;
	return 0;
}

int Teacher_Card::recharge(Bank_Card * b_card, int num)
{
	vector<Bank_Card *>::iterator it = b_cards.begin();
	while (it != b_cards.end()) {
		if (*it == b_card) {
			if (!b_card->consume(num)) {
				Card::account_balance += num;
				return 0;
			}
		}

		it++;
	}

	return -1;
}
