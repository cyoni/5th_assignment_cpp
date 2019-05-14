#include <iostream>
using namespace std;


namespace itertools{

	template <typename C1, typename C2> // templates for the 1st container(range1) and 2nd container(range2)
	class chain{
	public:

	C1 range1;
	C2 range2;
	
	chain<C1,C2>(const C1 r1, const C2 r2) : range1(r1),range2(r2) {} // constructor 

	
	class iterator{

	public:
	
	typename C1::iterator i1; // to specify to the compiler that this is a type (of iterator of range) and not value								
	iterator(typename C1::iterator r_1) : i1(r_1) {} // constructor of the iterator   

	auto operator*() const{ 
	return *i1; // range1
	}

	//C1* operator->() const{
		// ?? 	FIXME
	//}

	iterator& operator++(){//++i
	i1++;
	return *this;	
	}
	
	const iterator operator++(int){//i++
	iterator tmp=*this;
	i1++;
	return tmp;	
	}
	
	bool operator==(const iterator& a) const{
		return (i1 == a.i1);
	}
	
	bool operator!=(const iterator& a) const{
		return (i1 != a.i1);
	}

		};// end class
	
		iterator begin(){
		return chain<C1,C2>::iterator(range1.begin()); // it gets an iterator from range class
		}
		
		iterator end(){
		return chain<C1,C2>::iterator(range1.end());
		}
	
	}; // end main class

}
// end namespace