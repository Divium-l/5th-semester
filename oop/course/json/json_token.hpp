#include <string>
#include <memory>

namespace json {
    enum JsonTokenType {
        String,
        Number,
        Boolean,
        Array,
        Object,
        Null
    };

    struct JsonToken {
        std::wstring value;
        JsonTokenType type;
        int location;
        std::shared_ptr<std::wstring> full_source;
    };
}
