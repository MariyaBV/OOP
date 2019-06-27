#include "pch.h"

class IOutputStream
{
public:
	virtual void WriteChar(std::vector<char> vectorOfChar) const = 0;
};

class IInputStream
{
public:
	virtual void Read(std::vector<char> vectorOfChar) const = 0;
};

class MemoryOutputStream : public IOutputStream
{
public:
	MemoryOutputStream(std::vector<char> vectorOfChar);
	void WriteChar();
	void Clear();
	void Reset();

private:
	std::vector<char> m_vectorOfChar;
	char* m_pos = &m_vectorOfChar.back();
	//std::vector<char>* m_reference = &m_vectorOfChar;
};

class MemoryInputStream : public IInputStream
{
public:
	MemoryInputStream(std::vector<char> vectorOfChar);
	void Read();
	void Reset();
	void Clear();

private:
	std::vector<char> m_vectorOfChar;
	char* m_pos = &m_vectorOfChar.back();
};

class MemoryStream: public MemoryInputStream, public MemoryOutputStream
{
public:
	void Clear();

private:
	std::vector<char> m_vectorOfChar;
	char* m_posRead = &(*m_vectorOfChar.begin());
	char* m_posWrite = &(*m_vectorOfChar.begin());

};