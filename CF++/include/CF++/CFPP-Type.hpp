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
 * @header      CFPP-Type.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ base abstract class for CF wrappers
 */

#ifndef CFPP_TYPE_H
#define CFPP_TYPE_H

namespace CF
{
    typedef enum
    {
        PropertyListFormatXML       = 0x00,
        PropertyListFormatBinary    = 0x01
    }
    PropertyListFormat;
    
    class Type
    {
        public:
            
            virtual ~Type( void );
            
            virtual CFTypeID  GetTypeID( void ) const = 0;
            virtual CFTypeRef GetCFObject( void ) const = 0;
            
            bool operator == ( const Type & value ) const;
            bool operator != ( const Type & value ) const;
            
            operator CFTypeRef              () const;
            operator CFBooleanRef           () const;
            operator CFNumberRef            () const;
            operator CFDateRef              () const;
            operator CFStringRef            () const;
            operator CFMutableStringRef     () const;
            operator CFURLRef               () const;
            operator CFDataRef              () const;
            operator CFMutableDataRef       () const;
            operator CFArrayRef             () const;
            operator CFMutableArrayRef      () const;
            operator CFDictionaryRef        () const;
            operator CFMutableDictionaryRef () const;
            operator CFUUIDRef              () const;
            operator CFErrorRef             () const;
            operator CFReadStreamRef        () const;
            operator CFWriteStreamRef       () const;
            
            std::string Description( void ) const;
            CFHashCode  Hash( void ) const;
            void        Show( void ) const;
            CFIndex     GetRetainCount( void ) const;
            
            bool IsValid( void ) const;
            bool IsValidPropertyList( PropertyListFormat format ) const;
            bool IsBoolean( void ) const;
            bool IsNumber( void ) const;
            bool IsDate( void ) const;
            bool IsString( void ) const;
            bool IsURL( void ) const;
            bool IsData( void ) const;
            bool IsArray( void ) const;
            bool IsDictionary( void ) const;
            bool IsUUID( void ) const;
            bool IsError( void ) const;
            bool IsReadStream( void ) const;
            bool IsWriteStream( void ) const;
            
            friend std::ostream & operator << ( std::ostream & os, const Type & obj );
    };
}

#endif /* CFPP_TYPE_H */
