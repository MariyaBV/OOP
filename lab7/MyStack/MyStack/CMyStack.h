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

	CMyStack(CMyStack const& other)
	{
		if (!other.IsEmpty())
		{
			try
			{
				Component* current = other.m_top;
				//copy the top of the stack
				m_top = new Component;
				m_top->data = current->data;
				m_top->next = nullptr;

				Component* last = m_top; //set last to point to the node
				current = current->next; //set current to point to the next node
				//copy the remaining stack
				while (current)
				{
					Component* newNode = new Component;

					newNode->data = current->data;
					newNode->next = nullptr;
					last->next = newNode;
					last = newNode;
					current = current->next;
				}
			}
			catch (...)
			{
				Clear();
				throw;
			}
		}
	}

	CMyStack(CMyStack&& stack)
		: m_top(stack.m_top)
	{
		stack.m_top = nullptr;
	}

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

	CMyStack& operator=(CMyStack const& other)
	{
		if (std::addressof(&other) !=  std::addressof(this))
		{
			CMyStack newStack(other);

			std::swap(m_top, newStack.m_top);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other)
	{
		if (std::addressof(&other) !=  std::addressof(this))
		{
			Clear();
			m_top = other.m_top;
			other.m_top = nullptr;
		}
		return *this;
	}

private:
	Component* m_top = nullptr;
};