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
 
/* $Id$ */

/*!
 * @header      CFPP-Error.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFErrorRef wrapper
 */

#ifndef __CFPP_ERROR_H__
#define __CFPP_ERROR_H__

#include <CF++/CFPP-Type.h>

namespace CF
{
    class Error: public Type
    {
        public:
            
            Error( void );
            Error( const Error & value );
            Error( CFTypeRef value );
            Error( CFErrorRef value );
            Error( CF::String domain, CF::Number code );
            Error( CF::String domain, CF::Number code, CF::Dictionary userInfo );
            Error( CFStringRef domain, CFIndex code );
            Error( CFStringRef domain, CFIndex code, CFDictionaryRef userInfo );
            Error( std::string domain, CFIndex code );
            Error( std::string domain, CFIndex code, CF::Dictionary userInfo );
            Error( const char * domain, CFIndex code );
            Error( const char * domain, CFIndex code, CF::Dictionary userInfo );
            
            virtual ~Error( void );
            
            Error & operator = ( const Error & value );
            Error & operator = ( CFTypeRef value );
            Error & operator = ( CFErrorRef value );
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            CF::String     GetDomain( void );
            CF::Number     GetCode( void );
            CF::Dictionary GetUserInfo( void );
            CF::String     GetDescription( void );
            CF::String     GetFailureReason( void );
            CF::String     GetRecoverySuggestion( void );
            
        private:
            
            CFErrorRef _cfObject;
    };
}

#endif /* __CFPP_ERROR_H__ */
