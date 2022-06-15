
#ifndef _SCANNER_H_

#define _SCANNER_H_


#include <iostream>
#include <string>


///////////////////////////////
// TokenType
//         
//  symbols:  +, -, *, /, (, )
// literals:  integer
//  special:  eof, err
///////////////////////////////
typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }
TokenType ;


//---------//
//  Token  //
//---------//
class Token {
    public:
        TokenType tt;
        std::string text;
        int val;
};


// Desc: Display a Token
std::ostream &operator<<(std::ostream &lhs, Token &rhs);


// Desc: Token scanner.  Given an input stream, will return a sequence
//       of Tokens via successive calls to .getnext();
class Scanner {
    private:
        int line;
        std::istream *str;
        char buf[2];
    public:
        Scanner(std::istream &str);
        Token getnext();
};


#endif // _SCANNER_H_
