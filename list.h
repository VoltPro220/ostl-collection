#pragma once

namespace ostl
{


	template<typename T>
	class list
	{
	public:
		list()
		{
			this->size = 0;
			this->head = nullptr;
			this->tail = nullptr;
		}
		unsigned int get_length()
		{
			return this->size;
		}

		void push_front(T value)
		{
			Node<T> nd = new Node<T>(value);
			if(this->head == nullptr)
				this->tail = nd;
			else
			{
				this->head->prev = nd;
				nd.next = head;
			}
			this->head = nd;

			this->size++;
		}

		void pop_front()
		{

		}

		void clear()
		{
			while(this->size)
				this->pop_front();
		}

		~list()
		{
			this->clear();
		}

	private:
		template<typename T>
		class Node
		{
		public:
			Node(T value = T(), Node* next = nullptr, Node* prev = nullptr)
			{
				this->next = next;
				this->prev = prev;
				this->value = value;
			}
			Node* next;
			Node* prev;
			T value;
		};
		Node<T>* head;
		Node<T>* tail;
		unsigned int size;
	};
}