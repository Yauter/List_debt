#include "crypto_utils.h"
#include "logger.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

namespace {

void xorBuf(std::string& buf, char key)
{
    std::transform(buf.begin(), buf.end(), buf.begin(),
                   [key](char c){ return c ^ key; });
}

} 

void CryptoUtils::saveEncrypted(const std::string& file,
                                const std::vector<Customer>& data,
                                char key)
{
    std::ostringstream oss;
    for (const auto& c : data)
        oss << c.toString() << '\n';

    std::string buf = oss.str();
    xorBuf(buf, key);

    std::ofstream ofs(file, std::ios::binary);
    ofs.write(buf.data(), static_cast<std::streamsize>(buf.size()));
}

std::vector<Customer> CryptoUtils::loadEncrypted(const std::string& file,
                                                 char key)
{
    std::ifstream ifs(file, std::ios::binary);
    std::ostringstream tmp;
    tmp << ifs.rdbuf();
    std::string buf = tmp.str();
    xorBuf(buf, key);

    std::istringstream iss(buf);
    std::vector<Customer> vec;
    Customer c;
    while (iss >> c)
        vec.push_back(c);

    return vec;
}
