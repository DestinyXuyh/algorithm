#pragma once
#include <string>
#include <set>
#include "Folder.h"
using namespace std;

class Message
{
	friend class Folder;
public:
	//���캯��
	explicit Message(const string& str = string()) :contents(str) {}
	//�������캯��
	Message(const Message&);
	//������ֵ�����
	Message& operator = (const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	string contents;	//ʵ����Ϣ�ı�
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
	set<Folder*>::iterator iter = m.folders.begin();
	for (; iter != m.folders.end(); ++iter)
	{
		(*iter)->addMsg(this);
	}
	/*for (auto f : m.folders)
		f->addMsg(this);*/
}

//�������캯��
Message::Message(const Message& m) :contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

//��������
Message::~Message()
{
	remove_from_Folders();
}

//������ֵ�����
Message& Message::operator=(const Message& m)
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}