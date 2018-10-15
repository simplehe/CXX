//
// Created by simplehe on 2018/9/30.
//

#include "TLibrary.h"

TLibrary::TLibrary() : _total(0) {

}

void TLibrary::CheckOut(TMedia_1 &thisMedia, CustomerId) {
    thisMedia.SetCheckoutDate(_date);
    _total++;
}

float TLibrary::CheckIn(const TMedia_1 &thisMedia) {
    string checkoutDate = thisMedia.GetCheckoutDate();

    float lastfee = 0;

    return lastfee;

}


