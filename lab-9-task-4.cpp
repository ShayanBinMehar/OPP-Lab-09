#include <iostream>
#include <string>

using namespace std;

class PaymentProcessor {
public:
    virtual bool handleTransaction(double total) = 0;
    virtual ~PaymentProcessor() {}
};

class CardPayment : public PaymentProcessor {
private:
    string accountID;

public:
    CardPayment(const string& id) : accountID(id) {}

    bool handleTransaction(double total) override {
        if (total > 0) {
            cout << "Card transaction of $" << total << " initiated for account: " << accountID << endl;
            return true;
        }
        return false;
    }
};

class EWallet : public PaymentProcessor {
private:
    double walletFunds;

public:
    EWallet(double funds) : walletFunds(funds) {}

    bool handleTransaction(double total) override {
        if (total > 0 && total <= walletFunds) {
            walletFunds -= total;
            cout << "E-Wallet transaction of $" << total << " approved. Balance left: $" << walletFunds << endl;
            return true;
        }
        return false;
    }
};

int main() {
    CardPayment visa("ABCD-1234-EFGH-5678");
    EWallet phonePay(100.0);

    visa.handleTransaction(50.0);
    phonePay.handleTransaction(30.0);
    phonePay.handleTransaction(80.0);

    return 0;
}
