// 1. write a class String to operate character string in C++, 
// with constructors, comparation, assignment, and subscript operators;
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

class String{
public:
	char *sPtr;                                   // pointer to start
	String( const char * = "" );                  // default constructor
	String( const String & );                     // copy constructor
	~String();                                    // destructor
	String &operator=( const String & );          // assignment operator
	char operator[]( int ) ;                      // subscript operator
	String operator()( int, int = 0 );            // return a substring
	                                              // comparation operator:
	bool operator!() ;
	bool operator==( const String & ) ; 
	bool operator<( const String & ) ; 
	bool operator>( const String & ) ;
	bool operator!=( const String & );
	

private:
	int length;                                   // string length
	void setString( const char * );               // utility function
};



// default constructor
String::String( const char *s ) : length( ( s != 0 ) ? strlen( s ) : 0 ){
	setString( s ); 
}
// copy constructor
String::String( const String &copy ) : length( copy.length ) {
	setString( copy.sPtr );
}
// Destructor
String::~String(){
	delete [] sPtr;
}


 // overloaded = operator; avoids self assignment
String &String::operator=( const String &right)
{
	if ( &right != this )
	{
		delete [] sPtr;                         // prevents memory leak
		length = right.length;
		setString( right.sPtr );
	}
	else
		cout << "Attempted assignment of a String to itself" << endl;
	return *this;
}



bool String::operator!() {
	return length == 0;
}

bool String::operator!=( const String &right )
{
	return !( *this == right );
} 

bool String::operator==( const String &right )
{
	return strcmp( sPtr, right.sPtr ) == 0;
} 

bool String::operator<( const String &right )
{
	return strcmp( sPtr, right.sPtr ) < 0;
}
bool String::operator>( const String &right )
{
	return strcmp( sPtr, right.sPtr ) > 0;
}



char String::operator[]( int subscript )
{
	if( subscript< 0 || subscript >= length) {
		cout << "Out of range" << endl;
		exit(1);
	}
	return sPtr[ subscript ];
}


void String::setString( const char *string2 ){
	sPtr = new char[ length + 1 ];
	if ( string2 != 0 )
		strcpy( sPtr, string2 );
	else
		sPtr[0] = '\0';
}


String String::operator()( int index, int subLength )
{
	if ( index < 0 || index >= length || subLength < 0 )
	return "";
	int len;
	if ( ( subLength == 0 ) || ( index + subLength > length ) ) len = length - index;
	else
	   len = subLength;
	char *tempPtr = new char[ len + 1 ];
	strncpy( tempPtr, &sPtr[ index ], len ); tempPtr[ len ] = '\0';
	String tempString( tempPtr );
	delete [] tempPtr; 
	return tempString; 
}


ostream &operator<<(ostream &output, const String &s)
{
	output << s.sPtr;
	return output; 
} 


#endif