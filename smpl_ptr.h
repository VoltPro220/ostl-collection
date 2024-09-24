#pragma once


namespace ostl
{
	template<typename T>
	class smpl_ptr
	{
		T* obj;
	public:
		smpl_ptr(T* obj)
		{
			this->obj = obj;
		}
		~smpl_ptr()
		{
			delete this->obj;
		}
		T& operator* ()
		{
			return *obj;
		}
		T& operator[] (int index)
		{
			return obj[index];
		}
	};	
}

