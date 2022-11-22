#include "json.hpp"

namespace json {
    std::tuple<std::vector<JsonToken>, std::wstring> lex(std::wstring raw_json) {
        std::vector<JsonToken> tokens;
        auto original_copy = std::make_shared<std::wstring>(raw_json);
        
        auto generic_lexers = {lex_syntax, lex_number, lex_null, lex_true, lex_false};
        for (int i = 0; i < raw_json.length(); i++) {
            if (auto new_index = lex_whitespace(raw_json, i) ; i != new_index) {
                i = new_index - 1;
                continue;
            }

            auto found = false;
            for (auto lexer: generic_lexers) {
                if (auto [token, new_index, error] = lexer(raw_json, i); i != new_index) {
                    if (error.length()) {
                        return {{}, error};
                    }
                }

                tokens.full_source = original_copy;
                tokens.push_back(token);
                i = new_index - 1;
                found = true;
                break;
            }

            if (found) {
                continue;
            }

            return {{}, format_error("Unable to lex", raw_json, i)}
        }

        return {tokens, ""};
    }

}