#include <iostream>

using namespace std;


namespace itertools{

	template <typename C1, typename C2> // templates for the 1st container(range1) and 2nd container(range2)
	class zip{
	public:

	C1 c1;
	C2 c2;


	zip<C1,C2>(const C1 r1, const C2 r2) : c1(r1), c2(r2) {} // constructor 

	
	class iterator{

	private:
	typename C1::iterator i1; 
	typename C2::iterator i2; 


	public:
	
	
	
	iterator(typename C1::iterator c_1, typename C2::iterator c_2) : i1(c_1), i2(c_2) {} // constructor of the iterator   

		
	auto operator*() const{
	ostringstream o;
  	o << *i1  << ',' << *i2;   
	return o.str(); 
	}

	iterator& operator++(){//++i
	i1++; 
	i2++; 
	return *this;	
	}
	
	
	const iterator operator++(int){//i++
	iterator tmp=*this;
	i1++;
	i2++;
	return tmp;	
	}
	
	
	bool operator==(const iterator& other)const {
		return (i1 == other.i1);
	}
	 
	bool operator!=(const iterator& other) const {
		return (i1 != other.i1);
	}
		//template <typename X, typename Y> 
	 // friend ostream& operator<< (ostream& , const typename zip<X,Y>::iterator ostringstream& );
		
		};// end class
	
		iterator begin(){
		return zip<C1,C2>::iterator(c1.begin(), c2.begin()); 
		}
		
		iterator end(){
		return zip<C1,C2>::iterator(c1.end(), c2.end());
		}
	
    	friend ostream& operator<< (ostream& os, const  ostringstream& o);

	}; // end main class

		
	//	ostream& operator<< (ostream& os, ostringstream& o) {
	//	string a = "";
	//	a = o.str();
	//	os << a;
	//	return os;	
	//	}	


}
// end namespace