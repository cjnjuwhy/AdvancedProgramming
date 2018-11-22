#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>

using namespace std;

struct Job {
	int id;
	int enter_time;
	int duration;
	int priority;
	Job(){}
	Job(int id, int enter_time, int duration, int priority) {
		this->id = id;
		this->enter_time = enter_time;
		this->duration = duration;
		this->priority = priority;
	}
};

bool compare1(Job a, Job b) {
	return (b.enter_time > a.enter_time);
}
bool compare2(Job a, Job b) {
	return (a.priority> b.priority);
}

class JobSchedual {
public:
	JobSchedual(Job js[], int length) {
		for (int i = 0; i < length; i++) {
			data.push_back(js[i]);
		}
	}
	~JobSchedual() {
	}

	void FCFS() {

		sort(data.begin(), data.end(), compare1);
		if (data.empty())return;
		int time = data.front().enter_time;
		while (!data.empty()) {
			Job temp = data.front();
			if (temp.enter_time > time) time = temp.enter_time;
			time += temp.duration;
			cout << temp.id << " " << time << endl;
			data.pop_front();
		}

	}
	void RoundRobin(int time_slice) {
		if (data.empty())return;
		sort(data.begin(), data.end(), compare1);
		int time = data.front().enter_time;

		deque<Job> waiting;
		Job temp = data.front();
		waiting.push_back(temp);
		data.pop_front();

		int tic = time_slice;

		while (!data.empty() || !waiting.empty()) {
			tic--;
			time++;
			if (!waiting.empty())
				waiting.front().duration -= 1;

			if (!data.empty()) {
				Job temp = data.front();
				if (temp.enter_time <= time) {
					data.pop_front();
					waiting.push_back(temp);
				}
			}
			if (!waiting.empty()) {
				Job temp = waiting.front();
				if (temp.duration <= 0) {
					cout << temp.id << " " << time << endl;
					waiting.pop_front();
					tic = time_slice;
				}
				if (tic == 0) {
					tic = time_slice;
					Job temp = waiting.front();
					waiting.pop_front();
					waiting.push_back(temp);
				}
			}
		}


	}
	void PrioritySchedual() {
		if (data.empty())return;
		sort(data.begin(), data.end(), compare1);
		int time = data.front().enter_time;

		deque<Job> waiting;
		Job temp = data.front();
		waiting.push_back(temp);

		data.pop_front();

		while (!data.empty()|| !waiting.empty()) {
			time++;
			if (!waiting.empty())
				waiting.front().duration -= 1;
			while(!data.empty()) {
				Job temp = data.front();
				if (temp.enter_time <= time) {
					waiting.push_back(temp);
					data.pop_front();
				}
				else
					break;
			}

			sort(waiting.begin(), waiting.end(), compare2);

			Job temp = waiting.front();
			if (temp.duration == 0) {
				cout << temp.id << " " << time << endl;
				waiting.pop_front();
			}
		}
	}

	void show() {
		deque<Job>::iterator it = data.begin();
		for (; it != data.end(); it++) {
			printf("%d: %d %d %d\n",it->id, it->enter_time, it->duration, it->priority);
		}
	}

	friend bool compare1(Job a, Job b);
	friend bool compare2(Job a, Job b);

public:
	// you should use three different STL to finish this tash

	deque<Job> data;
};

