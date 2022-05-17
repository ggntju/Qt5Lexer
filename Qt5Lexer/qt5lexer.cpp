#include "qt5lexer.h"

Qt5Lexer::Qt5Lexer()
{

}

bool Qt5Lexer::generate_tokens(std::string expression_string) {
    if(!this->token_generator.process(expression_string)) {
        qDebug("%s", expression_string.c_str());
        return false;
    } else {
        this->expression_string = expression_string;
        this->clear_container();
        for(int i = 0; i < this->token_generator.size(); i++) {
            token_t token = this->token_generator[i];
            this->define_token(token.value);
        }
        return true;
    }
}

double Qt5Lexer::evaluate(std::unordered_map<std::string, double> token_value_map) {
    this->symbol_table.clear();
    for(auto&[token, value] : token_value_map) {
        if(this->token_container.contains(token)) {
            this->symbol_table.add_variable(token, value);
            this->symbol_table.add_constants();
        } else {
            return std::numeric_limits<double>::max();
        }
    }
    this->exp_expression.reset(new expression_t());
    this->exp_expression->register_symbol_table(symbol_table);
    this->exp_parser.compile(this->expression_string, *this->exp_expression.get());
    return this->exp_expression->value();
}

int Qt5Lexer::tokens_size() {
    return this->token_container.size();
}

void Qt5Lexer::clear_container() {
    this->token_container.clear();
}

void Qt5Lexer::define_token(std::string token) {
    if(!this->token_container.contains(token)) {
        this->token_container.push_back(token);
    }
}

bool Qt5Lexer::remove_token(std::string token) {
    return this->token_container.removeOne(token);
}

bool Qt5Lexer::contains_token(std::string token) {
    return this->token_container.contains(token);
}
