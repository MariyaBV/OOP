#include "pch.h"
#include "example1.h"

using namespace std;

// Интерфейс "Выходной поток данных"
// Поддерживает операции:
//  WriteChar - выводит в поток символ
//  В случае ошибки бросает исключение std::runtime_error
//class IOutputStream
//{
//	// Написать недостающий код
//};



// Интерфейс "Входной поток данных", поддерживает операции
// Поддерживает операции:
//  Read - считывает символ из потока данных
//   Если поток закончился, возвращает "пустой" символ
//   В случае ошибки бросает исключение std::runtime_error
//class IInputStream
//{
//	// Написать недостающий код
//};

	// Класс, реализующий интерфейс IOuputStream
// В качестве хранилища данных использует vector<char>, ссылка на который передаётся ему снаружи
// Внимание - векто
// Дополнительно предоставляет операции:
//   Clear(), очищающую массив и перематывающую в начало
//   Reset(), перематывает позицию записи в начало массива, не меняя его содержимое
//class MemoryOutputStream // Написать недостающий код
//{
//	// Написать недостающий код
//};

MemoryOutputStream::MemoryOutputStream(vector<char> vectorOfChar)
	: m_vectorOfChar(vectorOfChar)
{};

void MemoryOutputStream::WriteChar()
{
	try
	{
		char* reference = &(*m_vectorOfChar.begin());

		while (reference != m_pos)
		{
			cout << *reference;
			reference++;
		}
		/*for (auto& element : m_vectorOfChar)
		{
			cout << element;
		}*/
	}
	catch (...)
	{
		throw runtime_error("Error. No characters in output.\n");
	}
}

void MemoryOutputStream::Clear()
{
	m_vectorOfChar.clear();
}

void MemoryOutputStream::Reset()
{
	m_pos = &(*m_vectorOfChar.begin());
}
	// Класс, реализующий интерфейс IInputStream
// В качестве источника данных использует vector<char>, ссылка на который передаётся ему снаружи
// Дополнительно предоставляет операцию Reset(), выполняющую перемотку в начало вектора

MemoryInputStream::MemoryInputStream(vector<char> vectorOfChar)
	: m_vectorOfChar(vectorOfChar)
{ };

void MemoryInputStream::Read()// Написать недостающий код
{
	try
	{
		if (m_vectorOfChar[*m_pos] != m_vectorOfChar.size())
		{
			cin >> *m_pos;
			m_pos++;
		}
		/*for (auto& element : m_vectorOfChar)
		{
			cin >> element;
		}*/
	}
	catch (...)
	{
		throw runtime_error("Error. No characters in input.\n");
	}
};

void MemoryInputStream::Clear()
{
	m_vectorOfChar.clear();
}

void MemoryInputStream::Reset()
{
	m_pos = &(*m_vectorOfChar.begin());
}
// Класс, реализующий интерфейсы IInputStream и IOutputStream
// Использует для хранения массив vector<char>, которым и владеет единолично
// Чтение и запись производятся независимо друг от друга (позиция чтения и позиция записи - свои)
// Дополнительно предоставляет методы:
//   Clear() очищает массив и сбрасывает позиции чтения и записи
//   ResetReadPos() - сбрасывает позицию чтения, не меняя содержимое массива
//   ResetWritePos() - сбрасывает позицию записи, не меняя содержимое массив
//   ResetAll() - сбрасывает обе позиции, не меняя содержимое массива
void MemoryStream::Clear() // Написать недостающий код
{
	MemoryInputStream::Clear();
	MemoryOutputStream::Clear();
};

// Записывает строку в output посимвольно
void WriteString(IOutputStream& output, const std::string& s)
{
	// Написать недостающий код
}

// Читает из input посимвольно в строку до конца
std::string ReadString(IInputStream& input)
{
	// Написать недостающий код
	return {};
}

int main()
{
	// Создать массив
	// При помощи MemoryOutputStream записать в него посимвольно содержимое строки hello = "hello"
	// При помощи MemoryInputStream считать из него посимвольно строку hello1
	// Убедиться, что строки hello и hello1 одинаковы

	// Cоздать MemoryStream
	// Записать в него посимвольно строку goodbye = "Good bye"
	// Считать из него посимвольно строку goodbye1
	// Перемотать позицию записи и записать строку "Must di"
	// Перемотать позицию чтения и считать до конца содержимое
	// Убедиться, что прочитано "Must die"
}