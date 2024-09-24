#pragma once

#ifndef _IOREXCEPTION_H_
#include "IndexOutOfRangeException.h"
#define _IOREXCEPTION_H_
#endif // !_INDEXOUTOFRANGEEXCEPTION_H_

namespace ostl
{
#ifdef _WIN64
	typedef unsigned __int64 size_t;
#else
	typedef unsigned int     size_t;
#endif

	template<typename T>
	class vector
	{
		T* arr;
		ostl::size_t size;
	public:
		inline __cdecl vector(void)
		{
			this->size = 0;
			this->arr = new T[this->size];
		}

		ostl::size_t get_length(void)
		{
			return this->size;
		}

		T& operator[] (ostl::size_t index)
		{
			return *(arr + index);
		}

		T& at(int index)
		{
			if(index < 0 || index >= this->size)
				throw ostl::IndexOutOfRangeException((char*)"Index out of range exception");
			return this->arr[index];
		}

		void push_back(T value)
		{
			T* tmp = new T[this->size + 1];
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i];
			}
			tmp[this->size++] = value;
			delete[] this->arr;
			this->arr = tmp;
		}

		void push_front(T value)
		{
			T* tmp = new T[this->size + 1];
			tmp[0] = value;
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i + 1] = this->arr[i];
			}
			++this->size;
			delete[] this->arr;
			this->arr = tmp;
		}

		void insert(T value, ostl::size_t index)
		{
			T* tmp = new T[this->size + 1];
			for(size_t i = 0; i < index; i++)
			{
				tmp[i] = this->arr[i];
			}
			tmp[index] = value;
			for(size_t i = index; i < this->size; i++)
			{
				tmp[i + 1] = this->arr[i];
			}
			++this->size;
			delete[] this->arr;
			this->arr = tmp;
		}

		void pop_back(void)
		{
			T* tmp = new T[--this->size];
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = tmp;
		}

		void pop_front(void)
		{
			T* tmp = new T[--this->size];
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i + 1];
			}
			delete[] this->arr;
			this->arr = tmp;
		}

		void erase(ostl::size_t index)
		{
			T* tmp = new T[--this->size];
			for(size_t i = 0; i < index; i++)
			{
				tmp[i] = this->arr[i];
			}
			for(size_t i = index; i < this->size; i++)
			{
				tmp[i] = this->arr[i + 1];
			}
			delete[] this->arr;
			this->arr = tmp;
		}

		inline __cdecl ~vector(void)
		{
			delete[] this->arr;
			this->size = 0;
		}

		bool check(ostl::size_t index, T& var)
		{
			if(index >= 0 && index < this->size)
			{
				var = this->arr[index];
				return true;
			}
			return false;
		}
		bool check(ostl::size_t index)
		{
			if(index >= 0 && index < this->size)
				return true;
			return false;
		}

		int find(T value)
		{
			for(size_t i = 0; i < this->size; i++)
			{
				if(this->arr[i] == value)
					return i;
			}
			return -1;
		}

		void clear()
		{
			delete[] this->arr;
			this->arr = new T[this->size];
		}

		void remove()
		{
			delete[] arr;
			this->size = 0;
		}

		void reverse(ostl::size_t length)
		{
			T* tmp = new T[length];
			for(size_t i = 0; i < this->size && i < length; i++)
			{
				tmp[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = tmp;
			this->size = length;
		}

	};

	template<typename T>
	std::ostream& operator << (std::ostream& os, ostl::vector<T>& vref)
	{
		for(size_t i = 0; i < vref.get_length(); i++)
		{
			os << vref.at(i) << std::endl;
		}
		return os;
	}


};