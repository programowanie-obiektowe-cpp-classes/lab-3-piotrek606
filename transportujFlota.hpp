#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0;

    Stocznia     stocznia{};
    unsigned int suma            = 0;
    unsigned int liczbaZaglowcow = 0;

    while (suma < towar) {
        Statek* s = stocznia();          
        if (dynamic_cast< Zaglowiec* >(s) != nullptr) 
            ++liczbaZaglowcow;

        suma += s->transportuj(); 
        delete s;          
    }

    return liczbaZaglowcow;
}