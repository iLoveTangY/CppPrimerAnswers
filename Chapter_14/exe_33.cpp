struct IfThenElse
{
	int operator()(bool b, int i, int j) { return b ? i : j; }
};