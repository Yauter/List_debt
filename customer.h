#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>


class Customer {
private:
    int         id_{};
    std::string surname_;
    std::string name_;
    int         cardNumber_{};
    int         bankAccount_{};

    static bool isValidCard(int card);       
    static bool isValidAccount(int account); 

public:

    Customer() = default;
    Customer(int id,
             std::string surname,
             std::string name,
             int cardNumber,
             int bankAccount);

    
    void        setId(int id);
    int         id()           const;
    void        setSurname(const std::string& s);
    const std::string& surname() const;
    void        setName(const std::string& n);
    const std::string& name() const;
    void        setCardNumber(int c);
    int         cardNumber()   const;
    void        setBankAccount(int a);
    int         bankAccount()  const;

  
    std::string toString() const;

 
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    friend std::istream& operator>>(std::istream& is, Customer& c);

  
    bool operator<(const Customer& other) const;
};

#endif 
