#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <vector>
#include <string>
#include "customer.h"


namespace CryptoUtils {

void saveEncrypted(const std::string& file,
                   const std::vector<Customer>& data,
                   char key = '\x5A');

std::vector<Customer> loadEncrypted(const std::string& file,
                                    char key = '\x5A');

} 

#endif
