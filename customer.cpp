#include "customer.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>

bool Customer::isValidCard(int c)     { return c >= 1000 && c <= 9999; }
bool Customer::isValidAccount(int a)  { return a >= 10000 && a <= 99999; }


Customer::Customer(int id,
                   std::string surname,
                   std::string name,
                   int cardNumber,
                   int bankAccount)
    : id_(id),
      surname_(std::move(surname)),
      name_(std::move(name))
{
    setCardNumber(cardNumber);
    setBankAccount(bankAccount);
}


void Customer::setId(int id)                 { id_ = id; }
int  Customer::id() const                    { return id_; }
void Customer::setSurname(const std::string& s){ surname_ = s; }
const std::string& Customer::surname() const { return surname_; }
void Customer::setName(const std::string& n) { name_ = n; }
const std::string& Customer::name() const    { return name_; }

void Customer::setCardNumber(int c) {
    if (!isValidCard(c))
        throw std::invalid_argument("Card number must be 4 digits");
    cardNumber_ = c;
}
int Customer::cardNumber() const { return cardNumber_; }

void Customer::setBankAccount(int a) {
    if (!isValidAccount(a))
        throw std::invalid_argument("Account number must be 5 digits");
    bankAccount_ = a;
}
int Customer::bankAccount() const { return bankAccount_; }


std::string Customer::toString() const
{
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}


std::ostream& operator<<(std::ostream& os, const Customer& c)
{
    os << std::left << std::setw(3)  << c.id_ << "  "
       << std::setw(12) << c.surname_ << " "
       << std::setw(10) << c.name_ << "  "
       << std::setw(4)  << std::setfill('0') << c.cardNumber_ << std::setfill(' ') << "  "
       << std::setw(5)  << std::setfill('0') << c.bankAccount_ << std::setfill(' ');
    return os;
}


std::istream& operator>>(std::istream& is, Customer& c)
{
  
    int id, card, account;
    std::string sur, nam;
    if (is >> id >> sur >> nam >> card >> account) {
        c = Customer{id, sur, nam, card, account};
    }
    return is;
}


bool Customer::operator<(const Customer& other) const
{
    return surname_ < other.surname_;
}
