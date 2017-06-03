#include "exe_34_36_37.h"
#include <iostream>

using namespace std;

//����ǰ message ��ӵ�������Ŀ¼f��
void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

//����ǰ message �Ӹ�����Ŀ¼f���Ƴ�
void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

//����ǰ message ��ӵ����к��� m ��Ŀ¼ folders ��
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

//�����а�����ǰ message ��Ŀ¼���Ƴ���ǰmessage
void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

//�������캯��
Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::print()
{
	cout << contents << endl;
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;

	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Folder & Folder::operator=(const Folder &f)
{
	remove_from_Message();
	msgs = f.msgs;
	add_to_Messages(f);
	return *this;
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);
}

void Folder::remove_from_Message()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}

void Folder::print()
{
	for (auto m : msgs)
		cout << m->contents << endl;
}