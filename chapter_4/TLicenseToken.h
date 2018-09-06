//
// Created by simplehe on 2018/9/6.
//

#ifndef CHAPTER_4_TLICENSETOKEN_H
#define CHAPTER_4_TLICENSETOKEN_H

class TLicenseToken;

class TLicenseServer {
public:
    TLicenseServer(unsigned maxUsers);

    ~TLicenseServer();


    TLicenseServer *CreateNewLicense();

private:
    TLicenseServer(const TLicenseServer &other);

    TLicenseServer &operator=(const TLicenseServer &other);

    unsigned _numIssued;
    unsigned _maxTokens;
};

class TLicenseToken {
public:
    TLicenseToken();

    ~TLicenseToken();

private:
    TLicenseToken(const TLicenseToken &other);

    TLicenseToken &operator=(const TLicenseToken &other);
};

#endif //CHAPTER_4_TLICENSETOKEN_H
