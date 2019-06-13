#pragma once

template <typename T>
class CMyStack
{
	struct Component
	{
		T data;
		Component* next;
	};

public:
	CMyStack() = default;

	~CMyStack()
	{
		Clear();
	};

	bool IsEmpty() const
	{
		return (m_top == NULL) ? true : false;
	}

	void Push(T const& newData)
	{
		try
		{
			Component* newComponent = new Component; //создаем и выделяем память для нового элемента
			newComponent->data = newData; //записываем необходимую инфрмацию в data
			newComponent->next = m_top; //проводим связь от нового элемента, к вершине
			m_top = newComponent; //обозначаем, что вершиной теперь является новый элемент
		}
		catch (...)
		{
			throw;
		}
	}

	T GetTop() const
	{
		if (!IsEmpty())
		{
			return m_top->data;
		}
		else
		{
			throw std::out_of_range("Error. Empty stack.\n");
		}
	}

	T Pop()
	{
		if (!IsEmpty())
		{
			T tempData = m_top->data;
			Component* tempTop = m_top;
			m_top = m_top->next;
			free(tempTop);

			return tempData;
		}
		else
		{
			throw std::out_of_range("Error. Empty stack.\n");
		}
	}

	void Clear()
	{
		if (!IsEmpty())
		{
			while (m_top != NULL)
			{
				Component* tempTop = m_top;
				m_top = m_top->next;
				free(tempTop);
			}
		}
	}

private:
	Component* m_top = nullptr;
};