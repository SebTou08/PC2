#ifndef __HASHTABLE_H__
#define _HASHTABLE_H__

#include<iostream>
#include<list>
#include<stdlib.h>
#include<algorithm>
#include<functional>
#include "HashEntity.h"
#include<string>
using namespace std;
template<typename key, typename data>
class HashTable {
	static const long long HashGroups = 1000000000;
	list<pair<key, data>> table[HashGroups];
    int co;
	
public:
	HashTable() {
        co = 0;
		for (auto i : table)
		{
			i.clear();
		}
	}

	key HashFunction(key k) { return k % HashGroups; }
	data buscar(key k) {
		int HashKey = HashFunction(k);
		for (auto lv : table[HashKey])
		{
			if (lv.first == k) { return lv.second; }
		}
	}

	void Insert(key k, data d) {
        ++co;
		int HashKey = HashFunction(k);
		bool FoundKey = false;
		for (auto lv: table [HashKey])
		{
			if (lv.first == k) {
				lv.second = d;
				FoundKey = true;
			}
		}
		if (!FoundKey) {
			pair<key, data> p1(k, d);
			table[HashKey].push_back(p1);
		}
	}
    long long getco(){return co;}
};

#endif // !__HASHTABLE_H__


