#include <iostream>
#include <vector>

class Str{

friend std::istream& operator>>(std::istream&, Str&);

private:
    std::vector<char> data;

public:
    // default
    Str(){}

    Str(size_t n, char c) : data(n,c){}
    
    Str(const char* cp){
        std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
    }
    
    template <class In> Str(In b, In e){
        std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_t i){
        return data[i];
    }
    
    const char& operator[](size_t i) const{
        return data[i];
    }
    
    size_t size() const{
        return data.size();
    }

    Str& operator+=(const Str& s){
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }

};

// non-member function due to the nature of calling on Str object
std::ostream& operator<<(std::ostream& os, const Str& s){
    for(size_t i = 0; i!=s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s){
    // clear existing values
    s.data.clear();

    char c;
    while(is.get(c) && isspace(c))
        ;   // nothing to do except test the condition

    // if still something to read, do so until next whitespace character
    if(is){
        do{
            s.data.push_back(c);
        }while(is.get(c) && !isspace(c));

        // if we read whitespace, then put it back on the stream
        if(is)
            is.unget();
    }
    return is;
}

Str operator+(const Str& s, const Str& t){
    Str r = s;
    r += t;
    return r;
}

int main(){
    Str s = "hello";
    Str t = " world";
    Str u = s + t;
    std::cout << u << std::endl;
    return 0;
}
