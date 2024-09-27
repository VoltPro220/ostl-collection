#pragma once

#ifndef _OVECTOR_H_
#include"ovector.h"
#define _OVECTOR_H_
#endif

#ifndef _OUT_OF_RANGE_H_
#include"out_of_range.h"
#define _OUT_OF_RANGE_H_
#endif // !_OUT_OF_RANGE_H_


namespace ostl
{
	template<typename T>
	class forward_list
	{
	public:
		forward_list()
		{
			this->size = 0;
			this->head = nullptr;
		}

		ostl::size_t get_length()
		{
			return this->size;
		}

		void push_back(T value)
		{
			if(head == nullptr)
				head = new Node<T>(value);
			else
			{
				Node<T>* current = this->head;
				while(current->next != nullptr)
				{
					current = current->next;
				}
				current->next = new Node<T>(value);
			}

			this->size++;
		}

		void insert(T value, ostl::size_t index)
		{
			if(index < 0 || index >= this->size)
				throw out_of_range("Index out of range exception");
			if(index == 0)
				this->push_front(value);
			else
			{
				Node<T>* pre = this->head;
				for(size_t i = 0; i < index - 1; i++)
				{
					pre = pre->next;
				}
				pre->next = new Node<T>(value, pre->Next);
				this->size++;
			}
		}

		void push_front(T value)
		{
			this->head = new Node<T>(value, this->head);
			this->size++;	
		}

		void pop_front()
		{
			Node<T>* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
			this->size--;
		}

		void pop_back()
		{
			this->removeAt(this->size - 1);
		}

		void removeAt(ostl::size_t index)
		{
			if(index < 0 || index >= this->size)
				throw out_of_range("Index out of range exception");
			if(index == 0)
			{
				this->pop_front();
			}
			else
			{
				Node<T>* pre = this->head;
				for(size_t i = 0; i < index - 1; i++)
				{
					pre = pre->next;
				}
				Node<T>* del = pre->next;
				pre = del->next;
				delete del;
				this->size--;
			}


		}

		void clear()
		{
			while(this->size)
				this->pop_front();
		}


		T& operator[](ostl::size_t index)
		{
			ostl::size_t tmp = 0;
			Node<T>* current = this->head;
			while(current != nullptr)
			{
				if(tmp == index)
					return current->value;
				current = current->next;
				tmp++;
			}
		}

		~forward_list()
		{
			this->clear();
		}

	private:
		template<typename T>
		class Node
		{
		public:
			Node(T value = T(), Node* ptr = nullptr)
			{
				this->next = ptr;
				this->value = value;
			}
			Node* next;
			T value;
		};
		ostl::size_t size;
		Node<T>* head;

	};

}