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

	class const_iterator{

	private:
	typename C1::const_iterator i1; 
	typename C2::const_iterator i2; 
	typename C2::const_iterator i3;
	int c; 
	bool FirstTime;
	bool flag;

	public:
	

	const_iterator(typename C1::const_iterator c_1, typename C2::const_iterator c_2,typename C2::const_iterator c_3) : i1(c_1), i2(c_2), i3(c_3) {c=0;FirstTime=true; flag=true;} // constructor of the const_iterator   

	auto operator*() const{
	ostringstream o;
  	o << *i1  << ',' << *i2;   
	return o.str(); 
	}

	const_iterator& operator++(){//++i
	//i1++; 
	i2++; 
	return *this;	
	}
	
	
	const const_iterator operator++(int){//i++
	const_iterator tmp=*this;
	//i1++;
	//i2++;
	return tmp;	
	}
	
	
	bool operator==(const const_iterator& other)const {
		return (i1 == other.i1);
	}
	 
	bool operator!=(const const_iterator& other)  {
		if (c>100) return false;
		c++;
	if (FirstTime && i2 == other.i2) flag=false;
	FirstTime=false;
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
	
		const_iterator begin() const{
		return product<C1,C2>::const_iterator(c1.begin(), c2.begin(),c2.begin()); 
		}
		
		const_iterator end() const{
		return product<C1,C2>::const_iterator(c1.end(), c2.end(), c2.begin());
		}
	

	}; // end main class

}
// end namespace