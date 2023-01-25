#pragma once
#include "pch.h"

enum token_type
{
    tok_semicolon,
    tok_keyword,
    tok_identifier,
    tok_equals,
    tok_integer,
    tok_float,
    tok_lparen, tok_rparen,
    tok_quotation,
};

typedef std::pair<token_type, std::string> token;

class lexer
{
public:
    static std::vector<token> tokenize(std::string source)
    {
        std::vector<token> tokens;

        std::vector<std::string> lines;
        std::string current_token = "";
        char last_char = ' ';
        bool is_float = false;
        for (char& current_char : source)
        {
            if (current_char == '\n' || (isspace(current_char) && isspace(last_char)))
                continue;

            if (isalpha(current_char))
            {
                current_token += current_char;
            }
            else if (isdigit(current_char) || current_char == '.')
            {
                current_token += current_char;
                if (current_char == '.')
                    is_float = true;
            }
            else if (!current_token.empty())
            {
                if (isalpha(current_token[0]))
                {
                    if (current_token == "int"
                     || current_token == "float")
                        tokens.push_back({ tok_keyword, current_token });
                    else
                        tokens.push_back({ tok_identifier, current_token });
                }
                else if (isdigit(current_token[0]) || current_token[0] == '.')
                {
                    if (is_float)
                        tokens.push_back({ tok_float, current_token });
                    else
                        tokens.push_back({ tok_integer, current_token });
                    
                    is_float = false;
                }
                
                current_token = "";
            }

            if (current_char == '=')
                tokens.push_back({ tok_equals, "=" });
            
            if (current_char == '(')
                tokens.push_back({ tok_lparen, "(" });

            if (current_char == ')')
                tokens.push_back({ tok_lparen, ")" });

            if (current_char == '\"')
                tokens.push_back({ tok_quotation, "\"" });

            if (current_char == ';')
                tokens.push_back({ tok_semicolon, ";" });

            last_char = current_char;
        }

        for (token& tok : tokens)
        {
            switch (tok.first)
            {
                case tok_semicolon:
                    std::cout << "semicolon";
                    break;
                case tok_identifier:
                    std::cout << "identifier";
                    break;
                case tok_equals:
                    std::cout << "equals";
                    break;
                case tok_integer:
                    std::cout << "integer";
                    break;
                case tok_float:
                    std::cout << "float";
                    break;
                case tok_lparen:
                    std::cout << "lparen";
                    break;
                case tok_rparen:
                    std::cout << "rparen";
                    break;
                case tok_quotation:
                    std::cout << "quotation";
                    break;
            }
            std::cout << " : " << tok.second << "\n";
        }

        return tokens;
    }
private:
    static int get_token()
    {
        return 0;
    }
};