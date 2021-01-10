// my_string.cpp
#include <iostream>
#include "my_string.h"
#include "my_sstream.h"

// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods

// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {}
//   rule of "3"
//     my_string copy constructor
my_string::my_string(const my_string& other):_data(nullptr),_capacity(other._capacity),_size(other._size){
    _data = new char[_capacity];
    for(size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}
//     my_string copy assignment
	my_string& my_string::operator=(const my_string& rhs)	
{	
    if(this != &rhs)	
    {	
        _capacity = rhs._capacity;	
        delete[] _data;
        char* newArray = new char[_capacity];	
        for(size_t i = 0; i < rhs._size; ++i)	
        {	
            newArray[i] = rhs._data[i];	
        }	
        _size = rhs._size;	
        _data = newArray;
    }	
    return *this;	
}

//     destructor
my_string::~my_string()
{
    delete[] _data;
    _size = 0;
    _capacity = 0;
}
//   c-string copy constructor
my_string::my_string(const char* other):_data(nullptr),_capacity(0),_size(0)
{
    size_t size = 0;
    while(other[size] != '\0')
    {
        ++size;
    }
    char* newArray = new char[size];
    for(size_t i = 0; i < size; ++i)
    {
        newArray[i] = other[i];
    }
    _data = newArray;
    _capacity = size;
    _size = size;
}
my_string& my_string::operator=(const char* other)
{
    size_t size = 0;
    while(other[size] != '\0')
    {
        ++size;
    }
    char* newArray = new char[size];
    for(size_t i = 0; i < size; ++i)
    {
        newArray[i] = other[i];
    }
    delete[] _data;
    _data = newArray;
    _capacity = size;
    _size = size;
    return *this;
}

// element access
//   at
const char& my_string::at(size_type index) const
{
    if(index >= _size)
    {
        throw std::invalid_argument("Out of bounds");
    }
    return _data[index];
}
char& my_string::at(size_type index)
{
    if(index >= _size)
    {
        throw std::invalid_argument("index out of bounds");
    }
    return _data[index];
}
//   front
const char& my_string::front() const{

    return _data[0];
}
char& my_string::front(){
    return _data[0];
}

//   operator[]
const char& my_string::operator[](size_type index) const
{
    if(index >= _size)
    {
        throw std::invalid_argument("index out of bounds");
    }
    return _data[index];
}
char& my_string::operator[](size_type index)
{
    if(index >= _size)
        {
            throw std::invalid_argument("index out of bounds");
        }
    return _data[index];
}
// capacity
size_t my_string::capacity() const{
    return _capacity;   

}
bool my_string::empty() const
{
    return _size == 0;
}
size_t my_string::size() const
{
    return _size;
}

//   empty
//   size

// operations
//   concatenation
//     my_string + my_string (non-member, friend)
my_string operator+(my_string lhs, const my_string& rhs)
{
   char* newArray = new char[lhs._size + rhs._size];
   for(size_t i = 0; i < lhs._size; ++i)
   {
       newArray[i] = lhs[i];
   }
   for(size_t i = 0; i < rhs._size; ++i)
   {
       newArray[i+lhs._size] = rhs._data[i];
   }
   delete[] lhs._data;
   lhs._size += rhs._size;
   lhs._capacity = lhs._size;
   lhs._data = newArray;
   return lhs;
}
//     my_string + c-string (non-member, friend)
my_string operator+(my_string lhs, const char* rhs)
{
    size_t charSize = 0;
    while(rhs[charSize] != '\0')
    {
        charSize++;
    }
    char* newArray = new char[lhs._size + charSize];
    for(size_t i = 0; i < lhs._size; ++i){
       newArray[i] = lhs[i];
    }
    for(size_t i = 0; i < charSize; ++i)
    {
        newArray[lhs._size+i] = rhs[i];
    }
    delete[] lhs._data;
    lhs._data = newArray;
    lhs._size += charSize;
    lhs._capacity = lhs._size;
    return lhs;
}
//     my_string + char (non-member, friend)
my_string operator+(my_string lhs, char rhs)
{
    char* newArray = new char[lhs._size + 1];
    for(size_t i = 0; i < lhs._size; ++i)
    {
       newArray[i] = lhs[i];
    }
    newArray[lhs._size] = rhs;
    lhs._size++;
    lhs._capacity = lhs._size;
    delete[] lhs._data;
    lhs._data = newArray;
    return lhs;
}

//     c-string + my_string (non-member, friend)
my_string operator+(const char* lhs, const my_string& rhs){
    size_t charSize = 0;
    while(lhs[charSize] != '\0')
    {
        charSize++;
    }
    char* newArray = new char[rhs._size + charSize];
    my_string newString;
    delete[] newString._data;
    for(size_t i = 0; i < charSize; ++i)
    {
        newArray[i] = lhs[i];
    }
    for(size_t i = 0; i < rhs._size; ++i)
    {
        newArray[charSize + i] = rhs[i];
    }
    newString._data = newArray;
    newString._capacity = rhs._size + charSize;
    newString._size = newString._capacity;
    return newString;
 }
//     char + my_string (non-member, friend)
my_string operator+(char lhs, my_string rhs)
{
    char* newArray = new char[rhs._size + 1];
    newArray[0] = lhs;
    for(size_t i = 0; i < rhs._size; ++i)
    {
       newArray[i+1] = rhs[i];
    }
    rhs._size++;
    rhs._capacity = rhs._size;
    delete[] rhs._data;
    rhs._data = newArray;
    return rhs;
}
//my_string += my_string
my_string& my_string::operator+=(const my_string& rhs)
{
   char* newArray = new char[_size + rhs._size];
   for(size_t i = 0; i < _size; ++i)
   {
       newArray[i] = _data[i];
   }
   for(size_t i = 0; i < rhs._size; ++i)
   {
       newArray[i+_size] = rhs[i];
   }
   delete[] _data;
   _size += rhs._size;
   _capacity = _size;
   _data = newArray;
   return *this;

}
//     my_string += c-string
my_string& my_string::operator+=(const char* rhs)
{
    size_t charSize = 0;
    while(rhs[charSize] != '\0')
    {
        charSize++;
    }
    char* newArray = new char[_size + charSize];
    for(size_t i = 0; i < _size; ++i)
    {
        newArray[i] = _data[i];
    }
    for(size_t i = 0; i < charSize; ++i)
    {
        newArray[_size+i] = rhs[i];
    }
    _size += charSize;
    _capacity = _size;
    delete[] _data;
    _data = newArray;
    return *this;
}
//     my_string += char
my_string& my_string::operator+=(const char rhs)
{
    char* newArray = new char[_size+1];
    for(size_t i = 0; i < _size; ++i)
    {
        newArray[i] = _data[i];
    }
    newArray[_size] = rhs;
    _size++;
    _capacity++;
    delete[] _data;
    _data = newArray;
    return *this;
}
my_string my_string::substr(size_t start, size_t end)
{
    my_string copy = *this;
    if(start > end)
    {
        throw std::invalid_argument("Invalid argument, start is greater than end");
    }
    if(start == end)
    {
        return "";
    }
    char* newArray = new char[end-start];
    copy._size = end-start;
    copy._capacity = _size;
    for(size_t i = 0; i < end-start; ++i)
    {
        newArray[i] = _data[start+i];
    }
    delete[] copy._data;
    copy._data= newArray;
    return copy;
}

// search
//   find

// non-member functions
//   relational operators
//     my_string == my_string
bool operator==(const my_string& lhs, const my_string& rhs)
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    for(size_t i = 0; i < lhs.size(); ++i)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}
//     my_string == c-string
bool operator==(const my_string& lhs, const char* rhs)
{
    size_t charSize = 0;
    while(rhs[charSize] != '\0')
    {
        charSize++;
    }
    if(lhs.size() != charSize)
    {
        return false;
    }
    for(size_t i = 0; i < charSize; ++i)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}
