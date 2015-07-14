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
 * @file        CFPP-Error.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFErrorRef wrapper
 */

#include <CF++.hpp>

namespace CF
{
    Error::Error( void )
    {
        this->_cfObject = NULL;
    }
    
    Error::Error( const Error & value )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = reinterpret_cast< CFErrorRef >( const_cast< void * >( CFRetain( value._cfObject ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    Error::Error( const AutoPointer & value )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFErrorRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    Error::Error( CFTypeRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = reinterpret_cast< CFErrorRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    Error::Error( CFErrorRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = reinterpret_cast< CFErrorRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    Error::Error( String domain, Number code )
    {
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            domain,
            static_cast< CFIndex >( code.GetSInt64Value() ),
            NULL
        );
    }
    
    Error::Error( String domain, Number code, Dictionary userInfo )
    {
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            domain,
            static_cast< CFIndex >( code.GetSInt64Value() ),
            userInfo
        );
    }
    
    Error::Error( CFStringRef domain, CFIndex code )
    {
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            domain,
            code,
            NULL
        );
    }
    
    Error::Error( CFStringRef domain, CFIndex code, CFDictionaryRef userInfo )
    {
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            domain,
            code,
            userInfo
        );
    }
    
    Error::Error( std::string domain, CFIndex code )
    {
        String s;
        
        s = domain;
        
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            s,
            code,
            NULL
        );
    }
    
    Error::Error( std::string domain, CFIndex code, Dictionary userInfo )
    {
        String s;
        
        s = domain;
        
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            s,
            code,
            userInfo
        );
    }
    
    Error::Error( const char * domain, CFIndex code )
    {
        String s;
        
        s = domain;
        
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            s,
            code,
            NULL
        );
    }
    
    Error::Error( const char * domain, CFIndex code, Dictionary userInfo )
    {
        String s;
        
        s = domain;
        
        this->_cfObject = CFErrorCreate
        (
            static_cast< CFAllocatorRef >( NULL ),
            s,
            code,
            userInfo
        );
    }
    
    #ifdef CFPP_HAS_CPP11
    Error::Error( Error && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
    }
    #endif
    
    Error::~Error( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    
    }
    
    Error & Error::operator = ( Error value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    Error & Error::operator = ( const AutoPointer & value )
    {
        return operator =( value.GetCFObject() );
    }
    
    Error & Error::operator = ( CFTypeRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = reinterpret_cast< CFErrorRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    Error & Error::operator = ( CFErrorRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = reinterpret_cast< CFErrorRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    CFTypeID Error::GetTypeID( void ) const
    {
        return CFErrorGetTypeID();
    }
    
    CFTypeRef Error::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    String Error::GetDomain( void ) const
    {
        String      str;
        CFStringRef cfStr;
        
        if( this->_cfObject == NULL )
        {
            return str;
        }
        
        cfStr = CFErrorGetDomain( this->_cfObject );
        str   = cfStr;
        
        return str;
    }
    
    Number Error::GetCode( void ) const
    {
        Number n;
        
        if( this->_cfObject == NULL )
        {
            return n;
        }
        
        n.SetSInt64Value( static_cast< SInt64 >( CFErrorGetCode( this->_cfObject ) ) );
        
        return n;
    }
    
    Dictionary Error::GetUserInfo( void ) const
    {
        AutoPointer d;
        
        if( this->_cfObject == NULL )
        {
            return CF::Dictionary();
        }
        
        d = CFErrorCopyUserInfo( this->_cfObject );
        
        return d.As< CFDictionaryRef >();
    }
    
    String Error::GetDescription( void ) const
    {
        AutoPointer s;
        
        if( this->_cfObject == NULL )
        {
            return CF::String();
        }
        
        s = CFErrorCopyDescription( this->_cfObject );
        
        return s.As< CFStringRef >();
    }
    
    String Error::GetFailureReason( void ) const
    {
        AutoPointer s;
        
        if( this->_cfObject == NULL )
        {
            return CF::String();
        }
        
        s = CFErrorCopyFailureReason( this->_cfObject );
        
        return s.As< CFStringRef >();
    }
    
    String Error::GetRecoverySuggestion( void ) const
    {
        AutoPointer s;
        
        if( this->_cfObject == NULL )
        {
            return CF::String();
        }
        
        s = CFErrorCopyRecoverySuggestion( this->_cfObject );
        
        return s.As< CFStringRef >();
    }
    
    void swap( Error & v1, Error & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
