#include "exe_49_Message.h"
#include <iostream>

using namespace std;

//将当前 message 添加到给定的目录f中
void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

//将当前 message 从给定的目录f中移除
void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

//将当前 message 添加到所有含有 m 的目录 folders 中
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

//从所有包含当前 message 的目录中移除当前message
void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

//拷贝构造函数
Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
	move_Folders(&m);
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

Message & Message::operator=(Message &&rhs)
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);  //重置Folders指向本Message
	}
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