#include "qt5lexer.h"

Qt5Lexer::Qt5Lexer()
{

}

bool Qt5Lexer::generate_tokens(std::string expression_string) {
    if(!this->token_generator.process(expression_string)) {
        qDebug("%s", expression_string.c_str());
        return false;
    } else {
        this->clear_container();
        for(int i = 0; i < this->token_generator.size(); i++) {
            token_t token = this->token_generator[i];
            this->define_token(token.value);
        }
        return true;
    }
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
