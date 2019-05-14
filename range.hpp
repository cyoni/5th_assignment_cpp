#include <iostream>
using namespace std;

namespace itertools{


	template <typename T>
	class range{
		
	public:
	T number1;
	T number2;
	
	range<T>(const T a, const T b) : number1(a),number2(b){}
	
	T start(){return number1;}
	T finish(){return number2;}
	
	class iterator{
	private:
	 T current;
	
	public:
	iterator(T set_first):current(set_first){}
	

	T operator*() const { // points to the current number
	return current;
	}

	T* operator->() const{
		// ?? 	FIXME
	}

	iterator& operator++(){//++i
	current++;
	return *this;	
	}
	
	const iterator operator++(int){//i++
	iterator tmp=*this;
	(current)++;
	return tmp;	
	}
	
	bool operator==(const iterator& sec_inter) const{
		return (current==sec_inter.current);
	}
	
	bool operator!=(const iterator& sec_inter) const{
		return (current != sec_inter.current);
	}
	
};

	iterator begin(){
	return range<T>::iterator(number1); // go to the iterator of range and not somewhere else
	}
	
	iterator end(){
	return range<T>::iterator(number2);	
	}
	
			}; // end range class
			

						
		}// end namespace
