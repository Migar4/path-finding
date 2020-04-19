#ifndef VEC2_H
#define VEC2_H

#include <iostream>

template <class T>
class vec2 {

private:
	T x_val;
	T y_val;

public:
	vec2<T>();
	T getX() const;
	T getY() const;

	void setX(T _x);
	void setY(T _y);

	vec2(T x, T y);

	template<class T>
	friend vec2<T> operator+ (const vec2<T>& v1, const vec2<T>& v2);

	vec2<T>& operator=(const vec2<T>& v1);
	
	void print();
};


template<class T>
inline vec2<T>::vec2()
{
	x_val = (T)0;
	y_val = (T)0;
}


template<class T>
inline vec2<T>::vec2(T x, T y) :x_val(x), y_val(y)
{
}



template<class T>
inline T vec2<T>::getX() const
{
	return T(x_val);
}


template<class T>
inline T vec2<T>::getY() const
{
	return T(y_val);
}


template<class T>
inline void vec2<T>::setX(T _x)
{
	x_val = _x;
}


template<class T>
inline void vec2<T>::setY(T _y)
{
	y_val = _y;
}


template<class T>
inline void vec2<T>::print()
{
	std::cout << "( " << x_val << ", " << y_val << " )" << std::endl;
}


template<class T>
inline vec2<T> operator+ (const vec2<T> &v1, const vec2<T>& v2)
{
	return vec2<T>(T(v1.getX() + v2.getX()), T(v1.y_val + v2.y_val));
}



//something wrong here friend function wont work
template<class T>
inline vec2<T> operator-(const vec2<T>& v1, const vec2<T>& v2)
{
	return vec2<T>(T(v1.getX() - v2.getX()), T(v1.getY() - v2.getY()));
}

template<class T>
inline vec2<T>& vec2<T>::operator=(const vec2<T>& v1)
{
	x_val = v1.x_val;
	y_val = v1.y_val;

	return *this;
}

#endif
