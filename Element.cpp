/*
 * File:   Element.cpp
 * Author: rajib
 *
 * Created on November 25, 2011, 12:52 AM
 */

#include "Element.h"

Element::Element(string desc="")
{
   description=desc;
   moveable = true;
   counter = 0;
}

/*
 *string Element::get_description(){
 *    return description;
 *}
 *
 *void Element::set_description(string desc){
 *    description = desc;
 *}
 *
 */

Element::~Element()
{

}

