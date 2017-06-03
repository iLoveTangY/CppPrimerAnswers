#ifndef _EXE_49_
#define _EXE_49_
#pragma once

#include <string>
#include <set>

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const std::string &str = "") : contents(str) { }
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	~Message();

	void save(Folder&);
	void remove(Folder&);

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }

	void print();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *);
};

class Folder
{
public:
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }

	Folder() = default;
	Folder(const Folder &f) :
		msgs(f.msgs) {
		add_to_Messages(f);
	}
	~Folder() { remove_from_Message(); }
	Folder& operator=(const Folder&);

	void print();

private:
	std::set<Message *> msgs;
	//将当前目录添加到所有给定目录中包含的 message 中
	void add_to_Messages(const Folder&);
	//将当前目录从它包含所有的 message 中删除
	void remove_from_Message();
};

#endif
