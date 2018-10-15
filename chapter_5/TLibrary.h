//
// Created by simplehe on 2018/9/30.
//

#ifndef CHAPTER_5_TLIBRARY_H
#define CHAPTER_5_TLIBRARY_H

#include <string>

using std::string;

class TMedia_1;

class TMedia;

typedef long CustomerId;

class TLibrary {
public:
    TLibrary();

    virtual void CheckOut(TMedia_1 &thisMedia, CustomerId);

    virtual float CheckIn(const TMedia_1 &thisMedia);

private:

    unsigned long _total;
    string        _date;
};

TMedia::TMedia(const char *mediaDescription, unsigned short period, float lastRate) {

}

class TMedia {
public:
    TMedia(const char mediaDescription[], unsigned short period, float lastRate);

    ~TMedia() {}

    unsigned short GetCheckoutPeriod() const { return _checkoutDate; }

    float GetLateFeeRate() const { return _feeRate; }

    string GetCheckoutDate() const { return _checkoutDate; }

private:
    void SetCheckoutDate(const string &date);

    TMedia(const TMedia_1 &copy);

    TMedia &operator=(const TMedia_1 &assign);

    string _checkoutDate; //出借日期

    string _mediaTitle;

    float _feeRate;

    unsigned short _checkoutPeriod;

    friend class TLibrary;
};


class TMedia_1 {
public:
    TMedia_1(const char mediaDescription[]);

    virtual ~TMedia_1();

    virtual unsigned short GetCheckoutPeriod() const = 0;

    virtual float GetLateFeeRate() const = 0;

    string GetCheckoutDate() const { return _checkoutDate; }

private:

    void SetCheckoutDate(const string &date);

    TMedia_1(const TMedia_1 &copy);

    TMedia_1 &operator=(const TMedia_1 &assign);

    string _checkoutDate; //出借日期

    string _mediaTitle;

    friend class TLibrary;

};

TMedia_1::TMedia_1(const char *mediaDescription) : _mediaTitle(mediaDescription) {

}

class TPeriodical : public TMedia_1 {
public:
    TPeriodical(const char description[],
                unsigned short period, float rate) : TMedia_1(description), _checkoutPeriod(period),
                                                     _feeRate(rate) {
    }

    ~TPeriodical() {
    }

    virtual unsigned short GetCheckoutPeriod() const {
        return _checkoutPeriod;
    }

    virtual float GetLateFeeRate() const {
        return _feeRate;
    }

private:
    unsigned short _checkoutPeriod;
    float          _feeRate;//每天的滞纳金费率
};

class TVideoTape : public TMedia_1 {
public:
    TVideoTape(const char description[], unsigned short period, float rate) :
            TMedia_1(description), _checkoutPeroid(period), _feeRate(rate) {}

    ~TVideoTape();

    virtual unsigned short GetCheckOutPeriod() const {
        return _checkoutPeroid;
    }

    virtual float GetLateFeeRate() const {
        return _feeRate;
    }

private:
    unsigned short _checkoutPeroid;
    float          _feeRate;
};


#endif //CHAPTER_5_TLIBRARY_H
