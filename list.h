#pragma once

#ifndef _OUT_OF_RANGE_H_
#include "out_of_range.h"
#define _OUT_OF_RANGE_H_
#endif // !_OUT_OF_RANGE_H_

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
			Node<T>* nd = new Node<T>(value);
			if(this->head == nullptr)
				this->tail = nd;
			else
			{
				this->head->prev = nd;
				nd->next = this->head;
			}
			this->head = nd;

			this->size++;
		}

		void push_back(T value)
		{
			Node<T>* nd = new Node<T>(value);
			if(this->tail == nullptr)
				this->head = nd;
			else
			{
				this->tail->next = nd;
				nd->prev = this->tail;
			}
			this->tail = nd;

			this->size++;
		}

		void insert_after(unsigned int index, T value)
		{
			Node<T>* nd = this->head;
			int i = 0;
			while(i != index)
			{
				nd = nd->next;
				i++;
			}
			if(nd != nullptr)
			{
				Node<T>* nd2 = new Node<T>(value);
				if(nd == this->tail) this->tail = nd2;
				if(nd->next != nullptr) nd->next->prev = nd2;
				nd2->next = nd->next;
				nd->next = nd2;
				nd2->prev = nd;
			}
			this->size++;
		}

		void remove_at(unsigned int index)
		{
			if(index == 0)
			{
				this->pop_front();
				return;
			}
			else if(index == this->size - 1)
			{
				this->pop_back();
				return;
			}
			Node<T>* current = this->head;
			unsigned int i = 0;
			while(current != nullptr)
			{
				if(i == index)
				{
					if(current == this->head)
					{
						this->head = current->next;
						if(this->head != nullptr) this->head->prev = nullptr;
						else this->tail = nullptr;
					}
					else
					{
						current->prev->next = current->next;
						if(current->next != nullptr) current->next->prev = current->prev;
						else this->tail = current->prev;
					}
					break;
				}
				i++;
				current = current->next;
			}
			--this->size;
		}

		void pop_front()
		{
			if(this->head != nullptr)
			{
				Node<T>* del = this->head;
				this->head = this->head->next;
				delete del;
				--this->size;
			}
		}

		void pop_back()
		{
			if(this->tail != nullptr)
			{
				Node<T>* del = this->tail;
				this->tail = this->tail->prev;
				delete del;
				--this->size;
			}
		}

		T& at(unsigned int index)
		{
			if(index < 0 || index >= this->size)
				throw out_of_range((char*)"Index out of range exception");
			unsigned int tmp = 0;
			Node<T>* current = this->head;
			while(current != nullptr)
			{
				if(tmp == index)
					return current->value;
				current = current->next;
				tmp++;
			}
		}

		T& operator[](unsigned int index)
		{
			Node<T>* nd = this->head;
			unsigned int i = 0;
			while(nd != nullptr)
			{
				if(i == index) return nd->value;
				nd = nd->next;
				++i;
			}
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