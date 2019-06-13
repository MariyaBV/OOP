#pragma once

template <typename T>
class CMyStack
{
	struct Component
	{
		Component(const T& data, Component* next)
			: data(data)
			, next(next)
		{
		}
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
				m_top = new Component(current->data, nullptr);
				Component* last = m_top; //set last to point to the node
				current = current->next; //set current to point to the next node
				//copy the remaining stack
				while (current)
				{
					Component* newComponent = new Component(current->data, nullptr);
					last->next = newComponent;
					last = newComponent;
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
		: m_top(stack.m_top) noexcept
	{
		stack.m_top = nullptr;
	}

	~CMyStack()
	{
		Clear();
	};

	bool IsEmpty() const noexcept
	{
		return (m_top == NULL) ? true : false;
	}

	void Push(T const& newData)
	{
		Component* newComponent = new Component(newData, m_top); //создаем и выделяем память для нового элемента
		m_top = newComponent; //обозначаем, что вершиной теперь является новый элемент
	}

	const T& GetTop() const
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

	void Pop()
	{
		if (!IsEmpty())
		{
			Component* tempTop = m_top;
			m_top = m_top->next;
			delete tempTop;
		}
		else
		{
			throw std::out_of_range("Error. Empty stack.\n");
		}
	}

	void Clear() noexcept
	{
		while (m_top != NULL)
		{
			Component* tempTop = m_top;
			m_top = m_top->next;
			delete tempTop;
		}
	}

	CMyStack& operator=(CMyStack const& other)
	{
		if (std::addressof(&other) != std::addressof(this))
		{
			CMyStack newStack(other);

			std::swap(m_top, newStack.m_top);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other) noexcept
	{
		if (std::addressof(&other) != std::addressof(this))
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