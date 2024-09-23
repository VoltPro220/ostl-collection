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
		__cdecl vector(void)
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
			return arr[index];
		}
		T& at(int index)
		{
			if(index < 0 || index >= this->size)
				throw ostl::IndexOutOfRangeException((char*)"Index out of range exception");
			return arr[index];
		}
		void push_back(T value)
		{
			T* tmp = new T[this->size + 1];
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i];
			}
			tmp[this->size++] = value;
			delete[] arr;
			arr = tmp;

		}
		void pop_back(void)
		{
			T* tmp = new T[--this->size];
			for(size_t i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i];
			}
			delete[] arr;
			arr = tmp;
		}
		__cdecl ~vector(void)
		{
			delete[] arr;
		}



	};

};