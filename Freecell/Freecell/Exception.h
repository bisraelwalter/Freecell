//****Brandon Walter*****
#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
#endif

class Exception
{
private:
	char *m_msg;

public:
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();
	Exception &operator=(const Exception &rhs);
	const char* getMessage();
	void setMessage(char *msg);
	friend std::ostream &operator<<(std::ostream &stream, const Exception &except);
};