my_string to_string(int val)
{
  int numClone = val;
  size_t indices = 0;
  while(numClone != 0)
  {
    numClone /= 10;
    indices++;
  }
  char* newArray = new char[indices+1];
  size_t index = 0;
  while(val != 0)
  {
    newArray[indices-index-1] = val % 10 + '0';
    val/= 10;
    index++;
  }
  newArray[index] = '\0';
  index = 0;
  while(newArray[index] != '\0')
  {
      std::cout << newArray[index];
      index++;
  }
  std::cout << std::endl;

  my_string newOne(newArray);
  delete[] newArray;
  return newOne;
}
//   stream operators
//     ostream instertion operator
std::ostream& operator<<(std::ostream& os, const my_string& str)
{
    for(size_t i = 0; i < str.size(); ++i)
    {
        os << str.at(i);
    }
    return os;
}
std::istream& operator>>(std::istream& os, my_string& str)
{
    char input;

    str = "";
    while(os.get(input))
    {
        if(input == ' ' || input == '\n')
        {
            break;
        }
        else{
            str += input;
        }

     
    }
    return os;
}
/*std::istream& getline(std::istream& is, my_string& str, char delim='\n')
{
    char stuff;
    str = "";
    is >> stuff;
    while(stuff != delim)
    {
        str+= stuff;
        is >> stuff;
    }
    std::cout << str << std::endl;
    return is;
} */
//     istream extraction operator
//     getline
//   numeric conversions
//     to_string


// my_istringstream methods

my_istringstream::my_istringstream(const my_string& str) : _str(str), idx(0), state_fail(false), state_eof(str.empty()) {}

void my_istringstream::eat_whitespaces() {
    while (idx < _str.size() && isspace(_str[idx])) {
        idx++;
    }
}

my_istringstream& my_istringstream::operator>>(my_string& str) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    my_string s;
    while (idx < _str.size() && !isspace(_str[idx])) {
        s += _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    str = s;
    return *this;
}

my_istringstream& my_istringstream::operator>>(char& c) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    if (idx < _str.size()) {
        c = _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    return *this;
}

bool my_istringstream::good() const { return !(state_fail || state_eof); }
bool my_istringstream::fail() const { return state_fail; }
bool my_istringstream::eof() const { return state_eof; }

// TODO(student): define other my_istringstream methods, if any
