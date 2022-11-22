#include <string>
#include <fstream>

class serializable {
public:
    virtual void serialize(std::wstring path) const = 0;
    virtual void deserialize(std::wstring path) = 0;
};