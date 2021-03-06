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
 * @file        CFPP-AnyObject.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ generic container for CF types
 */

#include <CF++.hpp>

namespace CF
{
    AnyObject::AnyObject( void ): _cfObject( NULL )
    {}
    
    AnyObject::AnyObject( const AnyObject & value ): _cfObject( value._cfObject )
    {
        if( this->_cfObject != NULL )
        {
            CFRetain( this->_cfObject );
        }
    }
    
    AnyObject::AnyObject( const AutoPointer & value ): _cfObject( value.GetCFObject() )
    {
        if( this->_cfObject != NULL )
        {
            CFRetain( this->_cfObject );
        }
    }
    
    AnyObject::AnyObject( CFTypeRef value ): _cfObject( value )
    {
        if( value != NULL )
        {
            CFRetain( value );
        }
    }
    
    #ifdef CFPP_HAS_CPP11
    AnyObject::AnyObject( AnyObject && value ) noexcept
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    #endif
    
    AnyObject::~AnyObject( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    AnyObject & AnyObject::operator = ( AnyObject value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    AnyObject & AnyObject::operator = ( const AutoPointer & value )
    {
        return operator =( AnyObject( value ) );
    }
    
    AnyObject & AnyObject::operator = ( CFTypeRef value )
    {
        return operator =( AnyObject( value ) );
    }
    
    CFTypeID AnyObject::GetTypeID( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return 0;
        }
        
        return CFGetTypeID( this->_cfObject );
    }
    
    CFTypeRef AnyObject::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    void swap( AnyObject & v1, AnyObject & v2 ) noexcept
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
