#include <iostream>
#include <sstream>  

using namespace std;


namespace itertools{

	template <typename C1, typename C2> // templates for the 1st container(range1) and 2nd container(range2)
	class product{
	public:
	C1 c1;
	C2 c2;
	
	product<C1,C2>(const C1 r1, const C2 r2) : c1(r1), c2(r2) {} // constructor 

	class iterator{

	private:
	typename C1::iterator i1; 
	typename C2::iterator i2; 
	typename C2::iterator i3; 
	bool flag;

	public:
	

	iterator(typename C1::iterator c_1, typename C2::iterator c_2,typename C2::iterator c_3) : i1(c_1), i2(c_2), i3(c_3) { flag=true;} // constructor of the iterator   

	auto operator*() const{
	ostringstream o;
  	o << *i1  << ',' << *i2;   
	return o.str(); 
	}

	iterator& operator++(){//++i
	//i1++; 
	i2++; 
	return *this;	
	}
	
	
	const iterator operator++(int){//i++
	iterator tmp=*this;
	//i1++;
	//i2++;
	return tmp;	
	}
	
	
	bool operator==(const iterator& other)const {
		return (i1 == other.i1);
	}
	 
	bool operator!=(const iterator& other)  {
	if (flag)	{
		if (i1 == other.i1) return false;
			else
			 if (i2 == other.i2) { i1++; i2=i3; if (i1 == other.i1){flag=false;return false;}}
					else return true;
						return true;
		}
		else
			return false;
	}

		};// end class
	
		iterator begin(){
		return product<C1,C2>::iterator(c1.begin(), c2.begin(),c2.begin()); 
		}
		
		iterator end(){
		return product<C1,C2>::iterator(c1.end(), c2.end(), c2.begin());
		}
	

	}; // end main class

}
// end namespace
