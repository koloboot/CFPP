/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        Test-CFPP-Dictionary.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Dictionary
 */

#include <CF++.hpp>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Dictionary, CTOR )
{}

TEST( CFPP_Dictionary, CTOR_AutoPointer )
{}

TEST( CFPP_Dictionary, CTOR_CFType )
{}

TEST( CFPP_Dictionary, CTOR_CFDictionary )
{}

TEST( CFPP_Dictionary, CCTOR )
{}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_Dictionary, MCTOR )
{}
#endif

TEST( CFPP_Dictionary, OperatorAssignDictionary )
{}

TEST( CFPP_Dictionary, OperatorAssignAutoPointer )
{}

TEST( CFPP_Dictionary, OperatorAssignCFType )
{}

TEST( CFPP_Dictionary, OperatorAssignCFDictionary )
{}

TEST( CFPP_Dictionary, OperatorPlusEqual )
{}

TEST( CFPP_Dictionary, OperatorLeftShiftEqual )
{}

TEST( CFPP_Dictionary, OperatorSubscriptCFType )
{}

TEST( CFPP_Dictionary, OperatorSubscriptCChar )
{}

TEST( CFPP_Dictionary, OperatorSubscriptString )
{}

TEST( CFPP_Dictionary, GetTypeID )
{}

TEST( CFPP_Dictionary, GetCFObject )
{}

TEST( CFPP_Dictionary, ContainsKey )
{}

TEST( CFPP_Dictionary, ContainsValue )
{}

TEST( CFPP_Dictionary, RemoveAllValues )
{}

TEST( CFPP_Dictionary, GetCount )
{}

TEST( CFPP_Dictionary, GetValue )
{}

TEST( CFPP_Dictionary, AddValue )
{}

TEST( CFPP_Dictionary, RemoveValue )
{}

TEST( CFPP_Dictionary, ReplaceValue )
{}

TEST( CFPP_Dictionary, SetValue )
{}

TEST( CFPP_Dictionary, Swap )
{}
