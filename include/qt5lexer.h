#ifndef QT5LEXER_H
#define QT5LEXER_H

#include "Qt5Lexer_global.h"

typedef exprtk::symbol_table<double> symbol_table_t;

typedef exprtk::expression<double>   expression_t;

typedef exprtk::parser<double>       parser_t;

typedef lexertk::generator token_generator_t;

typedef lexertk::generator::token_t token_t;

class QT5LEXER_EXPORT Qt5Lexer
{

public:

    Qt5Lexer();

    bool generate_tokens(std::string expression_string);

    double evaluate(std::unordered_map<std::string, double> token_value_map);

    int tokens_size();

    void clear_container();

    void define_token(std::string token);

    bool remove_token(std::string token);

    bool contains_token(std::string token);

private:

    QVector<std::string> token_container;

    token_generator_t token_generator;

    symbol_table_t symbol_table;

    QSharedPointer<expression_t> exp_expression = QSharedPointer<expression_t>(new expression_t());

    parser_t exp_parser;

    std::string expression_string = "";
};

#endif // QT5LEXER_H
