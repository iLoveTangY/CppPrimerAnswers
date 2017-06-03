#include "exe_34_36_37.h"

int main()
{
	Message firstMail("hello");
	Message signInMail("welcome to cppprimer");
	Folder mailBox;

	firstMail.print(); // print: "hello"
	firstMail.save(mailBox); // send to mailBox
	mailBox.print();   // print: "hello"

	signInMail.print(); // print "welcome to cppprimer"
	signInMail.save(mailBox); // send to mailBox
	mailBox.print();    // print "welcome to cppprimer hello"

	firstMail = firstMail;   // test for assignment to self.
	firstMail.print(); // print "hello"
	mailBox.print();   // print "welcome to cppprimer hello"
}