#ifndef __HASHENTITY_H__
#define __HASHENTITY_H__
template<typename Key, typename Data>
class HashEntity {
private:
	Key key;
	Data data;
public:
	HashEntity(){}
	HashEntity(int key, int data) {
		this->key = key;
		this->data = data;
	}
	Key getkey() { return key; }
	Data getdata() { return data; }
	void setkey(Key k) { key = k; }
	void setdata(Data d) { data = d; }
};

#endif // !__HASHENTITY_H__

