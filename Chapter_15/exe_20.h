#ifndef _EXE_20_
#pragma once
#define _EXE_20_

class Base
{
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base
{
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
	int f1() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
	int f3() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; }
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
	// void memfcn(Base &b) { b = *this; } // error: 'Base' not accessible because 'Priv_Derv' uses 'private' to inherit from 'Base'
};
struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }
};
#endif // !_EXE_20_


