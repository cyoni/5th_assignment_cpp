#include <iostream>
using namespace std;


namespace itertools{

	template <typename C1> // templates for the 1st container(range1) and 2nd container(range2)
	class powerset{
	public:

	C1 c1;
	
	
	powerset<C1>(const C1 r1) : c1(r1) {} // constructor 

	
	class const_iterator{

	public:
	typename C1::const_iterator i1;
	 
	const_iterator(typename C1::const_iterator r_1) : i1(r_1) {} // constructor of the iterator   

	auto operator*() const{ 
	return *i1;
	}

	const_iterator& operator++(){//++i   !!
	i1++;
	return *this;	
	}
	
	const const_iterator operator++(int){//i++
	iterator tmp=*this;
	i1++;
	return tmp;	
	}
	
	bool operator==(const const_iterator& other) const{
		return (i1 == other.i1);
	}
	
	bool operator!=(const const_iterator& other) {
		return (i1 != other.i1);
	}

		};// end class
	
		const_iterator begin() const {
		return powerset<C1>::const_iterator(c1.begin());
		}
		
	    const_iterator end() const {
		return powerset<C1>::const_iterator(c1.end());
		}
	
	}; // end main class

}
// end namespace