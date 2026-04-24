#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
    char *data;
    size_t length;

    void allocate_and_copy(const char *src, size_t len) {
        length = len;
        data = new char[length + 1];
        if (src) {
            std::memcpy(data, src, length);
        }
        data[length] = '\0';
    }

public:
    str() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    str(const char &c) : data(nullptr), length(1) {
        data = new char[2];
        data[0] = c;
        data[1] = '\0';
    }

    str(const char *&& s_) : data(nullptr), length(0) {
        if (s_) {
            length = std::strlen(s_);
            data = new char[length + 1];
            std::memcpy(data, s_, length);
            data[length] = '\0';
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    str &operator=(const char *&& s_) {
        delete[] data;
        if (s_) {
            length = std::strlen(s_);
            data = new char[length + 1];
            std::memcpy(data, s_, length);
            data[length] = '\0';
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
        return *this;
    }

    str(const str &other) : data(nullptr), length(0) {
        allocate_and_copy(other.data, other.length);
    }

    str &operator=(const str &other) {
        if (this != &other) {
            delete[] data;
            allocate_and_copy(other.data, other.length);
        }
        return *this;
    }

    char &operator[](size_t pos) {
        return data[pos];
    }

    size_t len() const {
        return length;
    }

    str join(const std::vector<str> &strs) const {
        if (strs.empty()) {
            return str();
        }

        size_t total_length = 0;
        for (size_t i = 0; i < strs.size(); ++i) {
            total_length += strs[i].length;
            if (i > 0) {
                total_length += length;
            }
        }

        char *result = new char[total_length + 1];
        size_t pos = 0;

        for (size_t i = 0; i < strs.size(); ++i) {
            if (i > 0) {
                std::memcpy(result + pos, data, length);
                pos += length;
            }
            std::memcpy(result + pos, strs[i].data, strs[i].length);
            pos += strs[i].length;
        }
        result[total_length] = '\0';

        str result_str;
        delete[] result_str.data;
        result_str.data = result;
        result_str.length = total_length;

        return result_str;
    }

    str slice(size_t l, size_t r) const {
        if (l >= r || l >= length) {
            return str();
        }
        if (r > length) {
            r = length;
        }

        size_t slice_len = r - l;
        str result;
        delete[] result.data;
        result.data = new char[slice_len + 1];
        std::memcpy(result.data, data + l, slice_len);
        result.data[slice_len] = '\0';
        result.length = slice_len;

        return result;
    }

    ~str() {
        delete[] data;
    }
};