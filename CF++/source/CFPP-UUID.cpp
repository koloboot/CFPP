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
 * @file        CFPP-UUID.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFUUIDRef wrapper
 */

#include <CF++.hpp>

namespace CF
{
    UUID::UUID( void )
    {
        this->_cfObject = CFUUIDCreate( static_cast< CFAllocatorRef >( NULL ) );
    }
    
    UUID::UUID( const UUID & value )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFUUIDRef >( CFRetain( value._cfObject ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    UUID::UUID( const AutoPointer & value )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFUUIDRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    UUID::UUID( CFTypeRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFUUIDRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    UUID::UUID( CFUUIDRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFUUIDRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    #ifdef CFPP_HAS_CPP11
    UUID::UUID( UUID && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
    }
    #endif
    
    UUID::~UUID( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    UUID & UUID::operator = ( UUID value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    UUID & UUID::operator = ( const AutoPointer & value )
    {
        return operator =( value.GetCFObject() );
    }
    
    UUID & UUID::operator = ( CFTypeRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFUUIDRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    UUID & UUID::operator = ( CFUUIDRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFUUIDRef >( CFRetain( value ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    bool UUID::operator == ( const UUID & value ) const
    {
        return this->GetString() == value.GetString();
    }
    
    bool UUID::operator == ( CFTypeRef value ) const
    {
        UUID u;
        
        u = value;
        
        return *( this ) == u;
    }
    
    bool UUID::operator == ( CFUUIDRef value ) const
    {
        UUID u;
        
        u = value;
        
        return *( this ) == u;
    }
    
    bool UUID::operator == ( std::string value ) const
    {
        return this->GetString() == value;
    }
    
    bool UUID::operator != ( const UUID & value ) const
    {
        return !( *( this ) == value );
    }
    
    bool UUID::operator != ( CFTypeRef value ) const
    {
        return !( *( this ) == value );
    }
    
    bool UUID::operator != ( CFUUIDRef value ) const
    {
        return !( *( this ) == value );
    }
    
    bool UUID::operator != ( std::string value ) const
    {
        return !( *( this ) == value );
    }
    
    UUID::operator std::string () const
    {
        String s;
        
        s = this->GetString();
        
        return s.GetValue();
    }
    
    CFTypeID UUID::GetTypeID( void ) const
    {
        return CFUUIDGetTypeID();
    }
    
    CFTypeRef UUID::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    String UUID::GetString( void ) const
    {
        AutoPointer s;
        
        if( this->_cfObject == NULL )
        {
            return s.As< CFStringRef >();
        }
        
        s = CFUUIDCreateString( static_cast< CFAllocatorRef >( NULL ), this->_cfObject );
        
        return s.As< CFStringRef >();
    }
    
    void swap( UUID & v1, UUID & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
