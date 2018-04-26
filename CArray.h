#pragma once
#define CAP_INDEX 1.5

template <class _T>
class CArray
{
private:
	_T *Elem;
	unsigned int _size;
	unsigned int _capasity;
public: // Interface

		// Конструктор по умолчанию
	CArray();

	CArray(
		unsigned int _size
	);

	// Копирующий конструктор
	//CArray(
	//	const CArray & _array
	//);

	void operator= (
		const CArray<_T> & object
	);

	// Деструктор
	~CArray();

	//Заполнить массив
	void fill(unsigned int _n, _T _data);

	_T* getData();

	// Добавить элемент в конец массива
	//void push_back(
	//	const _T & _value
	//);

	// Добавить элемент в массив по заданному индексу
	//void insert(
	//	unsigned int  _index,
	//	const _T & _value
	//);

	// Удалить элемент массива по заданному индексу
	//void erase(
	//	unsigned int _index
	//);

	// Очистить массив
	void clear();

	// Получить размер массива
	unsigned int size() const;

	// Получить элемент массива по заданному индексу
	_T & operator[](
		unsigned int _index
		);

protected: // Attributes

};

template<class _T>
inline CArray<_T>::CArray()
{
	Elem = nullptr;
}

template<class _T>
inline CArray<_T>::CArray(unsigned int _size)
{
	Elem = new _T[_size];
	this->_size = _size;
	_capasity = _size*CAP_INDEX;
}

template<class _T>
void CArray<_T>::operator=(const CArray<_T> & object)
{
	if (Elem)
		delete[] Elem;
	_size = object._size;
	_capasity = object._capasity;
	Elem = new _T[_size];
	for (size_t i = 0;i < _size; ++i)
	{
		*(Elem+i) =  *(object.Elem+i);
	}
	//for (size_t i = 0; *(object.Elem + i) != '\0'; ++i)
	//{
	//	*(Elem + i) = *object.Elem + i;
	//}
}

template<class _T>
inline CArray<_T>::~CArray()
{
	if (Elem)
		delete[] Elem;
}

template<class _T>
void CArray<_T>::fill(unsigned int _n, _T _data)
{
	for (size_t i = 0; i < _n; ++i)
		*(Elem + i) = _data;
}

template<class _T>
_T* CArray<_T>::getData()
{
	return Elem;
}

template<class _T>
inline void CArray<_T>::clear()
{
	if (Elem)
	{
		delete[] Elem;
		Elem = nullptr;
		_size = 0;
		_capasity = 0;
	}
		
}

template<class _T>
inline unsigned int CArray<_T>::size() const
{
	return _size;
}

template<class _T>
inline _T & CArray<_T>::operator[](unsigned int _index)
{
	return *(Elem + _index);
}
