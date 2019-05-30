#pragma once

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// ������������ ����� value �� ������ newItemLocation
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// ������������� �� ������������� ������ ��������� ���������
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:
	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	// �������� �������� �� �������� ������� � to, ���������� newEnd
	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd) T(*srcBegin);
		}
	}

	static void DeleteItems(T* begin, T* end)
	{
		// ��������� ������ ��������
		DestroyItems(begin, end);
		// ����������� ������� ������ ��� �� ��������
		RawDealloc(begin);
	}

	static void DestroyItems(T* from, T* to)
	{
		// dst - ����� ������, ��� ��������������� �������� ���� ��������� ����������
		// to - ������ ������������������ ������
		while (to != from)
		{
			--to;
			// ���� �������� ���������� ��� ���������� ���� T
			to->~T();
		}
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};
